#pragma once
#include <iostream>
using namespace std;
#include <map>
#include <string>
#include <fstream>
#include "globalFile.h"

class OrderFile
{

public:

			/*�ӿ�*/

	//Ĭ�Ϲ���
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//ȡ��ֵ��
	void getKeyValue(string field,map<string,string> &m);


			/*����*/

	int m_OrderSize;		//��¼����
	map<int, map<string, string>> m_OrderData;		//����ԤԼ��Ϣ
};