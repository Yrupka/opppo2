#ifndef IMAGEPICKERDESKTOP_H
#define IMAGEPICKERDESKTOP_H
#ifndef __ANDROID__

#include "iimagepicker.h"
#include <QDebug>
#include <QImage>
#include <QFileDialog>
#include <QStandardPaths>

class ImagePicker : public IImagePicker {
  Q_OBJECT
public:
  ImagePicker() { }
public slots:
  void getImage() override {
    QUrl dir;
    do {
      const QStringList picturesLocation = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
      if (picturesLocation.empty() == false) {
        dir = picturesLocation[0];
        break;
      }

      const QStringList downloadLocation = QStandardPaths::standardLocations(QStandardPaths::DownloadLocation);
      if (downloadLocation.empty() == false) {
        dir = downloadLocation[0];
        break;
      }

      const QStringList documentLocation = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation);
      if (documentLocation.empty() == false) {
        dir = documentLocation[0];
        break;
      }

      dir = QDir::currentPath();
    } while (false);

    QString path = QFileDialog::getOpenFileName(nullptr,
                                                "Select one or more files to open",
                                                dir.path(),
                                                "Images (*.png *.jpg *.jpeg)"
    );

    QImage image(path);
    if (image.isNull())
      throw std::runtime_error("bad file format");

    emit imageSelected(image);
  }
signals:
  void imageSelected(QImage);
};

#endif
#endif // IMAGEPICKERDESKTOP_H
