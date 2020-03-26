#include "screencontroller.h"
#include <QKeyEvent>
#include <QDebug>

ScreenController::ScreenController(QWidget *parent)
    : ScreensStack(parent) {

  m_menu = new MainMenuWidget(this);
  connect(m_menu, SIGNAL(imageSelected(QImage)),
          this, SLOT(on_image_selected(QImage)));
  connect(m_menu, SIGNAL(helpSelected()),
          this, SLOT(on_help_selected()));
  connect(m_menu, SIGNAL(back()),
          this, SLOT(close()));
  push(m_menu);

  m_game = new PuzzleGame(this);
  connect(m_game, SIGNAL(back()),  this, SLOT(pop()));
  connect(m_game, SIGNAL(finished(bool)), this, SLOT(pop()));
  m_game->hide();

  // --
  m_stat_widget = new StatWidget(this);
  connect(m_stat_widget, SIGNAL(back()), this, SLOT(pop()));
  connect(m_game, SIGNAL(finished(bool)), this, SLOT(on_finished()));
  m_stat_widget->hide();
  m_stat_obj = new StatObject();
  // --

  m_help = new HelpViewer(this);
  connect(m_help, SIGNAL(back()), SLOT(pop()));
  m_help->hide();
}

void ScreenController::on_image_selected(QImage image) {
  QPixmap pixmap = QPixmap::fromImage(image);

  bool screenOrientation = height() > width();
  bool pixmapOrientation = pixmap.height() > pixmap.width();

  if (screenOrientation != pixmapOrientation) {
    QTransform transform;
    QTransform trans = transform.rotate(90);
    pixmap = pixmap.transformed(trans);
  }

  Mode mode = m_menu->mode();
  m_game->load(pixmap, mode.horizontally, mode.vertically, mode.rotated);
  push(m_game);

  // --
  m_stat_obj->start();
  // --
}

void ScreenController::on_back_selected() {
  pop();
}

void ScreenController::on_help_selected() {
    push(m_help);
}

void ScreenController::on_finished()
{
    QList<int> data = m_stat_obj->get_stats(m_menu->mode());
    m_stat_widget->set_data(data);
    push(m_stat_widget);
}

void ScreenController::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Back) {
    if (lenght() > 1)
      pop();
    else
      this->close();
  }
  event->accept();
}


