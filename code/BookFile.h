#pragma once
#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include"allFileManage.h"

using namespace std;

//存储预约记录文档文件类，用来方便构造输出预约记录文本中的数据
class BookFile {
private:										///类成员：
	map<int, map<string, string>> bookdata;     ///1.map容器bookdata，用来得到存储预约记录的文档中的数据
	int size;									///2.int变量 size，用来表示得到的预约记录数据的大小

public:
	BookFile();									///所有函数作用的注释均在对应的源文件中
	virtual ~BookFile();

	void UpdateBook();
	void KeyValue(string WaitToBreak, map<string, string>& m);

	int &GetSize();
	map<int, map<string, string>>& GetBookdata();
};