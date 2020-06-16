#include <iostream>
using namespace std;

//µÝ¹éº¯Êý 
int recycle(int x,int y,int z)
{
	int p;
	if(x>=2||y>=3){
		p=x/2+y/3;
		x=p+x%2;
		y=p+y%3;
		z=z+p;
		return recycle(x,y,z);
	}
	else return z;
}

int main()
{
	int bottle,cap,total=0;
	
	cin>>bottle;
	
	total=cap=bottle;
	
	cout<<recycle(bottle,cap,total);
	
	return 0;
}
