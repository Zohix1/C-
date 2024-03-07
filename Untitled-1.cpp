#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

 

class BaseClass{
public:
 BaseClass(){};
 ~BaseClass(){};
 void virtual fun1()
 {
  cout << "This is Base Class funtion One." << endl;
  fun2();
  return;
 }
 void fun2()
 {
  cout << "This is Base Class funtion Two." << endl;
  return;
 }

private:
 //int num;
 char name;
};

class DerivedClass : public BaseClass{
public:
 DerivedClass(){};
 ~DerivedClass(){};
 void fun1()
 {
  cout << "This is Derived Class One." << endl;
  fun2();
  BaseClass::fun1();
  return;
 }
 void fun2()
 {
  cout << "This is Derived Class Two" << endl;
  return;
 }
private:
 //char name;
 int num;
};

class SubClass : public DerivedClass{
public:
 static int scroe;
};

class Base{
public:
 Base(){};
 ~Base(){};
 void virtual funtion1(){};
};

class Empty{
public:
 Empty(){}
 ~Empty(){}
};

int main()
{
 cout << "Size of BaseClass : " << sizeof(BaseClass) << endl;
 cout << "Size of DerivedClass : " << sizeof(DerivedClass) << endl;
 cout << "Size of SubClass : " << sizeof(SubClass) << endl;

 cout << "Size of Base : " << sizeof(Base) << endl;
 cout << "Size of Empty : " << sizeof(Empty) << endl;

 system("pause");

 DerivedClass d;
 BaseClass &b = d;
 b.fun1();

 system("pause");

 DerivedClass d2;
 BaseClass *b2 = &d2;
 b2->fun1();

 system("pause");

 DerivedClass d1;
 BaseClass b1 = (DerivedClass)d1;
 b1.fun1();

 system("pause");

 int i = 10;
 const int &ci = i;
 int &mi = i;

 cout << ci << endl;
 cout << mi << endl;
 mi += 1;
 cout << ci << endl;
 cout << mi << endl;

 system("pause");
 return 0;
}
