#ifndef STATWIDGET_H
#define STATWIDGET_H

#include <QWidget>
#include <QLabel>
#include "menu/style_button/statisticslabel.h"


//! Класс объекта создающего завершающее окно
class StatWidget : public QWidget
{
    Q_OBJECT
public:
    //! Конструктор класса
    explicit StatWidget(QWidget *parent = nullptr);
    //! Передача данных для отображения
    void set_data(QList<int> data);

signals:

    //! Сигнал выхода из окна
    void back();
private:
    //! Поле текущего времени
    StatisticsLabel *score_current;
    //! Поле лучшего времени
    StatisticsLabel *score_best;
    //! Поле собранных пазлов
    StatisticsLabel *puzzles_complete;
};

#endif // STATWIDGET_H
