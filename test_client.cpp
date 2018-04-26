#define LOG_TAG "HelloService"
#include <fcntl.h>
#include <sys/prctl.h>
#include <sys/wait.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <cutils/properties.h>
#include <utils/Log.h>

#include "ISystemParamService.h"
#include "system_param_debug.h"

using namespace android;

#define SERVER_SERVICE_NAME "com.systemserver"


int main()
{
	char mac[40];
   /* getService */
   /* ������, mmap */
   sp<ProcessState> proc(ProcessState::self());

   /* ���BpServiceManager */
   sp<IServiceManager> sm = defaultServiceManager();
   //��ȡSERVER_SERVICE_NAME����
   sp<IBinder> binder = sm->getService(String16(SERVER_SERVICE_NAME));

   if (binder == 0)
   {
	   QZ_ERR("can't get %s service\n",SERVER_SERVICE_NAME);
	   return -1;
   }

   /* service�϶���BpHelloServieָ�� */
   sp<ISystemParamService> service = interface_cast<ISystemParamService>(binder);
   service->set_mac("12:30:45:91:20");
   service->get_mac(mac);
   QZ_INFO("get mac:%s\r\n",mac);
	
	return 0;
}
