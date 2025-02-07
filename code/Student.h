#pragma once
#include "User.h"
#include"Classroom.h"


//学生类，公开继承用户类
class Student :public User {
private:							  ///类成员：
	string StudentId;				  ///1.string变量 StudentId，表示学生的学号
	string level;					  ///2.string变量 level，表示学生的身份类型
	vector<Classroom> vClassroom;     ///3.vector容器 vClassroom，表示学生对教室数据的掌握

public:								  ///所有函数作用的注释均在对应的源文件中（下面两个派生类同理）
	Student();
	Student(string id, string name, string password,string level,string major);
	virtual ~Student();

	virtual void OpenMenu() = 0;
	virtual void ApplyBook() = 0;
	virtual void ShowMyBook() = 0;
	virtual void CancelBook() = 0;
	virtual void EvaluateBook() = 0;
	virtual void InitialVector() = 0;

	virtual bool HasBookFile(BookFile& file) = 0;
	virtual bool NotCancel(BookFile& file) = 0;
	virtual bool HitMaxRoom() = 0;
	virtual bool HasBookFileIndeed(BookFile file, string choice) = 0;
	virtual bool OnlyOneRoom(string date, string interval, string room);

	virtual string CalculateAuditTime(long int time);
	virtual string& GetStudentId();
	virtual string& GetLevel();
	virtual vector<Classroom>& GetvClassroom();
};



//普通学生类，公开继承学生类
class normalStudent :public Student {
public:
	normalStudent();
	normalStudent(string id, string name, string password, string level, string major);
	virtual ~normalStudent();

	void OpenMenu();
	void ApplyBook();
	void ShowMyBook();
	void CancelBook();
	void EvaluateBook();
	void InitialVector();

	bool HasBookFile(BookFile &file);
	bool HasBookFileIndeed(BookFile file, string choice);
	bool HitMaxRoom();
	bool NotCancel(BookFile &file);
};


//学生代表类，公开继承学生类
class Monitor :public Student {
public:
	Monitor();
	Monitor(string id, string name, string password, string level, string major);
	virtual ~Monitor();

	void OpenMenu();
	void ApplyBook();
	void ShowMyBook();
	void ShowAllBook();
	void CancelBook();
	void EvaluateBook();
	void InitialVector();

	bool HasBookFile(BookFile &file);
	bool HasBookFileIndeed(BookFile file, string choice);
	bool NotCancel(BookFile& file);
	bool HitMaxRoom();
};