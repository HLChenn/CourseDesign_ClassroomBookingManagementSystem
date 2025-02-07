#pragma once
#include "User.h"
#include"Student.h"
#include"Teacher.h"
#include"Classroom.h"

//����Ա�࣬�����̳������
class Manager :public User {
private:								  ///���Ա��
	vector<normalStudent> vNStudent;      ///1.vector���� vNstudent����ȡ�洢����ͨѧ���û����ݵ��ĵ�����ʾ����Ա����ͨѧ�����ݵ�����
	vector<Monitor> vMonitor;			  ///2.vector���� vMonitor����ȡ�洢��ѧ�������û����ݵ��ĵ�����ʾ����Ա��ѧ���������ݵ�����
	vector<Counsellor> vCounsellor;		  ///3.vector���� vCounsellor����ȡ�洢�˸���Ա�û����ݵ��ĵ�����ʾ����Ա�Ը���Ա���ݵ�����
	vector<Technician> vTechnician;		  ///4.vector���� vTechnician����ȡ�洢�˼�����ʦ�û����ݵ��ĵ�����ʾ����Ա�Լ�����ʦ���ݵ�����
	vector<Classroom> vClassroom;		  ///5.vector���� vClassroom����ȡ�洢�˽������ݵ��ĵ�����ʾ����Ա�Խ������ݵ�����

public:									  ///���к������õ�ע�;��ڶ�Ӧ��Դ�ļ���
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
