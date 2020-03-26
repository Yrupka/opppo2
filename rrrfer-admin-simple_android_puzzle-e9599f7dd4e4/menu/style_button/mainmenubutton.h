#ifndef STYLEDBUTTON_H
#define STYLEDBUTTON_H
#include <QWidget>
#include <QPushButton>

//! базовая кнопка с установленными стилями приложения
class MainMenuButton : public QPushButton {
     Q_OBJECT
public:
  MainMenuButton(const QString& text, QWidget *parent = nullptr);
};

#endif // STYLEDBUTTON_H
