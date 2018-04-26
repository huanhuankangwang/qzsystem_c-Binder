#include <utils/String8.h>

#include "system_param_debug.h"
#include "ISystemParamService.h"

char mac[40] = {"23:23:23:45:35"};
char sn[20]  = {"sddd2324"};
char verify[20] = {"yes"};

namespace android {

	/***********************************************************
	 *                    Private Functions                    *
	 ***********************************************************/
	status_t BnSystemParamService::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
	{
		status_t ret = -1;
		String8 s8_mac, s8_sn, s8_verify;
		String16 s16_mac, s16_sn, s16_verify;

		QZ_INFO("onTransact. code:%d, data.dataSize:%d", code, data.dataSize());
		
		switch (code)
		{		
		case PARAM_TRANSACT_CODE_GET_MAC:
			QZ_INFO("SK_PARAM_DAEMON_TRANSACT_CODE_GET_MAC");
			
			reply->writeString16(String16(mac));
			ret = 0;
			break;
		case PARAM_TRANSACT_CODE_GET_SN:
			QZ_INFO("SK_PARAM_DAEMON_TRANSACT_CODE_GET_SN");
			reply->writeString16(String16(sn));
			ret = 0;
			break;
			
		case PARAM_TRANSACT_CODE_GET_UPDATE_FLAG:
			QZ_INFO("SK_PARAM_DAEMON_TRANSACT_CODE_GET_VERIFY");

			reply->writeString16(String16(verify));
			ret = 0;
			break;
			
		case PARAM_TRANSACT_CODE_SET_MAC:
			QZ_INFO("SK_PARAM_DAEMON_TRANSACT_CODE_SET_MAC");

			s16_mac = data.readString16();
			s8_mac = String8(s16_mac);

			memset(mac, 0, sizeof(mac));
			strncpy(mac, s8_mac.string(), sizeof(mac));
			ret = 0;
			break;
		case PARAM_TRANSACT_CODE_SET_SN:
			QZ_INFO("SK_PARAM_DAEMON_TRANSACT_CODE_SET_SN");
			
			s16_sn = data.readString16();
			s8_sn = String8(s16_sn);
			memset(sn, 0, sizeof(sn));
			strncpy(sn, s8_sn.string(), sizeof(sn));
			ret = 0;	
			break;
			
		case PARAM_TRANSACT_CODE_SET_UPDATE_FLAG:
			QZ_INFO("SK_PARAM_DAEMON_TRANSACT_CODE_SET_VERIFY");
			s16_verify = data.readString16();
			s8_verify = String8(s16_verify);
			memset(verify, 0, sizeof(verify));
			strncpy(verify, s8_verify.string(), sizeof(verify));
			ret = 0;
			break;
		default:
			QZ_ERR("PARAM_TRANSACT_CODE_UNKNOWN");
			break;
		}

		return ret;
	}

	int BnSystemParamService::set_mac(const char * p_mac)
	{
		return 0;
	}
	int BnSystemParamService::set_updateFlag(const char * update)
	{
		return 0;
	}
	int BnSystemParamService::set_sn(const char * p_sn)
	{
		return 0;
	}
	int BnSystemParamService::get_mac(char *p_mac){return 0;}
	int BnSystemParamService::get_updateFlag(char * update){return 0;}
	int BnSystemParamService::get_sn(char * p_sn){return 0;}
}; //namespace android

