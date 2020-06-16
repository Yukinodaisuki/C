#include<iostream>
using namespace std;
class CPoint
{
private:
  	int cp1,cp2;
  	
public:
  	CPoint();
  	CPoint(int x,int y);
  	CPoint(CPoint& cp);
  	int Getcp1() {return cp1;};
  	int Getcp2() {return cp2;};
};
CPoint::CPoint()
{
	cp1=cp2=0;
	cout << "CPoint contstructor with default value(0,0) is called." << endl;
}
CPoint::CPoint(int x,int y)
{
	cp1=x;
	cp2=y;
	cout << "CPoint contstructor with default value(0,0) is called." << endl;
}
CPoint::CPoint(CPoint& cp)
{
	cp1=cp.cp1;
	cp2=cp.cp2;
	cout << "CPoint copy contstructor is called." << endl;
}


class CRectangle
{
private:
  	CPoint pp1,pp2;
  	
public:
  	CRectangle();
  	CRectangle(CPoint cpp1,CPoint cpp2);
  	CRectangle(int a,int b,int c,int d);
  	CRectangle(CRectangle& rect);
  	int GetArea();
};
CRectangle::CRectangle() : pp1(0,0),pp2(0,0)
{
	cout << "CRectangle default contstructor is called." << endl;
}
CRectangle::CRectangle(CPoint cpp1,CPoint cpp2) : pp1(cpp1),pp2(cpp2)
{
	cout << "CRectangle contstructor with (CPoint,CPoint) is called." << endl;
}
CRectangle::CRectangle(int a,int b,int c,int d) : pp1(a,b),pp2(c,d)
{
	cout << "CRectangle contstructor with (int,int,int,int) is called." << endl;
}
CRectangle::CRectangle(CRectangle& rect) : pp1(rect.pp1),pp2(rect.pp2)
{
	cout << "CRectangle copy contstructor is called." << endl;
}
int CRectangle::GetArea()
{
	return (pp1.Getcp1()-pp2.Getcp1())*(pp1.Getcp2()-pp2.Getcp2());
}

int  main()
{
        int  a=1,  b=1,  c=6,  d=11;
        cout<<"#  Define  p1  ######"<<endl;
        CPoint  p1;
        cout<<"#  Define  p2  ######"<<endl;
        CPoint  p2(10,20);
        cout<<"#  Define  rect1  ######"<<endl;
        CRectangle  rect1;
        cout<<"#  Define  rect2  ######"<<endl;
        CRectangle  rect2(p1,  p2);
        cout<<"#  Define  rect3  ######"<<endl;
        CRectangle  rect3(a,  b,  c,  d);
        cout<<"#  Define  rect4  ######"<<endl;
        CRectangle  rect4(rect2);
        cout<<"#  Calculate  area  ######"<<endl;
        cout  <<  "rect1面积为"  <<  rect1.GetArea()  <<  endl;
        cout  <<  "rect2面积为"  <<  rect2.GetArea()  <<  endl;
        cout  <<  "rect3面积为"  <<  rect3.GetArea()  <<  endl;
        cout  <<  "rect4面积为"  <<  rect4.GetArea()  <<  endl;
        system("pause");
        return  0;
}
