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

			/*接口*/

	//默认构造
	OrderFile();

	//更新预约记录
	void updateOrder();

	//取键值对
	void getKeyValue(string field,map<string,string> &m);


			/*属性*/

	int m_OrderSize;		//记录条数
	map<int, map<string, string>> m_OrderData;		//所有预约信息
};