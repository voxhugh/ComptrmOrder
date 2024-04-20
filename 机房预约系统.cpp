#pragma once
#include <iostream>
using namespace std;
#include "globalFile.h"
#include "Identity.h"
#include "fstream"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h" 


//学生菜单
void studentMenu(Identity* student)
{
	//申请预约、看我的预约、看所有预约、取消预约、注销登录

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
			cout << "注销登录成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
		
	}

}

//教师菜单
void teacherMenu(Identity* teacher)
{
	while (true)
	{
		teacher->opMenu();		//查看所有预约、审核、注销
		int select = 0;		//默认注销登录
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
		default://注销登录
			delete person;
			cout << "注销登录成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//管理员菜单
void managerMenu(Identity* manager)
{
	while (true)
	{
		manager->opMenu();		//添加、查看、查看、清空、注销
		int select = 0;		//默认注销登录
		cin >> select;

		Manager* person = (Manager*)manager;

		switch (select)
		{
		case 1://添加账号
			person->addPerson();
			break;
		case 2://查看账号
			person->showPerson();
			break;
		case 3://查看机房
			person->showComputer();
			break;
		case 4://清空预约
			person->cleanOrder();
			break;
		default://注销登录
			delete person;
			cout << "注销登录成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}


}



//登录函数
void logIn(string fileName,int type)
{
	//展现多态
	Identity * person = NULL;
	
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//文件不存在情况
	if (!ifs.is_open())
	{
		ifs.close();
		cout << "文件不存在" << endl;
		system("pause");
		system("cls");
		return;
	}

	//编号，用户名，密码
	int id = 0;
	string name;
	string pwd;

	switch (type)
	{
	case 1:
		cout << "请输入学号：" << endl;
		cin >> id;
		break;
	case 2:
		cout << "请输入职工号：" << endl;
		cin >> id;
		break;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;


	if (type == 1)	//学生
	{
		int fileId;
		string fileName;
		string filePwd;

		while (ifs >> fileId && ifs >> fileName && ifs >> filePwd)
		{	
			//bug：vs2022编码是Unicode，txt文本文件编码需要把UTF-8改成ANSI，读中文就不会出现乱码了
			if (fileId == id && fileName == name && filePwd == pwd)
			{
				cout << "学生登陆验证成功！" << endl;
				system("pause");
				system("cls");
				
				person = new Student(id, name, pwd);
				studentMenu(person);

				return;
			}

		}
		

	}
	else if (type == 2)	//老师
	{
		int fileId;
		string fileName;
		string filePwd;

		while (ifs >> fileId && ifs >> fileName && ifs >> filePwd)
		{

			if (fileId == id && fileName == name && filePwd == pwd)
			{
				cout << "教师登陆验证成功！" << endl;
				system("pause");
				system("cls");
				
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}

		}
	}
	else if (type == 3)	//管理员
	{
		string fileName;
		string filePwd;

		while (ifs >> fileName && ifs >> filePwd)
		{

			if (fileName == name && filePwd == pwd)
			{
				cout << "管理员登陆验证成功！" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);
				managerMenu(person);

				return;
			}

		}
	}


	//输入有误
	cout << "输入有误！" << endl;
	system("pause");
	system("cls"); 


}





int main()
{

	while(true)
	{
		cout << "=========================== 欢迎来到卓越播客机房预约系统 ===========================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t ---------------------------------------\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t|		1.学生代表		|\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t|		2.老	师		|\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t|		3.管 理 员		|\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t|		0.退	出		|\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t|		          		|\n";
		cout << "\t\t ---------------------------------------\n";
		cout << "输入您的选择：";

		int select;
		cin >> select;			//接受用户输入
		cout << endl;

		switch (select)
		{
		case 1:						//学生
			logIn(STUDENT_FILE, 1);
			break;
		case 2:						//老师
			logIn(TEACHER_FILE, 2);
			break;
		case 3:						//管理员
			logIn(ADMIN_FILE, 3);
			break;
		case 0:						//退出
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}













	system("pause");
	return 0;
}