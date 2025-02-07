#include"Teacher.h"

//����Ա���޲ι��캯��
Counsellor::Counsellor() {};

//����Ա���вι��캯������ʼ����ţ����֣����룬רҵ
Counsellor::Counsellor(string id, string name, string password, string major):Teacher(id, name, password, major) {}

//����Ա������������
Counsellor::~Counsellor() {};

//��Ա�������������Ա���Ӳ˵�ҳ��
void Counsellor::OpenMenu()
{
	cout << "   ��ӭ����Ա " + GetName() + " ��¼��" << endl;
	if (CalculateScore()) {     ///�ж���������������֣����ϸ񣬲��ܼ����鿴�����ѧ����ԤԼ
		cout << "-----------------------------------" << endl;
		cout << "|          1.�鿴��ͨѧ��ԤԼ     |" << endl;
		cout << "|          2.���ԤԼ             |" << endl;
		cout << "|          0.ע����¼             |" << endl;
		cout << "-----------------------------------" << endl;
	}
	else {
		system("pause");
		system("cls");
		return;
	}
}

//��Ա�������鿴����רҵ����ͨѧ��ԤԼ����
void Counsellor::CheckAllBook()
{
	BookFile file;     ///����ԤԼ��¼�ļ���Ķ��󣬽������û����ļ���Ϣ��ϵ������
	if (file.GetSize() == 0||!HasBookCheck()) {     ///����ļ���СΪ�գ�����û�п��Բ鿴�ı�רҵ����ͨѧ����ԤԼ��¼��������������
		cout << "-----------------------------------" << endl;
		cout << "|       û����ͨѧ��ԤԼ��¼��    |" << endl;
		cout << "-----------------------------------" << endl;
		system("pause");
		system("cls");
		return;
	}

	int index = 0;     ///���������±�
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["ԤԼ�����"] == "��ͨѧ��"&&file.GetBookdata()[i]["ԤԼ��רҵ"]==GetMajor()) {     ///�����жϣ��������ͨѧ�����Ǳ�רҵ��
			cout << "[" << ++index << "]" << endl;
			cout << "ԤԼ���ڣ�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
			cout << "ԤԼʱ��Σ�" << (file.GetBookdata()[i]["ԤԼʱ���"] == "1" ? "����" : "����") << endl;
			cout << "���ң�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
			cout << "ԤԼ����ݣ�" << file.GetBookdata()[i]["ԤԼ�����"] << endl;
			cout << "ԤԼ�ˣ�" << file.GetBookdata()[i]["ԤԼ��"] << endl;
			cout << "ԤԼ��ѧ�ţ�" << file.GetBookdata()[i]["ԤԼ��ѧ��"] << endl;
			cout << "ԤԼ��רҵ��" << file.GetBookdata()[i]["ԤԼ��רҵ"] << endl;
			cout << "��;�����ɣ�" << file.GetBookdata()[i]["ԤԼ��;������"] << endl;
			string status = "ԤԼ״̬��";
			if (file.GetBookdata()[i]["ԤԼ״̬"] == "1") {
				status += "��������У�";
			}
			if (file.GetBookdata()[i]["ԤԼ״̬"] == "2") {
				status += "��˳ɹ�,��ԤԼ!";
			}
			if (file.GetBookdata()[i]["ԤԼ״̬"] == "-1") {
				status += "���ʧ�ܣ�������ԤԼ��";
			}
			if (file.GetBookdata()[i]["ԤԼ״̬"] == "0") {
				status += "��ȡ��ԤԼ��";
			}
			if (file.GetBookdata()[i]["ԤԼ״̬"] == "3") {
				status += "��ͨ������Ա������ˣ��ȴ�������ʦ��ˣ�";
			}
			cout << status << endl;
			cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
			cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
			cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
			cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
			cout << "---------------------------------------" << endl;
		}
	}
	system("pause");
	system("cls");
}

//��Ա��������˽���רҵ����ͨѧ��ԤԼ����
void Counsellor::AuditBook()
{
	BookFile file;     ///����ԤԼ��¼�ļ���Ķ��󣬽������û����ļ���Ϣ��ϵ������
	if (file.GetSize() == 0 || !HasBookAudit()) {      ///���û����Ҫ��˵���ͨѧ����ԤԼ��¼��������������
		cout << "-----------------------------------" << endl;
		cout << "|    û����Ҫ����˵�ԤԼ��¼��   |" << endl;
		cout << "-----------------------------------" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����˵ļ�¼���£�" << endl;
	cout << "---------------------------------------" << endl;

	vector<int>v;     ///����ͨѧ���ࡰȡ��ԤԼ���ܡ������Ƶ�����������v����Ϊװ��bookdata�з�����������������
	int index = 1;
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["ԤԼ�����"] == "��ͨѧ��" && file.GetBookdata()[i]["ԤԼ״̬"] == "1" && file.GetBookdata()[i]["ԤԼ��רҵ"] == GetMajor()) {
			v.push_back(i);
			cout << "[" << index++ << "]" << endl;
			cout << "ԤԼ���ڣ�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
			cout << "ԤԼʱ��Σ�" << (file.GetBookdata()[i]["ԤԼʱ���"] == "1" ? "����" : "����") << endl;
			cout << "���ң�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
			cout << "ԤԼ����ݣ�" << file.GetBookdata()[i]["ԤԼ�����"] << endl;
			cout << "ԤԼ�ˣ�" << file.GetBookdata()[i]["ԤԼ��"] << endl;
			cout << "ԤԼ��ѧ�ţ�" << file.GetBookdata()[i]["ԤԼ��ѧ��"] << endl;
			cout << "ԤԼ��רҵ��" << file.GetBookdata()[i]["ԤԼ��רҵ"] << endl;
			cout << "��;�����ɣ�" << file.GetBookdata()[i]["ԤԼ��;������"] << endl;
			string status = "ԤԼ״̬��";
			if (file.GetBookdata()[i]["ԤԼ״̬"] == "1") {
				status += "��������У�";
			}
			cout << status << endl;
			cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
			cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
			cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
			cout << "---------------------------------------" << endl;
		}
	}

	cout << "������Ҫ��˵�ԤԼ��¼��0������" << endl;
	int choice = -1;
	string change;
	while (1) {

		cin >> change;
		try {     ///ͬ��������Ϸ��Լ��
			choice = stoi(change);
			if (choice == 0) {
				break;
			}
			if (choice > 0 && choice <= v.size()) {
				cout << "-----------------------------------" << endl;
				cout << "|         ��������˽����        |" << endl;
				cout << "|         1.�������ͨ��          |" << endl;
				cout << "|         2.������˲�ͨ��        |" << endl;
				cout << "-----------------------------------" << endl;
				int select = -1;
				string changeselect;
				while (1) {
					cout << "����������ѡ��";
					cin >> changeselect;
					try {
						select = stoi(changeselect);
						if (select < 1 || select>2) {
							cout << "-----------------------------------" << endl;
							cout << "|      �����������������룡     |" << endl;
							cout << "-----------------------------------" << endl;
						}
						else if (select == 1) {
							file.GetBookdata()[v[choice - 1]]["ԤԼ״̬"] = "3";
							break;
						}

						else if (select == 2) {
							file.GetBookdata()[v[choice - 1]]["ԤԼ״̬"] = "-1";
							break;
						}
					}
					catch (...) {
						cout << "-----------------------------------" << endl;
						cout << "|      �����������������룡     |" << endl;
						cout << "-----------------------------------" << endl;
					}
				}
				file.GetBookdata()[v[choice - 1]]["������ʦ"] = GetName();     ///������˽�������ԤԼ��¼�ĳ�����ʦ��Ӧ����
				
				time_t now = time(0);     ///��ȡϵͳ��ǰʱ�䣬����д������ԤԼʱ��ʱ��
				tm currenttime;
				localtime_s(&currenttime, &now);     ///��ϵͳʱ���ʼ��Ϊ����ʱ��
				string format = to_string(currenttime.tm_year + 1900) + "��" + to_string(currenttime.tm_mon + 1) + "��" + to_string(currenttime.tm_mday) + "��" + to_string(currenttime.tm_hour) + "ʱ" + to_string(currenttime.tm_min) + "��" + to_string(currenttime.tm_sec) + "��";
				string second = to_string(now);     ///���������������ֱ��ʽ�����õ���ʱ��ʹ�1970.1.1���������

				file.GetBookdata()[v[choice - 1]]["����ʱ��"] = format;
				file.GetBookdata()[v[choice - 1]]["����ֵ2"] = second;

				file.UpdateBook();     ///�����ɹ���ͨ��file���󽫴洢ԤԼ��¼���ĵ��ڲ����ݸ���
				cout << "-----------------------------------" << endl;
				cout << "|       �����ϣ���л������      |" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			else {
				cout << "-----------------------------------" << endl;
				cout << "|      �����������������룡     |" << endl;
				cout << "-----------------------------------" << endl;
			}
		}
		catch (...) {
			cout << "-----------------------------------" << endl;
			cout << "|      �����������������룡     |" << endl;
			cout << "-----------------------------------" << endl;
		}
	}
	system("pause");
	system("cls");
}

//��Ա�������ж��Ƿ���ڱ�רҵ����ͨѧ����ԤԼ��¼�������򷵻�true�����򷵻�false
bool Counsellor::HasBookCheck()
{
	BookFile file;
	int sum = 0;
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["ԤԼ�����"] == "��ͨѧ��"&&file.GetBookdata()[i]["ԤԼ��רҵ"]==GetMajor()) {     ///��ԤԼ��¼������ڼ�¼
			sum++;																									  ///�����ǡ���רҵ�ġ�����ͨѧ�����ļ�¼��sum+1
		}
	}
	if (sum > 0) {
		return 1;
	}
	return 0;
}

//��Ա�������ж��Ƿ������Ҫ��˵ı�רҵ����ͨѧ����ԤԼ��¼����ԤԼ״̬Ϊ��1�������з���true�����򷵻�false
bool Counsellor::HasBookAudit()
{
	BookFile file;
	int sum = 0;
	for (int i = 0; i < file.GetSize(); i++) {     ///���ĵ�����ԤԼ��¼�������Ǳ�רҵ����ͨѧ����Ҫ������˵�ԤԼ��¼��sum+1
		if (file.GetBookdata()[i]["ԤԼ�����"] == "��ͨѧ��"&&file.GetBookdata()[i]["ԤԼ״̬"]=="1"&& file.GetBookdata()[i]["ԤԼ��רҵ"] == GetMajor()) {
			sum++;
		}
	}
	if (sum > 0) {
		return 1;
	}
	return 0;
}

//��Ա�������жϸ���Ա�Ĳ��з��Ƿ�ϸ񣬼���������6�����Լ���������������Ϊ������û����޷���˻�鿴ѧ��ԤԼ
bool Counsellor::CalculateScore()
{
	BookFile file;
	double sum = 0;     ///�������ѱ����۵�ԤԼ��¼��
	double score = 0;     ///����ͳ�Ʒ����ܺ�
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["������ʦ"] == GetName() && file.GetBookdata()[i]["ԤԼ��רҵ"] == GetMajor() && file.GetBookdata()[i]["����1"] != "��δ����") {
			sum++;
			score += stod(file.GetBookdata()[i]["����1"]);
		}
	}
	if (sum == 0) {     ///û�����ۼ�¼��Ĭ��Ϊ10��
		cout << "���Ĳ���������Ϊ��" << GetCreditScore() <<"(����)"<< endl;
		return 1;
	}
	else {
		GetCreditScore() = score / sum;     ///����������Ĭ��Ϊ10�֣�����ʼ�����۷���ʱ������ƽ����
		cout <<fixed<<setprecision(2)<< "���Ĳ���������Ϊ��" << GetCreditScore();
		if (GetCreditScore() >= 6) {     ///��������6ʱ���϶�Ϊ�ϸ񣬿���ִ����һ������
			if (GetCreditScore() >= 9) {
				cout << "(����)" << endl;
			}
			else if (GetCreditScore() >= 7.5 && GetCreditScore() < 9) {
				cout << "(����)" << endl;
			}
			else if (GetCreditScore() >= 6 && GetCreditScore() < 7.5) {
				cout << "(�ϸ�)" << endl;
			}
			return 1;
		}
		else {     ///�����ϸ���ǿ���˳����޷�������һ������
			cout << "(���ϸ�)" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "| ���÷������ϸ�����ϵ����Ա������һ�������� |" << endl;
			cout << "------------------------------------------------" << endl;
			return 0;
		}
	}
}

