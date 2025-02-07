#pragma once
#include "User.h"
#include"Student.h"
#include"Teacher.h"
#include"Classroom.h"

//管理员类，公开继承身份类
class Manager :public User {
private:								  ///类成员：
	vector<normalStudent> vNStudent;      ///1.vector容器 vNstudent，读取存储了普通学生用户数据的文档，表示管理员对普通学生数据的掌握
	vector<Monitor> vMonitor;			  ///2.vector容器 vMonitor，读取存储了学生代表用户数据的文档，表示管理员对学生代表数据的掌握
	vector<Counsellor> vCounsellor;		  ///3.vector容器 vCounsellor，读取存储了辅导员用户数据的文档，表示管理员对辅导员数据的掌握
	vector<Technician> vTechnician;		  ///4.vector容器 vTechnician，读取存储了技术老师用户数据的文档，表示管理员对技术老师数据的掌握
	vector<Classroom> vClassroom;		  ///5.vector容器 vClassroom，读取存储了教室数据的文档，表示管理员对教室数据的掌握

public:									  ///所有函数作用的注释均在对应的源文件中
	Manager();
	Manager(string name, string password,string major);
	virtual ~Manager();

	void OpenMenu();
	void AddAccount();
	void DeleteAccount();
	void ChangeAccount();
	void CheckAllAccount();
	void FindAccount();
	void CheckClassroom();
	void ClearAllBook();

	void InitialVector();
	void SortVector();

	bool CheckAccountNotOnly(string id,string choice);
};
