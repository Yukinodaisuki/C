#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	double ch[100],k;
	int n=0,i,j;
	ifstream file1("a.txt",ios::binary);
	if(file1)
	{
		while(file1 >> ch[n])
		{
			n++;
		}
	}
	file1.close();
	
	for(i=0;i<n;i++)
		for(j=0;j<n-1;j++)
		{
			if(ch[j]>ch[j+1])
			{
				k=ch[j];
				ch[j]=ch[j+1];
				ch[j+1]=k;
			}
		}
	
	ofstream file2("b.txt",ios::binary);
	for(i=0;i<n;i++)
	{
		file2<<ch[i]<<' ';
	}
	file2.close();
	return 0;
}
