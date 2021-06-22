#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlQuery>
static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");
    if(!db.open()) return false;
    QSqlQuery query;
    query.exec("create table dataforht (id int primary key, temperature int, humanity int)");
    query.exec("insert into dataforht values (1,25,65)");
    query.exec("insert into dataforht values (2,32,88)");
    query.exec("insert into dataforht values (3,32,88)");
    query.exec("insert into dataforht values (3,28,78)");
    query.exec("insert into dataforht values (3,26,89)");
    query.exec("insert into dataforht values (3,22,78)");
    query.exec("insert into dataforht values (3,32,87)");

    return true;
}
#endif // CONNECTION_H
