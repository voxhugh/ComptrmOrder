#pragma once
#include <iostream>
using namespace std;
#include "globalFile.h"
#include "Identity.h"
#include "fstream"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h" 


//ѧ���˵�
void studentMenu(Identity* student)
{
	//����ԤԼ�����ҵ�ԤԼ��������ԤԼ��ȡ��ԤԼ��ע����¼

	while (true)
	{
 		student->opMenu();

		Student* person = (Student*)student;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			person->applyOrder();
			break;
		case 2:
			person->showMyOrder();
			break;
		case 3:
			person->showAllOrder();
			break;
		case 4:
			person->cancelOrder();
			break;
		default:
			delete person;
			cout << "ע����¼�ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		
	}

}

//��ʦ�˵�
void teacherMenu(Identity* teacher)
{
	while (true)
	{
		teacher->opMenu();		//�鿴����ԤԼ����ˡ�ע��
		int select = 0;		//Ĭ��ע����¼
		cin >> select;

		Teacher* person = (Teacher*)teacher;

		switch (select)
		{
		case 1:
			person->showAllOrder();
			break;
		case 2:
			person->checkOrder();
			break;
		default://ע����¼
			delete person;
			cout << "ע����¼�ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//����Ա�˵�
void managerMenu(Identity* manager)
{
	while (true)
	{
		manager->opMenu();		//��ӡ��鿴���鿴����ա�ע��
		int select = 0;		//Ĭ��ע����¼
		cin >> select;

		Manager* person = (Manager*)manager;

		switch (select)
		{
		case 1://����˺�
			person->addPerson();
			break;
		case 2://�鿴�˺�
			person->showPerson();
			break;
		case 3://�鿴����
			person->showComputer();
			break;
		case 4://���ԤԼ
			person->cleanOrder();
			break;
		default://ע����¼
			delete person;
			cout << "ע����¼�ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}


}



//��¼����
void logIn(string fileName,int type)
{
	//չ�ֶ�̬
	Identity * person = NULL;
	
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ļ����������
	if (!ifs.is_open())
	{
		ifs.close();
		cout << "�ļ�������" << endl;
		system("pause");
		system("cls");
		return;
	}

	//��ţ��û���������
	int id = 0;
	string name;
	string pwd;

	switch (type)
	{
	case 1:
		cout << "������ѧ�ţ�" << endl;
		cin >> id;
		break;
	case 2:
		cout << "������ְ���ţ�" << endl;
		cin >> id;
		break;
	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;


	if (type == 1)	//ѧ��
	{
		int fileId;
		string fileName;
		string filePwd;

		while (ifs >> fileId && ifs >> fileName && ifs >> filePwd)
		{	
			//bug��vs2022������Unicode��txt�ı��ļ�������Ҫ��UTF-8�ĳ�ANSI�������ľͲ������������
			if (fileId == id && fileName == name && filePwd == pwd)
			{
				cout << "ѧ����½��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				
				person = new Student(id, name, pwd);
				studentMenu(person);

				return;
			}

		}
		

	}
	else if (type == 2)	//��ʦ
	{
		int fileId;
		string fileName;
		string filePwd;

		while (ifs >> fileId && ifs >> fileName && ifs >> filePwd)
		{

			if (fileId == id && fileName == name && filePwd == pwd)
			{
				cout << "��ʦ��½��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}

		}
	}
	else if (type == 3)	//����Ա
	{
		string fileName;
		string filePwd;

		while (ifs >> fileName && ifs >> filePwd)
		{

			if (fileName == name && filePwd == pwd)
			{
				cout << "����Ա��½��֤�ɹ���" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);
				managerMenu(person);

				return;
			}

		}
	}


	//��������
	cout << "��������" << endl;
	system("pause");
	system("cls"); 


}





int main()
{

	while(true)
	{
		cout << "=========================== ��ӭ����׿Խ���ͻ���ԤԼϵͳ ===========================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t ---------------------------------------\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t|		1.ѧ������		|\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t|		2.��	ʦ		|\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t|		3.�� �� Ա		|\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t|		0.��	��		|\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t ---------------------------------------\n";
		cout << "��������ѡ��";

		int select;
		cin >> select;			//�����û�����
		cout << endl;

		switch (select)
		{
		case 1:						//ѧ��
			logIn(STUDENT_FILE, 1);
			break;
		case 2:						//��ʦ
			logIn(TEACHER_FILE, 2);
			break;
		case 3:						//����Ա
			logIn(ADMIN_FILE, 3);
			break;
		case 0:						//�˳�
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}













	system("pause");
	return 0;
}