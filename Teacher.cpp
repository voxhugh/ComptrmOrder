#pragma once
#include "Teacher.h"


//默认构造
Teacher::Teacher()
{

}

//有参构造
Teacher::Teacher(int empId, string name, string pwd)
{
	//属性初始化
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;

}

//菜单界面
void Teacher::opMenu()
{
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------------\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		1.查看所有预约		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		2.审核预约		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		0.注销登录		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t ---------------------------------------\n";
	cout << "输入您的选择：";
}

//查看所有预约
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_OrderSize == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_OrderSize; i++)
	{
		cout << "日期：星期" << of.m_OrderData[i]["date"] << "\t";
		cout << "时段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午") << "\t";
		cout << "学号：" << of.m_OrderData[i]["stuId"] << "\t";
		cout << "姓名：" << of.m_OrderData[i]["stuName"] << "\t";
		cout << "机房：" << of.m_OrderData[i]["room"] << "号" << "\t";
		string status = "预约状态：";		// 1审核中	2预约成功	-1预约失败	0取消预约
		if (of.m_OrderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_OrderData[i]["status"] == "2")
		{
			status += "已预约";
		}
		else if (of.m_OrderData[i]["status"] == "-1")
		{
			status += "预约失败，请稍后再试！";
		}
		else
		{
			status += "已取消";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");
}

//审核预约
void Teacher::checkOrder()
{
	OrderFile of;
	if (of.m_OrderSize == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约记录：" << endl;
	vector<int> v;
	int index = 0;

	for (int i = 0; i < of.m_OrderSize; i++)
	{
		if (of.m_OrderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << "【" << ++index << "】";
			cout << "日期：星期" << of.m_OrderData[i]["date"] << "\t";
			cout << "时段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午") << "\t";
			cout << "机房：" << of.m_OrderData[i]["room"] << "号" << "\t";
			string status = "预约状态：";
			if (of.m_OrderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			cout << status << endl;
		}
	}
	cout << "请输入要审核的记录，0 返回：" << endl;
	int select = 0;
	int ret = 0;

	while (true)
	{
		cin >> select;
		if (select > 0 && select <= index)	//合法
		{
			cout << "请审核：" << endl;
			cout << "1、通过" << endl;
			cout << "2、不通过" << endl;
			while (true)
			{
				cin >> ret;
				if (ret == 1)
				{
					of.m_OrderData[v[select - 1]]["status"] = "2";

					//更新到文件
					of.updateOrder();

					cout << "审核完毕！" << endl;
					system("pause");
					system("cls");
					return;
				}
				else if (ret == 2)
				{
					of.m_OrderData[v[select - 1]]["status"] = "-1";

					//更新到文件
					of.updateOrder();

					cout << "审核完毕！" << endl;
					system("pause");
					system("cls");
					return;
				}
				cout << "输入有误，请重新输入：" << endl;
			}

		}
		else if (select == 0)
		{
			system("cls");
			break;
		}
		cout << "输入有误，请重新输入：" << endl;
	}
	
}