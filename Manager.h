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

			/*�ӿ�*/
	
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);

	//�˵�����
	virtual void opMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanOrder();


	//��ʼ������
	void initVector();

	//id�Ƿ��ظ�
	bool isRepeat(int id,int type);

			/*����*/

	//ѧ������
	vector<Student> m_Stu;

	//��ʦ����
	vector<Teacher> m_Tea;

	//��������
	vector<ComputerRoom> m_Com;

};