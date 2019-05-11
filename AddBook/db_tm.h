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
		db.setHostName("127.0.0.1");      //�������ݿ�������(����"127.0.0.1"��"localhost"��
		db.setPort(3306);                 //�������ݿ�˿ں�
		db.setDatabaseName("ADDRESSBOOK");      //�������ݿ���
		db.setUserName("admin");          //���ݿ��û���
		db.setPassword("123456");    //���ݿ�����
	}	//�������ݿ�����
	void connect_mysql();	//�������״̬
	void close_mysql();		//�Ͽ����ݿ�����
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
