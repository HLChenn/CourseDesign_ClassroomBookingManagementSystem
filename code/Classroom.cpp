#include "Classroom.h"

//�������޲ι��캯��
Classroom::Classroom() {};

//�������вι��캯������ʼ�����ұ�ţ�����
Classroom::Classroom(string id, int v) :id(id), volume(v) {}

//����������������
Classroom::~Classroom() {};

//��Ա���������ؽ��ұ�ŵ�����
string &Classroom::GetId()
{
    return id;
}

//��Ա���������ؽ�������������
int &Classroom::GetVolume()
{
    return volume;
}
