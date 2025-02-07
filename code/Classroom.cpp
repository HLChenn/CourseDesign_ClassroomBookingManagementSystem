#include "Classroom.h"

//教室类无参构造函数
Classroom::Classroom() {};

//教室类有参构造函数：初始化教室编号，容量
Classroom::Classroom(string id, int v) :id(id), volume(v) {}

//教室类虚析构函数
Classroom::~Classroom() {};

//成员函数：返回教室编号的引用
string &Classroom::GetId()
{
    return id;
}

//成员函数：返回教室容量的引用
int &Classroom::GetVolume()
{
    return volume;
}
