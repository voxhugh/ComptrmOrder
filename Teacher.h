#pragma once
#include "Identity.h"
#include "OrderFile.h"
#include <vector>

class Teacher :public Identity
{
public:

			/*�ӿ�*/

	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void opMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void checkOrder();




		/*��������*/

	int m_EmpId;
};