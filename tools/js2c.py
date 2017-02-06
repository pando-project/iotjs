#!/usr/bin/env python

# Copyright 2015-present Samsung Electronics Co., Ltd. and other contributors
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
#  This file converts src/js/*.js to a C-array in src/iotjs_js.[h|c] file.
# And this file also generates magic string list in src/iotjs_string_ext.inl.h
# file to reduce JerryScript heap usage.

import sys
import glob
import os
import re
import subprocess
import struct

from common_py.system.filesystem import FileSystem as fs
from common_py import path


def writeLine(fo, content, indent=0):
    buf = '  ' * indent
    buf += content
    buf += '\n'
    fo.write(buf)


def regroup(l, n):
    return [l[i:i+n] for i in range(0, len(l), n)]


def removeComments(code):
    pattern = r'(\".*?\"|\'.*?\')|(/\*.*?\*/|//[^\r\n]*$)'
    regex = re.compile(pattern, re.MULTILINE | re.DOTALL)

    def _replacer(match):
        if match.group(2) is not None:
            return ""
        else:
            return match.group(1)

    return regex.sub(_replacer, code)


def removeWhitespaces(code):
    return re.sub('\n+', '\n', re.sub('\n +', '\n', code))


def parseLiterals(code):
    JERRY_SNAPSHOT_VERSION = 6

    literals = set()

    header = struct.unpack('IIII', code[0:16])
    if header[0] != JERRY_SNAPSHOT_VERSION :
        print ('Please check jerry snapshot version (Last confirmed: %d)'
               % JERRY_SNAPSHOT_VERSION)
        exit(1)

    code_ptr = header[1] + 8
    while code_ptr < len(code):
        length = struct.unpack('H', code[code_ptr : code_ptr + 2])[0]
        code_ptr = code_ptr + 2
        if length == 0:
            continue
        if (length < 32):
            item = struct.unpack('%ds' % length,
                                 code[code_ptr : code_ptr + length])
            literals.add(item[0])
        code_ptr = code_ptr + length + (length % 2)

    return literals


LICENSE = '''
/* Copyright 2015-present Samsung Electronics Co., Ltd. and other contributors
 *
 * Licensed under the Apache License, Version 2.0 (the \"License\");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an \"AS IS\" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This file is generated by tools/js2c.py
 * Do not modify this.
 */
'''

HEADER1 = '''#ifndef IOTJS_JS_H
#define IOTJS_JS_H
'''

FOOTER1 = '''
#endif
'''

HEADER2 = '''#include <stdio.h>
#include "iotjs_js.h"
'''

FOOTER2 = '''
'''

HEADER3 = '''
#define JERRY_MAGIC_STRING_ITEMS \\
  \\
'''

FOOTER3 = '''
'''

NATIVE_STRUCT1 = '''
typedef struct {
  const char* name;
  const void* code;
  const int length;
} iotjs_js_module;

extern const iotjs_js_module natives[];
'''

NATIVE_STRUCT2 = '''
const iotjs_js_module natives[] = {
'''

DUMPER = ''
NO_SNAPSHOT = True
BUILDTYPE = 'debug'
MAGIC_STRING_SET = { b'process' }

def hex_format(ch):
    if isinstance(ch, str):
        ch = ord(ch)

    return "0x{:02x}".format(ch)

def printJSContents(fout_c, name, indent = 0):

    global DUMPER
    global NO_SNAPSHOT
    global BUILDTYPE
    global MAGIC_STRING_SET

    js_path = fs.join(path.SRC_ROOT, 'js', name + '.js')

    if NO_SNAPSHOT is True:
        code = open(js_path, 'r').read() + '\0'

        # minimize code when release mode
        if BUILDTYPE != 'debug':
            code = removeComments(code)
            code = removeWhitespaces(code)

        for line in regroup(code, 10):
            buf = ', '.join(map(lambda ch: str(ord(ch)), line))
            if line[-1] != '\0':
                buf += ','
            writeLine(fout_c, buf, indent)

        length = len(code) - 1

    else:
        fmodule = open(js_path, 'r')
        module = fmodule.read()
        fmodule.close()

        fmodule_wrapped = open(js_path + '.wrapped', 'w')
        if name != 'iotjs':
            # fmodule_wrapped.write ("(function (a, b, c) {\n")
            fmodule_wrapped.write(
                "(function(exports, require, module) {\n")

        fmodule_wrapped.write(module)

        if name != 'iotjs':
            fmodule_wrapped.write("});\n")
            # fmodule_wrapped.write ("wwwwrap(a, b, c); });\n")
        fmodule_wrapped.close()

        ret = subprocess.call([DUMPER,
                               '--save-snapshot-for-eval',
                               js_path + '.snapshot',
                               js_path + '.wrapped'])
        if ret != 0:
            msg = 'Failed to dump ' + js_path + (": - %d]" % (ret))
            print("%s%s%s" % ("\033[1;31m", msg, "\033[0m"))
            exit(1)

        code = open(js_path + '.snapshot', 'rb').read()

        fs.remove(js_path + '.wrapped')
        fs.remove(js_path + '.snapshot')

        for line in regroup(code, 8):
            buf = ', '.join(map(hex_format, line))
            buf += ','
            writeLine(fout_c, buf, indent)

        length = len(code)

        MAGIC_STRING_SET = MAGIC_STRING_SET | parseLiterals(code)

    return length


def js2c(buildtype, no_snapshot, js_modules, js_dumper):
    global DUMPER
    DUMPER = js_dumper

    global NO_SNAPSHOT
    NO_SNAPSHOT = no_snapshot

    global BUILDTYPE
    BUILDTYPE = buildtype

    fout_h = open(fs.join(path.SRC_ROOT, 'iotjs_js.h'), 'w')
    fout_c = open(fs.join(path.SRC_ROOT, 'iotjs_js.c'), 'w')
    fout_magic_str = open(fs.join(path.SRC_ROOT, 'iotjs_string_ext.inl.h'), 'w')

    fout_h.write(LICENSE)
    fout_h.write(HEADER1)
    fout_c.write(LICENSE)
    fout_c.write(HEADER2)
    fout_magic_str.write(LICENSE)
    fout_magic_str.write(HEADER3)

    for name in sorted(js_modules):
        writeLine(fout_h, 'extern const char ' + name + '_n[];')
        writeLine(fout_h, 'extern const char ' + name + '_s[];')
        writeLine(fout_h, 'extern const int ' + name + '_l;')

        writeLine(fout_c, 'const char ' + name + '_n[] = "' + name + '";')
        writeLine(fout_c, 'const char ' + name + '_s[] = {')
        length = printJSContents(fout_c, name, 1)
        writeLine(fout_c, '};');
        writeLine(fout_c, '#define SIZE_%s %d' % (name.upper(), length))
        writeLine(fout_c, 'const int %s_l = SIZE_%s;' % (name, name.upper()))

    fout_h.write(NATIVE_STRUCT1)
    fout_c.write(NATIVE_STRUCT2)

    for name in sorted(js_modules):
        writeLine(fout_c,
                  '{ %s_n, %s_s, SIZE_%s },' % (name, name, name.upper()), 1)
    writeLine(fout_c, '{ NULL, NULL, 0 }', 1)
    writeLine(fout_c, '};')

    fout_h.write(FOOTER1)
    fout_c.write(FOOTER2)

    global MAGIC_STRING_SET
    sorted_magic_strings = sorted(MAGIC_STRING_SET, key=lambda x: (len(x), x))
    for idx, magic_string in enumerate(sorted_magic_strings):
        if not isinstance(magic_string, str):
            magic = magic_string.decode('utf-8')
        else:
            magic = magic_string
        magic_text = repr(magic)[1:-1]

        fout_magic_str.write('  MAGICSTR_EX_DEF(MAGIC_STR_%d, "%s") \\\n'
                             % (idx, magic_text))

    fout_magic_str.write(FOOTER3)
