#pragma once
#include "Student.h"

//默认构造
Student::Student()
{

}
//有参构造
Student::Student(int id, string name, string pwd)
{
	//属性初始化
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//机房容器初始化
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	
	while (ifs >> com.m_Id && ifs >> com.m_MaxNum)
	{
		this->m_Com.push_back(com);
	}


}

//菜单界面
void Student::opMenu()
{
	cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------------\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		1.申请预约		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		2.查看我的预约		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		3.查看所有预约		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		4.取消预约		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		0.注销登录		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t|		          		|\n";
	cout << "\t\t ---------------------------------------\n";
	cout << "请选择您的操作：" << endl;
}

//申请预约
void Student::applyOrder()
{
	int date = 0;	//日期
	int interval = 0;	//时间段
	int id = 0;	//机房号
	cout << "机房开放时间：周一~周五" << endl;
	cout << "请输入申请预约的日期：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	while (true)
	{
		cin >> date;
		if (date > 0 && date < 6)
		{
			break;
		}
		cout << "输入有误，请重新输入：" << endl;
	}
	cout << "请输入申请预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval>0&&interval<3)
		{
			break;
		}
		cout << "输入有误，请重新输入：" << endl;
	}
	
	//遍历显示机房
	for (vector<ComputerRoom>::iterator it = this->m_Com.begin(); it != this->m_Com.end(); it++)
	{
		cout << it->m_Id << "号机房\t最大容量：" << it->m_MaxNum << endl;
	}
	cout << "请输入要预约的机房：" << endl;

	while (true)
	{
		cin >> id;
		if (id>0&&id<4)			//目前只有1~3号机房
		{
			break;
		}
		cout << "输入有误，请重新输入：" << endl;
	}

	cout << "预约成功！审核中……" << endl;
	system("pause");

	//下面追加到文件中
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

//查看我的预约
void Student::showMyOrder()
{
	//首先创建一个预约文件对象
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
		//查找
		if (atoi(of.m_OrderData[i]["stuId"].c_str()) == this->m_Id)	//找到stuId后先转换成const char*再转换成int
		{
			cout << "日期：星期" << of.m_OrderData[i]["date"] << "\t";
			cout << "时段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午") << "\t";
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
		
	}
	system("pause");
	system("cls");
}

//查看所有预约
void Student::showAllOrder()
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

//取消预约
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_OrderSize == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	cout << "注意：审核中或预约成功的记录可以取消" << endl;

	vector<int> v;		//存放视图索引到预约索引的映射
	int index = 0;		//存放视图索引

	for (int i = 0; i < of.m_OrderSize; i++)
	{
		//查找自己的记录
		if (atoi(of.m_OrderData[i]["stuId"].c_str()) == this->m_Id)
		{
			//查找 审核中、已预约 的记录
			if (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2")
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
				else if (of.m_OrderData[i]["status"] == "2")
				{
					status += "已预约";
				}
				cout << status << endl;
			}
		}
	}
	cout << "输入要取消的记录，0 返回：" << endl;
	int select = 0;
	
	while (true)
	{
		cin >> select;
		if (select > 0 && select <= index)		//输入合法
		{
			of.m_OrderData[v[select - 1]]["status"] = "0";
			
			//更新到文件中
			of.updateOrder();

			cout << "预约取消成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else if (select == 0)
		{
			system("cls");
			break;
		}
		cout << "输入有误，请重新输入：" << endl;
	}
}