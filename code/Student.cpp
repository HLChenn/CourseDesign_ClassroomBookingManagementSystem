#include "Student.h"

//学生类无参构造函数
Student::Student() {};

//学生类有参构造函数：初始化学生的学号，名字，密码，以及教室容器成员
Student::Student(string id, string name, string password, string level, string major) :User(name, password, major), StudentId(id), level(level) { this->InitialVector(); }

//学生类虚析构函数
Student::~Student() {};

//成员函数：用来将特征值的差值（也就是申请预约到审核预约的时间）格式化为日时分秒的形式
string Student::CalculateAuditTime(long int time)
{
	int days, hours, minutes, seconds;

	days = time / (24 * 3600);     ///计算天数
	time = time % (24 * 3600);
	hours = time / 3600;     ///计算小时数
	time = time% 3600;
	minutes = time / 60;     ///计算分钟数
	seconds = time % 60;     ///计算秒数

	string format = to_string(days) + "日" + to_string(hours) + "时" + to_string(minutes) + "分" + to_string(seconds) + "秒";
	return format;
}

//成员函数：返回数据成员：学生学号的引用
string& Student::GetStudentId()
{
	return StudentId;
}

//成员函数：返回数据成员：学生身份的引用
string& Student::GetLevel()
{
	return level;
}

//成员函数：返回数据成员：教室容器的引用
vector<Classroom>& Student::GetvClassroom()
{
	return vClassroom;
}

//成员函数：判断教室是否已被预约
bool Student::OnlyOneRoom(string date, string interval, string room) {
	BookFile file;
	for (int i = 0; i < file.GetSize(); i++) {
		if (file.GetBookdata()[i]["预约日期"] == date && file.GetBookdata()[i]["预约时间段"] == interval && file.GetBookdata()[i]["预约教室"] == room && (file.GetBookdata()[i]["预约状态"] == "1" || file.GetBookdata()[i]["预约状态"] == "3")) {
			return 0;
		}
	}
	return 1;
}

//成员函数：子菜单初始化的函数接口，由派生类实现
void Student::OpenMenu() {};

//成员函数：申请预约的函数接口，由派生类实现
void Student::ApplyBook() {};

//成员函数：查看我的所有预约的函数接口，由派生类实现
void Student::ShowMyBook() {};

//成员函数：取消预约接口，由派生类实现
void Student::CancelBook() {};

//成员函数：初始化存储教室数据的容器成员的函数接口，由派生类实现
void Student::InitialVector() {};

//成员函数：判断有无预约记录的函数接口，由派生类实现
bool Student::HasBookFile(BookFile &file)
{
	return 0;
}

//成员函数：判断是否达到可预约教室数量接口，由派生类实现
bool Student::HitMaxRoom()
{
	return false;
}

//成员函数：判断有无没有取消的预约记录的函数接口，由派生类实现
bool Student::NotCancel(BookFile& file)
{
	return 0;
}

//成员函数：判断有无更加详细的预约记录的接口，由派生类实现
bool Student::HasBookFileIndeed(BookFile file, string choice)
{
	return 0;
}




