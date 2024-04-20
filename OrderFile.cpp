#pragma once
#include "OrderFile.h"

//默认构造
OrderFile::OrderFile()
{

	//记录条目初始化
	this->m_OrderSize = 0;

	//将磁盘信息全部读入容器

	//接收用户输入
	string date, interval, stuId, stuName, room, status;
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "打开失败！" << endl;
		system("pause");
		system("cls");
		return;
	}

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> room && ifs >> status)
	{
		//存放一行数据
		map<string, string> m;

		//提取键值对后，插入m容器
		this->getKeyValue(date,m);
		this->getKeyValue(interval, m);
		this->getKeyValue(stuId, m);
		this->getKeyValue(stuName, m);
		this->getKeyValue(room, m);
		this->getKeyValue(status, m);


		////测试用
		//for (map<string, string>::iterator it = m.begin(); it != m.end(); it++)
		//{
		//	cout << "key:" << it->first << "  value:" << it->second << "\t";
		//}
		//cout << endl;

		//一行记录完毕后，存入维护的订单容器中
		this->m_OrderData.insert(make_pair(this->m_OrderSize, m));		//记录从0开始索引
		
		//记录条目自增
		this->m_OrderSize++;
	}

	
}

//更新预约记录
void OrderFile::updateOrder()
{
	fstream ofs;
	//删了重建
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	if (!ofs.is_open())
	{
		cout << "文件打开失败！" << endl;
		system("pause");
		system("cls");
		return;
	}
	//全部写入磁盘中
	for (int i = 0; i < this->m_OrderSize; i++)
	{
		ofs << "date:" << this->m_OrderData[i]["date"] << " ";
		ofs << "interval:" << this->m_OrderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_OrderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_OrderData[i]["stuName"] << " ";
		ofs << "room:" << this->m_OrderData[i]["room"] << " ";
		ofs << "status:" << this->m_OrderData[i]["status"] << endl;
	}
}

//取键值对
void OrderFile::getKeyValue(string field, map<string, string> &m)
{
	string key, value;
	//下面开始截取			例：date:3
	int pos = field.find(":", 0);
	if (pos == -1)
	{
		return;
	}
	key = field.substr(0, pos);
	value = field.substr(pos + 1, field.size() - pos - 1);		//size-pos-1 取key
	m.insert(make_pair(key, value));
}