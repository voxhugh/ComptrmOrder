#pragma once
#include "Manager.h"


//遍历学生函数
void outputStu(Student& s)
{
	cout << "学号：" << s.m_Id << "\t姓名：" << s.m_Name << "\t密码：" << s.m_Pwd << endl;
}

//遍历老师仿函数
class OutputTeacher
{
public:
	void operator()(Teacher& t)
	{
		cout << "职工号：" << t.m_EmpId << "\t姓名：" << t.m_Name << "\t密码：" << t.m_Pwd << endl;
	}
};



//默认构造
Manager::Manager()
{

}

//有参构造
Manager::Manager(string name, string pwd)
{
	//属性初始化
	this->m_Name = name;
	this->m_Pwd = pwd;

	//容器初始化
	this->initVector();

	//机房容器初始化
	fstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	
	while (ifs >> com.m_Id && ifs >> com.m_MaxNum)
	{
		this->m_Com.push_back(com);
	}
}

//菜单界面
void Manager::opMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------------\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		1.添加账号		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		2.查看账号		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		3.查看机房		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		4.清空预约		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		0.注销登录		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t ---------------------------------------\n";
	cout << "请选择您的操作：" << endl;


}

//添加账号
void Manager::addPerson()
{
	cout << "请输入要添加账号的类型：" << endl;
	cout << "1、学生账号" << endl;
	cout << "2、教师账号" << endl;
	
	string fileName;	//文件名
	string tip;		//提示语
	string errorTip;	//错误提示语
	
	fstream ofs;
	int select;

	while (true)
	{
		cin >> select;
		if (select == 1)
		{
			fileName = STUDENT_FILE;
			tip = "请输入学号：";
			errorTip = "学号重复，请重新输入！";
			break;

		}
		else if (select == 2)
		{
			fileName = TEACHER_FILE;
			tip = "请输入职工号：";
			errorTip = "职工号重复，请重新输入！";
			break;

		}
		else
		{
			cout << "请重新输入：" << endl;
		}
	}
		
	//打开文件
	ofs.open(fileName, ios::out | ios::app);

	//要添加的号密
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

	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;

	cout << "添加成功！" << endl;

	//更新容器
	this->initVector();

	system("pause");
	system("cls");

	ofs.close();
}

//查看账号
void Manager::showPerson()
{
	cout << "请选择要查看的内容：" << endl;
	cout << "1、所有学生信息" << endl;
	cout << "2、所有老师信息" << endl;

	int select = 0;
	while (true)
	{
		cin >> select;
		if (select == 1)
		{
			cout << "所有学生信息如下;" << endl;
			for_each(this->m_Stu.begin(), this->m_Stu.end(), outputStu);
			
			system("pause");
			system("cls");
			return;
		}
		else if (select == 2)
		{
			cout << "所有老师信息如下：" << endl;
			for_each(this->m_Tea.begin(),this->m_Tea.end(),OutputTeacher());

			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入有误，请重新输入：" << endl;
		}
	}

}

//查看机房信息
void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = this->m_Com.begin(); it != this->m_Com.end(); it++)
	{
		cout << it->m_Id << "号机房\t容量："<<it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanOrder()
{
	fstream ofs;
	ofs.open(ORDER_FILE, ios::out|ios::trunc);
	ofs.close();
	cout << "清空成功！" << endl;

	system("pause");
	system("cls");

}


//初始化容器
void Manager::initVector()
{
	//首先清空两个容器
	this->m_Stu.clear();
	this->m_Tea.clear();

	fstream ifs;

	//读入学生
	ifs.open(STUDENT_FILE, ios::in);
	
	if (!ifs.is_open())
	{
		ifs.close();
		cout << "文件打开失败！" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		this->m_Stu.push_back(s);
	}
	ifs.close();

	//读入老师
	ifs.open(TEACHER_FILE, ios::in);


	if (!ifs.is_open())
	{
		ifs.close();
		cout << "文件打开失败！" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		this->m_Tea.push_back(t);
	}
	ifs.close();



}

//id是否重复
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

