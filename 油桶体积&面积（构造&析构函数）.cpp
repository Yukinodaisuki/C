#include <iostream>
#include <iomanip>
using namespace std;

double PI=3.1415926;

class cylinder
{
  private:
	double r,h;
	
  public:
  	cylinder(double H,double R);
  	~cylinder();
  	void getvolumn();
  	void getarea();
}; 

cylinder::cylinder(double H,double R)
{
	r=R;
	h=H;
	cout << "���캯��������" << endl;
}
cylinder::~cylinder()
{
	cout << "��������������" << endl;
}
void cylinder::getvolumn()
{
	cout << PI*r*r*h;
}
void cylinder::getarea()
{
	cout << 2*PI*r*r+2*PI*r*h;
}

int main()
{

    double d,h;

    cin>>d>>h;

    cylinder can(h,d/2);

    cout << fixed << setprecision(6);
	can.getvolumn();
//    cout << "��Ͱ���ݻ���" << can.getvolumn() << " " << endl;

//    cout << "��Ƥ�������" << can.getarea() << endl;

}
