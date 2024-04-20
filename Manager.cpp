#pragma once
#include "Manager.h"


//����ѧ������
void outputStu(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << "\t������" << s.m_Name << "\t���룺" << s.m_Pwd << endl;
}

//������ʦ�º���
class OutputTeacher
{
public:
	void operator()(Teacher& t)
	{
		cout << "ְ���ţ�" << t.m_EmpId << "\t������" << t.m_Name << "\t���룺" << t.m_Pwd << endl;
	}
};



//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι���
Manager::Manager(string name, string pwd)
{
	//���Գ�ʼ��
	this->m_Name = name;
	this->m_Pwd = pwd;

	//������ʼ��
	this->initVector();

	//����������ʼ��
	fstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	
	while (ifs >> com.m_Id && ifs >> com.m_MaxNum)
	{
		this->m_Com.push_back(com);
	}
}

//�˵�����
void Manager::opMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------------\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		1.����˺�		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		2.�鿴�˺�		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		3.�鿴����		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		4.���ԤԼ		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		0.ע����¼		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t ---------------------------------------\n";
	cout << "��ѡ�����Ĳ�����" << endl;


}

//����˺�
void Manager::addPerson()
{
	cout << "������Ҫ����˺ŵ����ͣ�" << endl;
	cout << "1��ѧ���˺�" << endl;
	cout << "2����ʦ�˺�" << endl;
	
	string fileName;	//�ļ���
	string tip;		//��ʾ��
	string errorTip;	//������ʾ��
	
	fstream ofs;
	int select;

	while (true)
	{
		cin >> select;
		if (select == 1)
		{
			fileName = STUDENT_FILE;
			tip = "������ѧ�ţ�";
			errorTip = "ѧ���ظ������������룡";
			break;

		}
		else if (select == 2)
		{
			fileName = TEACHER_FILE;
			tip = "������ְ���ţ�";
			errorTip = "ְ�����ظ������������룡";
			break;

		}
		else
		{
			cout << "���������룺" << endl;
		}
	}
		
	//���ļ�
	ofs.open(fileName, ios::out | ios::app);

	//Ҫ��ӵĺ���
	int id;
	string name;
	string pwd;

	cout << tip << endl;
	while (true)
	{
		cin >> id;
		if (!this->isRepeat(id, select))
		{
			break;
		}
		cout << errorTip << endl;
	}

	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;

	cout << "��ӳɹ���" << endl;

	//��������
	this->initVector();

	system("pause");
	system("cls");

	ofs.close();
}

//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��Ҫ�鿴�����ݣ�" << endl;
	cout << "1������ѧ����Ϣ" << endl;
	cout << "2��������ʦ��Ϣ" << endl;

	int select = 0;
	while (true)
	{
		cin >> select;
		if (select == 1)
		{
			cout << "����ѧ����Ϣ����;" << endl;
			for_each(this->m_Stu.begin(), this->m_Stu.end(), outputStu);
			
			system("pause");
			system("cls");
			return;
		}
		else if (select == 2)
		{
			cout << "������ʦ��Ϣ���£�" << endl;
			for_each(this->m_Tea.begin(),this->m_Tea.end(),OutputTeacher());

			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "�����������������룺" << endl;
		}
	}

}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = this->m_Com.begin(); it != this->m_Com.end(); it++)
	{
		cout << it->m_Id << "�Ż���\t������"<<it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanOrder()
{
	fstream ofs;
	ofs.open(ORDER_FILE, ios::out|ios::trunc);
	ofs.close();
	cout << "��ճɹ���" << endl;

	system("pause");
	system("cls");

}


//��ʼ������
void Manager::initVector()
{
	//���������������
	this->m_Stu.clear();
	this->m_Tea.clear();

	fstream ifs;

	//����ѧ��
	ifs.open(STUDENT_FILE, ios::in);
	
	if (!ifs.is_open())
	{
		ifs.close();
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		this->m_Stu.push_back(s);
	}
	ifs.close();

	//������ʦ
	ifs.open(TEACHER_FILE, ios::in);


	if (!ifs.is_open())
	{
		ifs.close();
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		this->m_Tea.push_back(t);
	}
	ifs.close();



}

//id�Ƿ��ظ�
bool Manager::isRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = this->m_Stu.begin(); it != this->m_Stu.end(); it++)
		{
			if (it->m_Id == id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = this->m_Tea.begin(); it != this->m_Tea.end(); it++)
		{
			if (it->m_EmpId == id)
			{
				return true;
			}
		}
	}
	return false;
}

