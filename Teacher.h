#pragma once
#include "Identity.h"
#include "OrderFile.h"
#include <vector>

class Teacher :public Identity
{
public:

			/*接口*/

	//默认构造
	Teacher();

	//有参构造
	Teacher(int empId, string name, string pwd);

	//菜单界面
	virtual void opMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void checkOrder();




		/*个性属性*/

	int m_EmpId;
};