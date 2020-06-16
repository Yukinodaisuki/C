#include  <iostream>
#include  <string>
using  namespace  std;

class  CStudent
{
	public:
		static int count;
		CStudent();
		CStudent(const char *Name,int Age);
		~CStudent();
		void printname();
		static int getcount();
	private:
		char name;
		int age;
		
};

//���������ʼ��̬��Ա����
int CStudent::count = 0;

CStudent::CStudent()
{
	count++;
	cout << "noname is contructing" << endl;
}

CStudent::CStudent(const char *Name,int Age)
{
	this->name=*Name;
	this->age=Age;
	count++;
	cout << name << " is contructing" << endl;
}

CStudent::~CStudent()
{
	count--;
	cout << name << " is destructing" << endl;
}

void CStudent::printname()
{
	cout << "name:" << name << endl;
}

int CStudent::getcount()
{
	return count;
}

int  main()
{
        cout  <<  "������ѧ��"  <<  CStudent::getcount()  <<  endl;
        {
                CStudent  stuB[5];
                stuB[4].printname();
                cout  <<  "������ѧ��"  <<  CStudent::getcount()  <<  endl;
        }
        cout  <<  "������ѧ��"  <<  CStudent::getcount()  <<  endl;
        {
                CStudent  stuA[2]  =  {CStudent("Tom",  3),  CStudent("Jerry",  2)};
                for  (int  i  =  0;  i  <  2;  i++)
                {
                        stuA[i].printname();
                }
                cout  <<  "������ѧ��"  <<  CStudent::getcount()  <<  endl;
        }
        cout  <<  "������ѧ��"  <<  CStudent::getcount()  <<  endl;

        return  0;
}
