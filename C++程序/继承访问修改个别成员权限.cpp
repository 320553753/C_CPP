#include <iostream>
#include <string>
using namespace std;

// ����˽�л򱣻��̳еĸ����Ա���������и�Ϊ���л�������

class person
{
public:
	person::person(string n="0", string s="0", string id="0");
	string name;
	string sex;
protected:
	void showp();
private:
	string IDnum;
	void showID();
};

class stu: private person
{
public:
	stu::stu(int g=0, int s=0, 
		string n="NUL", string sex="NUL", string id="NUL");
	int grade;
	int schoolnum;
	void show();
	person::name;   // ˽�м̳к󣬸������Ϊ����
	person::showp;  // �����ľ���˽�м̳и�Ϊ���е�
};

// --------person-----------
person::person(string n, string s, string id)
{
	name = n;
	sex = s;
	IDnum = id;
}

void person::showp()
{
	cout << "������" << name << endl;
	cout << "�Ա�" << sex << endl;
	cout << "ID��" << IDnum << endl;
}

void person::showID()
{
	cout << "���֤��:" << IDnum << endl;
}

// --------stu----------
stu::stu(int g, int s, string n, string sex, string id)
:person(n, sex, id)
{
	grade = g;
	schoolnum = s;
}

void stu::show()
{
	person::showp();
	cout << "�ɼ���" << grade << endl;
	cout << "ѧ�ţ�" << schoolnum << endl;
}

int main(void)
{
	stu s(98, 110202, "wujiaying", "Ů", "7058");

	s.show();
	cout << endl;
	s.name = "ck";
	s.show();
	cout << endl;
	s.showp();

	return 0;
}

