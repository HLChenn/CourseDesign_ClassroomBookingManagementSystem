#include "Manager.h"

//����Ա���޲ι��캯��
Manager::Manager() {};

//����Ա���вι��캯������ʼ�����֣����룬�Լ�������Ա
Manager::Manager(string name, string password,string major) :User(name, password,major) { this->InitialVector(); }

//����Ա������������
Manager::~Manager() {};

//��Ա�������Ӳ˵���ʼ��
void Manager::OpenMenu()
{
	cout << "      ��ӭ����Ա "+GetName()+" ��¼!" << endl;
	cout << "-----------------------------------" << endl;
	cout << "|            1.ע���û�           |" << endl;
	cout << "|            2.ɾ���û�           |" << endl;
	cout << "|            3.�޸��û�           |" << endl;
	cout << "|            4.�鿴�û�           |" << endl;
	cout << "|            5.��ѯ�û�           |" << endl;
	cout << "|            6.�鿴����           |" << endl;
	cout << "|            7.���ԤԼ           |" << endl;
	cout << "|            0.ע����¼           |" << endl;
	cout << "-----------------------------------" << endl;
}

//��Ա������ע���û�
void Manager::AddAccount()
{
	cout << "-----------------------------------" << endl;
	cout << "|      ��ѡ��Ҫע���û������ͣ�   |" << endl;
	cout << "|          1.��ͨѧ���û�         |" << endl;
	cout << "|          2.ѧ�������û�         |" << endl;
	cout << "|          3.����Ա�û�           |" << endl;
	cout << "|          4.������ʦ�û�         |" << endl;
	cout << "|          0.�����Ӳ˵�           |" << endl;
	cout << "-----------------------------------" << endl;
	string falsetip;     ///�ڲ�ͬѡ���и�ֵΪ��ͬ�Ĵ�����ʾ�������ִ���������ַ���
	string fname;        ///�ڲ�ͬѡ���и�ֵΪ��ͬ���ĵ��ļ�����
	string tip;			 ///
	ofstream ofs;		 ///����д�ļ������󣬴��Ҫд����ĵ��ļ�����ϵ

	string choice;		 ///����ѡ��Ҫע����û�����
	while (1) {
		cout << "����������ѡ��";
		cin >> choice;
		if (choice == "1") {
			fname = NORMALSTUDNET_FILE;
			tip = "��������ͨѧ��ѧ�ţ�";
			falsetip = "ѧ���ظ������������룡";
			break;
		}
		else if (choice == "2") {
			fname = MONITOR_FILE;
			tip = "������ѧ������ѧ�ţ�";
			falsetip = "ѧ���ظ������������룡";
			break;
		}
		else if (choice == "3") {
			fname = COUNSELLOR_FILE;
			tip = "�����븨��Ա��ţ�";
			falsetip = "����ظ������������룡";
			break;
		}
		else if (choice == "4") {
			fname = TECHNICIAN_FILE;
			tip = "�����뼼����ʦ��ţ�";
			falsetip = "����ظ������������룡";
			break;
		}
		else if (choice == "0") {
			system("cls");     ///���������Ӳ˵�
			return;
		}
		else {
			cout << "-----------------------------------" << endl;
			cout << "|      �����������������룡     |" << endl;
			cout << "-----------------------------------" << endl;
		}
	}
	string id;     ///��һ���������string���������룬���ڼ������Ϸ��ԣ���ͨ��stoi����תΪint��idcheck�����ں����������ж�
	int idcheck;

	string name;     ///�����û���������֣�����
	string password;

	string major = "������Ա";     ///���û�û�и���majorʱ��Ĭ��Ϊ������Ա

	ofs.open(fname, ios::out | ios::app);     ///��׷�ӷ�ʽд���ļ�

	while (1) {     ///�������Ƿ��ظ�
		cout << tip;
		cin >> id;
		try {     ///����ͨ��try��catch��ʽ�������Ϸ���
			idcheck = stoi(id);
			if (idcheck > 0) {
				bool check = CheckAccountNotOnly(id, choice);
				if (check) {
					cout << falsetip << endl;
				}
				else {
					break;
				}
			}
			else {
				cout << "-----------------------------------------" << endl;
				cout << "|          �����������������룡       |" << endl;
				cout << "-----------------------------------------" << endl;
			}
		}
		catch (...) {     ///��try���д�����֣��׳��쳣���ﵽ����Ϸ��Լ���Ŀ��
			cout << "-----------------------------------------" << endl;
			cout << "| ��������������������ֻ�����ֵ���ţ�|" << endl;
			cout << "-----------------------------------------" << endl;
		}	
	}
	cout << "������������";
	cin >> name;
	while (1) {
		cout << "����������(10λ����)�� ";
		cin >> password;
		if (password.size() > 10) {
			cout << "-----------------------------------" << endl;
			cout << "|    ����λ�����ޣ����������룡   |" << endl;
			cout << "-----------------------------------" << endl;
		}
		else if (password.size() <= 10) {
			break;
		}
	}
	if (choice != "4") {
		while (1) {
			cout << "����������רҵ��";
			cin >> major;
			if (major.size() == 0) {
				cout << "-----------------------------------------" << endl;
				cout << "|          �����������������룡       |" << endl;
				cout << "-----------------------------------------" << endl;
			}
			else {
				break;
			}
		}
	}
	ofs << id << " " << name << " " << password << " " << major << endl;     ///������ȫ���Ϸ�����ɺ�ͨ��ofsд�����ݵ�ָ���ĵ��ļ���
	cout << "-----------------------------------" << endl;
    cout << "|            ע��ɹ���           |" << endl;
	cout << "-----------------------------------" << endl;
    
    if (choice == "1") {     ///��ע����ɺ�ͬ�����¹���Ա���е����vector���ݳ�Ա
    	normalStudent s(id, name, password,"��ͨѧ��",major);
    	vNStudent.push_back(s);
    }
    else if (choice == "2") {
    	Monitor m(id, name, password,"ѧ������",major);
    	vMonitor.push_back(m);
    }
    else if (choice == "3") {
    	Counsellor c(id, name, password,major);
    	vCounsellor.push_back(c);
    }
    else if (choice == "4") {
    	Technician t(id, name, password,"������Ա");
    	vTechnician.push_back(t);
    }
	SortVector();     ///ͬʱ����

	ofs.close();     ///�ر�ofs���ĵ�����ϵ
	system("pause");
	system("cls");
}

//��Ա������ɾ���û�
void Manager::DeleteAccount()
{
	cout << "-----------------------------------" << endl;
	cout << "|        ��ѡ��ɾ���û����ͣ�     |" << endl;
	cout << "|          1.��ͨѧ���û�         |" << endl;
	cout << "|          2.ѧ�������û�         |" << endl;
	cout << "|          3.����Ա�û�           |" << endl;
	cout << "|          4.������ʦ�û�         |" << endl;
	cout << "|          0.�����Ӳ˵�           |" << endl;
	cout << "-----------------------------------" << endl;

	string choice;     
	int index = 1;     ///��������Ҫ�����Ϣ��������������ֵΪ1
	while (1) {
		cout << "����������ѡ��";
		cin >> choice;
		if (choice == "1") {
			cout << "������ͨѧ����Ϣ���£�" << endl;     ///ͨ��������Ʒ����ﵽ���������Ŀ��
			for (auto it = vNStudent.begin(); it < vNStudent.end(); it++) {     ///ͨ������������vector�����������Ϣ
				cout << setw(5) << left << index++
					<< "| ѧ�ţ�" << setw(7) << left << it->GetStudentId()
					<< "| ������" << setw(10) << it->GetName()
					<< "| ���룺" << setw(12) << it->GetPassword()
					<< " | רҵ��" << setw(20) << it->GetMajor() << "|" << endl;
			}
			break;
		}
		else if (choice == "2") {
			cout << "���е�ѧ��������Ϣ���£�" << endl;
			for (auto it = vMonitor.begin(); it < vMonitor.end(); it++) {
				cout << setw(5) << left << index++
					<< "| ѧ�ţ�" << setw(7) << left << it->GetStudentId()
					<< "| ������" << setw(10) << it->GetName()
					<< "| ���룺" << setw(12) << it->GetPassword()
					<< " | רҵ��" << setw(20) << it->GetMajor() << "|" << endl;
			}
			break;
		}
		else if (choice == "3") {
			cout << "���еĸ���Ա��Ϣ���£�" << endl;
			for (auto it = vCounsellor.begin(); it < vCounsellor.end(); it++) {
				cout << setw(5) << left << index++
					<< "| ��ţ�" << setw(7) << left << it->GetTeacherId()
					<< "| ������" << setw(10) << it->GetName()
					<< "| ���룺" << setw(12) << it->GetPassword()
					<< " | רҵ��" << setw(20) << it->GetMajor() << "|" << endl;	
			}
			break;
		}
		else if (choice == "4") {
			cout << "���еļ�����ʦ��Ϣ���£�" << endl;
			for (auto it = vTechnician.begin(); it < vTechnician.end(); it++) {
				cout << setw(5) << left << index++
					<< "| ��ţ�" << setw(7) << left << it->GetTeacherId()
					<< "| ������" << setw(10) << it->GetName()
					<< "| ���룺" << setw(12) << it->GetPassword() << "|" << endl;
			}
			break;
		}
		else if (choice == "0") {     ///���������Ӳ˵�
			system("cls");
			return;
		}
		else {
			cout << "-----------------------------------" << endl;
			cout << "|      �����������������룡     |" << endl;
			cout << "-----------------------------------" << endl;
		}
		}
		int select = -1;     ///��һ�����ͬ������������Լ������Ϸ���
		string change;

		index--;     ///�����һ��������һ����֤�߽���ȷ
		while (1) {
			cout << "��������Ҫɾ�����û���ţ�0�����أ� ";
			cin >> change;
			try {
				select = stoi(change);
				if (select<0 || select>index) {
					cout << "-----------------------------------" << endl;
					cout << "|      �����������������룡     |" << endl;
					cout << "-----------------------------------" << endl;
				}
				else if (select == 0) {
					system("cls");
					return;
				}
				else {
					break;
				}
			}
			catch (...) {
				cout << "-----------------------------------" << endl;
				cout << "|      �����������������룡     |" << endl;
				cout << "-----------------------------------" << endl;
			}

		}
		if (choice == "1") {     ///�����������Ϸ�����ɺ󣬽����ļ������Ĳ��֣�Ҳ�Ǻ��Ĳ��֣�������ɾ����ͨѧ���û�Ϊ��
			ofstream ofs(TEMP_FILE, ios::out | ios::trunc);     ///ofs����ʱ�ĵ��ļ���������ĵ�
			ifstream ifs(NORMALSTUDNET_FILE, ios::in);     ///ifs����ͨѧ���ĵ��ļ���Ĭ�ϴ�ͷ��ʼ��ȡ
			string id;     ///�ĸ����������Զ�ȡ�ĵ��е�ѧ�ţ����֣����룬רҵ
			string name;
			string password;
			string major;
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {     ///��ifs���ĵ��ж�ȡ�����ݲ�Ϊ��ʱ
				if (id != vNStudent[select - 1].GetStudentId()) {     ///���Һ��Ե�Ҫɾ����ĳ���û�����������ifs����ȡ�������ݣ�
					ofs << id << " " << name << " " << password << " " << major << endl;     ///ͬ����ofs������������д����ʱ�ĵ��У�����copy���ܣ�
				}
			}
			ofs.close();     ///�ж�ofs��ifs���ĵ���ϵ
			ifs.close();
			ofs.open(NORMALSTUDNET_FILE, ios::out | ios::trunc);     ///�����ĵ��ļ�������
			ifs.open(TEMP_FILE, ios::in);
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {     ///�ظ�������������ʱ��ʱ�ĵ�����û�С���ɾ���û���������
				ofs << id << " " << name << " " << password << " " << major << endl;     ///ԭ�ⲻ������ʱ�ĵ�copy����ͨѧ���ĵ��У��ﵽɾ���û����ݵĹ���
			}
			ofs.close();
			ifs.close();
			cout << "-----------------------------------" << endl;
			cout << "|           �û�ɾ���ɹ���        |" << endl;
			cout << "-----------------------------------" << endl;
			InitialVector();     ///ɾ������ȫ����ɺ�ͬ������������Ա���ݣ���ͬ��
		}
		if (choice == "2") {
			ofstream ofs(TEMP_FILE, ios::out | ios::trunc);
			ifstream ifs(MONITOR_FILE, ios::in);
			string id;
			string name;
			string password;
			string major;
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
				if (id != vMonitor[select - 1].GetStudentId()) {
					ofs << id << " " << name << " " << password << " " << major << endl;
				}
			}
			ofs.close();
			ifs.close();
			ofs.open(MONITOR_FILE, ios::out | ios::trunc);
			ifs.open(TEMP_FILE, ios::in);
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
				ofs << id << " " << name << " " << password << " " << major << endl;
			}
			ofs.close();
			ifs.close();

			cout << "-----------------------------------" << endl;
			cout << "|           �û�ɾ���ɹ���        |" << endl;
			cout << "-----------------------------------" << endl;
			InitialVector();
		}
		if (choice == "3") {
			ofstream ofs(TEMP_FILE, ios::out | ios::trunc);
			ifstream ifs(COUNSELLOR_FILE, ios::in);
			string id;
			string name;
			string password;
			string major;
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
				if (id != vCounsellor[select - 1].GetTeacherId()) {
					ofs << id << " " << name << " " << password << " " << major << endl;
				}
			}
			ofs.close();
			ifs.close();
			ofs.open(COUNSELLOR_FILE, ios::out | ios::trunc);
			ifs.open(TEMP_FILE, ios::in);
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
				ofs << id << " " << name << " " << password << " " << major << endl;
			}
			ofs.close();
			ifs.close();

			cout << "-----------------------------------" << endl;
			cout << "|           �û�ɾ���ɹ���        |" << endl;
			cout << "-----------------------------------" << endl;
			InitialVector();
		}
		if (choice == "4") {
			ofstream ofs(TEMP_FILE, ios::out | ios::trunc);
			ifstream ifs(TECHNICIAN_FILE, ios::in);
			string id;
			string name;
			string password;
			string major;
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
				if (id != vTechnician[select - 1].GetTeacherId()) {
					ofs << id << " " << name << " " << password << " " << "������Ա" << endl;
				}
			}
			ofs.close();
			ifs.close();
			ofs.open(TECHNICIAN_FILE, ios::out | ios::trunc);
			ifs.open(TEMP_FILE, ios::in);
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
				ofs << id << " " << name << " " << password << " " << "������Ա" << endl;
			}
			ofs.close();
			ifs.close();

			cout << "-----------------------------------" << endl;
			cout << "|           �û�ɾ���ɹ���        |" << endl;
			cout << "-----------------------------------" << endl;
			InitialVector();
		}
		system("pause");
		system("cls");
	}

//��Ա�������޸��û����������רҵ
void Manager::ChangeAccount()
{
	SortVector();
	cout << "-----------------------------------" << endl;
	cout << "|        ��ѡ���޸��û����ͣ�     |" << endl;
	cout << "|          1.��ͨѧ���û�         |" << endl;
	cout << "|          2.ѧ�������û�         |" << endl;
	cout << "|          3.����Ա�û�           |" << endl;
	cout << "|          4.������ʦ�û�         |" << endl;
	cout << "|          0.�����Ӳ˵�           |" << endl;
	cout << "-----------------------------------" << endl;
	string choice;
	int index = 1;     ///������ʾ��Ϣ����������ʼΪ1
	while (1) {
		cout << "����������ѡ��";
		cin >> choice;
		if (choice == "1") {
			cout << "������ͨѧ����Ϣ���£�" << endl;     ///ͨ��������Ʒ����ﵽ���������Ŀ��
			for (auto it = vNStudent.begin(); it < vNStudent.end(); it++) {
				cout << setw(5) << left << index++
					<< "| ѧ�ţ�" << setw(7) << left << it->GetStudentId()
					<< "| ������" << setw(10) << it->GetName()
					<< "| ���룺" << setw(12) << it->GetPassword()
					<< " | רҵ��" << setw(20) << it->GetMajor() << "|" << endl;
			}
			break;
		}
		else if (choice == "2") {
			cout << "���е�ѧ��������Ϣ���£�" << endl;
			for (auto it = vMonitor.begin(); it < vMonitor.end(); it++) {
				cout << setw(5) << left << index++
					<< "| ѧ�ţ�" << setw(7) << left << it->GetStudentId()
					<< "| ������" << setw(10) << it->GetName()
					<< "| ���룺" << setw(12) << it->GetPassword()
					<< " | רҵ��" << setw(20) << it->GetMajor() << "|" << endl;
			}
			break;
		}
		else if (choice == "3") {
			cout << "���еĸ���Ա��Ϣ���£�" << endl;
			for (auto it = vCounsellor.begin(); it < vCounsellor.end(); it++) {
				cout << setw(5) << left << index++
					<< "| ��ţ�" << setw(7) << left << it->GetTeacherId()
					<< "| ������" << setw(10) << it->GetName()
					<< "| ���룺" << setw(12) << it->GetPassword()
					<< " | רҵ��" << setw(20) << it->GetMajor() << "|" << endl;
			}
			break;
		}
		else if (choice == "4") {
			cout << "���еļ�����ʦ��Ϣ���£�" << endl;
			for (auto it = vTechnician.begin(); it < vTechnician.end(); it++) {
				cout << setw(5) << left << index++
					<< "| ��ţ�" << setw(7) << left << it->GetTeacherId()
					<< "| ������" << setw(10) << it->GetName()
					<< "| ���룺" << setw(12) << it->GetPassword() << "|" << endl;
			}
			break;
		}
		else if (choice == "0") {
			system("cls");
			return;
		}
		else {
			cout << "-----------------------------------" << endl;
			cout << "|      �����������������룡     |" << endl;
			cout << "-----------------------------------" << endl;
		}
	}
	index--;     ///��������һ����֤�߽���ȷ
	int select = -1;      ///��һ�����ͬ�����Լ������Ϸ��ԣ��ó����жദʹ�õ��˷�����
	string change;

	while (1) {
		cout << "��������Ҫ�޸���Ϣ���û���ţ�0�����أ� ";
		cin >> change;
		try {
			select = stoi(change);
			if (select<0 || select>index) {
				cout << "-----------------------------------" << endl;
				cout << "|      �����������������룡     |" << endl;
				cout << "-----------------------------------" << endl;
			}
			else if (select == 0) {
				system("cls");
				return;
			}
			else {
				break;
			}
		}
		catch (...) {
			cout << "-----------------------------------" << endl;
			cout << "|      �����������������룡     |" << endl;
			cout << "-----------------------------------" << endl;
		}

	}
	string finalchoice;     ///��������ѡ��Ҫ���ĵ���Ϣ�����뻹��רҵ
	string newPassword;     ///��������������
	string newMajor;        ///����������רҵ

	cout << "-----------------------------------" << endl;
	cout << "|        ��ѡ����Ҫ���ĵ���Ϣ��   |" << endl;
	cout << "|            1.����               |" << endl;
	cout << "|            2.רҵ               |" << endl;
	cout << "|            0.�����Ӳ˵�         |" << endl;
	cout << "-----------------------------------" << endl;
	while (1) {
		cout << "����������ѡ�� ";
		cin >> finalchoice;
		if (finalchoice == "1" || finalchoice == "2") {
			break;
		}
		if (finalchoice == "0") {
			system("cls");
			return;
		}
		else {
			cout << "-----------------------------------" << endl;
			cout << "|      �����������������룡     |" << endl;
			cout << "-----------------------------------" << endl;
		}
	}
	if (finalchoice == "1") {
		while (1) {
			cout << "�����������루10λ���ڣ��� ";
			cin >> newPassword;
			if (newPassword.size() > 0 && newPassword.size() <= 10) {     ///��֤����λ���߽���ȷ
				break;
			}
			else {
				cout << "-----------------------------------" << endl;
				cout << "|      �����������������룡     |" << endl;
				cout << "-----------------------------------" << endl;
			}
		}
	}
	else if (finalchoice == "2") {
		if (choice == "4") {     ///������ʦ���ܱ��޸�רҵ
			cout << "-----------------------------------------------------" << endl;
			cout << "| ��Ǹ��������ʦ�޷��޸�רҵ��Ϣ��Ĭ��Ϊ������Ա����|" << endl;
			cout << "-----------------------------------------------------" << endl;
			system("pause>nul");     ///��ͣ���������������pause��ǿ�ң���ʹ�����ڲ�ָ��
			system("cls");
			return;
		}
		while (1) {
			cout << "��������רҵ�� ";
			cin >> newMajor;
			if (newMajor.size() > 0 && newMajor.size() <= 15) {     ///��֤רҵ�ַ��������߽�
				break;
			}
			else {
				cout << "-----------------------------------" << endl;
				cout << "|      �����������������룡     |" << endl;
				cout << "-----------------------------------" << endl;
			}
		}
	}
							 ///������Ϊ�޸Ĳ�����Ҫ���֣���������̺����롰ɾ���û������ܴ��������
	if (choice == "1") {     ///��ͨѧ���Ķ�
		ofstream ofs(TEMP_FILE, ios::out | ios::trunc);
		ifstream ifs(NORMALSTUDNET_FILE, ios::in);
		string id;
		string name;
		string password;
		string major;
		if (finalchoice == "1") {     ///�Ķ�����
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
				if (id != vNStudent[select - 1].GetStudentId()) {     ///��ͬ�����ڣ�д�������ж�������һ��
					ofs << id << " " << name << " " << password << " " << major << endl;
				}
				if (id == vNStudent[select - 1].GetStudentId()) {
					ofs << id << " " << name << " " << newPassword << " " << major << endl;
				}
			}
		}
		else if (finalchoice == "2") {     ///�Ķ�רҵ����ͬ��
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
				if (id != vNStudent[select - 1].GetStudentId()) {
					ofs << id << " " << name << " " << password << " " << major << endl;
				}
				if (id == vNStudent[select - 1].GetStudentId()) {
					ofs << id << " " << name << " " << password << " " << newMajor << endl;
				}
			}
		}
			ofs.close();
			ifs.close();
			ofs.open(NORMALSTUDNET_FILE, ios::out | ios::trunc);
			ifs.open(TEMP_FILE, ios::in);
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
				ofs << id << " " << name << " " << password << " " << major << endl;
			}
			ofs.close();
			ifs.close();
			cout << "-----------------------------------" << endl;
			cout << "|         �û���Ϣ�Ķ��ɹ���      |" << endl;
			cout << "-----------------------------------" << endl;
			InitialVector();
	}
	else if (choice == "2") {     ///ѧ������Ķ�
		ofstream ofs(TEMP_FILE, ios::out | ios::trunc);
		ifstream ifs(MONITOR_FILE, ios::in);
		string id;
		string name;
		string password;
		string major;
		if (finalchoice == "1") {
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
				if (id != vMonitor[select - 1].GetStudentId()) {
					ofs << id << " " << name << " " << password << " " << major << endl;
				}
				if (id == vMonitor[select - 1].GetStudentId()) {
					ofs << id << " " << name << " " << newPassword << " " << major << endl;
				}
			}
		}
		else if (finalchoice == "2") {
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
				if (id != vMonitor[select - 1].GetStudentId()) {
					ofs << id << " " << name << " " << password << " " << major << endl;
				}
				if (id == vMonitor[select - 1].GetStudentId()) {
					ofs << id << " " << name << " " << password << " " << newMajor << endl;
				}
			}
		}
		ofs.close();
		ifs.close();
		ofs.open(MONITOR_FILE, ios::out | ios::trunc);
		ifs.open(TEMP_FILE, ios::in);
		while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
			ofs << id << " " << name << " " << password << " " << major << endl;
		}
		ofs.close();
		ifs.close();
		cout << "-----------------------------------" << endl;
		cout << "|         �û���Ϣ�Ķ��ɹ���      |" << endl;
		cout << "-----------------------------------" << endl;
		InitialVector();
	}
	else if (choice == "3") {     ///����Ա�Ķ�
		ofstream ofs(TEMP_FILE, ios::out | ios::trunc);
		ifstream ifs(COUNSELLOR_FILE, ios::in);
		string id;
		string name;
		string password;
		string major;
		if (finalchoice == "1") {
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
				if (id != vCounsellor[select - 1].GetTeacherId()) {
					ofs << id << " " << name << " " << password << " " << major << endl;
				}
				if (id == vCounsellor[select - 1].GetTeacherId()) {
					ofs << id << " " << name << " " << newPassword << " " << major << endl;
				}
			}
		}
		else if (finalchoice == "2") {
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
				if (id != vCounsellor[select - 1].GetTeacherId()) {
					ofs << id << " " << name << " " << password << " " << major << endl;
				}
				if (id == vCounsellor[select - 1].GetTeacherId()) {
					ofs << id << " " << name << " " << password << " " << newMajor << endl;
				}
			}
		}
		ofs.close();
		ifs.close();
		ofs.open(COUNSELLOR_FILE, ios::out | ios::trunc);
		ifs.open(TEMP_FILE, ios::in);
		while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
			ofs << id << " " << name << " " << password << " " << major << endl;
		}
		ofs.close();
		ifs.close();

		cout << "-----------------------------------" << endl;
		cout << "|         �û���Ϣ�Ķ��ɹ���      |" << endl;
		cout << "-----------------------------------" << endl;
		InitialVector();
	}
	else if (choice == "4") {     ///������ʦ�Ķ�
		ofstream ofs(TEMP_FILE, ios::out | ios::trunc);
		ifstream ifs(TECHNICIAN_FILE, ios::in);
		string id;
		string name;
		string password;
		string major;
		if (finalchoice == "1") {
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
				if (id != vTechnician[select - 1].GetTeacherId()) {
					ofs << id << " " << name << " " << password << " " << major << endl;
				}
				if (id == vTechnician[select - 1].GetTeacherId()) {
					ofs << id << " " << name << " " << newPassword << " " << major << endl;
				}
			}
		}
		else if (finalchoice == "2") {
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
				if (id != vTechnician[select - 1].GetTeacherId()) {
					ofs << id << " " << name << " " << password << " " << major << endl;
				}
				if (id == vTechnician[select - 1].GetTeacherId()) {
					ofs << id << " " << name << " " << password << " " << newMajor << endl;
				}
			}
		}
		ofs.close();
		ifs.close();
		ofs.open(TECHNICIAN_FILE, ios::out | ios::trunc);
		ifs.open(TEMP_FILE, ios::in);
		while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
			ofs << id << " " << name << " " << password << " " << "������Ա" << endl;
		}
		ofs.close();
		ifs.close();

		cout << "-----------------------------------" << endl;
		cout << "|         �û���Ϣ�Ķ��ɹ���      |" << endl;
		cout << "-----------------------------------" << endl;
		InitialVector();
	}
	system("pause");
	system("cls");
}

//��Ա�������鿴�����û�
void Manager::CheckAllAccount()
{
	SortVector();     ///���û�����Ŵ�С����
	int sum = vNStudent.size() + vMonitor.size() + vCounsellor.size() + vTechnician.size();     ///��չʾ�����û�����
	cout << endl;
	cout << "����Ϊ�û���������" << sum << endl;
	cout << "����,�������������£�" << endl;
	cout << "��ͨѧ���û�������" << vNStudent.size() << endl;
	cout << "ѧ�������û�������" << vMonitor.size() << endl;
	cout << "����Ա�û�������" << vCounsellor.size() << endl;
	cout << "������ʦ�û�������" << vTechnician.size() << endl;
	cout << endl;

	cout << "-----------------------------------" << endl;
	cout << "|         ��ѡ��鿴���ݣ�        |" << endl;
	cout << "|         1.��ͨѧ���û���Ϣ      |" << endl;
	cout << "|         2.ѧ�������û���Ϣ      |" << endl;
	cout << "|         3.����Ա�û���Ϣ        |" << endl;
	cout << "|         4.������ʦ�û���Ϣ      |" << endl;
	cout << "|         0.�����Ӳ˵�            |" << endl;
	cout << "-----------------------------------" << endl;
	string choice;
	while (1) {
		cout << "����������ѡ��";
		cin >> choice;
		if (choice == "1") {
			if (vNStudent.size() == 0) {
				cout << "-----------------------------------" << endl;
				cout << "|         ������ͨѧ���û���      |" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			cout << "������ͨѧ����Ϣ����(Ĭ����ѧ��˳������)��" << endl;
			cout << endl;
			for (auto it = vNStudent.begin(); it != vNStudent.end(); it++) {
				cout << "| ѧ�ţ�" << setw(7) << left << it->GetStudentId()
					<< "| ���֣�" << setw(10) << left << it->GetName()
					<< "| ���룺" << setw(12) << left << it->GetPassword()
					<< "| רҵ��" << setw(20) << left << it->GetMajor() << "|" << endl;
			}
			break;
		}
		else if (choice == "2") {
			if (vMonitor.size() == 0) {
				cout << "-----------------------------------" << endl;
				cout << "|         ����ѧ�������û���      |" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			cout << "���е�ѧ��������Ϣ����(Ĭ����ѧ��˳������)��" << endl;
			cout << endl;
			for (auto it = vMonitor.begin(); it != vMonitor.end(); it++) {
				cout << "| ѧ�ţ�" << setw(7) << left << it->GetStudentId()
					<< "| ���֣�" << setw(10) << left << it->GetName()
					<< "| ���룺" << setw(12) << left << it->GetPassword()
					<< "| רҵ��" << setw(20) << left << it->GetMajor() << "|" << endl;
			}
			break;
		}
		else if (choice == "3") {
			if (vCounsellor.size() == 0) {
				cout << "-----------------------------------" << endl;
				cout << "|          ���޸���Ա�û���       |" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			cout << "���еĸ���Ա��Ϣ����(Ĭ���Ա��˳������)��" << endl;
			cout << endl;
			for (auto it = vCounsellor.begin(); it != vCounsellor.end(); it++) {
				cout << "| ��ţ�" << setw(7) << left << it->GetTeacherId()
					<< "| ���֣�" << setw(10) << left << it->GetName()
					<< "| ���룺" << setw(12) << left << it->GetPassword()
					<< "| רҵ��" << setw(20) << left << it->GetMajor() << "|" << endl;
			}
			break;
		}
		else if (choice == "4") {
			if (vTechnician.size() == 0) {
				cout << "-----------------------------------" << endl;
				cout << "|         ���޼�����ʦ�û���      |" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			cout << "���еļ�����ʦ��Ϣ����(Ĭ���Ա��˳������)��" << endl;
			cout << endl;
			for (auto it = vTechnician.begin(); it != vTechnician.end(); it++) {
				cout << "| ��ţ�" << setw(7) << left << it->GetTeacherId()
					<< "| ���֣�" << setw(10) << left << it->GetName()
					<< "| ���룺" << setw(12) << left << it->GetPassword() << "|" << endl;
			}
			break;
		}
		else if (choice == "0") {
			system("cls");
			return;
		}
		else {
			cout << "-----------------------------------" << endl;
			cout << "|      �����������������룡     |" << endl;
			cout << "-----------------------------------" << endl;
		}
	}
	system("pause");
	system("cls");
}

//��Ա�������������ֻ���רҵ�����û�,ʹ��������ʽ��ģ������
void Manager::FindAccount()
{
	cout << "-----------------------------------" << endl;
	cout << "|      ��ѡ��Ҫ���Ҷ������ݣ�   |" << endl;
	cout << "|          1.��ͨѧ���û�         |" << endl;
	cout << "|          2.ѧ�������û�         |" << endl;
	cout << "|          0.�����Ӳ˵�           |" << endl;
	cout << "-----------------------------------" << endl;
	
	string select;     ///��һ��������Լ������Ϸ���
	int change = -1;

	while (1) {
		cout << "����������ѡ��";
		cin >> select;
		try {
			change = stoi(select);
			if (change > 0 && change <= 2) {
				break;
			}
			else if (change == 0) {
				system("cls");
				return;
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
	cout << "-----------------------------------" << endl;
	cout << "|     ��ѡ���������ַ�ʽ���ң�  |" << endl;
	cout << "|          1.�����ֲ���           |" << endl;
	cout << "|          2.��רҵ����           |" << endl;
	cout << "-----------------------------------" << endl;
	string choice;     ///�������밴���ֻ��ǰ�רҵ����
	while (1) {
		int index = 1;
		bool flag = 0;     ///�Ƿ��з����������û�������ҵ��ͼ�Ϊ1��û��Ĭ��Ϊ0
		cout << "����������ѡ��,0�����أ� ";
		cin >> choice;
		if (choice == "0") {
			system("cls");
			return;
		}
		else if (select=="1"&&choice == "1") {
			string name;
			cout << "������Ҫ���ҵ���ͨѧ�������֣�";
			
			cin.ignore(); 
			getline(cin, name);      ///ʹ��getline��ȡ�����ո����������
			string pattern = ".*" + name + ".*";     ///����������ʽ�ĸ�ʽ
			regex change(pattern, regex_constants::icase);      ///���Դ�Сд

			for (int i = 0; i < vNStudent.size(); i++) {
				if (regex_search(vNStudent[i].GetName(),change)) {     ///ģ������change�����ݣ��ж�Ӧ�ַ����־�ִ����䣨��ͬ��
					cout << "[" << index++ << "] " << endl;
					cout << "ѧ�ţ�" << vNStudent[i].GetStudentId() << endl;
					cout << "������" << vNStudent[i].GetName() << endl;
					cout << "���룺" << vNStudent[i].GetPassword() << endl;
					cout << "רҵ��" << vNStudent[i].GetMajor() << endl;
					cout << "-------------------" << endl;
					flag = 1;
				}
			}
			if (flag) {
				cout << "-----------------------------------" << endl;
				cout << "|       ��Ϊ�����ҵ������û�!     |" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			cout << endl;
			cout << "----------------------------------------" << endl;
			cout << "| ��Ǹ����ʱû�в��ҵ���ҪѰ�ҵĶ��� |" << endl;
			cout << "----------------------------------------" << endl;
		}
		else if (select=="1"&&choice == "2") {
			string major;
			cout << "������Ҫ���ҵ���ͨѧ����רҵ��";
			cin.ignore();
			getline(cin, major);
			string pattern = ".*" + major + ".*";
			regex change(pattern, regex_constants::icase);
			for (int i = 0; i < vNStudent.size(); i++) {
				if (regex_search(vNStudent[i].GetMajor(), change)) {
					cout << "[" << index++ << "] " << endl;
					cout << "ѧ�ţ�" << vNStudent[i].GetStudentId() << endl;
					cout << "������" << vNStudent[i].GetName() << endl;
					cout << "���룺" << vNStudent[i].GetPassword() << endl;
					cout << "רҵ��" << vNStudent[i].GetMajor() << endl;
					cout << "-------------------" << endl;
					flag = 1;
				}
			}
			if (flag) {
				cout << "-----------------------------------" << endl;
				cout << "|       ��Ϊ�����ҵ������û�!     |" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			cout << endl;
			cout << "----------------------------------------" << endl;
			cout << "| ��Ǹ����ʱû�в��ҵ���ҪѰ�ҵĶ��� |" << endl;
			cout << "----------------------------------------" << endl;
			break;
		}
		else if (select == "2" && choice == "1") {
			string name;
			cout << "������Ҫ���ҵ�ѧ����������֣�";
			cin.ignore(); 
			getline(cin, name); 
			string pattern = ".*" + name + ".*";
			regex change(pattern, regex_constants::icase); 
			for (int i = 0; i < vMonitor.size(); i++) {
				if (regex_search(vMonitor[i].GetName(),change)) {
					cout << "[" << index++ << "] " << endl;
					cout << "ѧ�ţ�" << vMonitor[i].GetStudentId() << endl;
					cout << "������" << vMonitor[i].GetName() << endl;
					cout << "���룺" << vMonitor[i].GetPassword() << endl;
					cout << "רҵ��" << vMonitor[i].GetMajor() << endl;
					cout << "-------------------" << endl;
					flag = 1;
				}
			}
			if (flag) {
				cout << "-----------------------------------" << endl;
				cout << "|       ��Ϊ�����ҵ������û�!     |" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			cout << endl;
			cout << "----------------------------------------" << endl;
			cout << "| ��Ǹ����ʱû�в��ҵ���ҪѰ�ҵĶ��� |" << endl;
			cout << "----------------------------------------" << endl;
		}
		else if (select == "2" && choice == "2") {
			string major;
			cout << "������Ҫ���ҵ���ͨѧ����רҵ��";
			cin.ignore();
			getline(cin, major);
			string pattern = ".*" + major + ".*";
			regex change(pattern, regex_constants::icase);
			for (int i = 0; i < vMonitor.size(); i++) {
				if (regex_search(vMonitor[i].GetMajor(),change)) {
					cout << "[" << index++ << "] " << endl;
					cout << "ѧ�ţ�" << vMonitor[i].GetStudentId() << endl;
					cout << "������" << vMonitor[i].GetName() << endl;
					cout << "���룺" << vMonitor[i].GetPassword() << endl;
					cout << "רҵ��" << vMonitor[i].GetMajor() << endl;
					cout << "-------------------" << endl;
					flag = 1;
				}
			}
			if (flag) {
				cout << "-----------------------------------" << endl;
				cout << "|       ��Ϊ�����ҵ������û�!     |" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			cout << endl;
			cout << "----------------------------------------" << endl;
			cout << "| ��Ǹ����ʱû�в��ҵ���ҪѰ�ҵĶ��� |" << endl;
			cout << "----------------------------------------" << endl;
			break;
		}

		else {
			cout << "-----------------------------------" << endl;
			cout << "|      �����������������룡     |" << endl;
			cout << "-----------------------------------" << endl;
		}
	}
	system("pause");
	system("cls");
}

//��Ա�������鿴����
void Manager::CheckClassroom()
{
	cout << "���еĽ�����Ϣ���£�" << endl;     ///ʹ��������Ʒ������������������
	for (auto it = vClassroom.begin(); it < vClassroom.end(); it++) {
		cout << "���ұ�ţ�" << setw(7) <<left<< it->GetId() 
			<< "| ������������" <<setw(10)<<left<< it->GetVolume() << endl;
	}
	system("pause");
	system("cls");
}

//��Ա�������������ԤԼ��¼
void Manager::ClearAllBook()
{
	cout << "-----------------------------------" << endl;     ///�ٴ�ȷ���Ƿ�Ҫ��գ���ֹ�󴥶�ɾ������ɾ���ļ�¼
	cout << "|���ٴ�ȷ���Ƿ�Ҫ�������ԤԼ��¼��|" << endl;
	cout << "|           1.ȷ�����             |" << endl;
	cout << "|           0.�����Ӳ˵�           |" << endl;
	cout << "-----------------------------------" << endl;
	cout << "����������ѡ��";
	int choice = -1;
	string change;
	while (1) {
		cin >> change;
		try {     ///ͬ���ж�����ĺϷ����
			choice = stoi(change);
			if (choice == 1) {
				ofstream ofs;
				ofs.open(BOOK_FILE, ios::trunc);     ///��trunc��ʽ���ļ����
				ofs.close();
				cout << "-----------------------------------" << endl;
				cout << "|       ԤԼ��Ϣ�Ѿ�ȫ����գ�    |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				break;
			}
			if (choice == 0) {     ///�����Ӳ˵�
				system("cls");
				return;
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
}

//��Ա��������ʼ�����߸��¸���洢���ݵ�������Ա
void Manager::InitialVector()
{
	vNStudent.clear();     ///�ȶ�����vector���ݳ�Ա��գ���ֹ�������ʱ�ص�����
	vMonitor.clear();
	vCounsellor.clear();
	vTechnician.clear();
	vClassroom.clear();

	ifstream ifs(NORMALSTUDNET_FILE, ios::in);     ///����ͨѧ����Ϣ����vector��
	if (!ifs.is_open()) {     ///ͬ�����ļ��Ĵ���������飬���û���ļ�������ʾ��ȡʧ��
		cout << "-----------------------------------" << endl;
		cout << "|           �ļ���ȡʧ�ܣ�        |" << endl;
		cout << "-----------------------------------" << endl;
		return;
	}
	normalStudent s;
	while (ifs >> s.GetStudentId() &&ifs>> s.GetName() && ifs>>s.GetPassword()&&ifs>>s.GetMajor()) {
		vNStudent.push_back(s);
	}
	ifs.close();

	ifs.open(MONITOR_FILE, ios::in);      ///��ѧ��������Ϣ
	if (!ifs.is_open()) {
		cout << "-----------------------------------" << endl;
		cout << "|           �ļ���ȡʧ�ܣ�        |" << endl;
		cout << "-----------------------------------" << endl;
		return;
	}
	Monitor m;
	while (ifs >> m.GetStudentId() && ifs >> m.GetName() && ifs >> m.GetPassword()&&ifs>>m.GetMajor()) {
		vMonitor.push_back(m);
	}
	ifs.close();

	ifs.open(COUNSELLOR_FILE, ios::in);     ///�渨��Ա��Ϣ
	if (!ifs.is_open()) {
		cout << "-----------------------------------" << endl;
		cout << "|           �ļ���ȡʧ�ܣ�        |" << endl;
		cout << "-----------------------------------" << endl;
		return;
	}
	Counsellor co;
	while (ifs >> co.GetTeacherId() &&ifs>> co.GetName() && ifs>> co.GetPassword()&&ifs>>co.GetMajor()) {
		vCounsellor.push_back(co);
	}
	ifs.close();

	ifs.open(TECHNICIAN_FILE, ios::in);     ///�漼����ʦ��Ϣ
	if (!ifs.is_open()) {
		cout << "-----------------------------------" << endl;
		cout << "|           �ļ���ȡʧ�ܣ�        |" << endl;
		cout << "-----------------------------------" << endl;
		return;
	}
	Technician te;
	while (ifs >> te.GetTeacherId() && ifs >> te.GetName() && ifs >> te.GetPassword()&&ifs>>te.GetMajor()) {
		vTechnician.push_back(te);
	}
	ifs.close();

	ifs.open(CLASSROOM_FILE, ios::in);     ///�������Ϣ
	Classroom c;
	while (ifs >> c.GetId() && ifs >> c.GetVolume()) {
		vClassroom.push_back(c);
	}
	ifs.close();
}

//��Ա��������������Ա�������˳������
void Manager::SortVector()
{
	if (vNStudent.size() != 0) {     ///Ŀǰ���õ���ð�������㷨
		for (size_t i = 0; i < vNStudent.size() - 1; i++) {
			for (size_t j = 0; j < vNStudent.size() - i - 1; j++) {
				if (stoi(vNStudent[j].GetStudentId()) > stoi(vNStudent[j + 1].GetStudentId())) {
					swap(vNStudent[j], vNStudent[j + 1]);
				}
			}
		}
	}
	if (vMonitor.size() != 0) {
		for (size_t i = 0; i < vMonitor.size() - 1; i++) {
			for (size_t j = 0; j < vMonitor.size() - i - 1; j++) {
				if (stoi(vMonitor[j].GetStudentId()) > stoi(vMonitor[j + 1].GetStudentId())) {
					swap(vMonitor[j], vMonitor[j + 1]);
				}
			}
		}
	}
	if (vCounsellor.size() != 0) {
		for (size_t i = 0; i < vCounsellor.size() - 1; i++) {
			for (size_t j = 0; j < vCounsellor.size() - i - 1; j++) {
				if (stoi(vCounsellor[j].GetTeacherId()) > stoi(vCounsellor[j + 1].GetTeacherId())) {
					swap(vCounsellor[j], vCounsellor[j + 1]);
				}
			}
		}
	}
	if (vTechnician.size() != 0) {
		for (size_t i = 0; i < vTechnician.size() - 1; i++) {
			for (size_t j = 0; j < vTechnician.size() - i - 1; j++) {
				if (stoi(vTechnician[j].GetTeacherId()) > stoi(vTechnician[j + 1].GetTeacherId())) {
					swap(vTechnician[j], vTechnician[j + 1]);
				}
			}
		}
	}
}

//��Ա����������û�Ψһ��
bool Manager::CheckAccountNotOnly(string id, string choice)
{
	///����������1.string��id�����Աȶ��ĵ���id
	///          2.string��choice�������ж����

	if (choice == "1"&& vNStudent.size()!=0) {     ///������ţ�ͨ���Ƚ���ź�������������ţ�������ڣ��򷵻�true�����򣬷���false(���������ڴ�С��ǰ���£�
		for (auto it = vNStudent.begin(); it != vNStudent.end(); it++) {
			if (stoi(it->GetStudentId()) == stoi(id)) {
				return true;
			}
		}
	}
	else if (choice == "2" && vMonitor.size() != 0) {
		for (auto it = vMonitor.begin(); it != vMonitor.end(); it++) {
			if (stoi(it->GetStudentId()) == stoi(id)) {
				return true;
			}
		}
	}
	else if (choice == "3" && vCounsellor.size() != 0) {
		for (auto it = vCounsellor.begin(); it != vCounsellor.end(); it++) {
			if (stoi(it->GetTeacherId()) == stoi(id)) {
				return true;
			}
		}
	}
	else if (choice == "4" && vTechnician.size() != 0) {
		for (auto it = vTechnician.begin(); it != vTechnician.end(); it++) {
			if (stoi(it->GetTeacherId()) == stoi(id))  {
				return true;
			}
		}
	}
	return false;
}
 