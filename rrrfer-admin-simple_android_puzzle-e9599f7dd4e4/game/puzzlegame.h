#ifndef PUZZLEGAME_H
#define PUZZLEGAME_H

#include "puzzleview.h"
#include "pathpoints.h"
#include "puzzlepath.h"
#include "game/puzzleitem/puzzleitem.h"
#include "sound_controller/soundcontroller.h"
#include <QLabel>

class SettableItem;

class PuzzleGame : public QWidget {
  Q_OBJECT
public:
  PuzzleGame(QWidget* parent = nullptr);
  void load(QPixmap &source, size_t n_rows, size_t n_columns, bool rotated);
protected slots:
  void onItemClicked();
  void onItemSetted();
  void rotate90();
signals:
  void finished(bool win);
  void back();
  void exit();

protected:
  QGraphicsScene m_scene;
  PuzzleView m_view;
  SoundController m_sound;
  QLabel m_label;

  const int GroundLayer = 0;
  int m_selectionLayer;
  int m_unsetted;
  bool m_image_orientation;
};

#endif // PUZZLEGAME_H
