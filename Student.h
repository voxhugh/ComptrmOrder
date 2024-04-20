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

				/*�ӿ�*/

	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void opMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();



			/*��������*/

	int m_Id;		//ѧ��
	vector<ComputerRoom> m_Com;		//��������

};