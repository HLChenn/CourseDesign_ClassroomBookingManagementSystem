#include"InitialProject.h"

//普通函数：初始化主菜单窗口，包含登录，注册，退出系统三大功能
void RunMainMenu()
{
	while (true) {     ///while循环输出，直到满足退出系统条件才break
		
		string firstchoice;     ///三个选择变量，分别对应三重if选择：
		string secondchoice;	///1.firstchoice对应登录，注册，退出系统
		string thirdchoice;		///2.secondchoice对应学生，老师，管理员三大身份（其中，管理员在此层进入登录页面）
								///3.thirdchoice对应（普通学生，学生代表），（辅导员，技术老师）具体身份，均在此层进入登录页面

		cout << "-----------------------------------" << endl;
		cout << "|    欢迎您来到教室预订管理系统   |" << endl;
		cout << "|            请选择操作：         |" << endl;
		cout << "|            1.登录               |" << endl;
		cout << "|            2.注册               |" << endl;
		cout << "|            0.退出系统           |" << endl;
		cout << "-----------------------------------" << endl;
		cout << "请输入您的选择：" ;
		cin >> firstchoice;
		if (firstchoice == "1") {     ///1.登录的身份选择

			cout << "-----------------------------------" << endl;
			cout << "|       请输入您的身份类型：      |" << endl;
			cout << "|            1.学生               |" << endl;
			cout << "|            2.老师               |" << endl;
			cout << "|            3.管理员             |" << endl;
			cout << "|            0.返回主菜单         |" << endl;
			cout << "-----------------------------------" << endl;
			cout << "请输入您的选择：" ;
			cin >> secondchoice;

			if (secondchoice == "1") {
				cout << "-----------------------------------" << endl;
				cout << "|       请输入您的具体身份是：    |" << endl;
				cout << "|            1.普通学生           |" << endl;
				cout << "|            2.学生代表           |" << endl;
				cout << "-----------------------------------" << endl;
				cout << "请输入您的选择：";
				cin >> thirdchoice;

				if (thirdchoice == "1") {     ///双重身份选择完毕并且输入均为合法操作后，通过Login函数进入相应具体身份的登录页面
					Login(NORMALSTUDNET_FILE, 1, 1);
				}
				else if (thirdchoice == "2") {
					Login(MONITOR_FILE, 1, 2);
				}
				else {     ///输入合法性检查
					cout << "-----------------------------------" << endl;
					cout << "|      输入有误，请重新输入！     |" << endl;
					cout << "-----------------------------------" << endl;
					system("pause");
					system("cls");
				}
			}
			else if (secondchoice == "2") {
				cout << "-----------------------------------" << endl;
				cout << "|         请输入您的级别是：      |" << endl;
				cout << "|             1.辅导员            |" << endl;
				cout << "|             2.技术老师          |" << endl;
				cout << "-----------------------------------" << endl;
				cout << "请输入您的选择：" ;
				cin >> thirdchoice;
				
				if (thirdchoice == "1") {
					Login(COUNSELLOR_FILE, 2, 1);
				}
				else if (thirdchoice == "2") {
					Login(TECHNICIAN_FILE, 2, 2);
				}
				else {
					cout << "-----------------------------------" << endl;
					cout << "|      输入有误，请重新输入！     |" << endl;
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
			else {     ///输入不合法，输出下面语句
				cout << "-----------------------------------" << endl;
				cout << "|      输入有误，请重新输入！     |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
			}
		}
		else if (firstchoice == "2") {     ///2.注册的身份选择
			Manager man("ad","1", "临时系统管理员");     ///创建Manager类临时变量man，在完成功能后撤销该对象，而不用真正的管理员账号（admin），保证管理员账号隐藏
			man.AddAccount();     ///通过man对象访问注册用户功能
		}
		else if (firstchoice == "0") {     ///3.退出系统
			cout << "-----------------------------------" << endl;
			cout << "|         欢迎下一次使用!         |" << endl;
			cout << "-----------------------------------" << endl;
			return;
		}
		else {     ///输入合法性判断
			cout << "-----------------------------------" << endl;
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
		}
	}
}

//普通函数：登录窗口，通过输入序号，名字，密码，在身份验证成功后进入对应子菜单
void Login(string fileName, int choice, int select) {

	///该函数包含三个参数：
    ///1.fileName，接受储存该登录身份类型的文本名字，用以读取文件数据，实现身份验证
    ///2.choice，判断是学生大类，老师大类，还是辅导员类
    ///3.select，判断是（普通学生，学生代表）还是（辅导员，技术老师）

	User* person = NULL;  ///创建用户类指针，便于后续在分支时统一输出：指向不同的派生类对象
	ifstream ifs;
	ifs.open(fileName, ios::in);  	
	if (!ifs.is_open()) {     ///对文件是否存在做判断
		cout << "-----------------------------------" << endl;
		cout << "|           文件并不存在          |" << endl;
		cout << "-----------------------------------" << endl;
		ifs.close();
		return;
	}
	
	string id;  	///准备接受用户的信息：序号，名字，密码
	string name;
	string password;

	if (choice == 1) {
		cout << "请输入你的学号：";
		cin >> id;
	}
	else if (choice == 2) {
		cout << "请输入你的编号：";
		cin >> id;
	}

	cout << "请输入用户名：";
	cin >> name;
	while (1) {     ///输入密码时有保密功能，即输入内容，但只显示“*”
		password.clear();	  ///在每次进入循环时，清空password
		cout << "请输入密码(十位以内)： ";
		char key;
		while (key = _getch()) {     ///从键盘中得到输入的一个字符，赋值给key，不输出在屏幕上
			if (key == 13) {     ///如果key的字符转为ascall码后为13，即换行符，并且输入的密码大小不为0，则break，否则判为输入有误
				if (password.size() != 0) {
					break;
				}
				else {
					cout << "-----------------------------------" << endl;
					cout << "|       操作有误，请重新输入！    |" << endl;
					cout << "-----------------------------------" << endl;
				}
			}
			else if (key != '\b') {     ///如果key不是退格符，那么就在password（string型）尾插入key，并在屏幕上输出“*”
				password += key;
				cout << "*";
			}
			else if (key == '\b' && password.size() > 0) {    ///如果key是退格符，并且此时password大小不为0，则在屏幕上输出退格符，再输出空格符覆盖原来的字符，然后再输出退格符，实现在屏幕上的“删除”操作
				cout << "\b \b";
				password = password.substr(0, password.size() - 1);     ///同步删除password内最后一位的字符
			}
		}
		cout << endl;
		if (password.size() <= 10) {     ///如果密码位数≤10，则break
			break;
		}
		else {
			cout << "-----------------------------------" << endl;
			cout << "|       密码超限，请重新输入！    |" << endl;
			cout << "-----------------------------------" << endl;
		}
	}

	string fid;     ///创建读取文件数据所需的四个string变量，分别读取序号，名字，密码，专业
	string fname;
	string fpassword;
	string fmajor;

	if (choice == 1) {
		if (select == 1) {
			while (ifs >> fid && ifs >> fname && ifs >> fpassword && ifs >> fmajor) {     ///从对应文件中读取四个字符串数据，当没有再读到有效数据，while不再执行（下面其他相似分支也同理）
				if (id == fid && name == fname && password == fpassword) {     ///当所读到的数据与输入数据一一对应时，判断为验证登录成功，进入子菜单（下同）
					cout << "-----------------------------------" << endl;
					cout << "|       普通学生验证登录成功！    |" << endl;
					cout << "-----------------------------------" << endl;
					system("pause");     ///按任意键继续
					system("cls");     ///清屏，便于进入下一个页面操作（下同）
					person = new normalStudent(id, name, password, "普通学生", fmajor);     ///通过person动态创建normalStudent类对象，并传参初始化赋值
					normalStudentMenu(person);     ///进入普通学生身份的子菜单中
					return;     ///当注销账号后，跳回此语句，并返回到主菜单页面（下同）
				}
			}
		}
		if (select == 2) {
			while (ifs >> fid && ifs >> fname && ifs >> fpassword && ifs >> fmajor) {
				if (id == fid && name == fname && password == fpassword) {
					cout << "-----------------------------------" << endl;
					cout << "|       学生代表验证登录成功！    |" << endl;
					cout << "-----------------------------------" << endl;
					system("pause");
					system("cls");
					person = new Monitor(id, name, password, "学生代表", fmajor);     ///通过person动态创建Monitor类对象，并传参初始化赋值
					MonitorMenu(person);     ///进入学生代表身份的子菜单中
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
					cout << "|        辅导员验证登录成功！     |" << endl;
					cout << "-----------------------------------" << endl;
					system("pause");
					system("cls");
					person = new Counsellor(id, name, password, fmajor);     ///通过person动态创建Counsellor类对象，并传参初始化赋值
					CounsellorMenu(person);     ///进入辅导员身份的子菜单中
					return;
				}
			}
		}
		if (select == 2) {
			while (ifs >> fid && ifs >> fname && ifs >> fpassword&&ifs>>fmajor) {
				if (id == fid && name == fname && password == fpassword) {
					cout << "-----------------------------------" << endl;
					cout << "|       技术老师验证登录成功！    |" << endl;
					cout << "-----------------------------------" << endl;
					system("pause");
					system("cls");
					person = new Technician(id, name, password, "技术人员");     ///通过person动态创建Technician类对象，并传参初始化赋值
					TechnicianMenu(person);     ///进入技术老师身份的子菜单中
					return;
				}
			}
		}
	}
	else if (choice == 3) {
		while (ifs >> fname && ifs >> fpassword) {
			if (name == fname && password == fpassword) {
				cout << "-----------------------------------" << endl;
				cout << "|       管理员验证登录成功！      |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, password, "系统管理员");     ///通过person动态创建Manager类对象，并传参初始化赋值
				managerMenu(person);     ///进入管理员身份的子菜单中
				return;
			}
		}
	}
	cout << "-----------------------------------" << endl;
	cout << "|           验证登录失败！        |" << endl;
	cout << "-----------------------------------" << endl;

	system("pause");     ///按任意键继续
	system("cls");     ///清空屏幕
	return;
}

//普通函数：管理员类子菜单窗口
void managerMenu(User* manager) {

	///该函数包含一个参数：manager，作为对象载体，通过访问对象类内成员函数，实现该类各种功能

	while (true) {     ///一直循环，直到注销账号时break
		manager->OpenMenu();     ///输出管理员类子菜单页面
		Manager* man = (Manager*)manager;     ///强制类型转换，将manger从Identity*转成Manager*，并赋给同样为Manager*对象man，便于访问派生类独有函数与成员

		cout << "请输入你的选择：";
		string choice ;
		cin >> choice;

		if (choice == "1") {
			man->AddAccount();     ///注册用户
		}
		else if (choice == "2") {
			man->DeleteAccount();     ///删除用户
		}
		else if (choice == "3") {
			man->ChangeAccount();     ///修改用户
		}
		else if (choice == "4") {
			man->CheckAllAccount();     ///查看用户
		}
		else if (choice == "5") {
			man->FindAccount();     ///查询用户
		}
		else if (choice == "6") {
			man->CheckClassroom();     ///查看教室
		}
		else if (choice == "7") {
			man->ClearAllBook();     ///清空预约记录
		}
		else if (choice == "0") {     ///注销账号
			delete manager;     ///动态删除manager
			cout << "-----------------------------------" << endl;
			cout << "|           注销账号成功！        |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {     ///不合法输入，重新循环
			cout << "-----------------------------------" << endl;
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
		}
	}
}

//普通函数：普通学生类子菜单窗口
void normalStudentMenu(User* normalstudent)
{
	///该函数包含一个参数：normalstudent，作为对象载体，通过访问对象类内成员函数，实现该类各种功能

	while (1) {     ///一直循环，直到注销账号时break
		normalstudent->OpenMenu();     ///输出普通学生类子菜单页面
		normalStudent* man = (normalStudent*)normalstudent;     ///同样有强制类型转换

		cout << "请输入你的选择：";
		string choice;
		cin >> choice;

		if (choice == "1") {
			man->ApplyBook();     ///申请预约
		}
		else if (choice == "2") {
			man->ShowMyBook();     ///查看我的预约
		}
		else if (choice == "3") {
			man->CancelBook();     ///取消预约
		}
		else if (choice == "4") {
			man->EvaluateBook();     ///评价功能
		}
		else if (choice == "0") {     ///注销账号
			delete normalstudent;     ///动态删除normalstudent
			cout << "-----------------------------------" << endl;
			cout << "|           注销账号成功！        |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {     ///输入合法性检查
			cout << "-----------------------------------" << endl;
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
		}
	}
}

//普通函数：学生代表类子菜单窗口
void MonitorMenu(User* monitor)
{
	///该函数包含一个参数：monitor，作为对象载体，通过访问对象类内成员函数，实现该类各种功能

	while (1) {     ///一直循环，直到注销账号时break
		monitor->OpenMenu();     ///输出学生代表类子菜单页面
		Monitor* man = (Monitor*)monitor;     ///同样有强制类型转换

		cout << "请输入你的选择：";
		string choice;
		cin >> choice;

		if (choice == "1") {
			man->ApplyBook();     ///申请预约
		}
		else if (choice == "2") {
			man->ShowMyBook();     ///查看我的预约
		}
		else if (choice =="3") {
			man->ShowAllBook();     ///查看所有人的预约
		}
		else if (choice == "4") {
			man->CancelBook();     ///取消预约
		}
		else if (choice == "5") {
			man->EvaluateBook();     ///评价功能
		}
		else if (choice == "0") {     ///注销账号
			delete monitor;     ///动态删除monitor
			cout << "-----------------------------------" << endl;
			cout << "|           注销账号成功！        |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {     ///输入合法性检查
			cout << "-----------------------------------" << endl;
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
		}
	}
}

//普通函数：辅导员类子菜单窗口
void CounsellorMenu(User* counsellor)
{
	///该函数包含一个参数：counsellor，作为对象载体，通过访问对象类内成员函数，实现该类各种功能

	while (1) {     ///一直循环，直到注销账号时break
		counsellor->OpenMenu();     ///输出辅导员类子菜单页面
		Counsellor* man = (Counsellor*)counsellor;     ///同样有强制类型转换
		if (man->GetCreditScore() < 6) {     ///若操行评定分不合格，则退出用户页面，回到主菜单
			break;
		}
		cout << "请输入你的选择：";
		string choice ;
		cin >> choice;

		if (choice == "1") {
			man->CheckAllBook();     ///查看普通学生预约
		}
		else if (choice == "2") {
			man->AuditBook();     ///审核普通学生预约
		}
		else if (choice == "0") {     ///注销账号
			delete counsellor;     ///动态删除counsellor
			cout << "-----------------------------------" << endl;
			cout << "|           注销账号成功！        |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {     ///输入合法性检查
			cout << "-----------------------------------" << endl;
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
		}
	}
}

//普通函数：技术老师类子菜单窗口
void TechnicianMenu(User* technician)
{
	///该函数包含一个参数：technician，作为对象载体，通过访问对象类内成员函数，实现该类各种功能

	while (1) {     ///一直循环，直到注销账号时break
		technician->OpenMenu();     ///输出学生代表类子菜单页面
		Technician* man = (Technician*)technician;      ///同样有强制类型转换
		if (man->GetCreditScore() < 6) {     ///若操行评定分不合格，则退出用户页面，回到主菜单
			break;
		}
		cout << "请输入你的选择：";
		string choice ;
		cin >> choice;

		if (choice == "1") {
			man->CheckAllBook();     ///查看所有预约
		}
		else if (choice == "2") {
			man->AuditBook();     ///审核所有预约
		}
		else if (choice == "0") {     ///注销账号
			delete technician;     ///动态删除technician
			cout << "-----------------------------------" << endl;
			cout << "|           注销账号成功！        |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {     ///输入合法性检查
			cout << "-----------------------------------" << endl;
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
		}
	}
}
