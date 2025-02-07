#include"Student.h"

//ѧ���������޲ι��캯��
Monitor::Monitor() {};

//ѧ���������вι��캯������ʼ��ѧ�������ѧ�ţ����֣����룬��ݣ�רҵ�Լ�����������Ա
Monitor::Monitor(string id, string name, string password, string level, string major) :Student(id, name, password, level, major) { this->InitialVector(); }

//ѧ������������������
Monitor::~Monitor() {};

//��Ա���������ѧ���������Ӳ˵�ҳ��
void Monitor::OpenMenu()
{
	cout << "    ��ӭѧ������ " +GetName()+ " ��¼�� " << endl;
	cout << "-----------------------------------" << endl;
	cout << "|           1.ԤԼ����            |" << endl;
	cout << "|           2.�鿴�ҵ�ԤԼ        |" << endl;
	cout << "|           3.�鿴����ԤԼ        |" << endl;
	cout << "|           4.ȡ��ԤԼ            |" << endl;
	cout << "|           5.����ԤԼ            |" << endl;
	cout << "|           0.ע����¼            |" << endl;
	cout << "-----------------------------------" << endl;
}

//��Ա����������ԤԼ����
void Monitor::ApplyBook()
{
	///�����ṹ����ͨѧ���ࡰ����ԤԼ���ܡ�һ�£��������ڣ�
	///1.�����������еĽ���
	///2.����������3��

	if (!HitMaxRoom()) {     ///�ж��������������ԤԼ���������
		cout << "-----------------------------------" << endl;
		cout << "|    ���ҵĿ���ʱ��Ϊ��һ������   |" << endl;
		cout << "|       ����������ԤԼ��ʱ�䣺    |" << endl;
		cout << "|             1.��һ              |" << endl;
		cout << "|             2.�ܶ�              |" << endl;
		cout << "|             3.����              |" << endl;
		cout << "|             4.����              |" << endl;
		cout << "|             5.����              |" << endl;
		cout << "|             6.����              |" << endl;
		cout << "|             7.����              |" << endl;
		cout << "|             0.�����Ӳ˵�        |" << endl;
		cout << "-----------------------------------" << endl;

		int datechoice = -1;     ///����������ֱ�����ڣ�ʱ��Σ�����ѡ��
		string choice1;			 ///ÿһ�����string���ܼ�������ֵ��ͨ��stoiת��Ϊint�����Դ���ɶ�����ĺϷ��Լ��

		int intervalchoice = -1;
		string choice2;

		int room = -1;
		string roomchoice;

		string date;     ///�������������ѡ����ɺ󣬽��и�ֵ
		string interval;
		
		while (1) {     ///��һ���ȶ����ڽ���ѡ��
			cout << "����������ѡ��";
			cin >> choice1;
			try {     ///ͨ��try��catch�����������Ϸ��Լ��
				datechoice = stoi(choice1);     ///���stoiת��ʧ�ܣ����׳��쳣���ж�Ϊ��������
				if (datechoice < 0 || datechoice >= 8) {
					cout << "-----------------------------------" << endl;
					cout << "|      �����������������룡     |" << endl;
					cout << "-----------------------------------" << endl;
				}
				else if (datechoice == 0) {     ///�����Ӳ˵�
					system("pause");
					system("cls");
					return;
				}
				else {
					switch (datechoice) {
					case 1:date = "��һ"; break;
					case 2:date = "�ܶ�"; break;
					case 3:date = "����"; break;
					case 4:date = "����"; break;
					case 5:date = "����"; break;
					case 6:date = "����"; break;
					case 7:date = "����"; break;
					}
					break;
				}
			}
			catch (...) {
				cout << "-----------------------------------" << endl;     ///�ڶ�����ʱ��ν���ѡ��
				cout << "|      �����������������룡     |" << endl;
				cout << "-----------------------------------" << endl;
			}
			
		}

		cout << "-----------------------------------" << endl;
		cout << "|           ��ѡ��ʱ��Σ�        |" << endl;
		cout << "|              1.����             |" << endl;
		cout << "|              2.����             |" << endl;
		cout << "-----------------------------------" << endl;
		while (1) {
			cout << "����������ѡ��";
			cin >> choice2;
			try {
				intervalchoice = stoi(choice2);
				if (intervalchoice <= 0 || intervalchoice >= 3) {
					cout << "-----------------------------------" << endl;
					cout << "|      �����������������룡     |" << endl;
					cout << "-----------------------------------" << endl;
				}
				else {
					if (intervalchoice == 1) {
						interval = "����";
					}
					else {
						interval = "����";
					}
					break;
				}
			}
			catch (...) {
				cout << "-----------------------------------" << endl;
				cout << "|      �����������������룡     |" << endl;
				cout << "-----------------------------------" << endl;
			}
		}

		cout << "������Ϣ���£�" << endl;     ///�������Խ��ҽ���ѡ��
		int i = 1;     ///��������ʾ������Ҳ�����жϿ�ԤԼ���������Ƿ�Ϊ0
		for (auto it = GetvClassroom().begin(); it != GetvClassroom().end(); it++) {
			cout <<"[" << i << "] ���ұ�ţ�" << it->GetId() << " ������������" << it->GetVolume() << endl;     ///����ѧ�����������������н���
			i++;
		}
		i--;
		while (1) {
			cout << "��ѡ����ұ��,0�����أ� ";
			cin >> roomchoice;
			try {     ///������Ϸ��Լ��
				room = stoi(roomchoice);
				if (room < 0 || room > i) {
					cout << "-----------------------------------" << endl;
					cout << "|      �����������������룡     |" << endl;
					cout << "-----------------------------------" << endl;
				}
				else if (room == 0) {
					system("pause");
					system("cls");
					return;
				}
				else if (!OnlyOneRoom(date, interval, GetvClassroom()[room - 1].GetId())) {     ///��ԤԼ�Ľ����Ƿ��ظ����ж�,����˽����ѱ�ԤԼ��ִ���������
					cout << "-------------------------------------" << endl;
					cout << "| ��ʱ��ν����ѱ�ԤԼ�����������룡|" << endl;
					cout << "-------------------------------------" << endl;
				}
				else {
					break;     ///����Ϸ����ҽ���δ��ԤԼռ�ã�����ѭ��������д�ļ�����
				}
			}
			catch (...) {
				cout << "-----------------------------------" << endl;
				cout << "|      �����������������룡     |" << endl;
				cout << "-----------------------------------" << endl;
			}
		}
		string BookReason;     ///����ԤԼ��ԭ��
		while (1) {
			cout << "������������;�����ɣ����磬ѧ�����ѧԺ��������������õȣ��� ";
			cin >> BookReason;
			if (BookReason.size() == 0) {
				cout << "-----------------------------------" << endl;
				cout << "|    ���ɲ���Ϊ�գ����������룡   |" << endl;
				cout << "-----------------------------------" << endl;
			}
			else {
				break;
			}
		}
		time_t now = time(0);     ///��ȡϵͳ��ǰʱ�䣬����д������ԤԼʱ��ʱ��
		tm currenttime;
		localtime_s(&currenttime, &now);     ///��ϵͳʱ���ʼ��Ϊ����ʱ��
		string format = to_string(currenttime.tm_year + 1900) + "��" + to_string(currenttime.tm_mon + 1) + "��" + to_string(currenttime.tm_mday) + "��" + to_string(currenttime.tm_hour) + "ʱ" + to_string(currenttime.tm_min) + "��" + to_string(currenttime.tm_sec) + "��";
		string second = to_string(now);     ///���������������ֱ��ʽ�����õ���ʱ��ʹ�1970.1.1���������

		ofstream ofs(BOOK_FILE, ios::out | ios::app);     ///ԤԼ�����������ȡȫ����ɣ������ǽ��¼�¼׷��д��BookFile�ļ��Ĺ���
		ofs << "ԤԼ����:" << date << " ";
		ofs << "ԤԼʱ���:" << interval << " ";
		ofs << "ԤԼ����:" << GetvClassroom()[room - 1].GetId() << " ";
		ofs << "ԤԼ�����:" << GetLevel() << " ";
		ofs << "ԤԼ��:" << GetName() << " ";
		ofs << "ԤԼ��ѧ��:" << GetStudentId() << " ";
		ofs << "ԤԼ��רҵ:" << GetMajor() << " ";
		ofs << "ԤԼ��;������:" << BookReason << " ";
		ofs << "������ʦ:����" << " ";
		ofs << "����1:��δ����" << " ";
		ofs << "������ʦ:����" << " ";
		ofs << "����2:��δ����" << " ";
		ofs << "ԤԼ״̬:" << 1 << endl;
		ofs << "����ʱ��:" << format << " ";
		ofs << "����ʱ��:����" << " ";
		ofs << "����ʱ��:����" << " ";
		ofs << "����ֵ1:" << second << " ";
		ofs << "����ֵ2:����" << " ";
		ofs << "����ֵ3:����" << endl;


		cout << "-----------------------------------" << endl;
		cout << "| ԤԼ�ɹ����뼰ʱ�鿴�������Ϣ��|" << endl;
		cout << "-----------------------------------" << endl;

		ofs.close();
	}
	else {     ///���������һ�����̶���ִ�У�Ҳ���������¼�ﵽ���ޣ��Ǿ�ִ���������
		cout << "-----------------------------------------------------" << endl;
		cout << "|  ������˵�ԤԼ�����Ѵ����ޣ�3�����޷�����ԤԼ��  |" << endl;
		cout << "-----------------------------------------------------" << endl;
	}
	system("pause");	  ///�����������
	system("cls");		  ///����
}

//��Ա�������鿴�ҵ�ԤԼ����
void Monitor::ShowMyBook()
{
	///�����ṹ����ͨѧ���ࡰ�鿴�ҵ�ԤԼ���ܡ�һ�£��������ڣ�
	///1.ѧ������û��ԤԼ״̬Ϊ��3���Ĵ����

	BookFile file;     ///����ԤԼ��¼�ļ���Ķ��󣬽������û����ļ���Ϣ��ϵ������
	if (file.GetSize() == 0 || !HasBookFile(file)) {     ///���û���Լ���ԤԼ��¼����ô����������
		cout << "-----------------------------------" << endl;
		cout << "|        û������ԤԼ��¼��       |" << endl;
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
			if (!HasBookFileIndeed(file, "0")) {     ///ͨ������һ���ĺ�����HasBookFileIndeed�����ж��Լ��Ƿ������и�ϸ�����ԤԼ��¼�����û�У�ͬ�����û�м�¼��Ȼ�󷵻��Ӳ˵�
				cout << "-----------------------------------" << endl;
				cout << "|           û��ԤԼ��¼��        |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				return;
			}
			for (int i = 0; i < file.GetSize(); i++) {     ///�������������ԤԼ��¼
				if (file.GetBookdata()[i]["ԤԼ��ѧ��"] == this->GetStudentId() && file.GetBookdata()[i]["ԤԼ�����"] == "ѧ������" && file.GetBookdata()[i]["ԤԼ״̬"] == "0") {
					cout << "[" << index++ << "]" << endl;
					cout << "ԤԼ���ڣ�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
					cout << "ԤԼʱ��Σ�" << (file.GetBookdata()[i]["ԤԼʱ���"] == "1" ? "����" : "����") << endl;
					cout << "���ң�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
					cout << "��;�����ɣ�" << file.GetBookdata()[i]["ԤԼ��;������"] << endl;
					string status = "��ȡ��ԤԼ!";
					cout << status << endl;
					cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
					cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
					cout << "---------------------------------------" << endl;
				}
			}
			break;
		}
		else if (choice == "2") {     ///�ڶ����жϣ��Ƿ���ʧ�ܵ�ԤԼ����ԤԼ״̬Ϊ��-1��
			if (!HasBookFileIndeed(file, "-1")) {
				cout << "-----------------------------------" << endl;
				cout << "|           û��ԤԼ��¼��        |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				return;
			}
			for (int i = 0; i < file.GetSize(); i++) {
				if (file.GetBookdata()[i]["ԤԼ��ѧ��"] == this->GetStudentId() && file.GetBookdata()[i]["ԤԼ�����"] == "ѧ������" && file.GetBookdata()[i]["ԤԼ״̬"] == "-1") {
					cout << "[" << index++ << "]" << endl;
					cout << "ԤԼ���ڣ�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
					cout << "ԤԼʱ��Σ�" << (file.GetBookdata()[i]["ԤԼʱ���"] == "1" ? "����" : "����") << endl;
					cout << "���ң�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
					cout << "��;�����ɣ�" << file.GetBookdata()[i]["ԤԼ��;������"] << endl;
					string status = "���ʧ�ܣ�������ԤԼ��";
					cout << status << endl;
					cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
					cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
					cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
					cout << "---------------------------------------" << endl;
				}
			}
			break;
		}
		else if (choice == "3") {     ///�������жϣ��Ƿ�������˵�ԤԼ����ԤԼ״̬Ϊ��1��
			if (!HasBookFileIndeed(file, "1")) {
				cout << "-----------------------------------" << endl;
				cout << "|           û��ԤԼ��¼��        |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				return;
			}
			for (int i = 0; i < file.GetSize(); i++) {
				if (file.GetBookdata()[i]["ԤԼ��ѧ��"] == this->GetStudentId() && file.GetBookdata()[i]["ԤԼ�����"] == "ѧ������" && file.GetBookdata()[i]["ԤԼ״̬"] == "1" ) {
					cout << "[" << index++ << "]" << endl;
					cout << "ԤԼ���ڣ�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
					cout << "ԤԼʱ��Σ�" << (file.GetBookdata()[i]["ԤԼʱ���"] == "1" ? "����" : "����") << endl;
					cout << "���ң�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
					cout << "��;�����ɣ�" << file.GetBookdata()[i]["ԤԼ��;������"] << endl;
					string status;
					if (file.GetBookdata()[i]["ԤԼ״̬"] == "1") {
						status += "��������У�";
					}
					cout << status << endl;
					cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
					cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
					cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
					cout << "---------------------------------------" << endl;
				}
			}
			break;
		}
		else if (choice == "4") {     ///���ĸ��жϣ��Ƿ��гɹ���ԤԼ����ԤԼ״̬Ϊ��2��
			if (!HasBookFileIndeed(file, "2")) {
				cout << "-----------------------------------" << endl;
				cout << "|           û��ԤԼ��¼��        |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				return;
			}
			for (int i = 0; i < file.GetSize(); i++) {
				if (file.GetBookdata()[i]["ԤԼ��ѧ��"] == this->GetStudentId() && file.GetBookdata()[i]["ԤԼ�����"] == "ѧ������" && file.GetBookdata()[i]["ԤԼ״̬"] == "2") {
					cout << "[" << index++ << "]" << endl;
					cout << "ԤԼ���ڣ�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
					cout << "ԤԼʱ��Σ�" << (file.GetBookdata()[i]["ԤԼʱ���"] == "1" ? "����" : "����") << endl;
					cout << "���ң�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
					cout << "��;�����ɣ�" << file.GetBookdata()[i]["ԤԼ��;������"] << endl;
					string status = "��˳ɹ�����ԤԼ��";
					cout << status << endl;
					cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
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

//��Ա�������鿴�����˵�ԤԼ���ܣ���ͨѧ��û�У�
void Monitor::ShowAllBook()
{
	BookFile file;     ///����ԤԼ��¼�ļ���Ķ��󣬽������û����ļ���Ϣ��ϵ������
	if (file.GetSize() == 0) {     ///��ʱ�жϼ�¼�Ƿ�Ϊ�ռ���
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
			if (!HasBookFileToCheck(file,"0")) {     ///ͨ������һ���ĺ�����HasBookFileToCheck�����ж��Լ��Ƿ������и�ϸ�����ԤԼ��¼�����û�У�ͬ�����û�м�¼��Ȼ�󷵻��Ӳ˵�
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
			if (!HasBookFileToCheck(file, "1")) {
				cout << "-----------------------------------" << endl;
				cout << "|           û��ԤԼ��¼��        |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				return;
			}
			for (int i = 0; i < file.GetSize(); i++) {
				if (file.GetBookdata()[i]["ԤԼ״̬"] == "1"||file.GetBookdata()[i]["ԤԼ״̬"]=="3") {
					cout << "[" << index++ << "]" << endl;
					cout << "ԤԼ���ڣ�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
					cout << "ԤԼʱ��Σ�" << (file.GetBookdata()[i]["ԤԼʱ���"] == "1" ? "����" : "����") << endl;
					cout << "���ң�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
					cout << "ԤԼ����ݣ�" << file.GetBookdata()[i]["ԤԼ�����"] << endl;
					cout << "ԤԼ�ˣ�" << file.GetBookdata()[i]["ԤԼ��"] << endl;
					cout << "ԤԼ��ѧ�ţ�" << file.GetBookdata()[i]["ԤԼ��ѧ��"] << endl;
					cout << "ԤԼ��רҵ��" << file.GetBookdata()[i]["ԤԼ��רҵ"] << endl;
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

//��Ա������ȡ��ԤԼ����
void Monitor::CancelBook()
{
	///�����ṹ����ͨѧ���ࡰȡ��ԤԼ���ܡ�һ�£��������ڣ�
	///1.û��ԤԼ״̬Ϊ��3������ش���Σ�Ҳ����û�С�ͨ������Ա����ˡ���һ��
	 
	BookFile file;
	if (file.GetSize() == 0 || !NotCancel(file)) {
		cout << "-----------------------------------" << endl;
		cout << "|       û�п�ִ�е�ԤԼ��¼��    |" << endl;
		cout << "-----------------------------------" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "|  ԤԼ״̬Ϊ������С��롰��˳ɹ����ľ���ȡ��ԤԼ����鿴Ҫȡ����ԤԼ��¼  |" << endl;
	cout << "--------------------------------------------------------------------------" << endl;

	vector<int>v;     ///ʵ����int��vector����v��������ѭ���з��������ģ�
					  ///1.ѧ�����Լ���
					  ///2.�����ѧ������
					  ///3.��¼�ļ���ԤԼ״̬Ϊ��1����2��
					  ///��ô�ͽ��±�i����ֵ���뵽v�У�Ҳ���ǽ�bookdata�����ķ�������������ֵ����ӳ�䵽��v�У��������ɾ��ʱ��Ϊ��������
	int index = 1;
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["ԤԼ��ѧ��"] == this->GetStudentId () && (file.GetBookdata()[i]["ԤԼ״̬"] == "1" || file.GetBookdata()[i]["ԤԼ״̬"] == "2")) {
			v.push_back(i);
			cout << "[" << index++ << "] " << endl;
			cout << "ԤԼ���ڣ�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
			cout << "ԤԼʱ��Σ�" << (file.GetBookdata()[i]["ԤԼʱ���"] == "1" ? "����" : "����") << endl;
			cout << "���ң�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
			cout << "ԤԼ�����" << file.GetBookdata()[i]["ԤԼ�����"] << endl;
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
			cout << status << endl;
			cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
			cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
			cout << "---------------------------------------" << endl;
		}
	}
	index--;
	int choice = -1;
	string change;
	while (1) {
		cout << "������Ҫȡ���ı�ţ�0�����أ� ";
		cin >> change;
		try {     ///����Ϸ����ж�
			choice = stoi(change);
			if (choice >= 0 && choice <= index) {
				if (choice == 0) {
					break;
				}
																			 ///��ԤԼ״̬��Ϊ0����ȡ��ԤԼ
				file.GetBookdata()[v[choice - 1]]["ԤԼ״̬"] = "0";		 ///choice��Ӧindex����index�Ǵ�1��ʼ��������v�±��0��ʼ����Ҫ��һ
																			 ///Ȼ��v��Ӧ�±�����bookdata�������ֵ��������ʵ���˴�v��bookdata���ҵ���¼���޸ĵ�Ŀ��

				file.UpdateBook();     ///�޸����ͬ�������ļ���ļ�¼
				cout << "-------------------------------------" << endl;
				cout << "| �Ѿ��ɹ�ȡ��ԤԼ����ע��鿴��Ϣ��|" << endl;
				cout << "-------------------------------------" << endl;
				break;
			}
			cout << "-----------------------------------" << endl;     ///������볬����Χ����Ϊ����
			cout << "|      �����������������룡     |" << endl;
			cout << "-----------------------------------" << endl;
		}
		catch (...) {
			cout << "-----------------------------------" << endl;     
			cout << "|      �����������������룡     |" << endl;
			cout << "-----------------------------------" << endl;
		}
	}
	system("pause");		///�����������
	system("cls");			///����
}

//��Ա���������۹���
void Monitor::EvaluateBook()
{
	string choice1;     ///������һ��ѡ��
	while (1) {
		cout << "-----------------------------------" << endl;
		cout << "|        ��ѡ��鿴����ԤԼ��     |" << endl;
		cout << "|        1.�����۹���ԤԼ����     |" << endl;
		cout << "|        2.�����۵�ԤԼ����       |" << endl;
		cout << "|        0.�����Ӳ˵�             |" << endl;
		cout << "-----------------------------------" << endl;

		cout << "����������ѡ��";
		cin >> choice1;
		if (choice1 == "0") {
			system("cls");
			return;
		}
		else if (choice1 == "1" || choice1 == "2") {
			break;
		}
		else {
			cout << "-----------------------------------" << endl;
			cout << "|      �����������������룡     |" << endl;
			cout << "-----------------------------------" << endl;
		}
	}
	BookFile file;
	int index = 0;
	vector<int> v;      ///�롰ȡ��ԤԼ���ܡ��������÷�
	if (choice1 == "1") {
		for (int i = 0; i < file.GetSize(); i++) {
			if (file.GetBookdata()[i]["ԤԼ��ѧ��"] == GetStudentId() && file.GetBookdata()[i]["ԤԼ�����"] == "ѧ������" && file.GetBookdata()[i]["ԤԼ״̬"] == "2" && file.GetBookdata()[i]["����2"] != "��δ����") {
				cout << "[" << ++index << "]" << endl;
				cout << "ԤԼ���ڣ�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
				cout << "ԤԼʱ��Σ�" << (file.GetBookdata()[i]["ԤԼʱ���"] == "1" ? "����" : "����") << endl;
				cout << "���ң�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
				cout << "��;�����ɣ�" << file.GetBookdata()[i]["ԤԼ��;������"] << endl;
				cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
				cout << "��������ʦ���۷֣�" << file.GetBookdata()[i]["����2"] << endl;
				cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
				cout << "����ʱ�䣺" << file.GetBookdata()[i]["����ʱ��"] << endl;
				cout << "--------------------------------------" << endl;
			}
		}
		if (index == 0) {
			cout << "-----------------------------------" << endl;
			cout << "|      û�������۹���ԤԼ���룡   |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	else if (choice1 == "2") {
		for (int i = 0; i < file.GetSize(); i++) {
			if (file.GetBookdata()[i]["ԤԼ��ѧ��"] == GetStudentId() && file.GetBookdata()[i]["ԤԼ�����"] == "ѧ������" && file.GetBookdata()[i]["ԤԼ״̬"] == "2" && file.GetBookdata()[i]["����2"] == "��δ����") {
				v.push_back(i);
				cout << "[" << ++index << "]" << endl;
				cout << "ԤԼ���ڣ�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
				cout << "ԤԼʱ��Σ�" << (file.GetBookdata()[i]["ԤԼʱ���"] == "1" ? "����" : "����") << endl;
				cout << "���ң�" << file.GetBookdata()[i]["ԤԼ����"] << endl;
				cout << "��;�����ɣ�" << file.GetBookdata()[i]["ԤԼ��;������"] << endl;
				cout << "������ʦ��" << file.GetBookdata()[i]["������ʦ"] << endl;
				cout << "--------------------------------------" << endl;

			}
		}
		if (index == 0) {
			cout << "-----------------------------------" << endl;
			cout << "|      û��������۵�ԤԼ���룡   |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
			return;
		}

		string choice2;
		int select;
		while (1) {
			bool flag = 0;     ///��־����Ϊ1�����˳��ò�ѭ��
			string score1;
			cout << "��ѡ��Ҫ���۵�ԤԼ��¼��";
			cin >> choice2;
			try {
				select = stoi(choice2);
				if (select <= 0 || select > index) {
					cout << "-----------------------------------" << endl;
					cout << "|      �����������������룡     |" << endl;
					cout << "-----------------------------------" << endl;
				}
				else {
					while (1) {

						int time = stoi(file.GetBookdata()[v[select - 1]]["����ֵ3"]) - stoi(file.GetBookdata()[v[select - 1]]["����ֵ1"]);     ///����ʱ��-����ʱ��=�������ʱ
						cout << "�������ʱ��" << CalculateAuditTime(time) << endl;

						cout << "��Ըü�����ʦ���۷֣�10��Ϊ���֣���";
						cin >> score1;
						if (stoi(score1) >= 0 && stoi(score1) <= 10) {
							file.GetBookdata()[v[static_cast<std::vector<int, std::allocator<int>>::size_type>(select) - 1]]["����2"] = score1;
							file.UpdateBook();     ///��ʱ��������
							cout << "-----------------------------------" << endl;
							cout << "|         ������ɣ���л��        |" << endl;
							cout << "-----------------------------------" << endl;
							flag = 1;     ///������۲�������ֵΪ1
							break;
						}
						else {
							cout << "-----------------------------------" << endl;
							cout << "|      �����������������룡     |" << endl;
							cout << "-----------------------------------" << endl;
						}
					}
				}
			}
			catch (...) {
				cout << "-----------------------------------" << endl;
				cout << "|      �����������������룡     |" << endl;
				cout << "-----------------------------------" << endl;
			}
			if (flag) {
				break;
			}
		}
	}
	system("pause");
	system("cls");
}

//��Ա��������ʼ������������Ա��Ϣ
void Monitor::InitialVector()
{
	GetvClassroom().clear();     ///����ս��������������ȡ�ص�����
	ifstream ifs(CLASSROOM_FILE, ios::in);     ///�򿪴�Ž������ݵ��ļ�����ȡ
	Classroom c;
	while (ifs >> c.GetId() && ifs >> c.GetVolume()) {
		GetvClassroom().push_back(c);     ///û�����������н�����Ϣ������������
	}
	ifs.close();
}

//��Ա�������ж��Ƿ�����Լ���ԤԼ��¼���з���true�����򷵻�false
bool Monitor::HasBookFile(BookFile &file)
{
	///����������ȡBookFile��Ĳ���file�����ã����ٿ���

	for (int i = 0; i < file.GetSize(); i++) {      ///ע����Ϊ��ͨѧ����ѧ������ѧ�ſ����ص��������������ж�
		if (file.GetBookdata()[i]["ԤԼ��ѧ��"] == this->GetStudentId()&&file.GetBookdata()[i]["ԤԼ�����"]=="ѧ������") {
			return 1;
		}
	}
	return 0;
}

bool Monitor::HasBookFileIndeed(BookFile file, string choice)
{
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["ԤԼ��ѧ��"] == GetStudentId() && file.GetBookdata()[i]["ԤԼ�����"] == GetLevel() && file.GetBookdata()[i]["ԤԼ״̬"] == choice) {
			return 1;
		}
	}
	return 0;
}

//��Ա�������ж��Ƿ���ں�����û�б�ȡ������ԤԼ���з���true�����򷵻�false
bool Monitor::NotCancel(BookFile& file)
{
	///����������ȡBookFile��Ĳ���file�����ã����ٿ���

	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["ԤԼ��ѧ��"] == this->GetStudentId() && (file.GetBookdata()[i]["ԤԼ״̬"] == "1" || file.GetBookdata()[i]["ԤԼ״̬"] == "2" )) {
			return 1;
		}
	}
	return 0;
}

//��Ա�������ж��Ƿ�ﵽԤԼ��3�������ޣ��з���true�����򷵻�false
bool Monitor::HitMaxRoom()
{
	int sum = 0;
	BookFile file;
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["ԤԼ��ѧ��"] == GetStudentId() && file.GetBookdata()[i]["ԤԼ״̬"] == "1") {
			sum++;
		}
	}
	if (sum >= 3) {
		return 1;
	}
	return 0;
}


