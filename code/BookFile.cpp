#include "BookFile.h"

//ԤԼ�ļ���¼���޲ι��캯��������ԤԼ��¼�ļ�����ʼ��Bookdata��Ա
BookFile::BookFile():size(0)
{
	bookdata.clear();     ///���ԭ�����ݣ���ֹ�����λ
	ifstream ifs(BOOK_FILE, ios::in);     ///�򿪴洢ԤԼ��¼���ĵ�
	if (!ifs.is_open()) {     ///�Դ����Ϸ��Լ��
		cout << "�ļ���ʧ�ܣ�" << endl;
	}

	string date;     ///ʮ�Ÿ��ַ������󣬷ֱ�������ȡ�ĵ�ĳһ�ݵ��������ݣ�����ԤԼ���ڡ�ʱ��Ρ����ҡ�ѧ����ݡ�ѧ��ѧ�š�רҵ��ԭ�򡢳�����ʦ������1��������ʦ������2��ԤԼ״̬������ʱ�䡢����ʱ�䡢����ʱ�䡢����ʱ���Ӧ������ֵ
	string interval;
	string roomid;
	string level;
	string name;
	string studentid;
	string major;
	string reason;
	string firstAduitTeacher;
	string score1;
	string secondAduitTeacher;
	string score2;
	string status;
	string applytime;
	string audittime1;
	string audittime2;
	string eigenvalue1;
	string eigenvalue2;
	string eigenvalue3;

	size = 0;     	///��size��ʼ��Ϊ0
	while (ifs>>date && ifs >> interval && ifs >> roomid && ifs >> level && ifs >> name && ifs >> studentid &&ifs>>major&&ifs>>reason&&ifs>>firstAduitTeacher&&ifs>>score1&&ifs>>secondAduitTeacher&&ifs>>score2&& ifs >> status&&ifs>>applytime&&ifs>> audittime1 &&ifs>> audittime2 &&ifs>> eigenvalue1&&ifs>> eigenvalue2&&ifs>> eigenvalue3) {     ///����ȡ���ݾ���Ϊ��ʱִ��ѭ��
		
		map<string, string> m;     ///����map����m��ԭ��
		                           ///1.���Ա��bookdata����Ƕ�׵�map<int,map<string,string>>����������ʼ����ʱ��Ҫint��map��������
								   ///2.������Ҫ�ȹ���map<string,string>����m���洢ȫ��������ļ�ֵ�Ժ��ٺ�size��int�ͣ�����µļ�ֵ�ԷŽ�bookdata��
		KeyValue(date, m);         
		KeyValue(interval, m);	   ///������ֵ�Բ���
		KeyValue(roomid, m);
		KeyValue(level, m);
		KeyValue(name, m);
		KeyValue(studentid, m);
		KeyValue(major, m);
		KeyValue(reason, m);
		KeyValue(firstAduitTeacher, m);
		KeyValue(score1, m);
		KeyValue(secondAduitTeacher, m);
		KeyValue(score2, m);
		KeyValue(status, m);
		KeyValue(applytime, m);
		KeyValue(audittime1, m);
		KeyValue(audittime2, m);
		KeyValue(eigenvalue1, m);
		KeyValue(eigenvalue2, m);
		KeyValue(eigenvalue3, m);

		bookdata.insert(make_pair(size, m));     ///��size��int����m��map<int,map<string,string>>)��ɼ�ֵ�Բ��뵽bookdataβ��
		
		size++;     ///���Ա��size����¼��Сͬ������+1
	}
	ifs.close();     ///�ر�ifs���ļ���ͨ��
}

//ԤԼ�ļ���¼������������
BookFile::~BookFile() {};

//��Ա����������������ֵ�ԣ���key��value��ֵ����map����m��
void BookFile::KeyValue(string WaitToBreak, map<string, string>& m) {

	///����������
	/// 1.�ַ�������WaitToBreak��ͨ�������ַ����ڡ�����ǰ�󲿷ֵ�ֵ�����뵽m��
	/// 2.map<string,string>�ͱ���m�����ã����ÿ����޸���ʵ����ֵ�������������ļ�ֵ��

	string key;     ///��ֵ����Ҫ�������ݣ��ֱ����key��value
	string value;

	size_t index = WaitToBreak.find(":");     ///����ȡ���ַ���a�еġ�:����Ϊ�����ڵ㣬�ֳ�key��valueֵ
	if (index > 0) {     ///������ҵ������������������±겻����λ�������ִ�ж��ַ���a�ļ�ֵ�Խ���
		key = WaitToBreak.substr(0, index);     ///keyֵΪ������ǰ��Ĳ��֣�����substr��int a��int b�����������ַ�����[a]�±꿪ʼ����Ϊb���Ӵ���������ͬ��
		value = WaitToBreak.substr(index + 1, WaitToBreak.size() - index - 1);     ///valueֵΪ����������Ĳ���

		m.insert(make_pair(key, value));     ///map���÷�����key��value��ɼ�ֵ�Բ��뵽m��
	}
}

//��Ա����������������������
void BookFile::UpdateBook()
{
	ofstream ofs;     ///�����ļ�������ofs������д�ļ�
	if (size == 0) {     ///���û�м�¼���������
		return;
	}
	ofs.open(BOOK_FILE, ios::out | ios::trunc);     ///д���ļ�ʱ������գ�trunc��ԭ���ļ����ݣ�������д���µ����ݣ��������ܴ󣡣�
	for (int i = 0; i < bookdata.size(); i++) {
		ofs <<"ԤԼ����:" << bookdata[i]["ԤԼ����"] << " ";
		ofs << "ԤԼʱ���:" << bookdata[i]["ԤԼʱ���"] << " ";
		ofs << "ԤԼ����:" << bookdata[i]["ԤԼ����"] << " ";
		ofs << "ԤԼ�����:" << bookdata[i]["ԤԼ�����"] << " ";
		ofs << "ԤԼ��:" << bookdata[i]["ԤԼ��"] << " ";
		ofs << "ԤԼ��ѧ��:" << bookdata[i]["ԤԼ��ѧ��"] << " ";
		ofs << "ԤԼ��רҵ:" << bookdata[i]["ԤԼ��רҵ"] << " ";
		ofs << "ԤԼ��;������:" << bookdata[i]["ԤԼ��;������"] << " ";
		ofs << "������ʦ:" << bookdata[i]["������ʦ"] << " ";
		ofs << "����1:" << bookdata[i]["����1"] << " ";
		ofs << "������ʦ:" << bookdata[i]["������ʦ"] << " ";
		ofs << "����2:" << bookdata[i]["����2"] << " ";
		ofs << "ԤԼ״̬:" << bookdata[i]["ԤԼ״̬"] << " ";
		ofs << "����ʱ��:" << bookdata[i]["����ʱ��"] << " ";
		ofs << "����ʱ��:" << bookdata[i]["����ʱ��"] << " ";
		ofs << "����ʱ��:" << bookdata[i]["����ʱ��"] << " ";
		ofs << "����ֵ1:" << bookdata[i]["����ֵ1"] << " ";
		ofs << "����ֵ2:" << bookdata[i]["����ֵ2"] << " ";
		ofs << "����ֵ3:" << bookdata[i]["����ֵ3"] << endl;
	}
	ofs.close();
}

//��Ա�����������ļ���¼��С������
int& BookFile::GetSize()
{
	return size;
}

//��Ա����������map����bookdata������
map<int, map<string, string>>& BookFile::GetBookdata()
{
	return bookdata;
}
