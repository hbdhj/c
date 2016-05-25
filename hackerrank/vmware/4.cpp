#include <iostream>
using namespace std;
class A {
public:
	int a;
	int b;
	virtual void fun() {}
	A(int t1 = 0, int t2 = 0) {
		a=t1;
		b=t2;
	}
	int getA(){return a;}
	int getB(){return b;}
};


int main() {
	A obj(5, 10);
	int* pInt=(int*)&obj;
	*(pInt+0) = 100;
	*(pInt+1) = 200;
	cout<<obj.getA()<<endl;
	cout<<obj.getB()<<endl;
	return 0;
}
