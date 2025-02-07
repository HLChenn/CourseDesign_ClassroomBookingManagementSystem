#include "User.h"

//�û����޲ι��캯��
User::User() {};

//�û����вι��캯������ʼ�����֣����룬רҵ
User::User(string name, string password, string major) :name(name), password(password), major(major) {}

//�û�������������
User::~User() {};

//��Ա�������������ֵ�����
string& User::GetName()
{
    return name;
}

//��Ա�������������������
string& User::GetPassword()
{
    return password;
}

//��Ա����������רҵ������
string& User::GetMajor()
{
    return major;
}

//��Ա�������ж��Ƿ��ж�Ӧ����ԤԼ��¼������ѧ��������ͼ�����ʦ�ࡰ�鿴������ԤԼ���ܡ���ʵ���ж�
bool User::HasBookFileToCheck(BookFile &file, string choice)
{
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["ԤԼ״̬"] == choice) {
			return 1;
		}
	}
	return 0;
}



