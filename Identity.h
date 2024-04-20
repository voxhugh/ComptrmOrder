#pragma once
#include <iostream>
using namespace std;

class Identity
{
public:

	virtual void opMenu() = 0;		//子菜单


	string m_Name;		//用户名
	string m_Pwd;		//密码
};