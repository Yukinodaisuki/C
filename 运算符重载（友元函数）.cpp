#include <iostream>
using namespace std;

class Complex
{
private:
	double real,imag;
public:
	Complex(double r=0.0,double i=0.0){real=r;imag=i;};
	friend Complex operator + (Complex c1,Complex c2);
	friend Complex operator + (Complex c1,double c2);
	friend Complex operator + (double c1,Complex c2);
	friend Complex operator - (Complex c1,Complex c2);
	friend Complex operator - (Complex c1,double c2);
	friend Complex operator - (double c1,Complex c2);
	void print();
};
Complex operator + (Complex c1,Complex c2)
{
	Complex c;
	c.real=c1.real+c2.real;
	c.imag=c1.imag+c2.imag;
	return Complex(c.real,c.imag);
}
Complex operator + (Complex c1,double c2)
{
	Complex c;
	c.real=c1.real+c2;
	c.imag=c1.imag;
	return Complex(c.real,c.imag);
}
Complex operator + (double c1,Complex c2)
{
	Complex c;
	c.real=c1+c2.real;
	c.imag=c2.imag;
	return Complex(c.real,c.imag);
}
Complex operator - (Complex c1,Complex c2)
{
	Complex c;
	c.real=c1.real-c2.real;
	c.imag=c1.imag-c2.imag;
	return Complex(c.real,c.imag);
}
Complex operator - (Complex c1,double c2)
{
	Complex c;
	c.real=c1.real-c2;
	c.imag=c1.imag;
	return Complex(c.real,c.imag);
}
Complex operator - (double c1,Complex c2)
{
	Complex c;
	c.real=c1-c2.real;
	c.imag=0-c2.imag;
	return Complex(c.real,c.imag);
}
void Complex::print()
{
	cout<<"("<<real<<")"<<"+"<<"("<<imag<<"i"<<")";
}

int  main()
{
        Complex  a(3,4),b(1,-1),c;
        c=a+b;
        cout<<"a+b=";
        c.print();
        cout<<endl;
        c=a-b;
        cout<<"a-b=";
        c.print();
        cout<<endl;
        c=a+100;
        cout<<"a+100=";
        c.print();
        cout<<endl;
        c=a-2.5;
        cout<<"a-2.5=";
        c.print();
        cout<<endl;
        c=100+a;
        cout<<"100+a=";
        c.print();
        cout<<endl;
        c=2.5-a;
        cout<<"2.5-a=";
        c.print();
        cout<<endl;
        return  0;
}
