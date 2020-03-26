#include "statisticslabel.h"
#include <QStyle>

StatisticsLabel::StatisticsLabel(const QString &text, QWidget *parent):
    QLabel(text, parent)
{
    setStyleSheet(
                    " QLabel {border-radius: 8px; padding: 6px;}"
                    " QLabel { background-color: #ccdd39;}"
                    " QLabel { font-family: hAndy;}" );
}
