#include <iostream>
#include <string>

using namespace std;

//     ���ϵͼ
//      animal
//     /  |  \
//   cat dog pig

// ����
class animal
{
public:
	animal()
	{ food = "��ʳ"; }
	virtual void show()		// �����麯��
	{
		cout << "����ʳ��: " << food << endl;
	}
	// ���������أ��� dog ������˵
	void show(int n)
	{
		cout << "��������: " << n << endl; 
	}
private:
	string food;
};

// ����������
class cat: public animal
{
public:
	cat(string &f)
	{ food = f; }
	~cat() {}
	virtual void show()
	{
		cout << "cat ��ʳ��: " << food << endl;
	}
private:
	string food;
};

class dog: public animal
{
public:
	dog(string &f)
	{ food = f; }
	virtual void show()
	{
		cout << "dog ��ʳ��: " << food << endl;
	}
	// �������show�����麯����������
	// ����ָ�벻��ָ����, ��Ϊ������û����
	void show(int n)
	{
		cout << "dog ������: " << n << endl;
	}
private:
	string food;
};

class pig: public animal
{
public:
	pig(string &f)
	{ food = f; }
	virtual void show();
private:
	string food;
};

// ���ⶨ�� pig::show, ���ü� virtual
void pig::show()
{
	cout << "pig ��ʳ��: " << food << endl;
}

// �������麯������
// �������̳� animal �е� show
class duck: public animal
{
public:
	duck::duck()
	{ cout << "duck create" << endl; }
};

int main(void)
{
	string a = "��";
	string b = "��";
	string e = "��";

	animal *p;
	animal an;
	cat c(a);
	dog d(b);
	pig g(e);

	// һ���ӿ� show(); ���ַ���
	p = &an;   p->show();
	p = &c;    p->show();
	p = &d;    p->show();
	p = &g;    p->show();
	p->show(123);

	duck du;
	p = &du;   p->show();

	return 0;
}
