/******************************************************************************
 * Copyright (C), 2011-2013, Skyworth Digital Tech. Co., Ltd.
 *
 * FileName: main.cpp
 *
 * Description: 
 *
 * modification history
 *
 * --------------------
 * sdt03866@skyworth.com	2013/11/18	v1.0   create this file
 *
 *******************************************************************************/
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <private/android_filesystem_config.h>

#include "ISystemParamService.h"

#define SERVER_SERVICE_NAME "com.systemserver"


using namespace android;


int main(int argc, char *argv[])
{
	sp<ProcessState> proc(ProcessState::self());
	sp<IServiceManager> sm = defaultServiceManager();

	sm->addService(String16(SERVER_SERVICE_NAME), new BnSystemParamService());

	ProcessState::self()->startThreadPool();
	IPCThreadState::self()->joinThreadPool();

	return 0;
}

