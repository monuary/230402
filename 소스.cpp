#include<iostream>
using namespace std;

class Base
{
public:
	Base() { cout << "Base Constructor" << endl; }
	void SimpleFunc() { cout << "BaseOne" << endl; }
};

class MiddleDerivedOne :virtual public Base
{
public:
	MiddleDerivedOne() :Base() { cout << "MiddleDerivedOne Constructor" << endl; }
	void MiddleFuncOne()
	{
		SimpleFunc();
		cout << "MiddleDerivedOne" << endl;
	}
};

class MiddleDerivedTwo :virtual public Base
{
public:
	MiddleDerivedTwo() :Base() { cout << "MiddleDerivedTwo Constructor" << endl; }
	void MiddleFuncTwo()
	{
		SimpleFunc();
		cout << "MiddleDerivedTwo" << endl;
	}
};

class LastDerived :public MiddleDerivedOne, public MiddleDerivedTwo
{
public:
	LastDerived() :MiddleDerivedOne(), MiddleDerivedTwo() { cout << "LastDerived Constructor" << endl; }	//B>Mo>B>Mt>L. ��, ������.
	void ComplexFunc()
	{
		MiddleFuncOne();	//B>Mo
		MiddleFuncTwo();	//B>Mt
		SimpleFunc();		//B
	}
};

int main()
{
	cout << "��ü���� �� ....." << endl;
	LastDerived ldr;
	cout << "��ü���� �� ....." << endl;
	ldr.ComplexFunc();
	return 0;
}

//Mo�� Mt�� �� �� ���������� �ް� �ְ�, ���߻������ ��ġ�� �Ǿ �ϳ��� ����ȴ�.