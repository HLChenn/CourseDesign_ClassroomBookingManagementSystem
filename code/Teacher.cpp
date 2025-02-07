#include "Teacher.h"

//老师类无参构造函数
Teacher::Teacher() {};

//老师类有参构造函数：初始化老师的编号，名字，密码，专业
Teacher::Teacher(string id, string name, string password, string major) :User(name, password, major), TeacherId(id) { CreditScore = 10; }

//老师类虚析构函数
Teacher::~Teacher() {};

//成员函数：返回编号的引用
string& Teacher::GetTeacherId()
{
	return TeacherId;
}

//成员函数：返回老师的操行评定分
double& Teacher::GetCreditScore()
{
	return CreditScore;
}

//成员函数：老师子菜单的函数接口，由派生类实现
void Teacher::OpenMenu() {};

//成员函数：查看预约的函数接口，由派生类实现
void Teacher::CheckAllBook() {};

//成员函数：审核预约的函数接口，由派生类实现
void Teacher::AuditBook() {};

//成员函数：判断是否有待审核的记录的函数接口，由派生类实现
bool Teacher::HasBookAudit() { return 0; };

