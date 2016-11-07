/* Copyright 2016 Samsung Electronics Co., Ltd.
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

#ifndef IOTJS_MODULE_PWM_LINUX_GENERAL_INL_H
#define IOTJS_MODULE_PWM_LINUX_GENERAL_INL_H


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "module/iotjs_module_pwm.h"
#include "iotjs_device_io-linux-general.h"


#define PWM_INTERFACE "/sys/class/pwm/pwmchip%d/"
#define PWM_PIN_INTERFACE "pwm%d/"
#define PWM_PIN_FORMAT PWM_INTERFACE PWM_PIN_INTERFACE
#define PWM_EXPORT PWM_INTERFACE "export"
#define PWM_UNEXPORT PWM_INTERFACE "unexport"
#define PWM_PIN_DUTYCYCLE "duty_cycle"
#define PWM_PIN_PERIOD "period"
#define PWM_PIN_ENABlE "enable"
#define PWM_DEFAULT_CHIP_NUMBER 0


namespace iotjs {


// Generic PWM implementation for linux.
class PwmLinuxGeneral : public Pwm {
 public:
  explicit PwmLinuxGeneral(const iotjs_jval_t* jpwm);

  static PwmLinuxGeneral* GetInstance();

  virtual int InitializePwmPath(PwmReqWrap* pwm_req);
  virtual int Export(PwmReqWrap* pwm_req);
  virtual int SetPeriod(PwmReqWrap* pwm_req);
  virtual int SetDutyCycle(PwmReqWrap* pwm_req);
  virtual int SetEnable(PwmReqWrap* pwm_req);
  virtual int Unexport(PwmReqWrap* pwm_req);

 public:
};


PwmLinuxGeneral::PwmLinuxGeneral(const iotjs_jval_t* jpwm)
    : Pwm(jpwm)
{
}


PwmLinuxGeneral* PwmLinuxGeneral::GetInstance() {
  return static_cast<PwmLinuxGeneral*>(Pwm::GetInstance());
}


// Set PWM period.
bool SetPwmPeriod(PwmReqData* req_data) {
  IOTJS_ASSERT(!iotjs_string_is_empty(&req_data->device));

  char path_buff[64] = {0};
  char value_buff[32] = {0};

  strcat(path_buff, iotjs_string_data(&req_data->device));
  strcat(path_buff, PWM_PIN_PERIOD);

  DDDLOG("PWM SetPeriod - path: %s, value: %d", path_buff, req_data->period);

  snprintf(value_buff, 31, "%d", req_data->period);

  if (!DeviceOpenWriteClose(path_buff, value_buff)) {
    return false;
  }

  return true;
}


// Set PWM Duty-Cycle.
bool SetPwmDutyCycle(PwmReqData* req_data) {
  IOTJS_ASSERT(!iotjs_string_is_empty(&req_data->device));

  char path_buff[64] = {0};
  char value_buff[32] = {0};

  strcat(path_buff, iotjs_string_data(&req_data->device));
  strcat(path_buff, PWM_PIN_DUTYCYCLE);

  DDDLOG("PWM SetdutyCycle - path: %s, value: %d",
         path_buff, req_data->duty_cycle);

  snprintf(value_buff, 31, "%d", req_data->duty_cycle);

  if (!DeviceOpenWriteClose(path_buff, value_buff)) {
    return false;
  }

  return true;
}


void AfterPwmWork(uv_work_t* work_req, int status) {
  PwmLinuxGeneral* pwm = PwmLinuxGeneral::GetInstance();
  PwmReqWrap* pwm_req = reinterpret_cast<PwmReqWrap*>(work_req->data);
  PwmReqData* req_data = pwm_req->req();

  if (status) {
    req_data->result = kPwmErrSys;
  }

  iotjs_jargs_t jargs = iotjs_jargs_create(1);
  iotjs_jargs_append_number(&jargs, req_data->result);

  switch (req_data->op) {
    case kPwmOpExport:
    case kPwmOpSetDutyCycle:
    case kPwmOpSetPeriod:
    case kPwmOpSetEnable:
    case kPwmOpUnexport:
      break;
    default:
    {
      IOTJS_ASSERT(!"Unreachable");
      break;
    }
  }

  iotjs_make_callback(pwm_req->jcallback(), Pwm::GetJPwm(), &jargs);

  iotjs_jargs_destroy(&jargs);
  iotjs_string_destroy(&req_data->device);

  delete work_req;
  delete pwm_req;
}


void ExportWorker(uv_work_t* work_req) {
  PwmReqWrap* pwm_req = reinterpret_cast<PwmReqWrap*>(work_req->data);
  PwmReqData* req_data = pwm_req->req();

  IOTJS_ASSERT(!iotjs_string_is_empty(&req_data->device));

  const char* path = iotjs_string_data(&req_data->device);
  const char* export_path;
  int32_t chip_number, pwm_number;

  // See if the pwm is already opened.
  if (!DeviceCheckPath(path)) {
    // Get chip_number and pwm_number.
    if (sscanf(path, PWM_PIN_FORMAT, &chip_number, &pwm_number) != 2) {
      req_data->result = kPwmErrExport;
      return;
    }

    // Write export pwm
    char buffer[64] = {0};
    snprintf(buffer, 63, PWM_EXPORT, chip_number);

    const char* created_files[] = {PWM_PIN_DUTYCYCLE, PWM_PIN_PERIOD,
                                   PWM_PIN_ENABlE};
    int created_files_length = sizeof(created_files) / sizeof(created_files[0]);
    if (!DeviceExport(buffer, pwm_number, path, created_files,
                      created_files_length)) {
      req_data->result = kPwmErrExport;
      return;
    }
  }

  // Set options.
  if (req_data->period >= 0) {
    if (!SetPwmPeriod(req_data)) {
      req_data->result = kPwmErrWrite;
      return;
    }
  }

  if (req_data->duty_cycle >= 0) {
    if (!SetPwmDutyCycle(req_data)) {
      req_data->result = kPwmErrWrite;
      return;
    }
  }

  DDDLOG("PWM ExportWorker - path: %s", path);

  req_data->result = kPwmErrOk;
}


void SetPeriodWorker(uv_work_t* work_req) {
  PwmReqWrap* pwm_req = reinterpret_cast<PwmReqWrap*>(work_req->data);
  PwmReqData* req_data = pwm_req->req();

  if (!SetPwmPeriod(req_data)) {
    req_data->result = kPwmErrWrite;
    return;
  }

  DDDLOG("PWM SetPeriodWorker");

  req_data->result = kPwmErrOk;
}


void SetDutyCycleWorker(uv_work_t* work_req) {
  PwmReqWrap* pwm_req = reinterpret_cast<PwmReqWrap*>(work_req->data);
  PwmReqData* req_data = pwm_req->req();

  if (!SetPwmDutyCycle(req_data)) {
    req_data->result = kPwmErrWrite;
    return;
  }

  DDDLOG("PWM SetDutyCycleWorker");

  req_data->result = kPwmErrOk;
}


void SetEnableWorker(uv_work_t* work_req) {
  PwmReqWrap* pwm_req = reinterpret_cast<PwmReqWrap*>(work_req->data);
  PwmReqData* req_data = pwm_req->req();

  IOTJS_ASSERT(!iotjs_string_is_empty(&req_data->device));

  iotjs_string_append(&req_data->device, PWM_PIN_ENABlE, -1);
  const char* path = iotjs_string_data(&req_data->device);

  char buff[10] = {0};
  snprintf(buff, 9, "%d", req_data->enable);
  if (!DeviceOpenWriteClose(path, buff)) {
    req_data->result = kPwmErrWrite;
    return;
  }

  DDDLOG("PWM SetEnableWorker - path: %s", path);

  req_data->result = kPwmErrOk;
}


void UnexportWorker(uv_work_t* work_req) {
  PwmReqWrap* pwm_req = reinterpret_cast<PwmReqWrap*>(work_req->data);
  PwmReqData* req_data = pwm_req->req();

  IOTJS_ASSERT(!iotjs_string_is_empty(&req_data->device));

  const char* path = iotjs_string_data(&req_data->device);
  const char* export_path;
  int32_t chip_number, pwm_number;

  if (DeviceCheckPath(path)) {
    sscanf(path, PWM_PIN_FORMAT, &chip_number, &pwm_number);
    // Write export pin
    char buffer[64] = {0};
    snprintf(buffer, 63, PWM_UNEXPORT, chip_number);

    DeviceUnexport(buffer, pwm_number);
  }

  DDDLOG("Pwm Unexport - path: %s", path);

  req_data->result = kPwmErrOk;
}


#define PWM_LINUX_GENERAL_IMPL_TEMPLATE(op) \
  do { \
    PwmLinuxGeneral* pwm = PwmLinuxGeneral::GetInstance(); \
    const iotjs_environment_t* env = iotjs_environment_get(); \
    uv_loop_t* loop = iotjs_environment_loop(env); \
    uv_work_t* req = new uv_work_t; \
    req->data = reinterpret_cast<void*>(pwm_req); \
    uv_queue_work(loop, req, op ## Worker, AfterPwmWork); \
  } while (0)


int PwmLinuxGeneral::InitializePwmPath(PwmReqWrap* pwm_req) {
  PwmReqData* req_data = pwm_req->req();

  int32_t chip_number, pwm_number;
  const char* path = iotjs_string_data(&req_data->device);
  char buffer[64] = {0};

  if (sscanf(path, PWM_PIN_FORMAT, &chip_number, &pwm_number) == 2) {

  } else if (sscanf(path, "%d", &pwm_number) == 1) {
    chip_number = PWM_DEFAULT_CHIP_NUMBER;
  } else {
    return -1;
  }

  // Create Device Path
  iotjs_string_make_empty(&req_data->device);
  snprintf(buffer, 63, PWM_PIN_FORMAT, chip_number, pwm_number);
  iotjs_string_append(&req_data->device, buffer, -1);

  return 0;
}


int PwmLinuxGeneral::Export(PwmReqWrap* pwm_req) {
  PWM_LINUX_GENERAL_IMPL_TEMPLATE(Export);
  return 0;
}


int PwmLinuxGeneral::SetPeriod(PwmReqWrap* pwm_req) {
  PWM_LINUX_GENERAL_IMPL_TEMPLATE(SetPeriod);
  return 0;
}


int PwmLinuxGeneral::SetDutyCycle(PwmReqWrap* pwm_req) {
  PWM_LINUX_GENERAL_IMPL_TEMPLATE(SetDutyCycle);
  return 0;
}


int PwmLinuxGeneral::SetEnable(PwmReqWrap* pwm_req) {
  PWM_LINUX_GENERAL_IMPL_TEMPLATE(SetEnable);
  return 0;
}


int PwmLinuxGeneral::Unexport(PwmReqWrap* pwm_req) {
  PWM_LINUX_GENERAL_IMPL_TEMPLATE(Unexport);
  return 0;
}


} // namespace iotjs


#endif /* IOTJS_MODULE_PWM_LINUX_GENERAL_INL_H */
