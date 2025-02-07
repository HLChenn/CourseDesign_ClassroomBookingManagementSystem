#include"Teacher.h"

//辅导员类无参构造函数
Counsellor::Counsellor() {};

//辅导员类有参构造函数：初始化编号，名字，密码，专业
Counsellor::Counsellor(string id, string name, string password, string major):Teacher(id, name, password, major) {}

//辅导员类虚析构函数
Counsellor::~Counsellor() {};

//成员函数：输出辅导员类子菜单页面
void Counsellor::OpenMenu()
{
	cout << "   欢迎辅导员 " + GetName() + " 登录！" << endl;
	if (CalculateScore()) {     ///判断与输出操行评定分，若合格，才能继续查看和审核学生的预约
		cout << "-----------------------------------" << endl;
		cout << "|          1.查看普通学生预约     |" << endl;
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

//成员函数：查看仅本专业的普通学生预约功能
void Counsellor::CheckAllBook()
{
	BookFile file;     ///创立预约记录文件类的对象，建立起用户与文件信息联系的桥梁
	if (file.GetSize() == 0||!HasBookCheck()) {     ///如果文件大小为空，或者没有可以查看的本专业的普通学生的预约记录，则输出下面语句
		cout << "-----------------------------------" << endl;
		cout << "|       没有普通学生预约记录！    |" << endl;
		cout << "-----------------------------------" << endl;
		system("pause");
		system("cls");
		return;
	}

	int index = 0;     ///创建索引下标
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["预约人身份"] == "普通学生"&&file.GetBookdata()[i]["预约人专业"]==GetMajor()) {     ///条件判断：身份是普通学生且是本专业的
			cout << "[" << ++index << "]" << endl;
			cout << "预约日期：" << file.GetBookdata()[i]["预约日期"] << endl;
			cout << "预约时间段：" << (file.GetBookdata()[i]["预约时间段"] == "1" ? "上午" : "下午") << endl;
			cout << "教室：" << file.GetBookdata()[i]["预约教室"] << endl;
			cout << "预约人身份：" << file.GetBookdata()[i]["预约人身份"] << endl;
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
			if (file.GetBookdata()[i]["预约状态"] == "-1") {
				status += "审核失败，请重新预约！";
			}
			if (file.GetBookdata()[i]["预约状态"] == "0") {
				status += "已取消预约！";
			}
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
	system("pause");
	system("cls");
}

//成员函数：审核仅本专业的普通学生预约功能
void Counsellor::AuditBook()
{
	BookFile file;     ///创立预约记录文件类的对象，建立起用户与文件信息联系的桥梁
	if (file.GetSize() == 0 || !HasBookAudit()) {      ///如果没有需要审核的普通学生的预约记录，则输出下面语句
		cout << "-----------------------------------" << endl;
		cout << "|    没有需要待审核的预约记录！   |" << endl;
		cout << "-----------------------------------" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "待审核的记录如下：" << endl;
	cout << "---------------------------------------" << endl;

	vector<int>v;     ///与普通学生类“取消预约功能”有类似的做法，创建v，作为装入bookdata中符合条件索引的容器
	int index = 1;
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["预约人身份"] == "普通学生" && file.GetBookdata()[i]["预约状态"] == "1" && file.GetBookdata()[i]["预约人专业"] == GetMajor()) {
			v.push_back(i);
			cout << "[" << index++ << "]" << endl;
			cout << "预约日期：" << file.GetBookdata()[i]["预约日期"] << endl;
			cout << "预约时间段：" << (file.GetBookdata()[i]["预约时间段"] == "1" ? "上午" : "下午") << endl;
			cout << "教室：" << file.GetBookdata()[i]["预约教室"] << endl;
			cout << "预约人身份：" << file.GetBookdata()[i]["预约人身份"] << endl;
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

	cout << "请输入要审核的预约记录，0代表返回" << endl;
	int choice = -1;
	string change;
	while (1) {

		cin >> change;
		try {     ///同样有输入合法性检查
			choice = stoi(change);
			if (choice == 0) {
				break;
			}
			if (choice > 0 && choice <= v.size()) {
				cout << "-----------------------------------" << endl;
				cout << "|         请输入审核结果：        |" << endl;
				cout << "|         1.初步审核通过          |" << endl;
				cout << "|         2.初步审核不通过        |" << endl;
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
							file.GetBookdata()[v[choice - 1]]["预约状态"] = "3";
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
				file.GetBookdata()[v[choice - 1]]["初审老师"] = GetName();     ///初步审核结束，该预约记录的初审老师对应更改
				
				time_t now = time(0);     ///获取系统当前时间，便于写入申请预约时的时间
				tm currenttime;
				localtime_s(&currenttime, &now);     ///将系统时间初始化为本地时间
				string format = to_string(currenttime.tm_year + 1900) + "年" + to_string(currenttime.tm_mon + 1) + "月" + to_string(currenttime.tm_mday) + "日" + to_string(currenttime.tm_hour) + "时" + to_string(currenttime.tm_min) + "分" + to_string(currenttime.tm_sec) + "秒";
				string second = to_string(now);     ///上述两个操作，分别格式化所得到的时间和从1970.1.1至今的秒数

				file.GetBookdata()[v[choice - 1]]["初审时间"] = format;
				file.GetBookdata()[v[choice - 1]]["特征值2"] = second;

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

//成员函数：判断是否存在本专业的普通学生的预约记录，若有则返回true，否则返回false
bool Counsellor::HasBookCheck()
{
	BookFile file;
	int sum = 0;
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["预约人身份"] == "普通学生"&&file.GetBookdata()[i]["预约人专业"]==GetMajor()) {     ///当预约记录里面存在记录
			sum++;																									  ///并且是“本专业的”“普通学生”的记录，sum+1
		}
	}
	if (sum > 0) {
		return 1;
	}
	return 0;
}

//成员函数：判断是否存在需要审核的本专业的普通学生的预约记录，即预约状态为“1”，若有返回true，否则返回false
bool Counsellor::HasBookAudit()
{
	BookFile file;
	int sum = 0;
	for (int i = 0; i < file.GetSize(); i++) {     ///当文档内有预约记录，并且是本专业的普通学生需要初步审核的预约记录，sum+1
		if (file.GetBookdata()[i]["预约人身份"] == "普通学生"&&file.GetBookdata()[i]["预约状态"]=="1"&& file.GetBookdata()[i]["预约人专业"] == GetMajor()) {
			sum++;
		}
	}
	if (sum > 0) {
		return 1;
	}
	return 0;
}

//成员函数：判断辅导员的操行分是否合格，即若分数≥6，可以继续操作，否则视为待审查用户，无法审核或查看学生预约
bool Counsellor::CalculateScore()
{
	BookFile file;
	double sum = 0;     ///用来计已被评价的预约记录数
	double score = 0;     ///用来统计分数总和
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["初审老师"] == GetName() && file.GetBookdata()[i]["预约人专业"] == GetMajor() && file.GetBookdata()[i]["评价1"] != "暂未评价") {
			sum++;
			score += stod(file.GetBookdata()[i]["评价1"]);
		}
	}
	if (sum == 0) {     ///没有评价记录，默认为10分
		cout << "您的操行评定分为：" << GetCreditScore() <<"(优秀)"<< endl;
		return 1;
	}
	else {
		GetCreditScore() = score / sum;     ///操行评定分默认为10分，当开始有评价反馈时，求其平均分
		cout <<fixed<<setprecision(2)<< "您的操行评定分为：" << GetCreditScore();
		if (GetCreditScore() >= 6) {     ///当分数≥6时，认定为合格，可以执行下一步操作
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
		else {     ///若不合格，则强制退出，无法进行下一步操作
			cout << "(不合格)" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "| 信用分数不合格，请联系管理员进行下一步操作！ |" << endl;
			cout << "------------------------------------------------" << endl;
			return 0;
		}
	}
}

