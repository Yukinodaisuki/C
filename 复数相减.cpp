#include <iostream>
#include <iomanip>
using namespace std;

//目标函数
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
	
	//设置保留两位小数 
	cout<<fixed<<setprecision(2);
	cout<<comp_numb(a,c)<<' '<<comp_numb(b,d);
	
	return 0;
} 
