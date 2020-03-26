#include <QApplication>
#include <QFontDatabase>
#include "screencontroller.h"
#include <QString>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  srand(time(0));

  QFontDatabase::addApplicationFont(":/fonts/14831.ttf");

  ScreenController controller;
  controller.show();

  controller.setStyleSheet(
        "QWidget { background-color:#FFFFE0; border: 0px; }"
  );

  return a.exec();
}
