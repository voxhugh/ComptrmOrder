#pragma once
#include "OrderFile.h"

//Ĭ�Ϲ���
OrderFile::OrderFile()
{

	//��¼��Ŀ��ʼ��
	this->m_OrderSize = 0;

	//��������Ϣȫ����������

	//�����û�����
	string date, interval, stuId, stuName, room, status;
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "��ʧ�ܣ�" << endl;
		system("pause");
		system("cls");
		return;
	}

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> room && ifs >> status)
	{
		//���һ������
		map<string, string> m;

		//��ȡ��ֵ�Ժ󣬲���m����
		this->getKeyValue(date,m);
		this->getKeyValue(interval, m);
		this->getKeyValue(stuId, m);
		this->getKeyValue(stuName, m);
		this->getKeyValue(room, m);
		this->getKeyValue(status, m);


		////������
		//for (map<string, string>::iterator it = m.begin(); it != m.end(); it++)
		//{
		//	cout << "key:" << it->first << "  value:" << it->second << "\t";
		//}
		//cout << endl;

		//һ�м�¼��Ϻ󣬴���ά���Ķ���������
		this->m_OrderData.insert(make_pair(this->m_OrderSize, m));		//��¼��0��ʼ����
		
		//��¼��Ŀ����
		this->m_OrderSize++;
	}

	
}

//����ԤԼ��¼
void OrderFile::updateOrder()
{
	fstream ofs;
	//ɾ���ؽ�
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	//ȫ��д�������
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

//ȡ��ֵ��
void OrderFile::getKeyValue(string field, map<string, string> &m)
{
	string key, value;
	//���濪ʼ��ȡ			����date:3
	int pos = field.find(":", 0);
	if (pos == -1)
	{
		return;
	}
	key = field.substr(0, pos);
	value = field.substr(pos + 1, field.size() - pos - 1);		//size-pos-1 ȡkey
	m.insert(make_pair(key, value));
}