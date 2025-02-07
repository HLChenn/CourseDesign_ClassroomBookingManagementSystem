#include "Manager.h"

//管理员类无参构造函数
Manager::Manager() {};

//管理员类有参构造函数：初始化名字，密码，以及容器成员
Manager::Manager(string name, string password,string major) :User(name, password,major) { this->InitialVector(); }

//管理员类虚析构函数
Manager::~Manager() {};

//成员函数：子菜单初始化
void Manager::OpenMenu()
{
	cout << "      欢迎管理员 "+GetName()+" 登录!" << endl;
	cout << "-----------------------------------" << endl;
	cout << "|            1.注册用户           |" << endl;
	cout << "|            2.删除用户           |" << endl;
	cout << "|            3.修改用户           |" << endl;
	cout << "|            4.查看用户           |" << endl;
	cout << "|            5.查询用户           |" << endl;
	cout << "|            6.查看教室           |" << endl;
	cout << "|            7.清空预约           |" << endl;
	cout << "|            0.注销登录           |" << endl;
	cout << "-----------------------------------" << endl;
}

//成员函数：注册用户
void Manager::AddAccount()
{
	cout << "-----------------------------------" << endl;
	cout << "|      请选择要注册用户的类型：   |" << endl;
	cout << "|          1.普通学生用户         |" << endl;
	cout << "|          2.学生代表用户         |" << endl;
	cout << "|          3.辅导员用户           |" << endl;
	cout << "|          4.技术老师用户         |" << endl;
	cout << "|          0.返回子菜单           |" << endl;
	cout << "-----------------------------------" << endl;
	string falsetip;     ///在不同选择中赋值为不同的错误提示，当出现错误，输出该字符串
	string fname;        ///在不同选择中赋值为不同的文档文件名字
	string tip;			 ///
	ofstream ofs;		 ///创建写文件流对象，搭建与要写入的文档文件的联系

	string choice;		 ///用来选择要注册的用户类型
	while (1) {
		cout << "请输入您的选择：";
		cin >> choice;
		if (choice == "1") {
			fname = NORMALSTUDNET_FILE;
			tip = "请输入普通学生学号：";
			falsetip = "学号重复，请重新输入！";
			break;
		}
		else if (choice == "2") {
			fname = MONITOR_FILE;
			tip = "请输入学生代表学号：";
			falsetip = "学号重复，请重新输入！";
			break;
		}
		else if (choice == "3") {
			fname = COUNSELLOR_FILE;
			tip = "请输入辅导员编号：";
			falsetip = "编号重复，请重新输入！";
			break;
		}
		else if (choice == "4") {
			fname = TECHNICIAN_FILE;
			tip = "请输入技术老师编号：";
			falsetip = "编号重复，请重新输入！";
			break;
		}
		else if (choice == "0") {
			system("cls");     ///清屏返回子菜单
			return;
		}
		else {
			cout << "-----------------------------------" << endl;
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
		}
	}
	string id;     ///这一组变量，由string来接受输入，便于检查输入合法性，再通过stoi函数转为int给idcheck，便于后续的条件判断
	int idcheck;

	string name;     ///接受用户输入的名字，密码
	string password;

	string major = "技术人员";     ///在用户没有更改major时，默认为技术人员

	ofs.open(fname, ios::out | ios::app);     ///以追加方式写入文件

	while (1) {     ///检测号码是否重复
		cout << tip;
		cin >> id;
		try {     ///依旧通过try，catch形式检查输入合法性
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
				cout << "|          输入有误，请重新输入！       |" << endl;
				cout << "-----------------------------------------" << endl;
			}
		}
		catch (...) {     ///当try内有错误出现，抛出异常，达到输入合法性检查的目的
			cout << "-----------------------------------------" << endl;
			cout << "| 输入有误，请您重新输入只含数字的序号！|" << endl;
			cout << "-----------------------------------------" << endl;
		}	
	}
	cout << "请输入姓名：";
	cin >> name;
	while (1) {
		cout << "请输入密码(10位以内)： ";
		cin >> password;
		if (password.size() > 10) {
			cout << "-----------------------------------" << endl;
			cout << "|    密码位数超限，请重新输入！   |" << endl;
			cout << "-----------------------------------" << endl;
		}
		else if (password.size() <= 10) {
			break;
		}
	}
	if (choice != "4") {
		while (1) {
			cout << "请输入所在专业：";
			cin >> major;
			if (major.size() == 0) {
				cout << "-----------------------------------------" << endl;
				cout << "|          输入有误，请重新输入！       |" << endl;
				cout << "-----------------------------------------" << endl;
			}
			else {
				break;
			}
		}
	}
	ofs << id << " " << name << " " << password << " " << major << endl;     ///当操作全部合法且完成后，通过ofs写入数据到指定文档文件中
	cout << "-----------------------------------" << endl;
    cout << "|            注册成功！           |" << endl;
	cout << "-----------------------------------" << endl;
    
    if (choice == "1") {     ///在注册完成后，同步更新管理员类中的相关vector数据成员
    	normalStudent s(id, name, password,"普通学生",major);
    	vNStudent.push_back(s);
    }
    else if (choice == "2") {
    	Monitor m(id, name, password,"学生代表",major);
    	vMonitor.push_back(m);
    }
    else if (choice == "3") {
    	Counsellor c(id, name, password,major);
    	vCounsellor.push_back(c);
    }
    else if (choice == "4") {
    	Technician t(id, name, password,"技术人员");
    	vTechnician.push_back(t);
    }
	SortVector();     ///同时排序

	ofs.close();     ///关闭ofs和文档的联系
	system("pause");
	system("cls");
}

//成员函数：删除用户
void Manager::DeleteAccount()
{
	cout << "-----------------------------------" << endl;
	cout << "|        请选择删除用户类型：     |" << endl;
	cout << "|          1.普通学生用户         |" << endl;
	cout << "|          2.学生代表用户         |" << endl;
	cout << "|          3.辅导员用户           |" << endl;
	cout << "|          4.技术老师用户         |" << endl;
	cout << "|          0.返回子菜单           |" << endl;
	cout << "-----------------------------------" << endl;

	string choice;     
	int index = 1;     ///创建即将要输出信息的索引变量，赋值为1
	while (1) {
		cout << "请输入您的选择：";
		cin >> choice;
		if (choice == "1") {
			cout << "所有普通学生信息如下：" << endl;     ///通过输出控制符来达到整齐输入的目的
			for (auto it = vNStudent.begin(); it < vNStudent.end(); it++) {     ///通过迭代器遍历vector容器，输出信息
				cout << setw(5) << left << index++
					<< "| 学号：" << setw(7) << left << it->GetStudentId()
					<< "| 姓名：" << setw(10) << it->GetName()
					<< "| 密码：" << setw(12) << it->GetPassword()
					<< " | 专业：" << setw(20) << it->GetMajor() << "|" << endl;
			}
			break;
		}
		else if (choice == "2") {
			cout << "所有的学生代表信息如下：" << endl;
			for (auto it = vMonitor.begin(); it < vMonitor.end(); it++) {
				cout << setw(5) << left << index++
					<< "| 学号：" << setw(7) << left << it->GetStudentId()
					<< "| 姓名：" << setw(10) << it->GetName()
					<< "| 密码：" << setw(12) << it->GetPassword()
					<< " | 专业：" << setw(20) << it->GetMajor() << "|" << endl;
			}
			break;
		}
		else if (choice == "3") {
			cout << "所有的辅导员信息如下：" << endl;
			for (auto it = vCounsellor.begin(); it < vCounsellor.end(); it++) {
				cout << setw(5) << left << index++
					<< "| 编号：" << setw(7) << left << it->GetTeacherId()
					<< "| 姓名：" << setw(10) << it->GetName()
					<< "| 密码：" << setw(12) << it->GetPassword()
					<< " | 专业：" << setw(20) << it->GetMajor() << "|" << endl;	
			}
			break;
		}
		else if (choice == "4") {
			cout << "所有的技术老师信息如下：" << endl;
			for (auto it = vTechnician.begin(); it < vTechnician.end(); it++) {
				cout << setw(5) << left << index++
					<< "| 编号：" << setw(7) << left << it->GetTeacherId()
					<< "| 姓名：" << setw(10) << it->GetName()
					<< "| 密码：" << setw(12) << it->GetPassword() << "|" << endl;
			}
			break;
		}
		else if (choice == "0") {     ///清屏返回子菜单
			system("cls");
			return;
		}
		else {
			cout << "-----------------------------------" << endl;
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
		}
		}
		int select = -1;     ///这一组变量同样组合起来用以检查输入合法性
		string change;

		index--;     ///将多加一的索引减一，保证边界正确
		while (1) {
			cout << "请输入你要删除的用户序号，0代表返回： ";
			cin >> change;
			try {
				select = stoi(change);
				if (select<0 || select>index) {
					cout << "-----------------------------------" << endl;
					cout << "|      输入有误，请重新输入！     |" << endl;
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
				cout << "|      输入有误，请重新输入！     |" << endl;
				cout << "-----------------------------------" << endl;
			}

		}
		if (choice == "1") {     ///当上述操作合法且完成后，进入文件流更改部分，也是核心部分，下面以删除普通学生用户为例
			ofstream ofs(TEMP_FILE, ios::out | ios::trunc);     ///ofs打开临时文档文件，并清空文档
			ifstream ifs(NORMALSTUDNET_FILE, ios::in);     ///ifs打开普通学生文档文件，默认从头开始读取
			string id;     ///四个变量，用以读取文档中的学号，名字，密码，专业
			string name;
			string password;
			string major;
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {     ///当ifs从文档中读取的数据不为空时
				if (id != vNStudent[select - 1].GetStudentId()) {     ///并且忽略掉要删除的某条用户的行数（即ifs不读取此行数据）
					ofs << id << " " << name << " " << password << " " << major << endl;     ///同步让ofs将读到的数据写入临时文档中（类似copy功能）
				}
			}
			ofs.close();     ///切断ofs和ifs与文档联系
			ifs.close();
			ofs.open(NORMALSTUDNET_FILE, ios::out | ios::trunc);     ///交换文档文件，并打开
			ifs.open(TEMP_FILE, ios::in);
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {     ///重复上述操作，此时临时文档中已没有“被删除用户”的数据
				ofs << id << " " << name << " " << password << " " << major << endl;     ///原封不动将临时文档copy回普通学生文档中，达到删除用户数据的功能
			}
			ofs.close();
			ifs.close();
			cout << "-----------------------------------" << endl;
			cout << "|           用户删除成功！        |" << endl;
			cout << "-----------------------------------" << endl;
			InitialVector();     ///删除操作全部完成后，同步更新容器成员数据（下同）
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
			cout << "|           用户删除成功！        |" << endl;
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
			cout << "|           用户删除成功！        |" << endl;
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
					ofs << id << " " << name << " " << password << " " << "技术人员" << endl;
				}
			}
			ofs.close();
			ifs.close();
			ofs.open(TECHNICIAN_FILE, ios::out | ios::trunc);
			ifs.open(TEMP_FILE, ios::in);
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
				ofs << id << " " << name << " " << password << " " << "技术人员" << endl;
			}
			ofs.close();
			ifs.close();

			cout << "-----------------------------------" << endl;
			cout << "|           用户删除成功！        |" << endl;
			cout << "-----------------------------------" << endl;
			InitialVector();
		}
		system("pause");
		system("cls");
	}

//成员函数：修改用户的密码或者专业
void Manager::ChangeAccount()
{
	SortVector();
	cout << "-----------------------------------" << endl;
	cout << "|        请选择修改用户类型：     |" << endl;
	cout << "|          1.普通学生用户         |" << endl;
	cout << "|          2.学生代表用户         |" << endl;
	cout << "|          3.辅导员用户           |" << endl;
	cout << "|          4.技术老师用户         |" << endl;
	cout << "|          0.返回子菜单           |" << endl;
	cout << "-----------------------------------" << endl;
	string choice;
	int index = 1;     ///创建显示信息的索引，初始为1
	while (1) {
		cout << "请输入您的选择：";
		cin >> choice;
		if (choice == "1") {
			cout << "所有普通学生信息如下：" << endl;     ///通过输出控制符来达到整齐输入的目的
			for (auto it = vNStudent.begin(); it < vNStudent.end(); it++) {
				cout << setw(5) << left << index++
					<< "| 学号：" << setw(7) << left << it->GetStudentId()
					<< "| 姓名：" << setw(10) << it->GetName()
					<< "| 密码：" << setw(12) << it->GetPassword()
					<< " | 专业：" << setw(20) << it->GetMajor() << "|" << endl;
			}
			break;
		}
		else if (choice == "2") {
			cout << "所有的学生代表信息如下：" << endl;
			for (auto it = vMonitor.begin(); it < vMonitor.end(); it++) {
				cout << setw(5) << left << index++
					<< "| 学号：" << setw(7) << left << it->GetStudentId()
					<< "| 姓名：" << setw(10) << it->GetName()
					<< "| 密码：" << setw(12) << it->GetPassword()
					<< " | 专业：" << setw(20) << it->GetMajor() << "|" << endl;
			}
			break;
		}
		else if (choice == "3") {
			cout << "所有的辅导员信息如下：" << endl;
			for (auto it = vCounsellor.begin(); it < vCounsellor.end(); it++) {
				cout << setw(5) << left << index++
					<< "| 编号：" << setw(7) << left << it->GetTeacherId()
					<< "| 姓名：" << setw(10) << it->GetName()
					<< "| 密码：" << setw(12) << it->GetPassword()
					<< " | 专业：" << setw(20) << it->GetMajor() << "|" << endl;
			}
			break;
		}
		else if (choice == "4") {
			cout << "所有的技术老师信息如下：" << endl;
			for (auto it = vTechnician.begin(); it < vTechnician.end(); it++) {
				cout << setw(5) << left << index++
					<< "| 编号：" << setw(7) << left << it->GetTeacherId()
					<< "| 姓名：" << setw(10) << it->GetName()
					<< "| 密码：" << setw(12) << it->GetPassword() << "|" << endl;
			}
			break;
		}
		else if (choice == "0") {
			system("cls");
			return;
		}
		else {
			cout << "-----------------------------------" << endl;
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
		}
	}
	index--;     ///将索引减一，保证边界正确
	int select = -1;      ///这一组变量同样用以检查输入合法性（该程序中多处使用到此方法）
	string change;

	while (1) {
		cout << "请输入你要修改信息的用户序号，0代表返回： ";
		cin >> change;
		try {
			select = stoi(change);
			if (select<0 || select>index) {
				cout << "-----------------------------------" << endl;
				cout << "|      输入有误，请重新输入！     |" << endl;
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
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
		}

	}
	string finalchoice;     ///用来输入选择要更改的信息是密码还是专业
	string newPassword;     ///用来输入新密码
	string newMajor;        ///用来输入新专业

	cout << "-----------------------------------" << endl;
	cout << "|        请选择您要更改的信息：   |" << endl;
	cout << "|            1.密码               |" << endl;
	cout << "|            2.专业               |" << endl;
	cout << "|            0.返回子菜单         |" << endl;
	cout << "-----------------------------------" << endl;
	while (1) {
		cout << "请输入您的选择： ";
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
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
		}
	}
	if (finalchoice == "1") {
		while (1) {
			cout << "请输入新密码（10位以内）： ";
			cin >> newPassword;
			if (newPassword.size() > 0 && newPassword.size() <= 10) {     ///保证密码位数边界正确
				break;
			}
			else {
				cout << "-----------------------------------" << endl;
				cout << "|      输入有误，请重新输入！     |" << endl;
				cout << "-----------------------------------" << endl;
			}
		}
	}
	else if (finalchoice == "2") {
		if (choice == "4") {     ///技术老师不能被修改专业
			cout << "-----------------------------------------------------" << endl;
			cout << "| 抱歉，技术老师无法修改专业信息（默认为技术人员）！|" << endl;
			cout << "-----------------------------------------------------" << endl;
			system("pause>nul");     ///暂停程序并抛弃输出，比pause更强烈，即使不是内部指令
			system("cls");
			return;
		}
		while (1) {
			cout << "请输入新专业： ";
			cin >> newMajor;
			if (newMajor.size() > 0 && newMajor.size() <= 15) {     ///保证专业字符数不超边界
				break;
			}
			else {
				cout << "-----------------------------------" << endl;
				cout << "|      输入有误，请重新输入！     |" << endl;
				cout << "-----------------------------------" << endl;
			}
		}
	}
							 ///接下来为修改操作重要部分，其操作流程核心与“删除用户”功能代码段相似
	if (choice == "1") {     ///普通学生改动
		ofstream ofs(TEMP_FILE, ios::out | ios::trunc);
		ifstream ifs(NORMALSTUDNET_FILE, ios::in);
		string id;
		string name;
		string password;
		string major;
		if (finalchoice == "1") {     ///改动密码
			while (ifs >> id && ifs >> name && ifs >> password && ifs >> major) {
				if (id != vNStudent[select - 1].GetStudentId()) {     ///不同点在于，写入读入的判断条件不一样
					ofs << id << " " << name << " " << password << " " << major << endl;
				}
				if (id == vNStudent[select - 1].GetStudentId()) {
					ofs << id << " " << name << " " << newPassword << " " << major << endl;
				}
			}
		}
		else if (finalchoice == "2") {     ///改动专业（下同）
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
			cout << "|         用户信息改动成功！      |" << endl;
			cout << "-----------------------------------" << endl;
			InitialVector();
	}
	else if (choice == "2") {     ///学生代表改动
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
		cout << "|         用户信息改动成功！      |" << endl;
		cout << "-----------------------------------" << endl;
		InitialVector();
	}
	else if (choice == "3") {     ///辅导员改动
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
		cout << "|         用户信息改动成功！      |" << endl;
		cout << "-----------------------------------" << endl;
		InitialVector();
	}
	else if (choice == "4") {     ///技术老师改动
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
			ofs << id << " " << name << " " << password << " " << "技术人员" << endl;
		}
		ofs.close();
		ifs.close();

		cout << "-----------------------------------" << endl;
		cout << "|         用户信息改动成功！      |" << endl;
		cout << "-----------------------------------" << endl;
		InitialVector();
	}
	system("pause");
	system("cls");
}

//成员函数：查看所有用户
void Manager::CheckAllAccount()
{
	SortVector();     ///对用户按序号大小排序
	int sum = vNStudent.size() + vMonitor.size() + vCounsellor.size() + vTechnician.size();     ///先展示各类用户人数
	cout << endl;
	cout << "以下为用户总人数：" << sum << endl;
	cout << "其中,各分类人数如下：" << endl;
	cout << "普通学生用户人数：" << vNStudent.size() << endl;
	cout << "学生代表用户人数：" << vMonitor.size() << endl;
	cout << "辅导员用户人数：" << vCounsellor.size() << endl;
	cout << "技术老师用户人数：" << vTechnician.size() << endl;
	cout << endl;

	cout << "-----------------------------------" << endl;
	cout << "|         请选择查看内容：        |" << endl;
	cout << "|         1.普通学生用户信息      |" << endl;
	cout << "|         2.学生代表用户信息      |" << endl;
	cout << "|         3.辅导员用户信息        |" << endl;
	cout << "|         4.技术老师用户信息      |" << endl;
	cout << "|         0.返回子菜单            |" << endl;
	cout << "-----------------------------------" << endl;
	string choice;
	while (1) {
		cout << "请输入您的选择：";
		cin >> choice;
		if (choice == "1") {
			if (vNStudent.size() == 0) {
				cout << "-----------------------------------" << endl;
				cout << "|         暂无普通学生用户！      |" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			cout << "所有普通学生信息如下(默认以学号顺序排列)：" << endl;
			cout << endl;
			for (auto it = vNStudent.begin(); it != vNStudent.end(); it++) {
				cout << "| 学号：" << setw(7) << left << it->GetStudentId()
					<< "| 名字：" << setw(10) << left << it->GetName()
					<< "| 密码：" << setw(12) << left << it->GetPassword()
					<< "| 专业：" << setw(20) << left << it->GetMajor() << "|" << endl;
			}
			break;
		}
		else if (choice == "2") {
			if (vMonitor.size() == 0) {
				cout << "-----------------------------------" << endl;
				cout << "|         暂无学生代表用户！      |" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			cout << "所有的学生代表信息如下(默认以学号顺序排列)：" << endl;
			cout << endl;
			for (auto it = vMonitor.begin(); it != vMonitor.end(); it++) {
				cout << "| 学号：" << setw(7) << left << it->GetStudentId()
					<< "| 名字：" << setw(10) << left << it->GetName()
					<< "| 密码：" << setw(12) << left << it->GetPassword()
					<< "| 专业：" << setw(20) << left << it->GetMajor() << "|" << endl;
			}
			break;
		}
		else if (choice == "3") {
			if (vCounsellor.size() == 0) {
				cout << "-----------------------------------" << endl;
				cout << "|          暂无辅导员用户！       |" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			cout << "所有的辅导员信息如下(默认以编号顺序排列)：" << endl;
			cout << endl;
			for (auto it = vCounsellor.begin(); it != vCounsellor.end(); it++) {
				cout << "| 编号：" << setw(7) << left << it->GetTeacherId()
					<< "| 名字：" << setw(10) << left << it->GetName()
					<< "| 密码：" << setw(12) << left << it->GetPassword()
					<< "| 专业：" << setw(20) << left << it->GetMajor() << "|" << endl;
			}
			break;
		}
		else if (choice == "4") {
			if (vTechnician.size() == 0) {
				cout << "-----------------------------------" << endl;
				cout << "|         暂无技术老师用户！      |" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			cout << "所有的技术老师信息如下(默认以编号顺序排列)：" << endl;
			cout << endl;
			for (auto it = vTechnician.begin(); it != vTechnician.end(); it++) {
				cout << "| 编号：" << setw(7) << left << it->GetTeacherId()
					<< "| 名字：" << setw(10) << left << it->GetName()
					<< "| 密码：" << setw(12) << left << it->GetPassword() << "|" << endl;
			}
			break;
		}
		else if (choice == "0") {
			system("cls");
			return;
		}
		else {
			cout << "-----------------------------------" << endl;
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
		}
	}
	system("pause");
	system("cls");
}

//成员函数：按照名字或者专业查找用户,使用正则表达式来模糊搜索
void Manager::FindAccount()
{
	cout << "-----------------------------------" << endl;
	cout << "|      请选择要查找对象的身份：   |" << endl;
	cout << "|          1.普通学生用户         |" << endl;
	cout << "|          2.学生代表用户         |" << endl;
	cout << "|          0.返回子菜单           |" << endl;
	cout << "-----------------------------------" << endl;
	
	string select;     ///这一组变量用以检查输入合法性
	int change = -1;

	while (1) {
		cout << "请输入您的选择：";
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
				cout << "|      输入有误，请重新输入！     |" << endl;
				cout << "-----------------------------------" << endl;
			}
		}
		catch (...) {
			cout << "-----------------------------------" << endl;
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
		}
	}
	cout << "-----------------------------------" << endl;
	cout << "|     请选择按以下哪种方式查找：  |" << endl;
	cout << "|          1.按名字查找           |" << endl;
	cout << "|          2.按专业查找           |" << endl;
	cout << "-----------------------------------" << endl;
	string choice;     ///用来输入按名字还是按专业查找
	while (1) {
		int index = 1;
		bool flag = 0;     ///是否有符合条件的用户，如果找到就记为1，没有默认为0
		cout << "请输入您的选择,0代表返回： ";
		cin >> choice;
		if (choice == "0") {
			system("cls");
			return;
		}
		else if (select=="1"&&choice == "1") {
			string name;
			cout << "请输入要查找的普通学生的名字：";
			
			cin.ignore(); 
			getline(cin, name);      ///使用getline获取包含空格的完整名字
			string pattern = ".*" + name + ".*";     ///构造正则表达式的格式
			regex change(pattern, regex_constants::icase);      ///忽略大小写

			for (int i = 0; i < vNStudent.size(); i++) {
				if (regex_search(vNStudent[i].GetName(),change)) {     ///模糊搜索change的内容，有对应字符出现就执行语句（下同）
					cout << "[" << index++ << "] " << endl;
					cout << "学号：" << vNStudent[i].GetStudentId() << endl;
					cout << "姓名：" << vNStudent[i].GetName() << endl;
					cout << "密码：" << vNStudent[i].GetPassword() << endl;
					cout << "专业：" << vNStudent[i].GetMajor() << endl;
					cout << "-------------------" << endl;
					flag = 1;
				}
			}
			if (flag) {
				cout << "-----------------------------------" << endl;
				cout << "|       已为您查找到以上用户!     |" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			cout << endl;
			cout << "----------------------------------------" << endl;
			cout << "| 抱歉，暂时没有查找到您要寻找的对象！ |" << endl;
			cout << "----------------------------------------" << endl;
		}
		else if (select=="1"&&choice == "2") {
			string major;
			cout << "请输入要查找的普通学生的专业：";
			cin.ignore();
			getline(cin, major);
			string pattern = ".*" + major + ".*";
			regex change(pattern, regex_constants::icase);
			for (int i = 0; i < vNStudent.size(); i++) {
				if (regex_search(vNStudent[i].GetMajor(), change)) {
					cout << "[" << index++ << "] " << endl;
					cout << "学号：" << vNStudent[i].GetStudentId() << endl;
					cout << "姓名：" << vNStudent[i].GetName() << endl;
					cout << "密码：" << vNStudent[i].GetPassword() << endl;
					cout << "专业：" << vNStudent[i].GetMajor() << endl;
					cout << "-------------------" << endl;
					flag = 1;
				}
			}
			if (flag) {
				cout << "-----------------------------------" << endl;
				cout << "|       已为您查找到以上用户!     |" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			cout << endl;
			cout << "----------------------------------------" << endl;
			cout << "| 抱歉，暂时没有查找到您要寻找的对象！ |" << endl;
			cout << "----------------------------------------" << endl;
			break;
		}
		else if (select == "2" && choice == "1") {
			string name;
			cout << "请输入要查找的学生代表的名字：";
			cin.ignore(); 
			getline(cin, name); 
			string pattern = ".*" + name + ".*";
			regex change(pattern, regex_constants::icase); 
			for (int i = 0; i < vMonitor.size(); i++) {
				if (regex_search(vMonitor[i].GetName(),change)) {
					cout << "[" << index++ << "] " << endl;
					cout << "学号：" << vMonitor[i].GetStudentId() << endl;
					cout << "姓名：" << vMonitor[i].GetName() << endl;
					cout << "密码：" << vMonitor[i].GetPassword() << endl;
					cout << "专业：" << vMonitor[i].GetMajor() << endl;
					cout << "-------------------" << endl;
					flag = 1;
				}
			}
			if (flag) {
				cout << "-----------------------------------" << endl;
				cout << "|       已为您查找到以上用户!     |" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			cout << endl;
			cout << "----------------------------------------" << endl;
			cout << "| 抱歉，暂时没有查找到您要寻找的对象！ |" << endl;
			cout << "----------------------------------------" << endl;
		}
		else if (select == "2" && choice == "2") {
			string major;
			cout << "请输入要查找的普通学生的专业：";
			cin.ignore();
			getline(cin, major);
			string pattern = ".*" + major + ".*";
			regex change(pattern, regex_constants::icase);
			for (int i = 0; i < vMonitor.size(); i++) {
				if (regex_search(vMonitor[i].GetMajor(),change)) {
					cout << "[" << index++ << "] " << endl;
					cout << "学号：" << vMonitor[i].GetStudentId() << endl;
					cout << "姓名：" << vMonitor[i].GetName() << endl;
					cout << "密码：" << vMonitor[i].GetPassword() << endl;
					cout << "专业：" << vMonitor[i].GetMajor() << endl;
					cout << "-------------------" << endl;
					flag = 1;
				}
			}
			if (flag) {
				cout << "-----------------------------------" << endl;
				cout << "|       已为您查找到以上用户!     |" << endl;
				cout << "-----------------------------------" << endl;
				break;
			}
			cout << endl;
			cout << "----------------------------------------" << endl;
			cout << "| 抱歉，暂时没有查找到您要寻找的对象！ |" << endl;
			cout << "----------------------------------------" << endl;
			break;
		}

		else {
			cout << "-----------------------------------" << endl;
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
		}
	}
	system("pause");
	system("cls");
}

//成员函数：查看教室
void Manager::CheckClassroom()
{
	cout << "所有的教室信息如下：" << endl;     ///使用输出控制符，对齐输出，更清晰
	for (auto it = vClassroom.begin(); it < vClassroom.end(); it++) {
		cout << "教室编号：" << setw(7) <<left<< it->GetId() 
			<< "| 可容纳人数：" <<setw(10)<<left<< it->GetVolume() << endl;
	}
	system("pause");
	system("cls");
}

//成员函数：清空所有预约记录
void Manager::ClearAllBook()
{
	cout << "-----------------------------------" << endl;     ///再次确认是否要清空，防止误触而删除不想删除的记录
	cout << "|请再次确定是否要清空所有预约记录：|" << endl;
	cout << "|           1.确认清空             |" << endl;
	cout << "|           0.返回子菜单           |" << endl;
	cout << "-----------------------------------" << endl;
	cout << "请输入您的选择：";
	int choice = -1;
	string change;
	while (1) {
		cin >> change;
		try {     ///同样有对输入的合法检查
			choice = stoi(change);
			if (choice == 1) {
				ofstream ofs;
				ofs.open(BOOK_FILE, ios::trunc);     ///用trunc方式将文件清空
				ofs.close();
				cout << "-----------------------------------" << endl;
				cout << "|       预约信息已经全部清空！    |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				break;
			}
			if (choice == 0) {     ///返回子菜单
				system("cls");
				return;
			}
			else {
				cout << "-----------------------------------" << endl;
				cout << "|      输入有误，请重新输入！     |" << endl;
				cout << "-----------------------------------" << endl;
			}
		}
		catch (...) {
			cout << "-----------------------------------" << endl;
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
		}
	}
}

//成员函数：初始化或者更新各类存储数据的容器成员
void Manager::InitialVector()
{
	vNStudent.clear();     ///先对所有vector数据成员清空，防止后面添加时重叠报错
	vMonitor.clear();
	vCounsellor.clear();
	vTechnician.clear();
	vClassroom.clear();

	ifstream ifs(NORMALSTUDNET_FILE, ios::in);     ///将普通学生信息存入vector中
	if (!ifs.is_open()) {     ///同样对文件的存在性做检查，如果没有文件，则显示读取失败
		cout << "-----------------------------------" << endl;
		cout << "|           文件读取失败！        |" << endl;
		cout << "-----------------------------------" << endl;
		return;
	}
	normalStudent s;
	while (ifs >> s.GetStudentId() &&ifs>> s.GetName() && ifs>>s.GetPassword()&&ifs>>s.GetMajor()) {
		vNStudent.push_back(s);
	}
	ifs.close();

	ifs.open(MONITOR_FILE, ios::in);      ///存学生代表信息
	if (!ifs.is_open()) {
		cout << "-----------------------------------" << endl;
		cout << "|           文件读取失败！        |" << endl;
		cout << "-----------------------------------" << endl;
		return;
	}
	Monitor m;
	while (ifs >> m.GetStudentId() && ifs >> m.GetName() && ifs >> m.GetPassword()&&ifs>>m.GetMajor()) {
		vMonitor.push_back(m);
	}
	ifs.close();

	ifs.open(COUNSELLOR_FILE, ios::in);     ///存辅导员信息
	if (!ifs.is_open()) {
		cout << "-----------------------------------" << endl;
		cout << "|           文件读取失败！        |" << endl;
		cout << "-----------------------------------" << endl;
		return;
	}
	Counsellor co;
	while (ifs >> co.GetTeacherId() &&ifs>> co.GetName() && ifs>> co.GetPassword()&&ifs>>co.GetMajor()) {
		vCounsellor.push_back(co);
	}
	ifs.close();

	ifs.open(TECHNICIAN_FILE, ios::in);     ///存技术老师信息
	if (!ifs.is_open()) {
		cout << "-----------------------------------" << endl;
		cout << "|           文件读取失败！        |" << endl;
		cout << "-----------------------------------" << endl;
		return;
	}
	Technician te;
	while (ifs >> te.GetTeacherId() && ifs >> te.GetName() && ifs >> te.GetPassword()&&ifs>>te.GetMajor()) {
		vTechnician.push_back(te);
	}
	ifs.close();

	ifs.open(CLASSROOM_FILE, ios::in);     ///存教室信息
	Classroom c;
	while (ifs >> c.GetId() && ifs >> c.GetVolume()) {
		vClassroom.push_back(c);
	}
	ifs.close();
}

//成员函数：将容器成员按照序号顺序排列
void Manager::SortVector()
{
	if (vNStudent.size() != 0) {     ///目前采用的是冒泡排序算法
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

//成员函数：检测用户唯一性
bool Manager::CheckAccountNotOnly(string id, string choice)
{
	///函数参数：1.string型id：用以比对文档中id
	///          2.string型choice：用来判断身份

	if (choice == "1"&& vNStudent.size()!=0) {     ///传入序号，通过比较序号和容器中已有序号，如果存在，则返回true，否则，返回false(在容器存在大小的前提下）
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
 