#pragma once
#include "Identity.h"
#include <fstream>
#include "globalFile.h"
#include <string>
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include <iostream>
#include <algorithm>
#include "ComputerRoom.h"

class Manager :public Identity
{
public:

			/*接口*/
	
	//默认构造
	Manager();

	//有参构造
	Manager(string name, string pwd);

	//菜单界面
	virtual void opMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void cleanOrder();


	//初始化容器
	void initVector();

	//id是否重复
	bool isRepeat(int id,int type);

			/*属性*/

	//学生容器
	vector<Student> m_Stu;

	//老师容器
	vector<Teacher> m_Tea;

	//机房容器
	vector<ComputerRoom> m_Com;

};