#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H

#include "menu/mainmenuwidget.h"
#include "game/puzzlegame.h"
#include "tutorialviewer/helpviewer.h"
#include "screensstack.h"
#include "statobject.h"
#include "statwidget.h"
#include <QTimer>

class ScreenController : public ScreensStack {
  Q_OBJECT
public:
  explicit ScreenController(QWidget *parent = nullptr);
public slots:
  void on_back_selected();
  void on_image_selected(QImage image);
  void on_help_selected();
  void on_finished();
protected:
  void keyPressEvent(QKeyEvent *event);
private:
  MainMenuWidget *m_menu;
  PuzzleGame *m_game;
  HelpViewer *m_help;

  StatObject *m_stat_obj;
  StatWidget *m_stat_widget;
};

#endif // SCREENCONTROLLER_H
