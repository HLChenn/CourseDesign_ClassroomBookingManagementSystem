#include "User.h"

//用户类无参构造函数
User::User() {};

//用户类有参构造函数：初始化名字，密码，专业
User::User(string name, string password, string major) :name(name), password(password), major(major) {}

//用户类虚析构函数
User::~User() {};

//成员函数：返回名字的引用
string& User::GetName()
{
    return name;
}

//成员函数：返回密码的引用
string& User::GetPassword()
{
    return password;
}

//成员函数：返回专业的引用
string& User::GetMajor()
{
    return major;
}

//成员函数：判断是否有对应类别的预约记录，用以学生代表类和技术老师类“查看所有人预约功能”的实现判断
bool User::HasBookFileToCheck(BookFile &file, string choice)
{
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["预约状态"] == choice) {
			return 1;
		}
	}
	return 0;
}



