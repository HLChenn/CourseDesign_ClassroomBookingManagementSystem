#pragma once
//��Ϊ�������Ϊ�ܶ���������Ļ��࣬�ʴ�ϵͳ��������ͷ�ļ��Ŵ˴�
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

//�û������࣬��Ϊѧ������ʦ������Ա��Ļ���
class User {
private:   				 ///���Ա��
	string name;		 ///1.string���� name����ʾ�û�����
	string password;     ///2.string���� password����ʾ�û�����
	string major;		 ///3.string���� major����ʾ�û�רҵ

public:					 ///���к������õ�ע�;��ڶ�Ӧ��Դ�ļ���
	User();
	User(string name, string password, string major);
	virtual ~User();

	virtual void OpenMenu() = 0;     ///�����˵� ���麯��

	virtual string& GetName();
	virtual string& GetPassword();
	virtual string& GetMajor();

	virtual bool HasBookFileToCheck(BookFile &file,string choice);
};


