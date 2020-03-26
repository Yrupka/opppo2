#include "statobject.h"

StatObject::StatObject()
{
    myDB = QSqlDatabase::addDatabase("QSQLITE");
    QString pathToDB = QDir::currentPath()+QString("/myDB.sql");
    myDB.setDatabaseName(pathToDB);

    QFileInfo info(pathToDB);
    if (!myDB.open())
        throw "errorDB";


    if (info.size() == 0) // если база пуста
    {
        QSqlQuery query;
        query.exec("CREATE TABLE puzzles ("
                   "type string, "
                   "best_time integer, "
                   "puzzle_count integer);");
    }
}

StatObject::~StatObject()
{
    myDB.close();
}

void StatObject::start()
{
    start_time.start();
}

QList<int> StatObject::get_stats(Mode mode)
{
    QSqlQuery query;
    QString mode_str;

    mode_str = QString("'%1x%2'").arg(QString::number(mode.horizontally))
            .arg(QString::number(mode.vertically));

    int best_time,
        user_time = start_time.elapsed() / 1000;
    int puzzles_complete = mode.horizontally * mode.vertically;

    query.exec("SELECT * FROM puzzles WHERE type = " + mode_str);
    if (query.next())
    {
        best_time = query.value(1).toInt();
        best_time = std::min(best_time, user_time);
        puzzles_complete += query.value(2).toInt();
        query.exec(QString("UPDATE puzzles SET best_time = %1, puzzle_count = %2 WHERE type = %3")
                   .arg(QString::number(best_time))
                   .arg(QString::number(puzzles_complete))
                   .arg(mode_str));
    }
    else
    {
        best_time = user_time;
        query.exec(QString("INSERT INTO puzzles (type, best_time, puzzle_count) VALUES (%1, %2, %3)")
                   .arg(mode_str)
                   .arg(QString::number(best_time))
                   .arg(QString::number(puzzles_complete)));
    }

    return QList<int>({user_time, best_time, puzzles_complete});
}
