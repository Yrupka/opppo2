#ifndef STATISTICSLABEL_H
#define STATISTICSLABEL_H

#include <QLabel>

class StatisticsLabel : public QLabel
{
public:
    StatisticsLabel(const QString& text, QWidget *parent = nullptr);
};

#endif // STATISTICSLABEL_H
