#include <iostream>
using namespace std;

class base
{
public:
	base::base(int x=0, int y=0)
	{
		a = x;
		b = y;
	}
	// �����麯��
	virtual void show()
	{
		cout << "base �� " << a << " , " << b << endl;
	}
private:
	int a;
	int b;
};

class son: public base
{
public:
	son::son(int x=0, int y=0, int z=0, int f=0)
		:base(x, y)
	{
		c = z;
		d = f;
	}
	// �����������ҲҪ����virtual
	virtual void show()
	{
		cout << "son �� "  << c << " , " << d << endl;
	}
	void test()
	{
		cout << "son��������Ա" << endl; 
	}
private:
	int c;
	int d;
};

int main()
{
	base *p;
	base b(50, 50);
	son s(1,2,10,10);

	p = &b;
	p->show();
	
	p = &s;		// �����麯����
	p->show();	// p->show �� s.show ��һ������
	s.show();

	return 0;
}
