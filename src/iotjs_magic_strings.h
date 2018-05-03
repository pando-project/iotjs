/* Copyright 2017-present Samsung Electronics Co., Ltd. and other contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef IOTJS_MAGIC_STRINGS_H
#define IOTJS_MAGIC_STRINGS_H

#if ENABLE_MODULE_SPI
#define IOTJS_MAGIC_STRING_0 "0"
#define IOTJS_MAGIC_STRING_1 "1"
#define IOTJS_MAGIC_STRING_2 "2"
#define IOTJS_MAGIC_STRING_3 "3"
#endif
#define IOTJS_MAGIC_STRING_ABORT "abort"
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING_ACKTYPE "type"
#endif
#if ENABLE_MODULE_ADC
#define IOTJS_MAGIC_STRING_ADC "Adc"
#endif
#define IOTJS_MAGIC_STRING_ADDHEADER "addHeader"
#if ENABLE_MODULE_UDP
#define IOTJS_MAGIC_STRING_ADDMEMBERSHIP "addMembership"
#endif
#define IOTJS_MAGIC_STRING_ADDRESS "address"
#define IOTJS_MAGIC_STRING_ARCH "arch"
#define IOTJS_MAGIC_STRING_ARGV "argv"
#define IOTJS_MAGIC_STRING_BASE64 "base64"
#if ENABLE_MODULE_UART
#define IOTJS_MAGIC_STRING_BAUDRATE "baudRate"
#endif
#define IOTJS_MAGIC_STRING_BIND "bind"
#if ENABLE_MODULE_BLE
#define IOTJS_MAGIC_STRING_BINDCONTROL "bindControl"
#endif
#define IOTJS_MAGIC_STRING_BINDING "binding"
#if ENABLE_MODULE_BLE
#define IOTJS_MAGIC_STRING_BINDRAW "bindRaw"
#define IOTJS_MAGIC_STRING_BINDUSER "bindUser"
#endif
#if ENABLE_MODULE_SPI
#define IOTJS_MAGIC_STRING_BITORDER "bitOrder"
#define IOTJS_MAGIC_STRING_BITORDER_U "BITORDER"
#define IOTJS_MAGIC_STRING_BITSPERWORD "bitsPerWord"
#endif
#define IOTJS_MAGIC_STRING_BOARD "board"
#if ENABLE_MODULE_GPIO
#define IOTJS_MAGIC_STRING_BOTH_U "BOTH"
#endif
#define IOTJS_MAGIC_STRING_BUFFER "Buffer"
#define IOTJS_MAGIC_STRING_BUILTIN_MODULES "builtin_modules"
#if ENABLE_MODULE_I2C || ENABLE_MODULE_SPI
#define IOTJS_MAGIC_STRING_BUS "bus"
#endif
#define IOTJS_MAGIC_STRING_BYTELENGTH "byteLength"
#define IOTJS_MAGIC_STRING_BYTEPARSED "byteParsed"
#if ENABLE_MODULE_HTTPS || ENABLE_MODULE_TLS
#define IOTJS_MAGIC_STRING_CA "ca"
#define IOTJS_MAGIC_STRING_CERT "cert"
#endif
#define IOTJS_MAGIC_STRING_CHDIR "chdir"
#if ENABLE_MODULE_PWM
#define IOTJS_MAGIC_STRING_CHIP "chip"
#endif
#if ENABLE_MODULE_SPI
#define IOTJS_MAGIC_STRING_CHIPSELECT "chipSelect"
#define IOTJS_MAGIC_STRING_CHIPSELECT_U "CHIPSELECT"
#endif
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING_CLIENTID "clientId"
#endif
#define IOTJS_MAGIC_STRING_CLOSE "close"
#define IOTJS_MAGIC_STRING_CLOSESYNC "closeSync"
#define IOTJS_MAGIC_STRING_CODE "code"
#define IOTJS_MAGIC_STRING_COMPARE "compare"
#define IOTJS_MAGIC_STRING_COMPILE "compile"
#define IOTJS_MAGIC_STRING_COMPILEMODULE "compileModule"
#define IOTJS_MAGIC_STRING_CONFIG "config"
#define IOTJS_MAGIC_STRING_CONNECT "connect"
#define IOTJS_MAGIC_STRING_COPY "copy"
#if ENABLE_MODULE_HTTPS
#define IOTJS_MAGIC_STRING_CREATEREQUEST "createRequest"
#endif
#define IOTJS_MAGIC_STRING__CREATESTAT "_createStat"
#define IOTJS_MAGIC_STRING_CREATETCP "createTCP"
#define IOTJS_MAGIC_STRING_CWD "cwd"
#define IOTJS_MAGIC_STRING_DATA "data"
#if ENABLE_MODULE_UART
#define IOTJS_MAGIC_STRING_DATABITS "dataBits"
#endif
#define IOTJS_MAGIC_STRING_DEBUGGERGETSOURCE "debuggerGetSource"
#define IOTJS_MAGIC_STRING_DEBUGGERWAITSOURCE "debuggerWaitSource"
#define IOTJS_MAGIC_STRING_DEVICE "device"
#if ENABLE_MODULE_GPIO
#define IOTJS_MAGIC_STRING_DIRECTION "direction"
#define IOTJS_MAGIC_STRING_DIRECTION_U "DIRECTION"
#endif
#ifdef ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING_DISCONNECT "disconnect"
#endif
#define IOTJS_MAGIC_STRING_DOEXIT "doExit"
#if ENABLE_MODULE_UDP
#define IOTJS_MAGIC_STRING_DROPMEMBERSHIP "dropMembership"
#endif
#if ENABLE_MODULE_PWM
#define IOTJS_MAGIC_STRING_DUTYCYCLE "dutyCycle"
#endif
#if ENABLE_MODULE_GPIO
#define IOTJS_MAGIC_STRING_EDGE "edge"
#define IOTJS_MAGIC_STRING_EDGE_U "EDGE"
#endif
#define IOTJS_MAGIC_STRING_EMIT "emit"
#define IOTJS_MAGIC_STRING_EMITEXIT "emitExit"
#if ENABLE_MODULE_TLS
#define IOTJS_MAGIC_STRING_END "end"
#endif
#define IOTJS_MAGIC_STRING_ENV "env"
#define IOTJS_MAGIC_STRING_ERRNAME "errname"
#define IOTJS_MAGIC_STRING_EXECUTE "execute"
#define IOTJS_MAGIC_STRING_EXITCODE "exitCode"
#define IOTJS_MAGIC_STRING_EXPORT "export"
#if ENABLE_MODULE_GPIO
#define IOTJS_MAGIC_STRING_FALLING_U "FALLING"
#endif
#define IOTJS_MAGIC_STRING_FAMILY "family"
#define IOTJS_MAGIC_STRING_FINISH "finish"
#if ENABLE_MODULE_HTTPS
#define IOTJS_MAGIC_STRING_FINISHREQUEST "finishRequest"
#endif
#if ENABLE_MODULE_GPIO
#define IOTJS_MAGIC_STRING_FLOAT_U "FLOAT"
#endif
#define IOTJS_MAGIC_STRING_FSTAT "fstat"
#define IOTJS_MAGIC_STRING_GETADDRINFO "getaddrinfo"
#define IOTJS_MAGIC_STRING_GETSOCKNAME "getsockname"
#if ENABLE_MODULE_GPIO
#define IOTJS_MAGIC_STRING_GPIO "Gpio"
#endif
#define IOTJS_MAGIC_STRING_HANDLER "handler"
#define IOTJS_MAGIC_STRING_HANDLETIMEOUT "handleTimeout"
#define IOTJS_MAGIC_STRING_HEADERS "headers"
#define IOTJS_MAGIC_STRING_HEX "hex"
#if ENABLE_MODULE_SPI
#define IOTJS_MAGIC_STRING_HIGH_U "HIGH"
#endif
#define IOTJS_MAGIC_STRING_HOME_U "HOME"
#define IOTJS_MAGIC_STRING_HOST "host"
#define IOTJS_MAGIC_STRING_HTTPPARSER "HTTPParser"
#if ENABLE_MODULE_GPIO
#define IOTJS_MAGIC_STRING_IN "IN"
#endif
#define IOTJS_MAGIC_STRING__INCOMING "_incoming"
#define IOTJS_MAGIC_STRING_IOTJS_ENV_U "IOTJS_ENV"
#define IOTJS_MAGIC_STRING_IOTJS_PATH_U "IOTJS_PATH"
#define IOTJS_MAGIC_STRING_IOTJS_EXTRA_MODULE_PATH_U "IOTJS_EXTRA_MODULE_PATH"
#define IOTJS_MAGIC_STRING_IOTJS_WORKING_DIR_PATH_U "IOTJS_WORKING_DIR_PATH"
#define IOTJS_MAGIC_STRING_IOTJS "iotjs"
#define IOTJS_MAGIC_STRING_IPV4 "IPv4"
#define IOTJS_MAGIC_STRING_IPV6 "IPv6"
#define IOTJS_MAGIC_STRING_ISALIVEEXCEPTFOR "isAliveExceptFor"
#define IOTJS_MAGIC_STRING_ISDEVUP "isDevUp"
#define IOTJS_MAGIC_STRING_ISDIRECTORY "isDirectory"
#define IOTJS_MAGIC_STRING_ISFILE "isFile"
#if ENABLE_MODULE_TLS
#define IOTJS_MAGIC_STRING_ISSERVER "isServer"
#endif
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING_KEEPALIVE "keepalive"
#endif
#define IOTJS_MAGIC_STRING_KEY "key"
#define IOTJS_MAGIC_STRING_LENGTH "length"
#define IOTJS_MAGIC_STRING_LISTEN "listen"
#define IOTJS_MAGIC_STRING_LOOPBACK "loopback"
#if ENABLE_MODULE_SPI
#define IOTJS_MAGIC_STRING_LSB "LSB"
#define IOTJS_MAGIC_STRING_MAXSPEED "maxSpeed"
#endif
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING_MESSAGE "message"
#endif
#define IOTJS_MAGIC_STRING_METHOD "method"
#define IOTJS_MAGIC_STRING_METHODS "methods"
#define IOTJS_MAGIC_STRING_MKDIR "mkdir"
#define IOTJS_MAGIC_STRING_MODE "mode"
#if ENABLE_MODULE_SPI || ENABLE_MODULE_GPIO
#define IOTJS_MAGIC_STRING_MODE_U "MODE"
#endif
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING_MQTTINIT "MqttInit"
#define IOTJS_MAGIC_STRING_MQTTMESSAGE "MqttMessage"
#define IOTJS_MAGIC_STRING_MQTTHANDLE "MqttHandle"
#endif
#if ENABLE_MODULE_SPI
#define IOTJS_MAGIC_STRING_MSB "MSB"
#endif
#if ENABLE_MODULE_SPI || ENABLE_MODULE_GPIO
#define IOTJS_MAGIC_STRING_NONE_U "NONE"
#endif
#define IOTJS_MAGIC_STRING_ONBODY "OnBody"
#define IOTJS_MAGIC_STRING_ONCLOSE "onclose"
#define IOTJS_MAGIC_STRING_ONCLOSED "onClosed"
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING__ONCONNECT "_onconnect"
#endif
#define IOTJS_MAGIC_STRING_ONCONNECTION "onconnection"
#define IOTJS_MAGIC_STRING_ONDATA "onData"
#ifdef ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING__ONDISCONNECT "_ondisconnect"
#endif
#define IOTJS_MAGIC_STRING_ONEND "onEnd"
#define IOTJS_MAGIC_STRING_ONERROR "onError"
#if ENABLE_MODULE_TLS
#define IOTJS_MAGIC_STRING_ONHANDSHAKEDONE "onhandshakedone"
#endif
#define IOTJS_MAGIC_STRING_ONHEADERSCOMPLETE "OnHeadersComplete"
#define IOTJS_MAGIC_STRING_ONHEADERS "OnHeaders"
#define IOTJS_MAGIC_STRING_ONMESSAGECOMPLETE "OnMessageComplete"
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING__ONMESSAGE "_onmessage"
#endif
#define IOTJS_MAGIC_STRING_ONMESSAGE "onmessage"
#define IOTJS_MAGIC_STRING__ONNEXTTICK "_onNextTick"
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING__ONPINGRESP "_onpingresp"
#define IOTJS_MAGIC_STRING__ONPUBACK "_onpuback"
#define IOTJS_MAGIC_STRING__ONPUBCOMP "_onpubcomp"
#define IOTJS_MAGIC_STRING__ONPUBREC "_onpubrec"
#define IOTJS_MAGIC_STRING__ONPUBREL "_onpubrel"
#endif
#define IOTJS_MAGIC_STRING_ONREAD "onread"
#define IOTJS_MAGIC_STRING_ONSOCKET "onSocket"
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING__ONSUBACK "_onsuback"
#define IOTJS_MAGIC_STRING__ONUNSUBACK "_onunsuback"
#endif
#define IOTJS_MAGIC_STRING_ONTIMEOUT "onTimeout"
#define IOTJS_MAGIC_STRING__ONUNCAUGHTEXCEPTION "_onUncaughtException"
#if ENABLE_MODULE_TLS
#define IOTJS_MAGIC_STRING_ONWRITE "onwrite"
#endif
#define IOTJS_MAGIC_STRING_ONWRITABLE "onWritable"
#if ENABLE_MODULE_GPIO
#define IOTJS_MAGIC_STRING_OPENDRAIN_U "OPENDRAIN"
#endif
#define IOTJS_MAGIC_STRING_OPEN "open"
#if ENABLE_MODULE_GPIO
#define IOTJS_MAGIC_STRING_OUT_U "OUT"
#endif
#define IOTJS_MAGIC_STRING_OWNER "owner"
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING_PACKETID "packet_id"
#define IOTJS_MAGIC_STRING_PASSWORD "password"
#endif
#define IOTJS_MAGIC_STRING_PAUSE "pause"
#define IOTJS_MAGIC_STRING_PERIOD "period"
#define IOTJS_MAGIC_STRING_PIN "pin"
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING_PING "ping"
#endif
#define IOTJS_MAGIC_STRING_PLATFORM "platform"
#define IOTJS_MAGIC_STRING_PORT "port"
#define IOTJS_MAGIC_STRING_PROTOTYPE "prototype"
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING_PUBLISH "publish"
#endif
#if ENABLE_MODULE_GPIO
#define IOTJS_MAGIC_STRING_PULLDOWN_U "PULLDOWN"
#define IOTJS_MAGIC_STRING_PULLUP_U "PULLUP"
#define IOTJS_MAGIC_STRING_PUSHPULL_U "PUSHPULL"
#endif
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING_QOS "qos"
#endif
#define IOTJS_MAGIC_STRING_READDIR "readdir"
#define IOTJS_MAGIC_STRING_READ "read"
#define IOTJS_MAGIC_STRING_READSOURCE "readSource"
#define IOTJS_MAGIC_STRING_READSTART "readStart"
#define IOTJS_MAGIC_STRING_READSYNC "readSync"
#define IOTJS_MAGIC_STRING_READUINT8 "readUInt8"
#if ENABLE_MODULE_DGRAM
#define IOTJS_MAGIC_STRING_RECVSTART "recvStart"
#define IOTJS_MAGIC_STRING_RECVSTOP "recvStop"
#endif
#define IOTJS_MAGIC_STRING_REF "ref"
#define IOTJS_MAGIC_STRING_REINITIALIZE "reinitialize"
#if ENABLE_MODULE_TLS || ENABLE_MODULE_HTTPS
#define IOTJS_MAGIC_STRING_REJECTUNAUTHORIZED "rejectUnauthorized"
#endif
#define IOTJS_MAGIC_STRING_RENAME "rename"
#define IOTJS_MAGIC_STRING_REQUEST_U "REQUEST"
#define IOTJS_MAGIC_STRING_RESPONSE_U "RESPONSE"
#define IOTJS_MAGIC_STRING_RESUME "resume"
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING_RETAIN "retain"
#endif
#define IOTJS_MAGIC_STRING__REUSEADDR "_reuseAddr"
#if ENABLE_MODULE_GPIO
#define IOTJS_MAGIC_STRING_RISING_U "RISING"
#endif
#define IOTJS_MAGIC_STRING_RMDIR "rmdir"
#define IOTJS_MAGIC_STRING_SEND "send"
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING_SENDACK "sendAck"
#endif
#define IOTJS_MAGIC_STRING_SENDREQUEST "sendRequest"
#if ENABLE_MODULE_TLS
#define IOTJS_MAGIC_STRING_SERVERNAME "servername"
#endif
#if ENABLE_MODULE_I2C
#define IOTJS_MAGIC_STRING_SETADDRESS "setAddress"
#endif
#if ENABLE_MODULE_UDP
#define IOTJS_MAGIC_STRING_SETBROADCAST "setBroadcast"
#endif
#if ENABLE_MODULE_PWM
#define IOTJS_MAGIC_STRING_SETDUTYCYCLE "setDutyCycle"
#define IOTJS_MAGIC_STRING_SETDUTYCYCLESYNC "setDutyCycleSync"
#define IOTJS_MAGIC_STRING_SETENABLE "setEnable"
#define IOTJS_MAGIC_STRING_SETENABLESYNC "setEnableSync"
#define IOTJS_MAGIC_STRING_SETFREQUENCY "setFrequency"
#define IOTJS_MAGIC_STRING_SETFREQUENCYSYNC "setFrequencySync"
#endif
#if ENABLE_MODULE_BLE
#define IOTJS_MAGIC_STRING_SETFILTER "setFilter"
#endif
#define IOTJS_MAGIC_STRING_SETKEEPALIVE "setKeepAlive"
#define IOTJS_MAGIC_STRING_SETMULTICASTLOOPBACK "setMulticastLoopback"
#if ENABLE_MODULE_DGRAM
#define IOTJS_MAGIC_STRING_SETMULTICASTTTL "setMulticastTTL"
#endif
#if ENABLE_MODULE_PWM
#define IOTJS_MAGIC_STRING_SETPERIOD "setPeriod"
#define IOTJS_MAGIC_STRING_SETPERIODSYNC "setPeriodSync"
#endif
#define IOTJS_MAGIC_STRING_SETTIMEOUT "setTimeout"
#if ENABLE_MODULE_DGRAM
#define IOTJS_MAGIC_STRING_SETTTL "setTTL"
#endif
#define IOTJS_MAGIC_STRING_SHOULDKEEPALIVE "shouldkeepalive"
#define IOTJS_MAGIC_STRING_SHUTDOWN "shutdown"
#define IOTJS_MAGIC_STRING_SLICE "slice"
#if ENABLE_MODULE_SPI
#define IOTJS_MAGIC_STRING_SPI "Spi"
#endif
#define IOTJS_MAGIC_STRING_START "start"
#define IOTJS_MAGIC_STRING_STAT "stat"
#define IOTJS_MAGIC_STRING_STATS "stats"
#define IOTJS_MAGIC_STRING_STATUS_MSG "status_msg"
#define IOTJS_MAGIC_STRING_STATUS "status"
#define IOTJS_MAGIC_STRING_STDERR "stderr"
#define IOTJS_MAGIC_STRING_STDOUT "stdout"
#define IOTJS_MAGIC_STRING_STOP "stop"
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING_SUBSCRIBE "subscribe"
#endif
#if ENABLE_MODULE_TLS
#define IOTJS_MAGIC_STRING_TLSSOCKET "TLSSocket"
#define IOTJS_MAGIC_STRING_TLSCONTEXT "TlsContext"
#define IOTJS_MAGIC_STRING_TLSINIT "TlsInit"
#endif
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING_TOPIC "topic"
#endif
#define IOTJS_MAGIC_STRING_TOSTRING "toString"
#if ENABLE_MODULE_SPI
#define IOTJS_MAGIC_STRING_TRANSFER "transfer"
#define IOTJS_MAGIC_STRING_TRANSFERSYNC "transferSync"
#endif
#define IOTJS_MAGIC_STRING_UNLINK "unlink"
#define IOTJS_MAGIC_STRING_UNREF "unref"
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING_UNSUBSCRIBE "unsubscribe"
#endif
#define IOTJS_MAGIC_STRING_UPGRADE "upgrade"
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING_USERNAME "username"
#endif
#define IOTJS_MAGIC_STRING_URL "url"
#define IOTJS_MAGIC_STRING_VERSION "version"
#if ENABLE_MODULE_MQTT
#define IOTJS_MAGIC_STRING_WILL "will"
#endif
#define IOTJS_MAGIC_STRING_WRITEUINT8 "writeUInt8"
#define IOTJS_MAGIC_STRING_WRITE "write"
#define IOTJS_MAGIC_STRING_WRITEDECODE "writeDecode"
#define IOTJS_MAGIC_STRING_WRITESYNC "writeSync"
#if ENABLE_MODULE_HTTPS
#define IOTJS_MAGIC_STRING__WRITE "_write"
#endif
#if ENABLE_MODULE_BRIDGE
#define IOTJS_MAGIC_STRING_MODULE_NAME "MODULE_NAME"
#endif
#if ENABLE_MODULE_TIZEN
#define IOTJS_MAGIC_STRING_TIZEN "tizen"
#define IOTJS_MAGIC_STRING_APP_CONTROL "appControl"
#endif

#endif /* IOTJS_MAGIC_STRINGS_H */
