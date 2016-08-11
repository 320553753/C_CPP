#include <iostream.h>
#include <string.h>

// �ַ������öѴ���
class hstring
{
public:
	hstring(char *s = NULL);
	~hstring();
	// ��ֵ���������Ϊ���Ա
	hstring &operator = (const hstring &a);
	// �� cout ����Լ��� hstring
	friend ostream &operator << (ostream &oc, hstring &a);
	int getlen()
	{ return lenth; }
private:
	int lenth;
	char *str;		// �ַ�����ַ
};

hstring::hstring(char *s)
{
	if (s)
	{
		lenth = strlen(s);	// strlen(); ���ܶ� NULL �󳤶�
		str = new char [lenth + 1];   // �����¿ռ�
		strcpy(str, s);
	}
	else 
	{
		lenth = 0;
		str = NULL;
	}
}

hstring::~hstring()
{
	if (str) delete [] str;
}

// �����out
ostream &operator << (ostream &out, hstring &a)
{
	out << a.str;	// �� cout ������
	return out;
}

// ��ֵ�����'='����
hstring &hstring::operator = (const hstring &a)
{
	if (&a == this) return *this;	// ������Լ�
	
	if (str) delete [] str;		// �ͷ�ԭ����
	lenth = a.lenth;			// ����ڲ���lenth ���Է���
	str = new char[lenth + 1];	// ����¯��
	strcpy(str, a.str);			// ���ƹ���

	return *this;
}

int main(void)
{
	hstring s1 = "123456";
	hstring s2("wujiaying");

	cout << s2 << endl;
	cout << s1 << endl;
	operator << (cout, s1);   // �ȼ����������

	s2 = s1;				// ��ʽ���� '='
	cout << endl << s2 << endl;

	s2.operator = (s1);		// ��ʽ���� '=' 
	cout << s2 << endl;
	cout << "lenth = " << s2.getlen() << endl;

	return 0;
}