#include <iostream.h>

class complex
{
public:
	complex(double a=0, double b=0)
	{ real = a;   imag = b; }

	// ����+-/*��˫Ŀ���������������Ԫ����
	// ����++��--��-���ȵ�Ŀ����������������Ա����
	// ��ΪҪ������˽�г�Ա���мӼ������������Ա
	friend complex operator + (complex &a, complex &b);
	friend complex operator + (complex &a, int b);
	friend complex operator + (int b, complex &a);
	void show()
	{
		cout << real;
		if (imag >= 0) cout << "+";
		cout << imag << "i" << endl;
	}
private:
	double real;
	double imag;
};

//  c3 = c2 + c1  ��
complex operator + (complex &a, complex &b)
{
	complex tmp;
	tmp.real = b.real + a.real;
	tmp.imag = b.imag + a.imag;
	return tmp;
}

//  c3 = c2 + 100  ��
complex operator + (complex &a, int b)
{
	complex tmp;
	tmp.real = a.real + b;
	tmp.imag = a.imag;
	return tmp;
}

//  c3 = 100 + c1  ��
complex operator + (int b, complex &a)
{
	complex tmp;
	tmp.real = a.real + b;
	tmp.imag = a.imag;
	return tmp;
}

int main(void)
{
	complex c1(1, 5);
	complex c2(2, 2);
	complex c3;

	c3 = c1 + c2;
	c3.show();   cout << endl;

	complex c4;

	c4 = 100 + c1;   c4.show();
	c4 = c1 + 100;   c4.show();

	return 0;
}
