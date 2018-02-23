#ifndef SQLITE_H
#define SQLITE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QVariant>
#include <QSqlQueryModel>
class sql
{
public:
    sql();
    ~sql();
    int getColumnSum(QString tableName);        //获得某个表的列数
    bool openSql(QString path);
    void closeSql();
    void controlSql(QString command);           //没啥用的数据库命令 等价于sql::mysql->exec("");
    QString seleteSql(QString command, int v);  //封装好的查询命令
    QString sqlError();                         //报错
    QSqlQuery *mysql;

private:    
    QSqlDatabase sqldb;
};

#endif // SQLITE_H
