#pragma once
#include<iostream>
using namespace std;

//教室类，存储构建教室信息数据
class Classroom {
private:			 ///类成员：
	string id;		 ///1.string变量 id，表示教室对象的编号
	int volume;      ///2.int变量 volume，表示教室容量

public:              ///所有函数作用的注释均在对应的源文件中
	Classroom();
	Classroom(string id, int v);
	virtual ~Classroom();

	string &GetId();
	int &GetVolume();
};
