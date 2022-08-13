//
// Created by binh on 8/13/2022.
//

#include <jni.h>
#include <MagickCore/studio.h>
#include <MagickCore/image.h>
#include <MagickWand/MagickWand.h>

JNIEXPORT jboolean JNICALL
Java_com_binh_imagemagick_MainActivity_convertWebpToGif(JNIEnv *env, jobject cls, jstring webp,
                                                        jstring gif) {

    const char *webpPath = (*env)->GetStringUTFChars(env, webp, 0);

    const char *gifPath = (*env)->GetStringUTFChars(env, gif, 0);

    ImageInfo *imageinfo = CloneImageInfo(0);
    int argc = 9;
    const char *argv[] = {"-dispose", "none", webpPath, "-coalesce", "-loop", "0", "-layers",
                          "optimize", gifPath};

    char **metadata = NULL;
    ExceptionInfo *exception = AcquireExceptionInfo();

    MagickWandGenesis();

    MagickBooleanType status = ConvertImageCommand(imageinfo, argc, (char **) argv, metadata,
                                                   exception);

    printf("MAGICK %s", exception->description);
    DestroyImageInfo(imageinfo);
    DestroyExceptionInfo(exception);

    MagickWandTerminus();

    return (status == MagickFalse ? 0 : 1);
}
