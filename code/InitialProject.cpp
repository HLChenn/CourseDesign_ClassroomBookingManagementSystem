#include"InitialProject.h"

//��ͨ��������ʼ�����˵����ڣ�������¼��ע�ᣬ�˳�ϵͳ������
void RunMainMenu()
{
	while (true) {     ///whileѭ�������ֱ�������˳�ϵͳ������break
		
		string firstchoice;     ///����ѡ��������ֱ��Ӧ����ifѡ��
		string secondchoice;	///1.firstchoice��Ӧ��¼��ע�ᣬ�˳�ϵͳ
		string thirdchoice;		///2.secondchoice��Ӧѧ������ʦ������Ա������ݣ����У�����Ա�ڴ˲�����¼ҳ�棩
								///3.thirdchoice��Ӧ����ͨѧ����ѧ��������������Ա��������ʦ��������ݣ����ڴ˲�����¼ҳ��

		cout << "-----------------------------------" << endl;
		cout << "|    ��ӭ����������Ԥ������ϵͳ   |" << endl;
		cout << "|            ��ѡ�������         |" << endl;
		cout << "|            1.��¼               |" << endl;
		cout << "|            2.ע��               |" << endl;
		cout << "|            0.�˳�ϵͳ           |" << endl;
		cout << "-----------------------------------" << endl;
		cout << "����������ѡ��" ;
		cin >> firstchoice;
		if (firstchoice == "1") {     ///1.��¼�����ѡ��

			cout << "-----------------------------------" << endl;
			cout << "|       ����������������ͣ�      |" << endl;
			cout << "|            1.ѧ��               |" << endl;
			cout << "|            2.��ʦ               |" << endl;
			cout << "|            3.����Ա             |" << endl;
			cout << "|            0.�������˵�         |" << endl;
			cout << "-----------------------------------" << endl;
			cout << "����������ѡ��" ;
			cin >> secondchoice;

			if (secondchoice == "1") {
				cout << "-----------------------------------" << endl;
				cout << "|       ���������ľ�������ǣ�    |" << endl;
				cout << "|            1.��ͨѧ��           |" << endl;
				cout << "|            2.ѧ������           |" << endl;
				cout << "-----------------------------------" << endl;
				cout << "����������ѡ��";
				cin >> thirdchoice;

				if (thirdchoice == "1") {     ///˫�����ѡ����ϲ��������Ϊ�Ϸ�������ͨ��Login����������Ӧ������ݵĵ�¼ҳ��
					Login(NORMALSTUDNET_FILE, 1, 1);
				}
				else if (thirdchoice == "2") {
					Login(MONITOR_FILE, 1, 2);
				}
				else {     ///����Ϸ��Լ��
					cout << "-----------------------------------" << endl;
					cout << "|      �����������������룡     |" << endl;
					cout << "-----------------------------------" << endl;
					system("pause");
					system("cls");
				}
			}
			else if (secondchoice == "2") {
				cout << "-----------------------------------" << endl;
				cout << "|         ���������ļ����ǣ�      |" << endl;
				cout << "|             1.����Ա            |" << endl;
				cout << "|             2.������ʦ          |" << endl;
				cout << "-----------------------------------" << endl;
				cout << "����������ѡ��" ;
				cin >> thirdchoice;
				
				if (thirdchoice == "1") {
					Login(COUNSELLOR_FILE, 2, 1);
				}
				else if (thirdchoice == "2") {
					Login(TECHNICIAN_FILE, 2, 2);
				}
				else {
					cout << "-----------------------------------" << endl;
					cout << "|      �����������������룡     |" << endl;
					cout << "-----------------------------------" << endl;
					system("pause");
					system("cls");
				}
			}
			else if (secondchoice == "3") {
				Login(MANAGER_FILE, 3, 1);
			}
			else if (secondchoice == "0") {
				system("pause");
				system("cls");
			}
			else {     ///���벻�Ϸ�������������
				cout << "-----------------------------------" << endl;
				cout << "|      �����������������룡     |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
			}
		}
		else if (firstchoice == "2") {     ///2.ע������ѡ��
			Manager man("ad","1", "��ʱϵͳ����Ա");     ///����Manager����ʱ����man������ɹ��ܺ����ö��󣬶����������Ĺ���Ա�˺ţ�admin������֤����Ա�˺�����
			man.AddAccount();     ///ͨ��man�������ע���û�����
		}
		else if (firstchoice == "0") {     ///3.�˳�ϵͳ
			cout << "-----------------------------------" << endl;
			cout << "|         ��ӭ��һ��ʹ��!         |" << endl;
			cout << "-----------------------------------" << endl;
			return;
		}
		else {     ///����Ϸ����ж�
			cout << "-----------------------------------" << endl;
			cout << "|      �����������������룡     |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
		}
	}
}

//��ͨ��������¼���ڣ�ͨ��������ţ����֣����룬�������֤�ɹ�������Ӧ�Ӳ˵�
void Login(string fileName, int choice, int select) {

	///�ú�����������������
    ///1.fileName�����ܴ���õ�¼������͵��ı����֣����Զ�ȡ�ļ����ݣ�ʵ�������֤
    ///2.choice���ж���ѧ�����࣬��ʦ���࣬���Ǹ���Ա��
    ///3.select���ж��ǣ���ͨѧ����ѧ���������ǣ�����Ա��������ʦ��

	User* person = NULL;  ///�����û���ָ�룬���ں����ڷ�֧ʱͳһ�����ָ��ͬ�����������
	ifstream ifs;
	ifs.open(fileName, ios::in);  	
	if (!ifs.is_open()) {     ///���ļ��Ƿ�������ж�
		cout << "-----------------------------------" << endl;
		cout << "|           �ļ���������          |" << endl;
		cout << "-----------------------------------" << endl;
		ifs.close();
		return;
	}
	
	string id;  	///׼�������û�����Ϣ����ţ����֣�����
	string name;
	string password;

	if (choice == 1) {
		cout << "���������ѧ�ţ�";
		cin >> id;
	}
	else if (choice == 2) {
		cout << "��������ı�ţ�";
		cin >> id;
	}

	cout << "�������û�����";
	cin >> name;
	while (1) {     ///��������ʱ�б��ܹ��ܣ����������ݣ���ֻ��ʾ��*��
		password.clear();	  ///��ÿ�ν���ѭ��ʱ�����password
		cout << "����������(ʮλ����)�� ";
		char key;
		while (key = _getch()) {     ///�Ӽ����еõ������һ���ַ�����ֵ��key�����������Ļ��
			if (key == 13) {     ///���key���ַ�תΪascall���Ϊ13�������з�����������������С��Ϊ0����break��������Ϊ��������
				if (password.size() != 0) {
					break;
				}
				else {
					cout << "-----------------------------------" << endl;
					cout << "|       �����������������룡    |" << endl;
					cout << "-----------------------------------" << endl;
				}
			}
			else if (key != '\b') {     ///���key�����˸������ô����password��string�ͣ�β����key��������Ļ�������*��
				password += key;
				cout << "*";
			}
			else if (key == '\b' && password.size() > 0) {    ///���key���˸�������Ҵ�ʱpassword��С��Ϊ0��������Ļ������˸����������ո������ԭ�����ַ���Ȼ��������˸����ʵ������Ļ�ϵġ�ɾ��������
				cout << "\b \b";
				password = password.substr(0, password.size() - 1);     ///ͬ��ɾ��password�����һλ���ַ�
			}
		}
		cout << endl;
		if (password.size() <= 10) {     ///�������λ����10����break
			break;
		}
		else {
			cout << "-----------------------------------" << endl;
			cout << "|       ���볬�ޣ����������룡    |" << endl;
			cout << "-----------------------------------" << endl;
		}
	}

	string fid;     ///������ȡ�ļ�����������ĸ�string�������ֱ��ȡ��ţ����֣����룬רҵ
	string fname;
	string fpassword;
	string fmajor;

	if (choice == 1) {
		if (select == 1) {
			while (ifs >> fid && ifs >> fname && ifs >> fpassword && ifs >> fmajor) {     ///�Ӷ�Ӧ�ļ��ж�ȡ�ĸ��ַ������ݣ���û���ٶ�����Ч���ݣ�while����ִ�У������������Ʒ�֧Ҳͬ��
				if (id == fid && name == fname && password == fpassword) {     ///������������������������һһ��Ӧʱ���ж�Ϊ��֤��¼�ɹ��������Ӳ˵�����ͬ��
					cout << "-----------------------------------" << endl;
					cout << "|       ��ͨѧ����֤��¼�ɹ���    |" << endl;
					cout << "-----------------------------------" << endl;
					system("pause");     ///�����������
					system("cls");     ///���������ڽ�����һ��ҳ���������ͬ��
					person = new normalStudent(id, name, password, "��ͨѧ��", fmajor);     ///ͨ��person��̬����normalStudent����󣬲����γ�ʼ����ֵ
					normalStudentMenu(person);     ///������ͨѧ����ݵ��Ӳ˵���
					return;     ///��ע���˺ź����ش���䣬�����ص����˵�ҳ�棨��ͬ��
				}
			}
		}
		if (select == 2) {
			while (ifs >> fid && ifs >> fname && ifs >> fpassword && ifs >> fmajor) {
				if (id == fid && name == fname && password == fpassword) {
					cout << "-----------------------------------" << endl;
					cout << "|       ѧ��������֤��¼�ɹ���    |" << endl;
					cout << "-----------------------------------" << endl;
					system("pause");
					system("cls");
					person = new Monitor(id, name, password, "ѧ������", fmajor);     ///ͨ��person��̬����Monitor����󣬲����γ�ʼ����ֵ
					MonitorMenu(person);     ///����ѧ��������ݵ��Ӳ˵���
					return;
				}
			}
		}
	}
	else if (choice == 2) {
		if (select == 1) {
			while (ifs >> fid && ifs >> fname && ifs >> fpassword && ifs >> fmajor) {
				if (id == fid && name == fname && password == fpassword) {
					cout << "-----------------------------------" << endl;
					cout << "|        ����Ա��֤��¼�ɹ���     |" << endl;
					cout << "-----------------------------------" << endl;
					system("pause");
					system("cls");
					person = new Counsellor(id, name, password, fmajor);     ///ͨ��person��̬����Counsellor����󣬲����γ�ʼ����ֵ
					CounsellorMenu(person);     ///���븨��Ա��ݵ��Ӳ˵���
					return;
				}
			}
		}
		if (select == 2) {
			while (ifs >> fid && ifs >> fname && ifs >> fpassword&&ifs>>fmajor) {
				if (id == fid && name == fname && password == fpassword) {
					cout << "-----------------------------------" << endl;
					cout << "|       ������ʦ��֤��¼�ɹ���    |" << endl;
					cout << "-----------------------------------" << endl;
					system("pause");
					system("cls");
					person = new Technician(id, name, password, "������Ա");     ///ͨ��person��̬����Technician����󣬲����γ�ʼ����ֵ
					TechnicianMenu(person);     ///���뼼����ʦ��ݵ��Ӳ˵���
					return;
				}
			}
		}
	}
	else if (choice == 3) {
		while (ifs >> fname && ifs >> fpassword) {
			if (name == fname && password == fpassword) {
				cout << "-----------------------------------" << endl;
				cout << "|       ����Ա��֤��¼�ɹ���      |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, password, "ϵͳ����Ա");     ///ͨ��person��̬����Manager����󣬲����γ�ʼ����ֵ
				managerMenu(person);     ///�������Ա��ݵ��Ӳ˵���
				return;
			}
		}
	}
	cout << "-----------------------------------" << endl;
	cout << "|           ��֤��¼ʧ�ܣ�        |" << endl;
	cout << "-----------------------------------" << endl;

	system("pause");     ///�����������
	system("cls");     ///�����Ļ
	return;
}

//��ͨ����������Ա���Ӳ˵�����
void managerMenu(User* manager) {

	///�ú�������һ��������manager����Ϊ�������壬ͨ�����ʶ������ڳ�Ա������ʵ�ָ�����ֹ���

	while (true) {     ///һֱѭ����ֱ��ע���˺�ʱbreak
		manager->OpenMenu();     ///�������Ա���Ӳ˵�ҳ��
		Manager* man = (Manager*)manager;     ///ǿ������ת������manger��Identity*ת��Manager*��������ͬ��ΪManager*����man�����ڷ�����������к������Ա

		cout << "���������ѡ��";
		string choice ;
		cin >> choice;

		if (choice == "1") {
			man->AddAccount();     ///ע���û�
		}
		else if (choice == "2") {
			man->DeleteAccount();     ///ɾ���û�
		}
		else if (choice == "3") {
			man->ChangeAccount();     ///�޸��û�
		}
		else if (choice == "4") {
			man->CheckAllAccount();     ///�鿴�û�
		}
		else if (choice == "5") {
			man->FindAccount();     ///��ѯ�û�
		}
		else if (choice == "6") {
			man->CheckClassroom();     ///�鿴����
		}
		else if (choice == "7") {
			man->ClearAllBook();     ///���ԤԼ��¼
		}
		else if (choice == "0") {     ///ע���˺�
			delete manager;     ///��̬ɾ��manager
			cout << "-----------------------------------" << endl;
			cout << "|           ע���˺ųɹ���        |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {     ///���Ϸ����룬����ѭ��
			cout << "-----------------------------------" << endl;
			cout << "|      �����������������룡     |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
		}
	}
}

//��ͨ��������ͨѧ�����Ӳ˵�����
void normalStudentMenu(User* normalstudent)
{
	///�ú�������һ��������normalstudent����Ϊ�������壬ͨ�����ʶ������ڳ�Ա������ʵ�ָ�����ֹ���

	while (1) {     ///һֱѭ����ֱ��ע���˺�ʱbreak
		normalstudent->OpenMenu();     ///�����ͨѧ�����Ӳ˵�ҳ��
		normalStudent* man = (normalStudent*)normalstudent;     ///ͬ����ǿ������ת��

		cout << "���������ѡ��";
		string choice;
		cin >> choice;

		if (choice == "1") {
			man->ApplyBook();     ///����ԤԼ
		}
		else if (choice == "2") {
			man->ShowMyBook();     ///�鿴�ҵ�ԤԼ
		}
		else if (choice == "3") {
			man->CancelBook();     ///ȡ��ԤԼ
		}
		else if (choice == "4") {
			man->EvaluateBook();     ///���۹���
		}
		else if (choice == "0") {     ///ע���˺�
			delete normalstudent;     ///��̬ɾ��normalstudent
			cout << "-----------------------------------" << endl;
			cout << "|           ע���˺ųɹ���        |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {     ///����Ϸ��Լ��
			cout << "-----------------------------------" << endl;
			cout << "|      �����������������룡     |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
		}
	}
}

//��ͨ������ѧ���������Ӳ˵�����
void MonitorMenu(User* monitor)
{
	///�ú�������һ��������monitor����Ϊ�������壬ͨ�����ʶ������ڳ�Ա������ʵ�ָ�����ֹ���

	while (1) {     ///һֱѭ����ֱ��ע���˺�ʱbreak
		monitor->OpenMenu();     ///���ѧ���������Ӳ˵�ҳ��
		Monitor* man = (Monitor*)monitor;     ///ͬ����ǿ������ת��

		cout << "���������ѡ��";
		string choice;
		cin >> choice;

		if (choice == "1") {
			man->ApplyBook();     ///����ԤԼ
		}
		else if (choice == "2") {
			man->ShowMyBook();     ///�鿴�ҵ�ԤԼ
		}
		else if (choice =="3") {
			man->ShowAllBook();     ///�鿴�����˵�ԤԼ
		}
		else if (choice == "4") {
			man->CancelBook();     ///ȡ��ԤԼ
		}
		else if (choice == "5") {
			man->EvaluateBook();     ///���۹���
		}
		else if (choice == "0") {     ///ע���˺�
			delete monitor;     ///��̬ɾ��monitor
			cout << "-----------------------------------" << endl;
			cout << "|           ע���˺ųɹ���        |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {     ///����Ϸ��Լ��
			cout << "-----------------------------------" << endl;
			cout << "|      �����������������룡     |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
		}
	}
}

//��ͨ����������Ա���Ӳ˵�����
void CounsellorMenu(User* counsellor)
{
	///�ú�������һ��������counsellor����Ϊ�������壬ͨ�����ʶ������ڳ�Ա������ʵ�ָ�����ֹ���

	while (1) {     ///һֱѭ����ֱ��ע���˺�ʱbreak
		counsellor->OpenMenu();     ///�������Ա���Ӳ˵�ҳ��
		Counsellor* man = (Counsellor*)counsellor;     ///ͬ����ǿ������ת��
		if (man->GetCreditScore() < 6) {     ///�����������ֲ��ϸ����˳��û�ҳ�棬�ص����˵�
			break;
		}
		cout << "���������ѡ��";
		string choice ;
		cin >> choice;

		if (choice == "1") {
			man->CheckAllBook();     ///�鿴��ͨѧ��ԤԼ
		}
		else if (choice == "2") {
			man->AuditBook();     ///�����ͨѧ��ԤԼ
		}
		else if (choice == "0") {     ///ע���˺�
			delete counsellor;     ///��̬ɾ��counsellor
			cout << "-----------------------------------" << endl;
			cout << "|           ע���˺ųɹ���        |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {     ///����Ϸ��Լ��
			cout << "-----------------------------------" << endl;
			cout << "|      �����������������룡     |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
		}
	}
}

//��ͨ������������ʦ���Ӳ˵�����
void TechnicianMenu(User* technician)
{
	///�ú�������һ��������technician����Ϊ�������壬ͨ�����ʶ������ڳ�Ա������ʵ�ָ�����ֹ���

	while (1) {     ///һֱѭ����ֱ��ע���˺�ʱbreak
		technician->OpenMenu();     ///���ѧ���������Ӳ˵�ҳ��
		Technician* man = (Technician*)technician;      ///ͬ����ǿ������ת��
		if (man->GetCreditScore() < 6) {     ///�����������ֲ��ϸ����˳��û�ҳ�棬�ص����˵�
			break;
		}
		cout << "���������ѡ��";
		string choice ;
		cin >> choice;

		if (choice == "1") {
			man->CheckAllBook();     ///�鿴����ԤԼ
		}
		else if (choice == "2") {
			man->AuditBook();     ///�������ԤԼ
		}
		else if (choice == "0") {     ///ע���˺�
			delete technician;     ///��̬ɾ��technician
			cout << "-----------------------------------" << endl;
			cout << "|           ע���˺ųɹ���        |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {     ///����Ϸ��Լ��
			cout << "-----------------------------------" << endl;
			cout << "|      �����������������룡     |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
		}
	}
}
