#ifndef HELP_H
#define HELP_H

#include <QWidget>
#include "scrolledtextbrowser.h"

//! окно вывода справки о программе
class HelpViewer : public QWidget {
  Q_OBJECT
public:
  HelpViewer(QWidget* parent = nullptr);
  void load();
signals:
  void back();
  void exit();
};

#endif // HELP_H
