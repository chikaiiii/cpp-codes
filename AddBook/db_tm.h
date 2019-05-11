#pragma once
#ifndef _DB_TM_H
#define _DB_TM_H
#include <QtCore/QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include<QSql.h>
class db_tm
{
public:
	db_tm()
	{
		db.setHostName("127.0.0.1");      //连接数据库主机名(可填"127.0.0.1"或"localhost"）
		db.setPort(3306);                 //连接数据库端口号
		db.setDatabaseName("ADDRESSBOOK");      //连接数据库名
		db.setUserName("admin");          //数据库用户名
		db.setPassword("123456");    //数据库密码
	}	//建立数据库连接
	void connect_mysql();	//检测连接状态
	void close_mysql();		//断开数据库连接
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
};
void db_tm:: connect_mysql()
{
	db.open();
	if (!db.open())
	{
		qDebug() << "Connect Failed!" << db.lastError().text();
		return;
	}
	else
	{
		qDebug() << "Connect Success!";
	}
}
void db_tm::close_mysql()
{
	db.close();
}
#endif
