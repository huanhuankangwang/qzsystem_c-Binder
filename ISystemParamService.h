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
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>  // for status_t
#include <utils/KeyedVector.h>

 
namespace android {
	class ISystemParamService: public IInterface
	{
		
	public:
		DECLARE_META_INTERFACE(SystemParamService);
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

		virtual int set_mac(const char * p_mac) = 0;
		virtual int set_updateFlag(const char * update) = 0;
		virtual int set_sn(const char * p_sn) = 0;
		virtual int get_mac(char *p_mac) = 0;
		virtual int get_updateFlag(char * update) = 0;
		virtual int get_sn(char * p_sn) = 0;
	};

	class BnSystemParamService : public BnInterface<ISystemParamService>    
	{    
		public:        
			virtual status_t    onTransact( uint32_t code,
												const Parcel& data, 
												Parcel* reply,
												uint32_t flags = 0);
			virtual int set_mac(const char * p_mac);
			virtual int set_updateFlag(const char * update);
			virtual int set_sn(const char * p_sn);
			virtual int get_mac(char *p_mac);
			virtual int get_updateFlag(char * update);
			virtual int get_sn(char * p_sn);
	};

}; //namespace android

