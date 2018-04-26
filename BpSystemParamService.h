/******************************************************************************
 * Copyright (C), 2011-2013, Skyworth Digital Tech. Co., Ltd.
 *
 * FileName: sk_crucial_params_utils.h
 *
 * Description: 
 *
 * modification history
 *
 * --------------------
 * sdt03866@skyworth.com	2013/11/18	v1.0   create this file
 *
 *******************************************************************************/
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <binder/Parcel.h>
#include <binder/IBinder.h>

 
namespace android {
	class BpSystemParamService :public BpInterface<ISystemParamService>
	{
	public:
		typedef enum param_transact_code_e
		{
			PARAM_TRANSACT_CODE_UNKNOWN		= 0,
			PARAM_TRANSACT_CODE_GET_MAC		= 1,
			PARAM_TRANSACT_CODE_SET_MAC		= 2,
			PARAM_TRANSACT_CODE_SET_SN		= 3,
			PARAM_TRANSACT_CODE_GET_SN		= 5,
			PARAM_TRANSACT_CODE_SET_UPDATE_FLAG		= 12,
			PARAM_TRANSACT_CODE_GET_UPDATE_FLAG		= 13,
		}param_transact_code_t;

		 BpSystemParamService(const sp<IBinder>& impl)
	       : BpInterface<ISystemParamService>(impl)
    	{
     	}

		int set_mac(const char * p_mac);
		int set_updateFlag(const char * update);
		int set_sn(const char * p_sn);
		int get_mac(char *p_mac);
		int get_updateFlag(char * update);
		int get_sn(char * p_sn);
	};

	
	IMPLEMENT_META_INTERFACE(SystemParamService, "android.media.ISystemParamService");
}; //namespace android

