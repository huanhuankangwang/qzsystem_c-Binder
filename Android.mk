LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
	
#LOCAL_MODULE_TAGS:= optional
LOCAL_SRC_FILES := \
	BpSystemParamService.cpp \
	test_client.cpp
	
	
LOCAL_SHARED_LIBRARIES := libcutils \
							libutils \
							libbinder \
							liblog 
LOCAL_C_INCLUDES:= $(LOCAL_PATH)
LOCAL_MODULE:= qzclient
include $(BUILD_EXECUTABLE)

#build server
##################################################
##################################################
#LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
	
#LOCAL_MODULE_TAGS:= optional
LOCAL_SRC_FILES := \
	BnSystemParamService.cpp \
	BpSystemParamService.cpp \
	test_server.cpp
	
	
LOCAL_SHARED_LIBRARIES := libcutils \
						   libutils \
						   libbinder \
						   liblog
LOCAL_C_INCLUDES:= $(LOCAL_PATH)
LOCAL_MODULE:= qzserver
include $(BUILD_EXECUTABLE)
