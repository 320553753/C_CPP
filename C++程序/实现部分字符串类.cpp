#include <iostream>
#include <string.h>
using namespace std;

class hstring
{
public:
	hstring(char *s=NULL);
	~hstring();
	int lenth()
	{ return len; }
	// ע�� = �ŷ��ص����Լ���һ������
	hstring &operator = (hstring &s);
	// ����Ҳ�Ƿ���һ�����ã�������һ������
	friend ostream &operator << (ostream &out, hstring &h);
private:
	char *base;
	int len;
};

hstring::~hstring()
{
	if (base) delete [] base;
}

ostream &operator << (ostream &out, hstring &h)
{
	out << h.base;
	return out;
}

hstring &hstring::operator = (hstring &s)
{
	if (&s == this) return *this;
	if (s.base)
	{
		char *n;	// ��ȫ��
		len = s.len;
		n = new char[len + 1];
		if (n) 
		{
			delete [] base;
			base = n;
			strcpy(base, s.base);
		}
	}
	return *this;
}

hstring::hstring(char *s)
{
	if (s)
	{
		len = strlen(s);
		base = new char[len + 1];
		if (base) strcpy(base, s);
	}
	else 
	{
		base = NULL;
		len = 0;
	}
}

int main()
{
	hstring str = "123456";
	hstring str2;

	str2 = str;
	cout << str2 << endl;

	hstring *p;
	p = new hstring("love");
	cout << *p << endl;
	delete p;

	return 0;
}
