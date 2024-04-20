#pragma once
#include "Teacher.h"


//Ĭ�Ϲ���
Teacher::Teacher()
{

}

//�вι���
Teacher::Teacher(int empId, string name, string pwd)
{
	//���Գ�ʼ��
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;

}

//�˵�����
void Teacher::opMenu()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------------\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		1.�鿴����ԤԼ		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		2.���ԤԼ		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		0.ע����¼		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t ---------------------------------------\n";
	cout << "��������ѡ��";
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_OrderSize == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_OrderSize; i++)
	{
		cout << "���ڣ�����" << of.m_OrderData[i]["date"] << "\t";
		cout << "ʱ�Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����") << "\t";
		cout << "ѧ�ţ�" << of.m_OrderData[i]["stuId"] << "\t";
		cout << "������" << of.m_OrderData[i]["stuName"] << "\t";
		cout << "������" << of.m_OrderData[i]["room"] << "��" << "\t";
		string status = "ԤԼ״̬��";		// 1�����	2ԤԼ�ɹ�	-1ԤԼʧ��	0ȡ��ԤԼ
		if (of.m_OrderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_OrderData[i]["status"] == "2")
		{
			status += "��ԤԼ";
		}
		else if (of.m_OrderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ�ܣ����Ժ����ԣ�";
		}
		else
		{
			status += "��ȡ��";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::checkOrder()
{
	OrderFile of;
	if (of.m_OrderSize == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼��" << endl;
	vector<int> v;
	int index = 0;

	for (int i = 0; i < of.m_OrderSize; i++)
	{
		if (of.m_OrderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << "��" << ++index << "��";
			cout << "���ڣ�����" << of.m_OrderData[i]["date"] << "\t";
			cout << "ʱ�Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����") << "\t";
			cout << "������" << of.m_OrderData[i]["room"] << "��" << "\t";
			string status = "ԤԼ״̬��";
			if (of.m_OrderData[i]["status"] == "1")
			{
				status += "�����";
			}
			cout << status << endl;
		}
	}
	cout << "������Ҫ��˵ļ�¼��0 ���أ�" << endl;
	int select = 0;
	int ret = 0;

	while (true)
	{
		cin >> select;
		if (select > 0 && select <= index)	//�Ϸ�
		{
			cout << "����ˣ�" << endl;
			cout << "1��ͨ��" << endl;
			cout << "2����ͨ��" << endl;
			while (true)
			{
				cin >> ret;
				if (ret == 1)
				{
					of.m_OrderData[v[select - 1]]["status"] = "2";

					//���µ��ļ�
					of.updateOrder();

					cout << "�����ϣ�" << endl;
					system("pause");
					system("cls");
					return;
				}
				else if (ret == 2)
				{
					of.m_OrderData[v[select - 1]]["status"] = "-1";

					//���µ��ļ�
					of.updateOrder();

					cout << "�����ϣ�" << endl;
					system("pause");
					system("cls");
					return;
				}
				cout << "�����������������룺" << endl;
			}

		}
		else if (select == 0)
		{
			system("cls");
			break;
		}
		cout << "�����������������룺" << endl;
	}
	
}