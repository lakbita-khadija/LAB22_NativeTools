#include <jni.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <android/log.h>

#define TAG "NATIVE_TOOLS"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_nativetools_MainActivity_getNativeMessage(
        JNIEnv* env,
        jobject /* this */) {
    LOGI("Message natif demande");
    return env->NewStringUTF("Bonjour depuis le code C++");
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_nativetools_MainActivity_computePower(
        JNIEnv* env,
        jobject /* this */,
        jint base,
        jint exponent) {

    if (exponent < 0) {
        LOGE("Exposant negatif");
        return -1;
    }

    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_nativetools_MainActivity_convertToUpper(
        JNIEnv* env,
        jobject /* this */,
        jstring input) {

    if (input == nullptr) {
        return env->NewStringUTF("Texte invalide");
    }

    const char* chars = env->GetStringUTFChars(input, nullptr);
    std::string text(chars);
    env->ReleaseStringUTFChars(input, chars);

    for (char& c : text) {
        c = static_cast<char>(toupper(static_cast<unsigned char>(c)));
    }

    return env->NewStringUTF(text.c_str());
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_example_nativetools_MainActivity_calculateAverage(
        JNIEnv* env,
        jobject /* this */,
        jintArray numbers) {

    if (numbers == nullptr) {
        return -1;
    }

    jsize len = env->GetArrayLength(numbers);
    if (len == 0) {
        return 0;
    }

    jint* elements = env->GetIntArrayElements(numbers, nullptr);

    long long sum = 0;
    for (jsize i = 0; i < len; i++) {
        sum += elements[i];
    }

    env->ReleaseIntArrayElements(numbers, elements, 0);

    return (double) sum / len;
}