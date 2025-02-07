#include "Student.h"

//ѧ�����޲ι��캯��
Student::Student() {};

//ѧ�����вι��캯������ʼ��ѧ����ѧ�ţ����֣����룬�Լ�����������Ա
Student::Student(string id, string name, string password, string level, string major) :User(name, password, major), StudentId(id), level(level) { this->InitialVector(); }

//ѧ��������������
Student::~Student() {};

//��Ա����������������ֵ�Ĳ�ֵ��Ҳ��������ԤԼ�����ԤԼ��ʱ�䣩��ʽ��Ϊ��ʱ�������ʽ
string Student::CalculateAuditTime(long int time)
{
	int days, hours, minutes, seconds;

	days = time / (24 * 3600);     ///��������
	time = time % (24 * 3600);
	hours = time / 3600;     ///����Сʱ��
	time = time% 3600;
	minutes = time / 60;     ///���������
	seconds = time % 60;     ///��������

	string format = to_string(days) + "��" + to_string(hours) + "ʱ" + to_string(minutes) + "��" + to_string(seconds) + "��";
	return format;
}

//��Ա�������������ݳ�Ա��ѧ��ѧ�ŵ�����
string& Student::GetStudentId()
{
	return StudentId;
}

//��Ա�������������ݳ�Ա��ѧ����ݵ�����
string& Student::GetLevel()
{
	return level;
}

//��Ա�������������ݳ�Ա����������������
vector<Classroom>& Student::GetvClassroom()
{
	return vClassroom;
}

//��Ա�������жϽ����Ƿ��ѱ�ԤԼ
bool Student::OnlyOneRoom(string date, string interval, string room) {
	BookFile file;
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["ԤԼ����"] == date && file.GetBookdata()[i]["ԤԼʱ���"] == interval && file.GetBookdata()[i]["ԤԼ����"] == room && (file.GetBookdata()[i]["ԤԼ״̬"] == "1" || file.GetBookdata()[i]["ԤԼ״̬"] == "3")) {
			return 0;
		}
	}
	return 1;
}

//��Ա�������Ӳ˵���ʼ���ĺ����ӿڣ���������ʵ��
void Student::OpenMenu() {};

//��Ա����������ԤԼ�ĺ����ӿڣ���������ʵ��
void Student::ApplyBook() {};

//��Ա�������鿴�ҵ�����ԤԼ�ĺ����ӿڣ���������ʵ��
void Student::ShowMyBook() {};

//��Ա������ȡ��ԤԼ�ӿڣ���������ʵ��
void Student::CancelBook() {};

//��Ա��������ʼ���洢�������ݵ�������Ա�ĺ����ӿڣ���������ʵ��
void Student::InitialVector() {};

//��Ա�������ж�����ԤԼ��¼�ĺ����ӿڣ���������ʵ��
bool Student::HasBookFile(BookFile &file)
{
	return 0;
}

//��Ա�������ж��Ƿ�ﵽ��ԤԼ���������ӿڣ���������ʵ��
bool Student::HitMaxRoom()
{
	return false;
}

//��Ա�������ж�����û��ȡ����ԤԼ��¼�ĺ����ӿڣ���������ʵ��
bool Student::NotCancel(BookFile& file)
{
	return 0;
}

//��Ա�������ж����޸�����ϸ��ԤԼ��¼�Ľӿڣ���������ʵ��
bool Student::HasBookFileIndeed(BookFile file, string choice)
{
	return 0;
}




