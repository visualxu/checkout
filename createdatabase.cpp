#include"createdatabase.h"
QSqlQuery createdata::createbase() {
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("root");
        db.setDatabaseName("MYSQL");
        db.setUserName("wangxu");
        db.setPassword("58271769");
        if (!db.open()) {
            fprintf(stderr,"open database failed !\n");
        }
        QSqlQuery query;
        query.exec("create table list(id int primary key,address varchar(100))");
        return query;

}
