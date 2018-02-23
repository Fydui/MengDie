#include "sqlite.h"

sql::sql()
{
    
    sqldb = QSqlDatabase::addDatabase("QSQLITE");
    mysql =  nullptr;
}
sql::~sql()
{
    closeSql();    
    delete mysql;
}

bool sql::openSql(QString path)
{  
    sqldb.setDatabaseName(path);  
    //QString err = sqldb.lastError().text();
    /*
    QFile dfile("assets:/db/"+path);
    if (dfile.exists()){
        dfile.copy("./"+path);

    }
    
    sqldb.setDatabaseName("./" + path);*/
    if(!sqldb.open()){
        return false;
    }
    else if(sqldb.open() && mysql == nullptr) {        
        mysql = new QSqlQuery;
        return true;        
    }
    return false;
}

void sql::closeSql()
{
    sqldb.close();
}

QString sql::sqlError()
{
    return mysql->lastError().text();
}

QString sql::seleteSql(QString command,int v)
{
    mysql->exec(command);
    QString temp;
    if(mysql->isSelect())
        while (mysql->next()) 
            temp =  mysql->value(v).toString();        
    return temp;
}

void sql::controlSql(QString command)
{
    mysql->exec(command);
}

int sql::getColumnSum(QString tableName)
{
    QSqlQueryModel model;
    model.setQuery("SELECT * FROM " + tableName);   
    QString m = model.lastError().text();
    int c =  model.rowCount();
    return c;
}
