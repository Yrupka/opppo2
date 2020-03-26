#ifndef IMAGEPICKERANDROID_H
#define IMAGEPICKERANDROID_H
#ifdef __ANDROID__
//source: https://stackoverflow.com/questions/34006608/qt-and-android-get-path-from-image-in-gallery

#include <QObject>
#include <QtAndroidExtras>

#include "iimagepicker.h"

#include <QDebug>
#include <QImage>

class ImagePicker : public IImagePicker, public QAndroidActivityResultReceiver {
  Q_OBJECT
public:
  ImagePicker() : IImagePicker(), QAndroidActivityResultReceiver() {
  }
public slots:
  void getImage() override {
    QAndroidJniObject ACTION_PICK = QAndroidJniObject::fromString("android.intent.action.GET_CONTENT");
    QAndroidJniObject intent("android/content/Intent");
    if (ACTION_PICK.isValid() && intent.isValid())
    {
      intent.callObjectMethod("setAction", "(Ljava/lang/String;)Landroid/content/Intent;", ACTION_PICK.object<jstring>());
      intent.callObjectMethod("setType", "(Ljava/lang/String;)Landroid/content/Intent;", QAndroidJniObject::fromString("image/*").object<jstring>());
      QtAndroid::startActivity(intent.object<jobject>(), 101, this);
    }
  }
public:
    virtual void handleActivityResult(int receiverRequestCode, int resultCode, const QAndroidJniObject & data) override {
      jint RESULT_OK = QAndroidJniObject::getStaticField<jint>("android/app/Activity", "RESULT_OK");
      if (receiverRequestCode == 101 && resultCode == RESULT_OK) {
        QAndroidJniObject activity = QtAndroid::androidActivity();
        QAndroidJniObject bytes = QAndroidJniObject::callStaticObjectMethod (
          "lqsa/util/ImageFromActivityResult",
          "getImage",
          "(Landroid/content/Intent;Lorg/qtproject/qt5/android/bindings/QtActivity;)[B",
          data.object<jobject>(), activity.object<jobject>()
        );

        QAndroidJniEnvironment env;
        jbyteArray imageDataArray = bytes.object<jbyteArray>();
        if (imageDataArray) {
          jsize imageSize = env->GetArrayLength(imageDataArray);
          if (imageSize > 0) {
            jboolean isCopy;
            jbyte *imageBytes = env->GetByteArrayElements(imageDataArray, &isCopy);
            QImage image = QImage(QImage::fromData((uchar*) imageBytes, imageSize));
            env->ReleaseByteArrayElements(imageDataArray, imageBytes, JNI_ABORT);
            emit imageSelected(image);
          }
        }
      }
    }
signals:
  void imageSelected(QImage);
};
#endif
#endif // IMAGEPICKERANDROID_H
