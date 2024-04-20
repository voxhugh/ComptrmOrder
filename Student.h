#pragma once
#include "Identity.h"
#include <vector>
#include "ComputerRoom.h"
#include "globalFile.h"
#include <fstream>
#include "OrderFile.h"

class Student:public Identity
{

public:

				/*接口*/

	//默认构造
	Student();
	//有参构造
	Student(int id, string name, string pwd);

	//菜单界面
	virtual void opMenu();

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();



			/*个性属性*/

	int m_Id;		//学号
	vector<ComputerRoom> m_Com;		//机房容器

};