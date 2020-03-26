#include "statwidget.h"
#include <QGridLayout>
#include "menu/style_button/mainmenubutton.h"

StatWidget::StatWidget(QWidget *parent) : QWidget(parent)
{
    QGridLayout *layer = new QGridLayout(this);
    setLayout(layer);
    setStyleSheet("background: white;");

    MainMenuButton *exitButton = new MainMenuButton("ОК",this);
    score_current = new StatisticsLabel("",this);
    score_best = new StatisticsLabel("",this);
    puzzles_complete = new StatisticsLabel("",this);
    StatisticsLabel *statistic = new StatisticsLabel("СТАТИСТИКА",this);

    layer->addItem(new QSpacerItem(10, 0, QSizePolicy::Minimum, QSizePolicy::Expanding), 5, 0);
    layer->addWidget(statistic, 10, 0, Qt::AlignCenter);
    layer->addItem(new QSpacerItem(10, 0, QSizePolicy::Minimum, QSizePolicy::Expanding), 15, 0);
    layer->addWidget(score_current, 20, 0, Qt::AlignCenter);
    layer->addItem(new QSpacerItem(10, 0, QSizePolicy::Minimum, QSizePolicy::Expanding), 25, 0);
    layer->addWidget(score_best, 30, 0, Qt::AlignCenter);
    layer->addItem(new QSpacerItem(10, 0, QSizePolicy::Minimum, QSizePolicy::Expanding), 35, 0);
    layer->addWidget(puzzles_complete, 40, 0, Qt::AlignCenter);
    layer->addItem(new QSpacerItem(10, 0, QSizePolicy::Minimum, QSizePolicy::Expanding), 45, 0);
    layer->addWidget(exitButton, 50, 0);

    connect(exitButton, SIGNAL(clicked()), SIGNAL(back()));
}

void StatWidget::set_data(QList<int> data)
{
    score_current->setText("Ваше время, сек: " + QString::number(data[0]));
    score_best->setText("Лучшее время, сек: " + QString::number(data[1]));
    puzzles_complete->setText("Собрано пазлов: " + QString::number(data[2]));
}
