#pragma once
#include<iostream>
using namespace std;

//�����࣬�洢����������Ϣ����
class Classroom {
private:			 ///���Ա��
	string id;		 ///1.string���� id����ʾ���Ҷ���ı��
	int volume;      ///2.int���� volume����ʾ��������

public:              ///���к������õ�ע�;��ڶ�Ӧ��Դ�ļ���
	Classroom();
	Classroom(string id, int v);
	virtual ~Classroom();

	string &GetId();
	int &GetVolume();
};
