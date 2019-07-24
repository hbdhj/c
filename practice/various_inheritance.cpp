#include <iostream>
#include <stdlib.h>

using namespace std;

class A {
private:
    int apri;
    void print_a_pri();
protected:
    int apro;
    void print_a_pro();
public:
    int apub;
    void print_a_pub();
};

void A::print_a_pri()
{
	cout<<apri;
	cout<<apro;
	cout<<apub;
}

void A::print_a_pro()
{
	cout<<apri;
	cout<<apro;
	cout<<apub;
}

void A::print_a_pub()
{
	cout<<apri;
	cout<<apro;
	cout<<apub;
}
 
class B: public A {
private:
    void print_b_pri();
protected:
    void print_b_pro();
public:
    void print_b_pub();
};

void B::print_b_pub()
{
	// print_a_pri(); // sub-class can't access parent's private
	print_a_pro();
	print_a_pub();
}

void B::print_b_pro()
{
	//print_a_pri(); // sub-class can't access parent's private
	print_a_pro();
	print_a_pub();
}

void B::print_b_pri()
{
	//print_a_pri(); // sub-class can't access parent's private
	print_a_pro();
	print_a_pub();
}

class C: protected A {
private:
    void print_c_pri();
protected:
    void print_c_pro();
public:
    void print_c_pub();
};

void C::print_c_pub()
{
	//print_a_pri(); // sub-class can't access parent's private
	print_a_pro();
	print_a_pub();
}

void C::print_c_pro()
{
	//print_a_pri(); // sub-class can't access parent's private
	print_a_pro();
	print_a_pub();
}

void C::print_c_pri()
{
	//print_a_pri(); // sub-class can't access parent's private
	print_a_pro();
	print_a_pub();
}

class D: private A {
private:
    void print_d_pri();
protected:
    void print_d_pro();
public:
    void print_d_pub();
};

void D::print_d_pub()
{
	//print_a_pri(); // sub-class can't access parent's private
	print_a_pro();
	print_a_pub();
}

void D::print_d_pro()
{
	//print_a_pri(); // sub-class can't access parent's private
	print_a_pro();
	print_a_pub();
}

void D::print_d_pri()
{
	//print_a_pri(); // sub-class can't access parent's private
	print_a_pro();
	print_a_pub();
}

class E: public B {
private:
    void print_e_pri();
protected:
    void print_e_pro();
public:
    void print_e_pub();
};

void E::print_e_pub()
{
	//print_a_pri(); // sub-class can't access parent's private
	print_a_pro();
	print_a_pub();
	//print_b_pri(); // sub-class can't access parent's private
	print_b_pro();
	print_b_pub();
}

void E::print_e_pro()
{
	//print_a_pri(); // sub-class can't access parent's private
	print_a_pro();
	print_a_pub();
	//print_b_pri(); // sub-class can't access parent's private
	print_b_pro();
	print_b_pub();
}

void E::print_e_pri()
{
	//print_a_pri(); // sub-class can't access parent's private
	print_a_pro();
	print_a_pub();
	//print_b_pri(); // sub-class can't access parent's private
	print_b_pro();
	print_b_pub();
}

class F: public C {
private:
    void print_f_pri();
protected:
    void print_f_pro();
public:
    void print_f_pub();
};

void F::print_f_pub()
{
	//print_a_pri(); // sub-class can't access parent's private
	print_a_pro();
	print_a_pub();
	//print_c_pri(); // sub-class can't access parent's private
	print_c_pro();
	print_c_pub();
}

void F::print_f_pro()
{
	//print_a_pri(); // sub-class can't access parent's private
	print_a_pro();
	print_a_pub();
	//print_c_pri(); // sub-class can't access parent's private
	print_c_pro();
	print_c_pub();
}

void F::print_f_pri()
{
	//print_a_pri(); // sub-class can't access parent's private
	print_a_pro();
	print_a_pub();
	//print_c_pri(); // sub-class can't access parent's private
	print_c_pro();
	print_c_pub();
}

class G: public D {
private:
    void print_g_pri();
protected:
    void print_g_pro();
public:
    void print_g_pub();
};

void G::print_g_pub()
{
	//print_a_pri(); // sub-class can't access parent's private
	//print_a_pro(); // sub-class can't access grand-parent's protected through a private parent
	//print_a_pub(); // sub-class can't access grand-parent's protected through a private parent
	//print_d_pri(); // sub-class can't access parent's private
	print_d_pro();
	print_d_pub();
}

void G::print_g_pro()
{
	//print_a_pri(); // sub-class can't access parent's private
	//print_a_pro(); // sub-class can't access grand-parent's protected through a private parent
	//print_a_pub(); // sub-class can't access grand-parent's protected through a private parent
	//print_d_pri(); // sub-class can't access parent's private
	print_d_pro();
	print_d_pub();
}

void G::print_g_pri()
{
	//print_a_pri(); // sub-class can't access parent's private
	//print_a_pro(); // sub-class can't access grand-parent's protected through a private parent
	//print_a_pub(); // sub-class can't access grand-parent's protected through a private parent
	//print_d_pri(); // sub-class can't access parent's private
	print_d_pro();
	print_d_pub();
}

int main(int argc, char** argv)
{
    A a;
	B b;
	C c;
	D d;
	//a.print_a_pri(); // out side can't access class private
	//a.print_a_pro(); // out side can't access class protected
	a.print_a_pub();
	//b.print_a_pri();
	//b.print_a_pro();
	b.print_a_pub();
	//c.print_a_pri();
	//c.print_a_pro();
	//c.print_a_pub(); // out side can't access class protected parent's public
	//d.print_a_pri();
	//d.print_a_pro();
	//d.print_a_pub(); // out side can't access class private parent's public
	exit(0);
}