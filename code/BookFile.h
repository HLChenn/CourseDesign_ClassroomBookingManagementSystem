#pragma once
#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include"allFileManage.h"

using namespace std;

//�洢ԤԼ��¼�ĵ��ļ��࣬�������㹹�����ԤԼ��¼�ı��е�����
class BookFile {
private:										///���Ա��
	map<int, map<string, string>> bookdata;     ///1.map����bookdata�������õ��洢ԤԼ��¼���ĵ��е�����
	int size;									///2.int���� size��������ʾ�õ���ԤԼ��¼���ݵĴ�С

public:
	BookFile();									///���к������õ�ע�;��ڶ�Ӧ��Դ�ļ���
	virtual ~BookFile();

	void UpdateBook();
	void KeyValue(string WaitToBreak, map<string, string>& m);

	int &GetSize();
	map<int, map<string, string>>& GetBookdata();
};