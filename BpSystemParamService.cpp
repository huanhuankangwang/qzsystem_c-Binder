/******************************************************************************
 * Copyright (C), 2011-2013, Skyworth Digital Tech. Co., Ltd.
 *
 * FileName: sk_crucial_params_utils.cpp
 *
 * Description: 
 *
 * modification history
 *
 * --------------------
 * sdt03866@skyworth.com	2013/11/18	v1.0   create this file
 *
 *******************************************************************************/
#include <stdio.h>
#include <utils/String8.h>

#include "ISystemParamService.h"
#include "system_param_debug.h"
//#include "BpSystemParamService.h"

#define WSERVER_SERVICE_NAME "com.wserver"



namespace android {

	class BpSystemParamService :public BpInterface<ISystemParamService>
	{
	public:
		BpSystemParamService(const sp<IBinder>& impl)
		 		   : BpInterface<ISystemParamService>(impl)
			{}

	int set_mac(const char * p_mac)
	{
		Parcel data, reply;
		
		if (NULL == p_mac || 0 == strlen(p_mac))
		{
			QZ_ERR("Illegal mac\n");
			return -1;
		}

		QZ_INFO("set mac: %s\n", p_mac);

		data.writeString16(String16(p_mac));

		remote()->transact(PARAM_TRANSACT_CODE_SET_MAC, data, &reply);

		return 0;
	}

	int set_updateFlag(const char * p_mac)
	{
		Parcel data, reply;

		if (NULL == p_mac || 0 == strlen(p_mac))
		{
			QZ_ERR("Illegal updateFlag\n");
			return -1;
		}

		QZ_INFO("set wifimac: %s\n", p_mac);

		data.writeString16(String16(p_mac));

		remote()->transact(PARAM_TRANSACT_CODE_SET_UPDATE_FLAG, data, &reply);

		return 0;
	}

	int set_sn(const char * p_sn)
	{
		Parcel data, reply;
		
		if (NULL == p_sn || 0 == strlen(p_sn))
		{
			QZ_ERR("Illegal sn\n");
			return -1;
		}

		QZ_INFO("set sn: %s\n", p_sn);

		data.writeString16(String16(p_sn));

		remote()->transact(PARAM_TRANSACT_CODE_SET_SN, data, &reply);

		return 0;
	}

	int get_sn(char * p_sn)
	{
		Parcel data, reply;
		String8 sn8;
		
		if (NULL == p_sn )
		{
			QZ_ERR("Illegal sn\n");
			return -1;
		}

		data.writeString16(String16(p_sn));
		remote()->transact(PARAM_TRANSACT_CODE_GET_SN, data, &reply);
		String16 s16 = reply.readString16();
		String8 s8 = String8(s16);
		int len = s8.length();
		strncpy(p_sn, s8.string(), s8.length());
		p_sn[len] = '\0';
		QZ_INFO("get sn: %s\n", p_sn);		

		return 0;
	}

	int get_mac(char * p_mac)
	{
		Parcel data, reply;
		String8 sn8;

		if (NULL == p_mac )
		{
			QZ_ERR("Illegal sn\n");
			return -1;
		}

		remote()->transact(PARAM_TRANSACT_CODE_GET_MAC, data, &reply);
		String16 s16 = reply.readString16();
		String8 s8 = String8(s16);
		int len = s8.length();
		strncpy(p_mac, s8.string(), s8.length());
		p_mac[len] = '\0';
		QZ_INFO("get mac: %s\n", p_mac);

		return 0;
	}

	int get_updateFlag(char * p_update)
	{
		Parcel data, reply;
		
		if (NULL == p_update )
		{
			QZ_ERR("Illegal updateFlag\n");
			return -1;
		}

		remote()->transact(PARAM_TRANSACT_CODE_GET_UPDATE_FLAG, data, &reply);
		String16 s16 = reply.readString16();
		String8 s8 = String8(s16);
		int len = s8.length();
		strncpy(p_update, s8.string(), s8.length());
		p_update[len] = '\0';
		QZ_INFO("get update: %s\n", p_update);

		return 0;
	}

	};
	
	IMPLEMENT_META_INTERFACE(SystemParamService, "ISystemParamService");

}; //namespace android

