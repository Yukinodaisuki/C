#include  <iostream>
using  namespace  std;
const  float  pi=3.14159;

class Shape
{
private:
	int m_ID;
public:
	Shape(){};
	Shape(int id){m_ID=id;cout<<"Shape constructor called:"<<m_ID<<endl;};
	~Shape(){cout<<"Shape destructor called:"<<getID()<<endl;};
	int getID(){return m_ID;};
	void setID(int id){m_ID=id;};
	int getArea(){return 0;};
};

class Circle:public Shape
{
private:
	int r;
public:
	Circle(){};
	Circle(int R,int id);
	~Circle(){cout<<"Circle destructor called:"<<getID()<<endl;};
	int getR(){return r;};
	void setR(int R){r=R;};
	float getArea(){return pi*r*r;};
};
Circle::Circle(int R,int id):Shape(id)
{
	r=R;
	cout<<"Circle constructor called:"<<getID()<<endl;
}

class Rectangle:public Shape
{
private:
	int h,w;
public:
	Rectangle(){};
	Rectangle(int h,int w,int id);
	~Rectangle(){cout<<"Rectangle destructor called:"<<getID()<<endl;};
	int getH(){return h;};
	int getW(){return w;};
	void setH(int H){h=H;};
	void setW(int W){w=W;};
	int getArea(){return h*w;};
};
Rectangle::Rectangle(int H,int W,int id):Shape(id)
{
	h=H;
	w=W;
	cout<<"Rectangle constructor called:"<<getID()<<endl;
}

int  main()
{
        Shape  s(1);//1��ʾID
        Circle  c(4,2);//4��ʾ�뾶��2��ʾID
        Rectangle  r(4,  5,3);//4��5��ʾ���Ϳ�3��ʾID
        cout<<"Shape�����"<<s.getArea()<<endl;
        cout<<"Circle�����"<<c.getArea()<<endl;
        cout<<"Rectangle�����"<<r.getArea()<<endl;
}
