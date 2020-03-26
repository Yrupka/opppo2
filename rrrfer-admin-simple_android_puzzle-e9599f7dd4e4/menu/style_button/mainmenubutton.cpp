#include "mainmenubutton.h"
#include <QStyle>

MainMenuButton::MainMenuButton(const QString& text, QWidget *parent)
  : QPushButton(text, parent) {
  setStyleSheet(
    " QPushButton {border-radius: 8px; padding: 6px;}"
    " QPushButton { background-color: #ccdd39;}"
    " QPushButton:pressed {"
    " background-color: #4baf4f;"
    "}"
    " QPushButton { font-family: hAndy;}"
              );
}

