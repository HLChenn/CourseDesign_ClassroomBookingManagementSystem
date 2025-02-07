#pragma once
#include "User.h"

//��ʦ�࣬�����̳��û���
class Teacher :public User {
private:
	string TeacherId;
	double CreditScore;

public:
	Teacher();
	Teacher(string id, string name, string password,string major);
	virtual ~Teacher();

	virtual void OpenMenu() = 0;
	virtual void CheckAllBook() = 0;
	virtual void AuditBook() = 0;
	virtual bool HasBookAudit() = 0;
	virtual bool CalculateScore() = 0;

	virtual string& GetTeacherId();
	virtual double& GetCreditScore();
};

//����Ա�࣬�����̳���ʦ��
class Counsellor :public Teacher {
public:
	Counsellor();
	Counsellor(string id, string name, string password, string major);
	virtual ~Counsellor();

	void OpenMenu();
	void CheckAllBook();
	void AuditBook();

	bool HasBookCheck();
	bool HasBookAudit();
	bool CalculateScore();
};

//������ʦ�࣬�����̳���ʦ��
class Technician : public Teacher {
public:
	Technician();
	Technician(string id, string name, string password, string major);
	virtual ~Technician();

	void OpenMenu();
	void CheckAllBook();
	void AuditBook();

	bool HasBookAudit();
	bool CalculateScore();
};