//! код отсюда: https://pro-prof.com/forums/topic/%D0%B4%D0%B8%D0%BD%D0%B0%D0%BC%D0%B8%D1%87%D0%B5%D1%81%D0%BA%D0%B8%D0%B5-%D1%81%D0%B2%D0%BE%D0%B9%D1%81%D1%82%D0%B2%D0%B0-qt-%D0%B8-style-sheet

#ifndef PICKEDBUTTON_H
#define PICKEDBUTTON_H
#include <QPushButton>

//! кнопка-переключатель
//! находится в двух состояниях - выбрано-невыбрано
//! вырабатывает сигналы при переключении
class PickedButton: public QPushButton {
 Q_OBJECT
 Q_PROPERTY(bool picked READ picked WRITE pick NOTIFY picked)
public:
  PickedButton(const QString& text, QWidget *parent = nullptr);
public slots:
  void pick(bool);
  bool picked();
protected slots:
  void invert();
signals:
  void picked(bool);
private:
  bool m_picked;
};

#endif PICKEDBUTTON_H
