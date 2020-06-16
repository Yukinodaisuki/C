#include <iostream>
#include <fstream>
using namespace std;

struct student
{
	short stu_id,score;
};

int main()
{
	int n,i=0;
	cin>>n; 
	student *a=new student[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i].stu_id>>a[i].score;
	}
	
	ofstream file1("out.txt",ios::binary);
	file1.write((char *)a,sizeof(a)*n);
	file1.close();
	
	ifstream file2("out.txt",ios::binary);
	student *b=new student[n];
	while(!file2.eof())
	{
		file2.read((char *)&b[i++],sizeof(b));
	}
	file2.close();
	
	ofstream file3("out.txt",ios::app);
	file3.write((char *)b,sizeof(b)*n);
	file3.close();
	
	return 0;
}
