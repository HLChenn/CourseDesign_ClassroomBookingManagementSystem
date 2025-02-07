#pragma once
#include "User.h"
#include"Classroom.h"


//ѧ���࣬�����̳��û���
class Student :public User {
private:							  ///���Ա��
	string StudentId;				  ///1.string���� StudentId����ʾѧ����ѧ��
	string level;					  ///2.string���� level����ʾѧ�����������
	vector<Classroom> vClassroom;     ///3.vector���� vClassroom����ʾѧ���Խ������ݵ�����

public:								  ///���к������õ�ע�;��ڶ�Ӧ��Դ�ļ��У���������������ͬ��
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



//��ͨѧ���࣬�����̳�ѧ����
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


//ѧ�������࣬�����̳�ѧ����
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