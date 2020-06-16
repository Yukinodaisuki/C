#include<bits/stdc++.h>
using namespace std;
class CPoint 
{
public:
    CPoint(int p1=0,int p2=0);
    CPoint(CPoint& p);
    int Getpoint1()
    {
    	return point1;
	}
	int Getpoint2()
	{
		return point2;
	}
private:
    int point1,point2;
};

CPoint::CPoint(int p1,int p2)
{
    point1=p1;
    point2=p2;
    cout<<"CPoint contstructor with default value(0,0) is called."<<endl;
}

CPoint::CPoint(CPoint& p)
{
	point1=p.point1;
	point2=p.point2;
	cout<<"CPoint copy contstructor is called."<<endl;
} 

class CRectangle
{
public:
	CRectangle(CPoint cpoint1,CPoint cpoint2);
	/*这里将会有四次拷贝构造函数地调用，因为在形参是对象（注意：不是引用）
	就会发生拷贝构造函数地调用*/
	CRectangle(int a,int b,int c,int d);
	CRectangle(CRectangle& a);//拷贝构造函数
	CRectangle();//无参构造函数
private:
	CPoint cp1,cp2; 
     
};

CRectangle::CRectangle(CPoint cpoint1,CPoint cpoint2):cp1(cpoint1),cp2(cpoint2)
{
	cout<<"CRectangle contstructor with (CPoint,CPoint) is called."<<endl;
}

CRectangle::CRectangle(int a,int b,int c,int d):cp1(a,b),cp2(c,d)
{
	cout<<"CRectangle contstructor with (int,int,int,int) is called."<<endl;
}

CRectangle::CRectangle(CRectangle& a):cp1(a.cp1),cp2(a.cp2)
{
	cout<<"CRectangle copy contstructor is called."<<endl;
}

CRectangle::CRectangle():cp1(0,0),cp2(0,0)
//无参构造函数 
{
	cout<<"CRectangle default contstructor is called."<<endl;
}

int main()
{
	int a=1, b=1, c=6, d=11;
    CPoint p1;
	CPoint p2(10,20);
	CRectangle rect1;//调用无参构造函数进行初始化
	CRectangle rect2(p1, p2);
	CRectangle rect3(a, b, c, d);
	CRectangle rect4(rect2);
	system("pause");
    return 0;
}



