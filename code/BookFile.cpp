#include "BookFile.h"

//预约文件记录类无参构造函数：读入预约记录文件，初始化Bookdata成员
BookFile::BookFile():size(0)
{
	bookdata.clear();     ///清空原有数据，防止插入错位
	ifstream ifs(BOOK_FILE, ios::in);     ///打开存储预约记录的文档
	if (!ifs.is_open()) {     ///对打开作合法性检查
		cout << "文件打开失败！" << endl;
	}

	string date;     ///十九个字符串对象，分别用来读取文档某一份的所有数据：包括预约日期、时间段、教室、学生身份、学生学号、专业、原因、初审老师、评价1、终审老师、评价2、预约状态、申请时间、初审时间、终审时间、三个时间对应的特征值
	string interval;
	string roomid;
	string level;
	string name;
	string studentid;
	string major;
	string reason;
	string firstAduitTeacher;
	string score1;
	string secondAduitTeacher;
	string score2;
	string status;
	string applytime;
	string audittime1;
	string audittime2;
	string eigenvalue1;
	string eigenvalue2;
	string eigenvalue3;

	size = 0;     	///将size初始化为0
	while (ifs>>date && ifs >> interval && ifs >> roomid && ifs >> level && ifs >> name && ifs >> studentid &&ifs>>major&&ifs>>reason&&ifs>>firstAduitTeacher&&ifs>>score1&&ifs>>secondAduitTeacher&&ifs>>score2&& ifs >> status&&ifs>>applytime&&ifs>> audittime1 &&ifs>> audittime2 &&ifs>> eigenvalue1&&ifs>> eigenvalue2&&ifs>> eigenvalue3) {     ///当读取数据均不为空时执行循环
		
		map<string, string> m;     ///构建map容器m的原因：
		                           ///1.类成员（bookdata）是嵌套的map<int,map<string,string>>容器，当初始化它时需要int和map两个变量
								   ///2.所以需要先构建map<string,string>容器m，存储全部解析完的键值对后再和size（int型）组成新的键值对放进bookdata中
		KeyValue(date, m);         
		KeyValue(interval, m);	   ///解析键值对操作
		KeyValue(roomid, m);
		KeyValue(level, m);
		KeyValue(name, m);
		KeyValue(studentid, m);
		KeyValue(major, m);
		KeyValue(reason, m);
		KeyValue(firstAduitTeacher, m);
		KeyValue(score1, m);
		KeyValue(secondAduitTeacher, m);
		KeyValue(score2, m);
		KeyValue(status, m);
		KeyValue(applytime, m);
		KeyValue(audittime1, m);
		KeyValue(audittime2, m);
		KeyValue(eigenvalue1, m);
		KeyValue(eigenvalue2, m);
		KeyValue(eigenvalue3, m);

		bookdata.insert(make_pair(size, m));     ///将size（int）和m（map<int,map<string,string>>)组成键值对插入到bookdata尾端
		
		size++;     ///类成员（size）记录大小同步更新+1
	}
	ifs.close();     ///关闭ifs与文件的通道
}

//预约文件记录类虚析构函数
BookFile::~BookFile() {};

//成员函数：用来解析键值对，将key和value的值放入map容器m中
void BookFile::KeyValue(string WaitToBreak, map<string, string>& m) {

	///函数参数：
	/// 1.字符串变量WaitToBreak，通过解析字符串内“：”前后部分的值，插入到m中
	/// 2.map<string,string>型变量m的引用（引用可以修改真实对象值），储存解析后的键值对

	string key;     ///键值对需要两个数据，分别代表key和value
	string value;

	size_t index = WaitToBreak.find(":");     ///将读取的字符串a中的“:”作为索引节点，分出key和value值
	if (index > 0) {     ///如果查找到“：”，并且索引下标不是首位，则继续执行对字符串a的键值对解析
		key = WaitToBreak.substr(0, index);     ///key值为“：”前面的部分，其中substr（int a，int b）函数返回字符串从[a]下标开始长度为b的子串副本（下同）
		value = WaitToBreak.substr(index + 1, WaitToBreak.size() - index - 1);     ///value值为“：”后面的部分

		m.insert(make_pair(key, value));     ///map的用法，将key和value组成键值对插入到m中
	}
}

//成员函数：用来更新类中数据
void BookFile::UpdateBook()
{
	ofstream ofs;     ///创建文件流对象ofs，用来写文件
	if (size == 0) {     ///如果没有记录，无需更新
		return;
	}
	ofs.open(BOOK_FILE, ios::out | ios::trunc);     ///写入文件时，先清空（trunc）原有文件数据，再重新写入新的数据（但开销很大！）
	for (int i = 0; i < bookdata.size(); i++) {
		ofs <<"预约日期:" << bookdata[i]["预约日期"] << " ";
		ofs << "预约时间段:" << bookdata[i]["预约时间段"] << " ";
		ofs << "预约教室:" << bookdata[i]["预约教室"] << " ";
		ofs << "预约人身份:" << bookdata[i]["预约人身份"] << " ";
		ofs << "预约人:" << bookdata[i]["预约人"] << " ";
		ofs << "预约人学号:" << bookdata[i]["预约人学号"] << " ";
		ofs << "预约人专业:" << bookdata[i]["预约人专业"] << " ";
		ofs << "预约用途与理由:" << bookdata[i]["预约用途与理由"] << " ";
		ofs << "初审老师:" << bookdata[i]["初审老师"] << " ";
		ofs << "评价1:" << bookdata[i]["评价1"] << " ";
		ofs << "终审老师:" << bookdata[i]["终审老师"] << " ";
		ofs << "评价2:" << bookdata[i]["评价2"] << " ";
		ofs << "预约状态:" << bookdata[i]["预约状态"] << " ";
		ofs << "申请时间:" << bookdata[i]["申请时间"] << " ";
		ofs << "初审时间:" << bookdata[i]["初审时间"] << " ";
		ofs << "终审时间:" << bookdata[i]["终审时间"] << " ";
		ofs << "特征值1:" << bookdata[i]["特征值1"] << " ";
		ofs << "特征值2:" << bookdata[i]["特征值2"] << " ";
		ofs << "特征值3:" << bookdata[i]["特征值3"] << endl;
	}
	ofs.close();
}

//成员函数：返回文件记录大小的引用
int& BookFile::GetSize()
{
	return size;
}

//成员函数：返回map容器bookdata的引用
map<int, map<string, string>>& BookFile::GetBookdata()
{
	return bookdata;
}
