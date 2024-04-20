#pragma once
#include "Student.h"

//Ĭ�Ϲ���
Student::Student()
{

}
//�вι���
Student::Student(int id, string name, string pwd)
{
	//���Գ�ʼ��
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//����������ʼ��
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	
	while (ifs >> com.m_Id && ifs >> com.m_MaxNum)
	{
		this->m_Com.push_back(com);
	}


}

//�˵�����
void Student::opMenu()
{
	cout << "��ӭѧ������" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------------\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		1.����ԤԼ		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		2.�鿴�ҵ�ԤԼ		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		3.�鿴����ԤԼ		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		4.ȡ��ԤԼ		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		0.ע����¼		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t ---------------------------------------\n";
	cout << "��ѡ�����Ĳ�����" << endl;
}

//����ԤԼ
void Student::applyOrder()
{
	int date = 0;	//����
	int interval = 0;	//ʱ���
	int id = 0;	//������
	cout << "��������ʱ�䣺��һ~����" << endl;
	cout << "����������ԤԼ�����ڣ�" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	while (true)
	{
		cin >> date;
		if (date > 0 && date < 6)
		{
			break;
		}
		cout << "�����������������룺" << endl;
	}
	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	while (true)
	{
		cin >> interval;
		if (interval>0&&interval<3)
		{
			break;
		}
		cout << "�����������������룺" << endl;
	}
	
	//������ʾ����
	for (vector<ComputerRoom>::iterator it = this->m_Com.begin(); it != this->m_Com.end(); it++)
	{
		cout << it->m_Id << "�Ż���\t���������" << it->m_MaxNum << endl;
	}
	cout << "������ҪԤԼ�Ļ�����" << endl;

	while (true)
	{
		cin >> id;
		if (id>0&&id<4)			//Ŀǰֻ��1~3�Ż���
		{
			break;
		}
		cout << "�����������������룺" << endl;
	}

	cout << "ԤԼ�ɹ�������С���" << endl;
	system("pause");

	//����׷�ӵ��ļ���
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "room:" << id << " ";
	ofs << "status:" << 1 << " " << endl;

	ofs.close();
	system("cls");
}

//�鿴�ҵ�ԤԼ
void Student::showMyOrder()
{
	//���ȴ���һ��ԤԼ�ļ�����
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
		//����
		if (atoi(of.m_OrderData[i]["stuId"].c_str()) == this->m_Id)	//�ҵ�stuId����ת����const char*��ת����int
		{
			cout << "���ڣ�����" << of.m_OrderData[i]["date"] << "\t";
			cout << "ʱ�Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����") << "\t";
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
		
	}
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder()
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

//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_OrderSize == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	cout << "ע�⣺����л�ԤԼ�ɹ��ļ�¼����ȡ��" << endl;

	vector<int> v;		//�����ͼ������ԤԼ������ӳ��
	int index = 0;		//�����ͼ����

	for (int i = 0; i < of.m_OrderSize; i++)
	{
		//�����Լ��ļ�¼
		if (atoi(of.m_OrderData[i]["stuId"].c_str()) == this->m_Id)
		{
			//���� ����С���ԤԼ �ļ�¼
			if (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2")
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
				else if (of.m_OrderData[i]["status"] == "2")
				{
					status += "��ԤԼ";
				}
				cout << status << endl;
			}
		}
	}
	cout << "����Ҫȡ���ļ�¼��0 ���أ�" << endl;
	int select = 0;
	
	while (true)
	{
		cin >> select;
		if (select > 0 && select <= index)		//����Ϸ�
		{
			of.m_OrderData[v[select - 1]]["status"] = "0";
			
			//���µ��ļ���
			of.updateOrder();

			cout << "ԤԼȡ���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		else if (select == 0)
		{
			system("cls");
			break;
		}
		cout << "�����������������룺" << endl;
	}
}