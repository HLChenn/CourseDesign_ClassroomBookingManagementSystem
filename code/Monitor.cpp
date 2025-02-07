#include"Student.h"

//学生代表类无参构造函数
Monitor::Monitor() {};

//学生代表类有参构造函数：初始化学生代表的学号，名字，密码，身份，专业以及教室容器成员
Monitor::Monitor(string id, string name, string password, string level, string major) :Student(id, name, password, level, major) { this->InitialVector(); }

//学生代表类虚析构函数
Monitor::~Monitor() {};

//成员函数：输出学生代表类子菜单页面
void Monitor::OpenMenu()
{
	cout << "    欢迎学生代表 " +GetName()+ " 登录！ " << endl;
	cout << "-----------------------------------" << endl;
	cout << "|           1.预约教室            |" << endl;
	cout << "|           2.查看我的预约        |" << endl;
	cout << "|           3.查看所有预约        |" << endl;
	cout << "|           4.取消预约            |" << endl;
	cout << "|           5.评价预约            |" << endl;
	cout << "|           0.注销登录            |" << endl;
	cout << "-----------------------------------" << endl;
}

//成员函数：申请预约功能
void Monitor::ApplyBook()
{
	///基本结构与普通学生类“申请预约功能”一致，区别在于：
	///1.可以申请所有的教室
	///2.申请上限是3条

	if (!HitMaxRoom()) {     ///判断如果还可以申请预约，继续输出
		cout << "-----------------------------------" << endl;
		cout << "|    教室的开放时间为周一至周日   |" << endl;
		cout << "|       请输入申请预约的时间：    |" << endl;
		cout << "|             1.周一              |" << endl;
		cout << "|             2.周二              |" << endl;
		cout << "|             3.周三              |" << endl;
		cout << "|             4.周四              |" << endl;
		cout << "|             5.周五              |" << endl;
		cout << "|             6.周六              |" << endl;
		cout << "|             7.周日              |" << endl;
		cout << "|             0.返回子菜单        |" << endl;
		cout << "-----------------------------------" << endl;

		int datechoice = -1;     ///三组变量，分别对日期，时间段，教室选择
		string choice1;			 ///每一组均由string接受键盘输入值，通过stoi转换为int，并以此完成对输入的合法性检查

		int intervalchoice = -1;
		string choice2;

		int room = -1;
		string roomchoice;

		string date;     ///该组变量用来在选择完成后，进行赋值
		string interval;
		
		while (1) {     ///第一，先对日期进行选择
			cout << "请输入您的选择：";
			cin >> choice1;
			try {     ///通过try，catch语句对输入做合法性检查
				datechoice = stoi(choice1);     ///如果stoi转换失败，则抛出异常，判断为输入有误
				if (datechoice < 0 || datechoice >= 8) {
					cout << "-----------------------------------" << endl;
					cout << "|      输入有误，请重新输入！     |" << endl;
					cout << "-----------------------------------" << endl;
				}
				else if (datechoice == 0) {     ///返回子菜单
					system("pause");
					system("cls");
					return;
				}
				else {
					switch (datechoice) {
					case 1:date = "周一"; break;
					case 2:date = "周二"; break;
					case 3:date = "周三"; break;
					case 4:date = "周四"; break;
					case 5:date = "周五"; break;
					case 6:date = "周六"; break;
					case 7:date = "周日"; break;
					}
					break;
				}
			}
			catch (...) {
				cout << "-----------------------------------" << endl;     ///第二，对时间段进行选择
				cout << "|      输入有误，请重新输入！     |" << endl;
				cout << "-----------------------------------" << endl;
			}
			
		}

		cout << "-----------------------------------" << endl;
		cout << "|           请选择时间段：        |" << endl;
		cout << "|              1.上午             |" << endl;
		cout << "|              2.下午             |" << endl;
		cout << "-----------------------------------" << endl;
		while (1) {
			cout << "请输入您的选择：";
			cin >> choice2;
			try {
				intervalchoice = stoi(choice2);
				if (intervalchoice <= 0 || intervalchoice >= 3) {
					cout << "-----------------------------------" << endl;
					cout << "|      输入有误，请重新输入！     |" << endl;
					cout << "-----------------------------------" << endl;
				}
				else {
					if (intervalchoice == 1) {
						interval = "上午";
					}
					else {
						interval = "下午";
					}
					break;
				}
			}
			catch (...) {
				cout << "-----------------------------------" << endl;
				cout << "|      输入有误，请重新输入！     |" << endl;
				cout << "-----------------------------------" << endl;
			}
		}

		cout << "教室信息如下：" << endl;     ///第三，对教室进行选择
		int i = 1;     ///既用来表示索引，也用来判断可预约教室数量是否不为0
		for (auto it = GetvClassroom().begin(); it != GetvClassroom().end(); it++) {
			cout <<"[" << i << "] 教室编号：" << it->GetId() << " 可容纳人数：" << it->GetVolume() << endl;     ///对于学生代表，可以申请所有教室
			i++;
		}
		i--;
		while (1) {
			cout << "请选择教室编号,0代表返回： ";
			cin >> roomchoice;
			try {     ///对输入合法性检查
				room = stoi(roomchoice);
				if (room < 0 || room > i) {
					cout << "-----------------------------------" << endl;
					cout << "|      输入有误，请重新输入！     |" << endl;
					cout << "-----------------------------------" << endl;
				}
				else if (room == 0) {
					system("pause");
					system("cls");
					return;
				}
				else if (!OnlyOneRoom(date, interval, GetvClassroom()[room - 1].GetId())) {     ///对预约的教室是否重复的判断,如果此教室已被预约，执行下面语句
					cout << "-------------------------------------" << endl;
					cout << "| 该时间段教室已被预约，请重新输入！|" << endl;
					cout << "-------------------------------------" << endl;
				}
				else {
					break;     ///输入合法并且教室未被预约占用，跳出循环，进入写文件语句段
				}
			}
			catch (...) {
				cout << "-----------------------------------" << endl;
				cout << "|      输入有误，请重新输入！     |" << endl;
				cout << "-----------------------------------" << endl;
			}
		}
		string BookReason;     ///申请预约的原因
		while (1) {
			cout << "请输入申请用途与理由（比如，学生活动、学院活动、比赛场地征用等）： ";
			cin >> BookReason;
			if (BookReason.size() == 0) {
				cout << "-----------------------------------" << endl;
				cout << "|    理由不能为空，请重新输入！   |" << endl;
				cout << "-----------------------------------" << endl;
			}
			else {
				break;
			}
		}
		time_t now = time(0);     ///获取系统当前时间，便于写入申请预约时的时间
		tm currenttime;
		localtime_s(&currenttime, &now);     ///将系统时间初始化为本地时间
		string format = to_string(currenttime.tm_year + 1900) + "年" + to_string(currenttime.tm_mon + 1) + "月" + to_string(currenttime.tm_mday) + "日" + to_string(currenttime.tm_hour) + "时" + to_string(currenttime.tm_min) + "分" + to_string(currenttime.tm_sec) + "秒";
		string second = to_string(now);     ///上述两个操作，分别格式化所得到的时间和从1970.1.1至今的秒数

		ofstream ofs(BOOK_FILE, ios::out | ios::app);     ///预约输入的内容收取全部完成，下面是将新记录追加写入BookFile文件的过程
		ofs << "预约日期:" << date << " ";
		ofs << "预约时间段:" << interval << " ";
		ofs << "预约教室:" << GetvClassroom()[room - 1].GetId() << " ";
		ofs << "预约人身份:" << GetLevel() << " ";
		ofs << "预约人:" << GetName() << " ";
		ofs << "预约人学号:" << GetStudentId() << " ";
		ofs << "预约人专业:" << GetMajor() << " ";
		ofs << "预约用途与理由:" << BookReason << " ";
		ofs << "初审老师:暂无" << " ";
		ofs << "评价1:暂未评价" << " ";
		ofs << "终审老师:暂无" << " ";
		ofs << "评价2:暂未评价" << " ";
		ofs << "预约状态:" << 1 << endl;
		ofs << "申请时间:" << format << " ";
		ofs << "初审时间:暂无" << " ";
		ofs << "终审时间:暂无" << " ";
		ofs << "特征值1:" << second << " ";
		ofs << "特征值2:暂无" << " ";
		ofs << "特征值3:暂无" << endl;


		cout << "-----------------------------------" << endl;
		cout << "| 预约成功！请及时查看待审核信息！|" << endl;
		cout << "-----------------------------------" << endl;

		ofs.close();
	}
	else {     ///如果上述整一个过程都不执行，也就是申请记录达到上限，那就执行下面语句
		cout << "-----------------------------------------------------" << endl;
		cout << "|  您待审核的预约申请已达上限（3），无法继续预约！  |" << endl;
		cout << "-----------------------------------------------------" << endl;
	}
	system("pause");	  ///按任意键继续
	system("cls");		  ///清屏
}

//成员函数：查看我的预约功能
void Monitor::ShowMyBook()
{
	///基本结构与普通学生类“查看我的预约功能”一致，区别在于：
	///1.学生代表没有预约状态为“3”的代码段

	BookFile file;     ///创立预约记录文件类的对象，建立起用户与文件信息联系的桥梁
	if (file.GetSize() == 0 || !HasBookFile(file)) {     ///如果没有自己的预约记录，那么输出下面语句
		cout << "-----------------------------------" << endl;
		cout << "|        没有您的预约记录！       |" << endl;
		cout << "-----------------------------------" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "-----------------------------------" << endl;     ///如果有记录，输出下面语句
	cout << "|        请选择要查看的预约：     |" << endl;
	cout << "|         1.已取消的预约          |" << endl;
	cout << "|         2.失败的预约            |" << endl;
	cout << "|         3.正在审核的预约        |" << endl;
	cout << "|         4.已成功的预约          |" << endl;
	cout << "|         0.返回子菜单            |" << endl;
	cout << "-----------------------------------" << endl;
	string choice;
	int index = 1;
	while (1) {
		cout << "请输入您的选择：";
		cin >> choice;
		if (choice == "1") {     ///第一个判断：是否有已取消的预约，即预约状态为“0” 
			if (!HasBookFileIndeed(file, "0")) {     ///通过更进一步的函数（HasBookFileIndeed），判断自己是否有下列更细分类的预约记录，如果没有，同样输出没有记录，然后返回子菜单
				cout << "-----------------------------------" << endl;
				cout << "|           没有预约记录！        |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				return;
			}
			for (int i = 0; i < file.GetSize(); i++) {     ///输出符合条件的预约记录
				if (file.GetBookdata()[i]["预约人学号"] == this->GetStudentId() && file.GetBookdata()[i]["预约人身份"] == "学生代表" && file.GetBookdata()[i]["预约状态"] == "0") {
					cout << "[" << index++ << "]" << endl;
					cout << "预约日期：" << file.GetBookdata()[i]["预约日期"] << endl;
					cout << "预约时间段：" << (file.GetBookdata()[i]["预约时间段"] == "1" ? "上午" : "下午") << endl;
					cout << "教室：" << file.GetBookdata()[i]["预约教室"] << endl;
					cout << "用途与理由：" << file.GetBookdata()[i]["预约用途与理由"] << endl;
					string status = "已取消预约!";
					cout << status << endl;
					cout << "终审老师：" << file.GetBookdata()[i]["终审老师"] << endl;
					cout << "申请时间：" << file.GetBookdata()[i]["申请时间"] << endl;
					cout << "---------------------------------------" << endl;
				}
			}
			break;
		}
		else if (choice == "2") {     ///第二个判断：是否有失败的预约，即预约状态为“-1”
			if (!HasBookFileIndeed(file, "-1")) {
				cout << "-----------------------------------" << endl;
				cout << "|           没有预约记录！        |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				return;
			}
			for (int i = 0; i < file.GetSize(); i++) {
				if (file.GetBookdata()[i]["预约人学号"] == this->GetStudentId() && file.GetBookdata()[i]["预约人身份"] == "学生代表" && file.GetBookdata()[i]["预约状态"] == "-1") {
					cout << "[" << index++ << "]" << endl;
					cout << "预约日期：" << file.GetBookdata()[i]["预约日期"] << endl;
					cout << "预约时间段：" << (file.GetBookdata()[i]["预约时间段"] == "1" ? "上午" : "下午") << endl;
					cout << "教室：" << file.GetBookdata()[i]["预约教室"] << endl;
					cout << "用途与理由：" << file.GetBookdata()[i]["预约用途与理由"] << endl;
					string status = "审核失败，请重新预约！";
					cout << status << endl;
					cout << "终审老师：" << file.GetBookdata()[i]["终审老师"] << endl;
					cout << "申请时间：" << file.GetBookdata()[i]["申请时间"] << endl;
					cout << "终审时间：" << file.GetBookdata()[i]["终审时间"] << endl;
					cout << "---------------------------------------" << endl;
				}
			}
			break;
		}
		else if (choice == "3") {     ///第三个判断：是否有在审核的预约，即预约状态为“1”
			if (!HasBookFileIndeed(file, "1")) {
				cout << "-----------------------------------" << endl;
				cout << "|           没有预约记录！        |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				return;
			}
			for (int i = 0; i < file.GetSize(); i++) {
				if (file.GetBookdata()[i]["预约人学号"] == this->GetStudentId() && file.GetBookdata()[i]["预约人身份"] == "学生代表" && file.GetBookdata()[i]["预约状态"] == "1" ) {
					cout << "[" << index++ << "]" << endl;
					cout << "预约日期：" << file.GetBookdata()[i]["预约日期"] << endl;
					cout << "预约时间段：" << (file.GetBookdata()[i]["预约时间段"] == "1" ? "上午" : "下午") << endl;
					cout << "教室：" << file.GetBookdata()[i]["预约教室"] << endl;
					cout << "用途与理由：" << file.GetBookdata()[i]["预约用途与理由"] << endl;
					string status;
					if (file.GetBookdata()[i]["预约状态"] == "1") {
						status += "正在审核中！";
					}
					cout << status << endl;
					cout << "终审老师：" << file.GetBookdata()[i]["终审老师"] << endl;
					cout << "申请时间：" << file.GetBookdata()[i]["申请时间"] << endl;
					cout << "终审时间：" << file.GetBookdata()[i]["终审时间"] << endl;
					cout << "---------------------------------------" << endl;
				}
			}
			break;
		}
		else if (choice == "4") {     ///第四个判断：是否有成功的预约，即预约状态为“2”
			if (!HasBookFileIndeed(file, "2")) {
				cout << "-----------------------------------" << endl;
				cout << "|           没有预约记录！        |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				return;
			}
			for (int i = 0; i < file.GetSize(); i++) {
				if (file.GetBookdata()[i]["预约人学号"] == this->GetStudentId() && file.GetBookdata()[i]["预约人身份"] == "学生代表" && file.GetBookdata()[i]["预约状态"] == "2") {
					cout << "[" << index++ << "]" << endl;
					cout << "预约日期：" << file.GetBookdata()[i]["预约日期"] << endl;
					cout << "预约时间段：" << (file.GetBookdata()[i]["预约时间段"] == "1" ? "上午" : "下午") << endl;
					cout << "教室：" << file.GetBookdata()[i]["预约教室"] << endl;
					cout << "用途与理由：" << file.GetBookdata()[i]["预约用途与理由"] << endl;
					string status = "审核成功，已预约！";
					cout << status << endl;
					cout << "终审老师：" << file.GetBookdata()[i]["终审老师"] << endl;
					cout << "申请时间：" << file.GetBookdata()[i]["申请时间"] << endl;
					cout << "终审时间：" << file.GetBookdata()[i]["终审时间"] << endl;
					cout << "---------------------------------------" << endl;
				}
			}
			break;
		}
		else if (choice == "0") {     ///0返回子菜单
			system("cls");
			return;
		}
		else {     ///其他输入均不合法
			cout << "-----------------------------------" << endl;
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
			system("cls");
		}
	}
	system("pause");
	system("cls");
}

//成员函数：查看所有人的预约功能（普通学生没有）
void Monitor::ShowAllBook()
{
	BookFile file;     ///创立预约记录文件类的对象，建立起用户与文件信息联系的桥梁
	if (file.GetSize() == 0) {     ///此时判断记录是否为空即可
		cout << "-----------------------------------" << endl;
		cout << "|           没有预约记录！        |" << endl;
		cout << "-----------------------------------" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "-----------------------------------" << endl;     ///如果有记录，输出下面语句
	cout << "|        请选择要查看的预约：     |" << endl;
	cout << "|         1.已取消的预约          |" << endl;
	cout << "|         2.失败的预约            |" << endl;
	cout << "|         3.正在审核的预约        |" << endl;
	cout << "|         4.已成功的预约          |" << endl;
	cout << "|         0.返回子菜单            |" << endl;
	cout << "-----------------------------------" << endl;

	string choice;
	int index = 1;
	while (1) {
		cout << "请输入您的选择：";
		cin >> choice;
		if (choice == "1") {     ///第一个判断：是否有已取消的预约，即预约状态为“0” 
			if (!HasBookFileToCheck(file,"0")) {     ///通过更进一步的函数（HasBookFileToCheck），判断自己是否有下列更细分类的预约记录，如果没有，同样输出没有记录，然后返回子菜单
				cout << "-----------------------------------" << endl;
				cout << "|           没有预约记录！        |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				return;
			}
			for (int i = 0; i < file.GetSize(); i++) {     ///输出符合条件的预约记录
				if (file.GetBookdata()[i]["预约状态"] == "0") {
					cout << "[" << index++ << "]" << endl;
					cout << "预约日期：" << file.GetBookdata()[i]["预约日期"] << endl;
					cout << "预约时间段：" << (file.GetBookdata()[i]["预约时间段"] == "1" ? "上午" : "下午") << endl;
					cout << "教室：" << file.GetBookdata()[i]["预约教室"] << endl;
					cout << "预约人身份：" << file.GetBookdata()[i]["预约人身份"] << endl;
					cout << "预约人：" << file.GetBookdata()[i]["预约人"] << endl;
					cout << "预约人学号：" << file.GetBookdata()[i]["预约人学号"] << endl;
					cout << "预约人专业：" << file.GetBookdata()[i]["预约人专业"] << endl;
					string status = "已取消预约!";
					cout << status << endl;
					cout << "初审老师：" << file.GetBookdata()[i]["初审老师"] << endl;
					cout << "终审老师：" << file.GetBookdata()[i]["终审老师"] << endl;
					cout << "申请时间：" << file.GetBookdata()[i]["申请时间"] << endl;
					cout << "---------------------------------------" << endl;
				}
			}
			break;
		}
		else if (choice == "2") {     ///第二个判断：是否有失败的预约，即预约状态为“-1”
			if (!HasBookFileToCheck(file, "-1")) {
				cout << "-----------------------------------" << endl;
				cout << "|           没有预约记录！        |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				return;
			}
			for (int i = 0; i < file.GetSize(); i++) {
				if (file.GetBookdata()[i]["预约状态"] == "-1") {
					cout << "[" << index++ << "]" << endl;
					cout << "预约日期：" << file.GetBookdata()[i]["预约日期"] << endl;
					cout << "预约时间段：" << (file.GetBookdata()[i]["预约时间段"] == "1" ? "上午" : "下午") << endl;
					cout << "教室：" << file.GetBookdata()[i]["预约教室"] << endl;
					cout << "预约人身份：" << file.GetBookdata()[i]["预约人身份"] << endl;
					cout << "预约人：" << file.GetBookdata()[i]["预约人"] << endl;
					cout << "预约人学号：" << file.GetBookdata()[i]["预约人学号"] << endl;
					cout << "预约人专业：" << file.GetBookdata()[i]["预约人专业"] << endl;
					string status = "审核失败，请重新预约！";
					cout << status << endl;
					cout << "初审老师：" << file.GetBookdata()[i]["初审老师"] << endl;
					cout << "终审老师：" << file.GetBookdata()[i]["终审老师"] << endl;
					cout << "申请时间：" << file.GetBookdata()[i]["申请时间"] << endl;
					cout << "初审时间：" << file.GetBookdata()[i]["初审时间"] << endl;
					cout << "终审时间：" << file.GetBookdata()[i]["终审时间"] << endl;
					cout << "---------------------------------------" << endl;
				}
			}
			break;
		}
		else if (choice == "3") {     ///第三个判断：是否有在审核的预约，即预约状态为“1”
			if (!HasBookFileToCheck(file, "1")) {
				cout << "-----------------------------------" << endl;
				cout << "|           没有预约记录！        |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				return;
			}
			for (int i = 0; i < file.GetSize(); i++) {
				if (file.GetBookdata()[i]["预约状态"] == "1"||file.GetBookdata()[i]["预约状态"]=="3") {
					cout << "[" << index++ << "]" << endl;
					cout << "预约日期：" << file.GetBookdata()[i]["预约日期"] << endl;
					cout << "预约时间段：" << (file.GetBookdata()[i]["预约时间段"] == "1" ? "上午" : "下午") << endl;
					cout << "教室：" << file.GetBookdata()[i]["预约教室"] << endl;
					cout << "预约人身份：" << file.GetBookdata()[i]["预约人身份"] << endl;
					cout << "预约人：" << file.GetBookdata()[i]["预约人"] << endl;
					cout << "预约人学号：" << file.GetBookdata()[i]["预约人学号"] << endl;
					cout << "预约人专业：" << file.GetBookdata()[i]["预约人专业"] << endl;
					string status;
					if (file.GetBookdata()[i]["预约状态"] == "1") {
						status += "正在审核中！";
					}
					else if (file.GetBookdata()[i]["预约状态"] == "3") {
						status += "已通过辅导员初步审核，等待最终审核！";
					}
					cout << status << endl;
					cout << "初审老师：" << file.GetBookdata()[i]["初审老师"] << endl;
					cout << "终审老师：" << file.GetBookdata()[i]["终审老师"] << endl;
					cout << "申请时间：" << file.GetBookdata()[i]["申请时间"] << endl;
					cout << "初审时间：" << file.GetBookdata()[i]["初审时间"] << endl;
					cout << "终审时间：" << file.GetBookdata()[i]["终审时间"] << endl;
					cout << "---------------------------------------" << endl;
				}
			}
			break;
		}
		else if (choice == "4") {     ///第四个判断：是否有成功的预约，即预约状态为“2”
			if (!HasBookFileToCheck(file, "2")) {
				cout << "-----------------------------------" << endl;
				cout << "|           没有预约记录！        |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				return;
			}
			for (int i = 0; i < file.GetSize(); i++) {
				if (file.GetBookdata()[i]["预约状态"] == "2") {
					cout << "[" << index++ << "]" << endl;
					cout << "预约日期：" << file.GetBookdata()[i]["预约日期"] << endl;
					cout << "预约时间段：" << (file.GetBookdata()[i]["预约时间段"] == "1" ? "上午" : "下午") << endl;
					cout << "教室：" << file.GetBookdata()[i]["预约教室"] << endl;
					cout << "预约人身份：" << file.GetBookdata()[i]["预约人身份"] << endl;
					cout << "预约人：" << file.GetBookdata()[i]["预约人"] << endl;
					cout << "预约人学号：" << file.GetBookdata()[i]["预约人学号"] << endl;
					cout << "预约人专业：" << file.GetBookdata()[i]["预约人专业"] << endl;
					string status = "审核成功，已预约！";
					cout << status << endl;
					cout << "初审老师：" << file.GetBookdata()[i]["初审老师"] << endl;
					cout << "终审老师：" << file.GetBookdata()[i]["终审老师"] << endl;
					cout << "申请时间：" << file.GetBookdata()[i]["申请时间"] << endl;
					cout << "初审时间：" << file.GetBookdata()[i]["初审时间"] << endl;
					cout << "终审时间：" << file.GetBookdata()[i]["终审时间"] << endl;
					cout << "---------------------------------------" << endl;
				}
			}
			break;
		}
		else if (choice == "0") {     ///0返回子菜单
			system("cls");
			return;
		}
		else {     ///其他输入均不合法
			cout << "-----------------------------------" << endl;
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
			system("cls");
		}
	}
	system("pause");
	system("cls");
}

//成员函数：取消预约功能
void Monitor::CancelBook()
{
	///基本结构与普通学生类“取消预约功能”一致，区别在于：
	///1.没有预约状态为“3”的相关代码段，也就是没有“通过辅导员的审核”这一步
	 
	BookFile file;
	if (file.GetSize() == 0 || !NotCancel(file)) {
		cout << "-----------------------------------" << endl;
		cout << "|       没有可执行的预约记录！    |" << endl;
		cout << "-----------------------------------" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "|  预约状态为“审核中”与“审核成功”的均可取消预约，请查看要取消的预约记录  |" << endl;
	cout << "--------------------------------------------------------------------------" << endl;

	vector<int>v;     ///实例化int型vector对象v，将下面循环中符合条件的：
					  ///1.学号是自己的
					  ///2.身份是学生代表
					  ///3.记录文件中预约状态为“1”或“2”
					  ///那么就将下标i的数值插入到v中，也就是将bookdata容器的符合条件的行数值数列映射到了v中，方便后面删除时作为索引依据
	int index = 1;
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["预约人学号"] == this->GetStudentId () && (file.GetBookdata()[i]["预约状态"] == "1" || file.GetBookdata()[i]["预约状态"] == "2")) {
			v.push_back(i);
			cout << "[" << index++ << "] " << endl;
			cout << "预约日期：" << file.GetBookdata()[i]["预约日期"] << endl;
			cout << "预约时间段：" << (file.GetBookdata()[i]["预约时间段"] == "1" ? "上午" : "下午") << endl;
			cout << "教室：" << file.GetBookdata()[i]["预约教室"] << endl;
			cout << "预约人身份" << file.GetBookdata()[i]["预约人身份"] << endl;
			cout << "预约人：" << file.GetBookdata()[i]["预约人"] << endl;
			cout << "预约人学号：" << file.GetBookdata()[i]["预约人学号"] << endl;
			cout << "预约人专业：" << file.GetBookdata()[i]["预约人专业"] << endl;
			cout << "用途与理由：" << file.GetBookdata()[i]["预约用途与理由"] << endl;
			string status = "预约状态：";
			if (file.GetBookdata()[i]["预约状态"] == "1") {
				status += "正在审核中！";
			}
			if (file.GetBookdata()[i]["预约状态"] == "2") {
				status += "审核成功,已预约!";
			}
			cout << status << endl;
			cout << "初审老师：" << file.GetBookdata()[i]["初审老师"] << endl;
			cout << "终审老师：" << file.GetBookdata()[i]["终审老师"] << endl;
			cout << "---------------------------------------" << endl;
		}
	}
	index--;
	int choice = -1;
	string change;
	while (1) {
		cout << "请输入要取消的编号，0代表返回： ";
		cin >> change;
		try {     ///输入合法性判断
			choice = stoi(change);
			if (choice >= 0 && choice <= index) {
				if (choice == 0) {
					break;
				}
																			 ///将预约状态设为0，即取消预约
				file.GetBookdata()[v[choice - 1]]["预约状态"] = "0";		 ///choice对应index，而index是从1开始，但容器v下标从0开始，需要减一
																			 ///然后将v对应下标里存的bookdata里的索引值读出来，实现了从v到bookdata内找到记录并修改的目的

				file.UpdateBook();     ///修改完后同步更新文件里的记录
				cout << "-------------------------------------" << endl;
				cout << "| 已经成功取消预约，请注意查看信息！|" << endl;
				cout << "-------------------------------------" << endl;
				break;
			}
			cout << "-----------------------------------" << endl;     ///如果输入超过范围，判为有误
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
		}
		catch (...) {
			cout << "-----------------------------------" << endl;     
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
		}
	}
	system("pause");		///按任意键继续
	system("cls");			///清屏
}

//成员函数：评价功能
void Monitor::EvaluateBook()
{
	string choice1;     ///用来第一层选择
	while (1) {
		cout << "-----------------------------------" << endl;
		cout << "|        请选择查看下列预约：     |" << endl;
		cout << "|        1.已评价过的预约申请     |" << endl;
		cout << "|        2.待评价的预约申请       |" << endl;
		cout << "|        0.返回子菜单             |" << endl;
		cout << "-----------------------------------" << endl;

		cout << "请输入您的选择：";
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
			cout << "|      输入有误，请重新输入！     |" << endl;
			cout << "-----------------------------------" << endl;
		}
	}
	BookFile file;
	int index = 0;
	vector<int> v;      ///与“取消预约功能”有类似用法
	if (choice1 == "1") {
		for (int i = 0; i < file.GetSize(); i++) {
			if (file.GetBookdata()[i]["预约人学号"] == GetStudentId() && file.GetBookdata()[i]["预约人身份"] == "学生代表" && file.GetBookdata()[i]["预约状态"] == "2" && file.GetBookdata()[i]["评价2"] != "暂未评价") {
				cout << "[" << ++index << "]" << endl;
				cout << "预约日期：" << file.GetBookdata()[i]["预约日期"] << endl;
				cout << "预约时间段：" << (file.GetBookdata()[i]["预约时间段"] == "1" ? "上午" : "下午") << endl;
				cout << "教室：" << file.GetBookdata()[i]["预约教室"] << endl;
				cout << "用途与理由：" << file.GetBookdata()[i]["预约用途与理由"] << endl;
				cout << "终审老师：" << file.GetBookdata()[i]["终审老师"] << endl;
				cout << "对终审老师评价分：" << file.GetBookdata()[i]["评价2"] << endl;
				cout << "申请时间：" << file.GetBookdata()[i]["申请时间"] << endl;
				cout << "终审时间：" << file.GetBookdata()[i]["终审时间"] << endl;
				cout << "--------------------------------------" << endl;
			}
		}
		if (index == 0) {
			cout << "-----------------------------------" << endl;
			cout << "|      没有已评价过的预约申请！   |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	else if (choice1 == "2") {
		for (int i = 0; i < file.GetSize(); i++) {
			if (file.GetBookdata()[i]["预约人学号"] == GetStudentId() && file.GetBookdata()[i]["预约人身份"] == "学生代表" && file.GetBookdata()[i]["预约状态"] == "2" && file.GetBookdata()[i]["评价2"] == "暂未评价") {
				v.push_back(i);
				cout << "[" << ++index << "]" << endl;
				cout << "预约日期：" << file.GetBookdata()[i]["预约日期"] << endl;
				cout << "预约时间段：" << (file.GetBookdata()[i]["预约时间段"] == "1" ? "上午" : "下午") << endl;
				cout << "教室：" << file.GetBookdata()[i]["预约教室"] << endl;
				cout << "用途与理由：" << file.GetBookdata()[i]["预约用途与理由"] << endl;
				cout << "终审老师：" << file.GetBookdata()[i]["终审老师"] << endl;
				cout << "--------------------------------------" << endl;

			}
		}
		if (index == 0) {
			cout << "-----------------------------------" << endl;
			cout << "|      没有需待评价的预约申请！   |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
			return;
		}

		string choice2;
		int select;
		while (1) {
			bool flag = 0;     ///标志，若为1，则退出该层循环
			string score1;
			cout << "请选择要评价的预约记录：";
			cin >> choice2;
			try {
				select = stoi(choice2);
				if (select <= 0 || select > index) {
					cout << "-----------------------------------" << endl;
					cout << "|      输入有误，请重新输入！     |" << endl;
					cout << "-----------------------------------" << endl;
				}
				else {
					while (1) {

						int time = stoi(file.GetBookdata()[v[select - 1]]["特征值3"]) - stoi(file.GetBookdata()[v[select - 1]]["特征值1"]);     ///终审时间-申请时间=审核总用时
						cout << "审核总用时：" << CalculateAuditTime(time) << endl;

						cout << "请对该技术老师评价分（10分为满分）：";
						cin >> score1;
						if (stoi(score1) >= 0 && stoi(score1) <= 10) {
							file.GetBookdata()[v[static_cast<std::vector<int, std::allocator<int>>::size_type>(select) - 1]]["评价2"] = score1;
							file.UpdateBook();     ///及时更新数据
							cout << "-----------------------------------" << endl;
							cout << "|         评价完成，感谢！        |" << endl;
							cout << "-----------------------------------" << endl;
							flag = 1;     ///完成评价操作，赋值为1
							break;
						}
						else {
							cout << "-----------------------------------" << endl;
							cout << "|      输入有误，请重新输入！     |" << endl;
							cout << "-----------------------------------" << endl;
						}
					}
				}
			}
			catch (...) {
				cout << "-----------------------------------" << endl;
				cout << "|      输入有误，请重新输入！     |" << endl;
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

//成员函数：初始化教室容器成员信息
void Monitor::InitialVector()
{
	GetvClassroom().clear();     ///先清空教室容器，避免读取重叠出错
	ifstream ifs(CLASSROOM_FILE, ios::in);     ///打开存放教室数据的文件，读取
	Classroom c;
	while (ifs >> c.GetId() && ifs >> c.GetVolume()) {
		GetvClassroom().push_back(c);     ///没有条件，所有教室信息均插入容器中
	}
	ifs.close();
}

//成员函数：判断是否存在自己的预约记录，有返回true，否则返回false
bool Monitor::HasBookFile(BookFile &file)
{
	///函数参数：取BookFile类的参数file的引用，减少开销

	for (int i = 0; i < file.GetSize(); i++) {      ///注意因为普通学生和学生代表学号可以重叠，所以是两个判断
		if (file.GetBookdata()[i]["预约人学号"] == this->GetStudentId()&&file.GetBookdata()[i]["预约人身份"]=="学生代表") {
			return 1;
		}
	}
	return 0;
}

bool Monitor::HasBookFileIndeed(BookFile file, string choice)
{
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["预约人学号"] == GetStudentId() && file.GetBookdata()[i]["预约人身份"] == GetLevel() && file.GetBookdata()[i]["预约状态"] == choice) {
			return 1;
		}
	}
	return 0;
}

//成员函数：判断是否存在合理（即没有被取消）的预约，有返回true，否则返回false
bool Monitor::NotCancel(BookFile& file)
{
	///函数参数：取BookFile类的参数file的引用，减少开销

	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["预约人学号"] == this->GetStudentId() && (file.GetBookdata()[i]["预约状态"] == "1" || file.GetBookdata()[i]["预约状态"] == "2" )) {
			return 1;
		}
	}
	return 0;
}

//成员函数：判断是否达到预约（3条）上限，有返回true，否则返回false
bool Monitor::HitMaxRoom()
{
	int sum = 0;
	BookFile file;
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["预约人学号"] == GetStudentId() && file.GetBookdata()[i]["预约状态"] == "1") {
			sum++;
		}
	}
	if (sum >= 3) {
		return 1;
	}
	return 0;
}


