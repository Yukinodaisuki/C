#include <iostream>
#include <iomanip>
using namespace std;

//Ŀ�꺯��
float comp_numb(float m,float n)
{
	float x;
	x=m-n;
	return x;
}

int main()
{
	float a,b,c,d;
	
	cin>>a>>b>>c>>d;
	
	//���ñ�����λС�� 
	cout<<fixed<<setprecision(2);
	cout<<comp_numb(a,c)<<' '<<comp_numb(b,d);
	
	return 0;
} 
