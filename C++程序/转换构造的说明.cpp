#include <iostream.h>

class point
{
public:
	// �������ת�����캯��
	// �Ͳ����ô���Ĭ�ϲ����Ĺ��캯��
	// ��Ϊ point(double a=0, double b=0) �� point(double a)
	// �� point(3.14) ��֪������˭������������
	point(double a, double b)
	{ x = a;   y = b; }
	point(double a)
	{ x = a;   y = 0; }
	point()
	{ x = 0;   y = 0; }
	friend bool operator < (point &p1, point &p2);
	bool operator > (point &p1)
	{
		if (x > p1.x) return true;
		else return false;
	}
private:
	double x;
	double y;
};

bool operator < (point &p1, point &p2)
{
	if (p1.x < p2.x) return true;
	else return false;
}

int main()
{
	point a(1, 2);
	point b(2, 3);

	// ��ʽ������Ԫ <
	if (a < b) cout << "a < b";
	else cout << "a >= b";
	cout << endl;
	
	// ����ת����ת������
	if (a < point(2.2)) cout << "a < b";
	else cout << "a >= b";
	cout << endl;

	// ��ʾ����
	if (operator < (a, b)) cout << "a < b";
	else cout << "a >= b";
	cout << endl;

	// ���Ա����
	if (b > a) cout << "b > a";
	else cout << "b <= a";
	cout << endl;

	// ��ʾ����
	if (b.operator > (a)) cout << "b > a";
	else cout << "b <= a";
	cout << endl;

	return 0;
}
