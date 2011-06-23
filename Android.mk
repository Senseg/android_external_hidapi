LOCAL_PATH := $(call my-dir)

LIBICONV   := $(LOCAL_PATH)/../libiconv
LIBICONVINC:= $(LIBICONV)/include
LIBUSB     := $(LOCAL_PATH)/../libusb

include $(CLEAR_VARS)

LOCAL_MODULE    := hidapi

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/android \
	$(LIBUSB)/libusb \
	$(LIBUSB)/libusb/os \
	$(LIBICONVINC)

LOCAL_SRC_FILES  := \
	android/pthread_barrier.c \
	linux/hid-libusb.c \

include $(BUILD_STATIC_LIBRARY)

