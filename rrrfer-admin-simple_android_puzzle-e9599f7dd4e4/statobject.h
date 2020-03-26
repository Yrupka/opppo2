#ifndef STATOBJECT_H
#define STATOBJECT_H

#include "QtSql"
#include "mode.h"

//! Класс объекта управляющего статистикой
class StatObject
{
public:
    //! Конструктор класса
    StatObject();
    //! Деструктор класса
    ~StatObject();

    //! Запуск таймера считающего продолжительность игры
    void start();
    //! Возвращение данных статистики за игровую сессию
    QList<int> get_stats(Mode mode);

private:
    //! База данных статистики
    QSqlDatabase myDB;
    //! Таймер
    QTime start_time;
};

#endif // STATOBJECT_H
