#include <iostream>
using namespace std;

class Complex
{
private:
	double real,imag;
public:
	Complex(double r=0.0,double i=0.0){real=r;imag=i;};
	Complex operator + (Complex c2);
	Complex operator + (double c2);
	Complex operator - (Complex c2);
	Complex operator - (double c2);
	void print();
};
Complex Complex::operator + (Complex c2)
{
	Complex c;
	c.real=real+c2.real;
	c.imag=imag+c2.imag;
	return Complex(c.real,c.imag);
}
Complex Complex::operator + (double c2)
{
	Complex c;
	c.real=real+c2;
	c.imag=imag;
	return Complex(c.real,c.imag);
}
Complex Complex::operator - (Complex c2)
{
	Complex c;
	c.real=real-c2.real;
	c.imag=imag-c2.imag;
	return Complex(c.real,c.imag);
}
Complex Complex::operator - (double c2)
{
	Complex c;
	c.real=real-c2;
	c.imag=imag;
	return Complex(c.real,c.imag);
}
void Complex::print()
{
	cout << real << "+" << imag << "i";
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

        return  0;
}
