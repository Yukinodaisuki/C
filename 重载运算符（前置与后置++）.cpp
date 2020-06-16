#include  <iostream>
using  namespace  std;

class Point
{
private:
	int m_x,m_y;
public:
	Point(int x=0,int y=0){m_x=x;m_y=y;};
	//«∞÷√++ 
	Point& operator ++ ();
	//∫Û÷√++ 
	Point operator ++ (int);
	friend ostream& operator << (ostream& output,const Point& p);
}; 
Point& Point::operator ++()
{
	m_x++;
	m_y++;
	return *this;
}
Point Point::operator ++(int)
{
	Point p=*this;
	++(*this);
	return p;
}
ostream& operator << (ostream& output,const Point& p)
{
	output << "(" << p.m_x << "," << p.m_y << ")" << endl;
	return output;
}

int  main()
{
        Point  a(1,3);
        cout<<a;
        cout<<a++;
        cout<<++a;
        return  0;
}
