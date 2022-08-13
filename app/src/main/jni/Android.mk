
# android-magick
include $(CLEAR_VARS)

LOCAL_MODULE := android-magick

LOCAL_C_INCLUDES  :=  \
    $(IMAGE_MAGICK) \
    $(PNG_LIB_PATH) \
    $(JPEG_LIB_PATH) \
    $(WEBP_LIB_PATH) \

LOCAL_SRC_FILES := \
    $(ANDROID_MAGICK)/android-magick.c \

LOCAL_SHARED_LIBRARIES := \
    magick \
    libmagickcore-7 \
    libmagickwand-7 \

include $(BUILD_SHARED_LIBRARY)