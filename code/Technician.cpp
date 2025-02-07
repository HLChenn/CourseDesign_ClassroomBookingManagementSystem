#include"Teacher.h"

//技术老师类无参构造函数
Technician::Technician() {};

//技术老师类有参构造函数：初始化编号，名字，密码，专业（默认为“技术人员”）
Technician::Technician(string id, string name, string password,string major) :Teacher(id, name, password,major) {}

//技术老师类虚析构函数
Technician::~Technician() {};

//成员函数：输出技术老师类子菜单页面
void Technician::OpenMenu()
{
	cout << "    欢迎技术老师 "+GetName()+" 登录！" << endl;
	if (CalculateScore()) {     ///判断与输出操行评定分，若合格，才能继续查看和审核学生的预约
		cout << "-----------------------------------" << endl;
		cout << "|          1.查看所有学生预约     |" << endl;
		cout << "|          2.审核预约             |" << endl;
		cout << "|          0.注销登录             |" << endl;
		cout << "-----------------------------------" << endl;
	}
	else {
		system("pause");
		system("cls");
		return;
	}
}

//成员函数：查看所有学生的预约功能
void Technician::CheckAllBook()
{
	///基本结构与辅导员类“查看预约功能”一致，区别在于：
	///1.判断有无预约记录只需判断储存预约记录的文件是否为空
	///2.没有身份限制，可以查看所有学生的预约记录

	BookFile file;     ///创立预约记录文件类的对象，建立起用户与文档文件信息联系的桥梁
	if (file.GetSize() == 0) {     ///只要文件大小为空，则输出下面语句
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
			if (!HasBookFileToCheck(file, "0")) {     ///通过更进一步的函数（HasBookFileToCheck），判断自己是否有下列更细分类的预约记录，如果没有，同样输出没有记录，然后返回子菜单
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
					cout << "用途与理由：" << file.GetBookdata()[i]["预约用途与理由"] << endl;
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
					cout << "用途与理由：" << file.GetBookdata()[i]["预约用途与理由"] << endl;
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
			if (!HasBookFileToCheck(file, "1")&&!HasBookFileToCheck(file,"3")) {
				cout << "-----------------------------------" << endl;
				cout << "|           没有预约记录！        |" << endl;
				cout << "-----------------------------------" << endl;
				system("pause");
				system("cls");
				return;
			}
			for (int i = 0; i < file.GetSize(); i++) {
				if (file.GetBookdata()[i]["预约状态"] == "1" || file.GetBookdata()[i]["预约状态"] == "3") {
					cout << "[" << index++ << "]" << endl;
					cout << "预约日期：" << file.GetBookdata()[i]["预约日期"] << endl;
					cout << "预约时间段：" << (file.GetBookdata()[i]["预约时间段"] == "1" ? "上午" : "下午") << endl;
					cout << "教室：" << file.GetBookdata()[i]["预约教室"] << endl;
					cout << "预约人身份：" << file.GetBookdata()[i]["预约人身份"] << endl;
					cout << "预约人：" << file.GetBookdata()[i]["预约人"] << endl;
					cout << "预约人学号：" << file.GetBookdata()[i]["预约人学号"] << endl;
					cout << "预约人专业：" << file.GetBookdata()[i]["预约人专业"] << endl;
					cout << "用途与理由：" << file.GetBookdata()[i]["预约用途与理由"] << endl;
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
					cout << "用途与理由：" << file.GetBookdata()[i]["预约用途与理由"] << endl;
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

//成员函数：审核所有学生的预约功能
void Technician::AuditBook()
{
	///基本结构与辅导员类“审核预约功能”一致，区别在于：
	///1.没有身份限制，可以审核所有学生的预约，但判断条件是：
	///a.普通学生申请并且通过了辅导员初步审核的预约（预约状态为“3”）
	///b.学生代表申请的预约（预约状态为“1”）
	/// 
		BookFile file;     ///创立预约记录文件类的对象，建立起用户与文件信息联系的桥梁
		if (file.GetSize() == 0 || !HasBookAudit()) {     ///如果没有需要审核的所有的学生的预约记录，则输出下面语句
			cout << "-----------------------------------" << endl;
			cout << "|     没有需要审核的预约记录！    |" << endl;
			cout << "-----------------------------------" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "待审核的记录如下：" << endl;

		vector<int>v;     ///与普通学生类“取消预约功能”有类似的做法，创建v，作为装入bookdata中符合条件索引的容器

		int index = 1;      ///默认先展示学生代表的预约，再展示普通学生的预约记录
		for (int i = 0; i < file.GetSize(); i++) {
			if (file.GetBookdata()[i]["预约状态"] == "1" && file.GetBookdata()[i]["预约人身份"] == "学生代表") {
				v.push_back(i);
				cout << "[" << index++ << "]" << endl;
				cout << "预约日期：" << file.GetBookdata()[i]["预约日期"] << endl;
				cout << "预约时间段：" << (file.GetBookdata()[i]["预约时间段"] == "1" ? "上午" : "下午") << endl;
				cout << "教室：" << file.GetBookdata()[i]["预约教室"] << endl;
				cout << "身份：" << file.GetBookdata()[i]["预约人身份"] << endl;
				cout << "预约人：" << file.GetBookdata()[i]["预约人"] << endl;
				cout << "预约人学号：" << file.GetBookdata()[i]["预约人学号"] << endl;
				cout << "预约人专业：" << file.GetBookdata()[i]["预约人专业"] << endl;
				cout << "用途与理由：" << file.GetBookdata()[i]["预约用途与理由"] << endl;
				string status = "预约状态：";
				if (file.GetBookdata()[i]["预约状态"] == "1") {
					status += "正在审核中！";
				}
				cout << status << endl;
				cout << "初审老师：" << file.GetBookdata()[i]["初审老师"] << endl;
				cout << "终审老师：" << file.GetBookdata()[i]["终审老师"] << endl;
				cout << "申请时间：" << file.GetBookdata()[i]["申请时间"] << endl;
				cout << "---------------------------------------" << endl;
			}
		}
		for (int i = 0; i < file.GetSize(); i++) {
			if (file.GetBookdata()[i]["预约状态"] == "3") {
				v.push_back(i);
				cout << "[" << index++ << "]" << endl;
				cout << "预约日期：" << file.GetBookdata()[i]["预约日期"] << endl;
				cout << "预约时间段：" << (file.GetBookdata()[i]["预约时间段"] == "1" ? "上午" : "下午") << endl;
				cout << "教室：" << file.GetBookdata()[i]["预约教室"] << endl;
				cout << "身份：" << file.GetBookdata()[i]["预约人身份"] << endl;
				cout << "预约人：" << file.GetBookdata()[i]["预约人"] << endl;
				cout << "预约人学号：" << file.GetBookdata()[i]["预约人学号"] << endl;
				cout << "用途与理由：" << file.GetBookdata()[i]["预约用途与理由"] << endl;
				string status = "预约状态：";
				if (file.GetBookdata()[i]["预约状态"] == "3") {
					status += "已通过辅导员初步审核，等待技术老师审核！";
				}
				cout << status << endl;
				cout << "初审老师：" << file.GetBookdata()[i]["初审老师"] << endl;
				cout << "终审老师：" << file.GetBookdata()[i]["终审老师"] << endl;
				cout << "申请时间：" << file.GetBookdata()[i]["申请时间"] << endl;
				cout << "初审时间：" << file.GetBookdata()[i]["初审时间"] << endl;
				cout << "---------------------------------------" << endl;
			}
		}

		int choice = -1;
		string change;
		while (1) {
			cout << "请输入要审核的预约记录，0代表返回： ";
			cin >> change;
			try {     ///同样有输入合法性检查
				choice = stoi(change);
				if (choice == 0) {
					break;
				}
				if (choice > 0 && choice <= v.size()) {
					cout << "-----------------------------------" << endl;
					cout << "|          请输入审核结果：       |" << endl;
					cout << "|          1.审核通过             |" << endl;
					cout << "|          2.审核不通过           |" << endl;
					cout << "-----------------------------------" << endl;
					int select = -1;
					string changeselect;
					while (1) {
						cout << "请输入您的选择：";
						cin >> changeselect;
						try {
							select = stoi(changeselect);
							if (select < 1 || select>2) {
								cout << "-----------------------------------" << endl;
								cout << "|      输入有误，请重新输入！     |" << endl;
								cout << "-----------------------------------" << endl;
							}
							else if (select == 1) {
								file.GetBookdata()[v[choice - 1]]["预约状态"] = "2";
								break;
							}

							else if (select == 2) {
								file.GetBookdata()[v[choice - 1]]["预约状态"] = "-1";
								break;
							}
						}
						catch (...) {
							cout << "-----------------------------------" << endl;
							cout << "|      输入有误，请重新输入！     |" << endl;
							cout << "-----------------------------------" << endl;
						}
					}
					file.GetBookdata()[v[choice - 1]]["终审老师"] = GetName();

					time_t now = time(0);     ///获取系统当前时间，便于写入申请预约时的时间
					tm currenttime;
					localtime_s(&currenttime, &now);     ///将系统时间初始化为本地时间
					string format = to_string(currenttime.tm_year + 1900) + "年" + to_string(currenttime.tm_mon + 1) + "月" + to_string(currenttime.tm_mday) + "日" + to_string(currenttime.tm_hour) + "时" + to_string(currenttime.tm_min) + "分" + to_string(currenttime.tm_sec) + "秒";
					string second = to_string(now);     ///上述两个操作，分别格式化所得到的时间和从1970.1.1至今的秒数

					file.GetBookdata()[v[choice - 1]]["终审时间"] = format;
					file.GetBookdata()[v[choice - 1]]["特征值3"] = second;

					file.UpdateBook();     ///操作成功后，通过file对象将存储预约记录的文档内部数据更新
					cout << "-----------------------------------" << endl;
					cout << "|       审核完毕，感谢操作！      |" << endl;
					cout << "-----------------------------------" << endl;
					break;
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
	system("pause");
	system("cls");
}

//成员函数：判断是否有需要审核的预约记录，有返回true，否则返回false
bool Technician::HasBookAudit()
{
	BookFile file;
	int sum = 0;
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["预约人身份"] == "普通学生") {     ///如果是普通学生，需要满足通过辅导员初步审核("3")的条件
			if (file.GetBookdata()[i]["预约状态"] == "3") {
				sum++;
			}
		}
		if (file.GetBookdata()[i]["预约人身份"] == "学生代表") {     ///如果是学生代表，只需满足申请并且等待审核("1")的条件
			if (file.GetBookdata()[i]["预约状态"] == "1") {
				sum++;
			}
		}
	}
	if (sum > 0) {
		return 1;
	}
	return 0;
}

//成员函数：判断技术老师的操行分是否合格，即若分数≥6，可以继续操作，否则视为待审查用户，无法审核或查看学生预约
bool Technician::CalculateScore()
{
	///与辅导员中同名函数结构类似，区别在于：
	///1.身份和评价类型不同
	
	BookFile file;
	double sum = 0;
	double score = 0;
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["终审老师"] == GetName() && file.GetBookdata()[i]["评价2"] != "暂未评价") {
			sum++;
			score += stod(file.GetBookdata()[i]["评价2"]);
		}
	}
	if (sum == 0) {
		cout << "您的操行评定分为：" << GetCreditScore() << "(优秀)" << endl;
		return 1;
	}
	else {
		GetCreditScore() = score / sum;
		cout << fixed << setprecision(2) << "您的操行评定分为：" << GetCreditScore();
		if (GetCreditScore() >= 6) {
			if (GetCreditScore() >= 9) {
				cout << "(优秀)" << endl;
			}
			else if (GetCreditScore() >= 7.5 && GetCreditScore() < 9) {
				cout << "(良好)" << endl;
			}
			else if (GetCreditScore() >= 6 && GetCreditScore() < 7.5) {
				cout << "(合格)" << endl;
			}
			return 1;
		}
		else {
			cout << "(不合格)" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "| 信用分数不合格，请联系管理员进行下一步操作！ |" << endl;
			cout << "------------------------------------------------" << endl;
			return 0;
		}
	}
}
;