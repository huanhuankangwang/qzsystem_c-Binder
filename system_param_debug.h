/******************************************************************************
 * Copyright (C), 2011-2013, Skyworth Digital Tech. Co., Ltd.
 *
 * FileName: sk_param_daemon_debug.h
 *
 * Description: 
 *
 * modification history
 *
 * --------------------
 * sdt03866@skyworth.com	2013/11/18	v1.0   create this file
 *
 *******************************************************************************/
#ifndef PARAM_DAEMON_DEBUG_H
#define PARAM_DAEMON_DEBUG_H


#include <android/log.h>


#define TAG "QZParamDaemon"

#if 1
#define QZ_INFO(fmt, ...)	__android_log_print(ANDROID_LOG_INFO, TAG, "[%5d][%s]"fmt, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#else
#define KW_INFO(fmt, ...)	((void)0)
#endif
#define QZ_ERR(fmt, ...)	__android_log_print(ANDROID_LOG_ERROR, TAG, "[%5d][%s]"fmt, __LINE__, __FUNCTION__, ##__VA_ARGS__)


#endif //KW_PARAM_DEBUG_H
