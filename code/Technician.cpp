#include"Teacher.h"

//������ʦ���޲ι��캯��
Technician::Technician() {};

//������ʦ���вι��캯������ʼ����ţ����֣����룬רҵ��Ĭ��Ϊ��������Ա����
Technician::Technician(string id, string name, string password,string major) :Teacher(id, name, password,major) {}

//������ʦ������������
Technician::~Technician() {};

//��Ա���������������ʦ���Ӳ˵�ҳ��
void Technician::OpenMenu()
{
	cout << "    ��ӭ������ʦ "+GetName()+" ��¼��" << endl;
	if (CalculateScore()) {     ///�ж���������������֣����ϸ񣬲��ܼ����鿴�����ѧ����ԤԼ
		cout << "-----------------------------------" << endl;
		cout << "|          1.�鿴����ѧ��ԤԼ     |" << endl;
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

//��Ա�������鿴����ѧ����ԤԼ����
void Technician::CheckAllBook()
{
	///�����ṹ�븨��Ա�ࡰ�鿴ԤԼ���ܡ�һ�£��������ڣ�
	///1.�ж�����ԤԼ��¼ֻ���жϴ���ԤԼ��¼���ļ��Ƿ�Ϊ��
	///2.û��������ƣ����Բ鿴����ѧ����ԤԼ��¼

	BookFile file;     ///����ԤԼ��¼�ļ���Ķ��󣬽������û����ĵ��ļ���Ϣ��ϵ������
	if (file.GetSize() == 0) {     ///ֻҪ�ļ���СΪ�գ�������������
		cout << "-----------------------------------" << endl;
		cout << "|           û��ԤԼ��¼��        |" << endl;
		cout << "-----------------------------------" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "-----------------------------------" << endl;     ///����м�¼������������
	cout << "|        ��ѡ��Ҫ�鿴��ԤԼ��     |" << endl;
	cout << "|         1.��ȡ����ԤԼ          |" << endl;
	cout << "|         2.ʧ�ܵ�ԤԼ            |" << endl;
	cout << "|         3.������˵�ԤԼ        |" << endl;
	cout << "|         4.�ѳɹ���ԤԼ          |" << endl;
	cout << "|         0.�����Ӳ˵�            |" << endl;
	cout << "-----------------------------------" << endl;

	string choice;
	int index = 1;
	while (1) {
		cout << "����������ѡ��";
		cin >> choice;
		if (choice == "1") {     ///��һ���жϣ��Ƿ�����ȡ����ԤԼ����ԤԼ״̬Ϊ��0�� 
			if (!HasBookFileToCheck(file, "0")) {     ///ͨ������һ���ĺ�����HasBookFileToCheck�����ж��Լ��Ƿ������и�ϸ�����ԤԼ��¼�����û�У�ͬ�����û�м�¼��Ȼ�󷵻��Ӳ˵�
				cout << "-----------------------------------" << endl;
				cout << "|           û��ԤԼ��¼��        |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				return;
			}
			for (int i = 0; i < file.GetSize(); i++) {     ///�������������ԤԼ��¼
				if (file.GetBookdata()[i]["ԤԼ״̬"] == "0") {
					cout << "[" << index++ << "]" << endl;
					cout << "ԤԼ���ڣ�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
					cout << "ԤԼʱ��Σ�" << (file.GetBookdata()[i]["ԤԼʱ���"] == "1" ? "����" : "����") << endl;
					cout << "���ң�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
					cout << "ԤԼ����ݣ�" << file.GetBookdata()[i]["ԤԼ�����"] << endl;
					cout << "ԤԼ�ˣ�" << file.GetBookdata()[i]["ԤԼ��"] << endl;
					cout << "ԤԼ��ѧ�ţ�" << file.GetBookdata()[i]["ԤԼ��ѧ��"] << endl;
					cout << "ԤԼ��רҵ��" << file.GetBookdata()[i]["ԤԼ��רҵ"] << endl;
					cout << "��;�����ɣ�" << file.GetBookdata()[i]["ԤԼ��;������"] << endl;
					string status = "��ȡ��ԤԼ!";
					cout << status << endl;
					cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
					cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
					cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
					cout << "---------------------------------------" << endl;
				}
			}
			break;
		}
		else if (choice == "2") {     ///�ڶ����жϣ��Ƿ���ʧ�ܵ�ԤԼ����ԤԼ״̬Ϊ��-1��
			if (!HasBookFileToCheck(file, "-1")) {
				cout << "-----------------------------------" << endl;
				cout << "|           û��ԤԼ��¼��        |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				return;
			}
			for (int i = 0; i < file.GetSize(); i++) {
				if (file.GetBookdata()[i]["ԤԼ״̬"] == "-1") {
					cout << "[" << index++ << "]" << endl;
					cout << "ԤԼ���ڣ�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
					cout << "ԤԼʱ��Σ�" << (file.GetBookdata()[i]["ԤԼʱ���"] == "1" ? "����" : "����") << endl;
					cout << "���ң�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
					cout << "ԤԼ����ݣ�" << file.GetBookdata()[i]["ԤԼ�����"] << endl;
					cout << "ԤԼ�ˣ�" << file.GetBookdata()[i]["ԤԼ��"] << endl;
					cout << "ԤԼ��ѧ�ţ�" << file.GetBookdata()[i]["ԤԼ��ѧ��"] << endl;
					cout << "ԤԼ��רҵ��" << file.GetBookdata()[i]["ԤԼ��רҵ"] << endl;
					cout << "��;�����ɣ�" << file.GetBookdata()[i]["ԤԼ��;������"] << endl;
					string status = "���ʧ�ܣ�������ԤԼ��";
					cout << status << endl;
					cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
					cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
					cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
					cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
					cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
					cout << "---------------------------------------" << endl;
				}
			}
			break;
		}
		else if (choice == "3") {     ///�������жϣ��Ƿ�������˵�ԤԼ����ԤԼ״̬Ϊ��1��
			if (!HasBookFileToCheck(file, "1")&&!HasBookFileToCheck(file,"3")) {
				cout << "-----------------------------------" << endl;
				cout << "|           û��ԤԼ��¼��        |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				return;
			}
			for (int i = 0; i < file.GetSize(); i++) {
				if (file.GetBookdata()[i]["ԤԼ״̬"] == "1" || file.GetBookdata()[i]["ԤԼ״̬"] == "3") {
					cout << "[" << index++ << "]" << endl;
					cout << "ԤԼ���ڣ�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
					cout << "ԤԼʱ��Σ�" << (file.GetBookdata()[i]["ԤԼʱ���"] == "1" ? "����" : "����") << endl;
					cout << "���ң�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
					cout << "ԤԼ����ݣ�" << file.GetBookdata()[i]["ԤԼ�����"] << endl;
					cout << "ԤԼ�ˣ�" << file.GetBookdata()[i]["ԤԼ��"] << endl;
					cout << "ԤԼ��ѧ�ţ�" << file.GetBookdata()[i]["ԤԼ��ѧ��"] << endl;
					cout << "ԤԼ��רҵ��" << file.GetBookdata()[i]["ԤԼ��רҵ"] << endl;
					cout << "��;�����ɣ�" << file.GetBookdata()[i]["ԤԼ��;������"] << endl;
					string status;
					if (file.GetBookdata()[i]["ԤԼ״̬"] == "1") {
						status += "��������У�";
					}
					else if (file.GetBookdata()[i]["ԤԼ״̬"] == "3") {
						status += "��ͨ������Ա������ˣ��ȴ�������ˣ�";
					}
					cout << status << endl;
					cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
					cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
					cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
					cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
					cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
					cout << "---------------------------------------" << endl;
				}
			}
			break;
		}
		else if (choice == "4") {     ///���ĸ��жϣ��Ƿ��гɹ���ԤԼ����ԤԼ״̬Ϊ��2��
			if (!HasBookFileToCheck(file, "2")) {
				cout << "-----------------------------------" << endl;
				cout << "|           û��ԤԼ��¼��        |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				return;
			}
			for (int i = 0; i < file.GetSize(); i++) {
				if (file.GetBookdata()[i]["ԤԼ״̬"] == "2") {
					cout << "[" << index++ << "]" << endl;
					cout << "ԤԼ���ڣ�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
					cout << "ԤԼʱ��Σ�" << (file.GetBookdata()[i]["ԤԼʱ���"] == "1" ? "����" : "����") << endl;
					cout << "���ң�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
					cout << "ԤԼ����ݣ�" << file.GetBookdata()[i]["ԤԼ�����"] << endl;
					cout << "ԤԼ�ˣ�" << file.GetBookdata()[i]["ԤԼ��"] << endl;
					cout << "ԤԼ��ѧ�ţ�" << file.GetBookdata()[i]["ԤԼ��ѧ��"] << endl;
					cout << "ԤԼ��רҵ��" << file.GetBookdata()[i]["ԤԼ��רҵ"] << endl;
					cout << "��;�����ɣ�" << file.GetBookdata()[i]["ԤԼ��;������"] << endl;
					string status = "��˳ɹ�����ԤԼ��";
					cout << status << endl;
					cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
					cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
					cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
					cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
					cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
					cout << "---------------------------------------" << endl;
				}
			}
			break;
		}
		else if (choice == "0") {     ///0�����Ӳ˵�
			system("cls");
			return;
		}
		else {     ///������������Ϸ�
			cout << "-----------------------------------" << endl;
			cout << "|      �����������������룡     |" << endl;
			cout << "-----------------------------------" << endl;
			system("cls");
		}
	}
	system("pause");
	system("cls");
}

//��Ա�������������ѧ����ԤԼ����
void Technician::AuditBook()
{
	///�����ṹ�븨��Ա�ࡰ���ԤԼ���ܡ�һ�£��������ڣ�
	///1.û��������ƣ������������ѧ����ԤԼ�����ж������ǣ�
	///a.��ͨѧ�����벢��ͨ���˸���Ա������˵�ԤԼ��ԤԼ״̬Ϊ��3����
	///b.ѧ�����������ԤԼ��ԤԼ״̬Ϊ��1����
	/// 
		BookFile file;     ///����ԤԼ��¼�ļ���Ķ��󣬽������û����ļ���Ϣ��ϵ������
		if (file.GetSize() == 0 || !HasBookAudit()) {     ///���û����Ҫ��˵����е�ѧ����ԤԼ��¼��������������
			cout << "-----------------------------------" << endl;
			cout << "|     û����Ҫ��˵�ԤԼ��¼��    |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "����˵ļ�¼���£�" << endl;

		vector<int>v;     ///����ͨѧ���ࡰȡ��ԤԼ���ܡ������Ƶ�����������v����Ϊװ��bookdata�з�����������������

		int index = 1;      ///Ĭ����չʾѧ�������ԤԼ����չʾ��ͨѧ����ԤԼ��¼
		for (int i = 0; i < file.GetSize(); i++) {
			if (file.GetBookdata()[i]["ԤԼ״̬"] == "1" && file.GetBookdata()[i]["ԤԼ�����"] == "ѧ������") {
				v.push_back(i);
				cout << "[" << index++ << "]" << endl;
				cout << "ԤԼ���ڣ�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
				cout << "ԤԼʱ��Σ�" << (file.GetBookdata()[i]["ԤԼʱ���"] == "1" ? "����" : "����") << endl;
				cout << "���ң�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
				cout << "��ݣ�" << file.GetBookdata()[i]["ԤԼ�����"] << endl;
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
		for (int i = 0; i < file.GetSize(); i++) {
			if (file.GetBookdata()[i]["ԤԼ״̬"] == "3") {
				v.push_back(i);
				cout << "[" << index++ << "]" << endl;
				cout << "ԤԼ���ڣ�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
				cout << "ԤԼʱ��Σ�" << (file.GetBookdata()[i]["ԤԼʱ���"] == "1" ? "����" : "����") << endl;
				cout << "���ң�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
				cout << "��ݣ�" << file.GetBookdata()[i]["ԤԼ�����"] << endl;
				cout << "ԤԼ�ˣ�" << file.GetBookdata()[i]["ԤԼ��"] << endl;
				cout << "ԤԼ��ѧ�ţ�" << file.GetBookdata()[i]["ԤԼ��ѧ��"] << endl;
				cout << "��;�����ɣ�" << file.GetBookdata()[i]["ԤԼ��;������"] << endl;
				string status = "ԤԼ״̬��";
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

		int choice = -1;
		string change;
		while (1) {
			cout << "������Ҫ��˵�ԤԼ��¼��0�����أ� ";
			cin >> change;
			try {     ///ͬ��������Ϸ��Լ��
				choice = stoi(change);
				if (choice == 0) {
					break;
				}
				if (choice > 0 && choice <= v.size()) {
					cout << "-----------------------------------" << endl;
					cout << "|          ��������˽����       |" << endl;
					cout << "|          1.���ͨ��             |" << endl;
					cout << "|          2.��˲�ͨ��           |" << endl;
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
								file.GetBookdata()[v[choice - 1]]["ԤԼ״̬"] = "2";
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
					file.GetBookdata()[v[choice - 1]]["������ʦ"] = GetName();

					time_t now = time(0);     ///��ȡϵͳ��ǰʱ�䣬����д������ԤԼʱ��ʱ��
					tm currenttime;
					localtime_s(&currenttime, &now);     ///��ϵͳʱ���ʼ��Ϊ����ʱ��
					string format = to_string(currenttime.tm_year + 1900) + "��" + to_string(currenttime.tm_mon + 1) + "��" + to_string(currenttime.tm_mday) + "��" + to_string(currenttime.tm_hour) + "ʱ" + to_string(currenttime.tm_min) + "��" + to_string(currenttime.tm_sec) + "��";
					string second = to_string(now);     ///���������������ֱ��ʽ�����õ���ʱ��ʹ�1970.1.1���������

					file.GetBookdata()[v[choice - 1]]["����ʱ��"] = format;
					file.GetBookdata()[v[choice - 1]]["����ֵ3"] = second;

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

//��Ա�������ж��Ƿ�����Ҫ��˵�ԤԼ��¼���з���true�����򷵻�false
bool Technician::HasBookAudit()
{
	BookFile file;
	int sum = 0;
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["ԤԼ�����"] == "��ͨѧ��") {     ///�������ͨѧ������Ҫ����ͨ������Ա�������("3")������
			if (file.GetBookdata()[i]["ԤԼ״̬"] == "3") {
				sum++;
			}
		}
		if (file.GetBookdata()[i]["ԤԼ�����"] == "ѧ������") {     ///�����ѧ������ֻ���������벢�ҵȴ����("1")������
			if (file.GetBookdata()[i]["ԤԼ״̬"] == "1") {
				sum++;
			}
		}
	}
	if (sum > 0) {
		return 1;
	}
	return 0;
}

//��Ա�������жϼ�����ʦ�Ĳ��з��Ƿ�ϸ񣬼���������6�����Լ���������������Ϊ������û����޷���˻�鿴ѧ��ԤԼ
bool Technician::CalculateScore()
{
	///�븨��Ա��ͬ�������ṹ���ƣ��������ڣ�
	///1.��ݺ��������Ͳ�ͬ
	
	BookFile file;
	double sum = 0;
	double score = 0;
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["������ʦ"] == GetName() && file.GetBookdata()[i]["����2"] != "��δ����") {
			sum++;
			score += stod(file.GetBookdata()[i]["����2"]);
		}
	}
	if (sum == 0) {
		cout << "���Ĳ���������Ϊ��" << GetCreditScore() << "(����)" << endl;
		return 1;
	}
	else {
		GetCreditScore() = score / sum;
		cout << fixed << setprecision(2) << "���Ĳ���������Ϊ��" << GetCreditScore();
		if (GetCreditScore() >= 6) {
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
		else {
			cout << "(���ϸ�)" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "| ���÷������ϸ�����ϵ����Ա������һ�������� |" << endl;
			cout << "------------------------------------------------" << endl;
			return 0;
		}
	}
}
;