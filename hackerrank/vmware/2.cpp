#include <iostream>
using namespace std;
struct A{
	int i, j;
	A(int ii, int jj):i(ii),j(ii){}
	A(const A&a){}
	A& operator = (const A& a){
		i=a.i;j=a.j;
	}
};
int main() {
	A a(1, 2);
	A b(2, 3);
	A z = (a=b);
	cout<<z.i<< " "<<z.j<<endl;
	return 0;
}
