#include <iostream>
#include <cmath>
using namespace std;

//大写变小写 
void trans(char *x)
{
	int i;
	for(i=0;i<10;i++)
		if(x[i]>='A'&&x[i]<='Z') x[i]=x[i]+32;
}

//测量数组长度
int leng(char *y)
{
	int length=0;
	while(*y!='\0')
	{
		y++;
		length++;
	}
	return length;
}

int main()
{
	char a[12],b[12];
	int i,j,min,t;
	
	cin>>a>>b;
	
	//大写字母转换小写 
	trans(a);
	trans(b);
	
	//计算最短距离 
	min=abs(a[0]-b[0]);
	for(i=0;i<leng(a);i++)
		for(j=0;j<leng(b);j++){
			t=abs(a[i]-b[j]);
			if(t<=min) min=t;
		}
	 
	cout<<min;
	
	return 0;
}
