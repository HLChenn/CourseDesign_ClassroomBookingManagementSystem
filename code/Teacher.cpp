#include "Teacher.h"

//��ʦ���޲ι��캯��
Teacher::Teacher() {};

//��ʦ���вι��캯������ʼ����ʦ�ı�ţ����֣����룬רҵ
Teacher::Teacher(string id, string name, string password, string major) :User(name, password, major), TeacherId(id) { CreditScore = 10; }

//��ʦ������������
Teacher::~Teacher() {};

//��Ա���������ر�ŵ�����
string& Teacher::GetTeacherId()
{
	return TeacherId;
}

//��Ա������������ʦ�Ĳ���������
double& Teacher::GetCreditScore()
{
	return CreditScore;
}

//��Ա��������ʦ�Ӳ˵��ĺ����ӿڣ���������ʵ��
void Teacher::OpenMenu() {};

//��Ա�������鿴ԤԼ�ĺ����ӿڣ���������ʵ��
void Teacher::CheckAllBook() {};

//��Ա���������ԤԼ�ĺ����ӿڣ���������ʵ��
void Teacher::AuditBook() {};

//��Ա�������ж��Ƿ��д���˵ļ�¼�ĺ����ӿڣ���������ʵ��
bool Teacher::HasBookAudit() { return 0; };

