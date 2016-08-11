#include <iostream.h>

class complex;		// �����������

class point		// ������
{
public:
	point(int a, int b)
	{ x = a;  y = b; }
	friend complex;
private:
	int x;
	int y;
};

class complex	// ������
{
public:
	complex()
	{ real = 0; imag = 0; }
	complex(double s)		// ת�����캯�� double ת complex
	{ real = s; imag = 0; }
	complex(point &a)		// point ת complex
	{
		real = a.x;
		imag = a.y;
	}
	complex(double a, double b)
	{ real = a, imag = b; }
	friend complex operator - (complex &a, complex &b);
	friend ostream &operator << (ostream &out, complex &a);
private:
	double real;
	double imag;
};

complex operator - (complex &a, complex &b)
{
	return complex (a.real - b.real, a.imag - b.imag);
}

ostream &operator << (ostream &out, complex &a)
{
	out << a.real;
	if (a.imag >= 0) cout << "+";
	cout << a.imag << "i";
	return out;
}

int main()
{
	complex c1(8, 7);
	complex c2(2, 1);
	complex c3(1.3);

	// ����һ����ʱ�� complex ����
	cout << complex(1, 5) << endl;
	cout << c1 << endl;
	cout << c1 - c2 << endl;

	// ǿ�ƽ� 1.3 תΪ complex �ͣ����� int(1.3)
	c3 = c2 - complex(1.3);
	cout << c3 << endl;

	// ǿ�ƽ�������תΪ complex ��
	point p1(10, -10);
	complex c4;
	c4 = complex(p1);
	cout << c4 << endl;

	return 0;
}
