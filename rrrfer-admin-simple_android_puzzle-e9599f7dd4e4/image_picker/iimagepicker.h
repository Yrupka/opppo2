#ifndef IIMAGEPICKER_H
#define IIMAGEPICKER_H

#include <QObject>

#include <QDebug>
#include <QImage>

class IImagePicker : public QObject {
  Q_OBJECT
public:
  IImagePicker() { }
  virtual ~IImagePicker() { }
public slots:
  virtual void getImage() = 0;
signals:
  void imageSelected(QImage);
};

#endif // IIMAGEPICKER_H
