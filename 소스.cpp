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
	LastDerived() :MiddleDerivedOne(), MiddleDerivedTwo() { cout << "LastDerived Constructor" << endl; }	//B>Mo>B>Mt>L. 단, 가상상속.
	void ComplexFunc()
	{
		MiddleFuncOne();	//B>Mo
		MiddleFuncTwo();	//B>Mt
		SimpleFunc();		//B
	}
};

int main()
{
	cout << "객체생성 전 ....." << endl;
	LastDerived ldr;
	cout << "객체생성 후 ....." << endl;
	ldr.ComplexFunc();
	return 0;
}

//Mo와 Mt는 둘 다 가상상속으로 받고 있고, 다중상속으로 겹치게 되어도 하나만 선언된다.