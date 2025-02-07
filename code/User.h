#pragma once
//因为身份类作为很多其他的类的基类，故此系统许多基本的头文件放此处
#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<string>
#include<regex>
#include <functional>
#include<ctime>
#include"BookFile.h"

using namespace std;

//用户抽象类，作为学生、老师、管理员类的基类
class User {
private:   				 ///类成员：
	string name;		 ///1.string变量 name，表示用户名字
	string password;     ///2.string变量 password，表示用户密码
	string major;		 ///3.string变量 major，表示用户专业

public:					 ///所有函数作用的注释均在对应的源文件中
	User();
	User(string name, string password, string major);
	virtual ~User();

	virtual void OpenMenu() = 0;     ///操作菜单 纯虚函数

	virtual string& GetName();
	virtual string& GetPassword();
	virtual string& GetMajor();

	virtual bool HasBookFileToCheck(BookFile &file,string choice);
};


