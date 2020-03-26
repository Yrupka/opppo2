#ifndef MAINMENUWIDGET_H
#define MAINMENUWIDGET_H
#include <QWidget>
#include "levelmodewidget.h"

#ifdef __ANDROID__
  #include "image_picker/imagepickerandroid.h"
#else
  #include "image_picker/imagepickerdesktop.h"
#endif

class MainMenuWidget: public QWidget {
  Q_OBJECT
public:
  MainMenuWidget(QWidget* parent = nullptr);
  Mode mode();
signals:
  void helpSelected();
  void back();
  void imageSelected(QImage);
protected:
  LevelModeWidget* m_modeWidget;

  ImagePicker m_imagePicker;

};

#endif // MAINMENUWIDGET_H
