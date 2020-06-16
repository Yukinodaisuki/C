#include <iostream>
using namespace std;
class watch
{
public:
    watch()
    {
        m_hour = 0;
        m_min = 0;
        m_sec = 0;
        cout << "watch default constructor called" << endl;        
    }
    watch(int h, int m, int s)
    {
        m_hour = h;
        m_min = m;
        m_sec = s;
        cout << "watch constructor called" << endl;
    }

    //注意保护成员在以公有继承方式被继承时，在派生类中依然是保护成员，
	//即可以在派生类内访问，但是不能在类外访问。
protected:
    int m_hour; //小时
    int m_min;  //分钟
    int m_sec;  //秒钟
};

//派生类watchDerived的设计
class watchDerived : public watch
{
    //请补充派生类watchDerived的设计
public:
	watchDerived();
    watchDerived(int h, int m, int s);
    ~watchDerived();
    void setzero();
    
    //重载前置++ 
    watchDerived& operator ++ ();
    //重载后置++
    watchDerived operator ++ (int);
    
    friend ostream &operator<<(ostream &, const watchDerived &);
    friend istream &operator>>(istream &,  watchDerived &);
};

//构造函数
watchDerived::watchDerived()
{
	m_hour = 0;
	m_min = 0;
	m_sec = 0;
	cout << "watchDerived default constructor called" << endl;
}

//重载构造函数 
watchDerived::watchDerived(int h, int m, int s)
{
	m_hour = h;
	m_min = m;
	m_sec = s;
	cout << "watchDerived constructor called" << endl;
}

//析构函数 
watchDerived::~watchDerived()
{
	
}

//清零函数
void watchDerived::setzero()
{
	m_hour = 0;
	m_min = 0;
	m_sec = 0;
}

//重载 前置++
watchDerived& watchDerived::operator ++ ()
{
	m_sec++;
	while(m_sec>=60)
	{
		m_sec = m_sec-60;
		m_min++;
		while(m_min>=60)
		{
			m_min = m_min-60;
			m_hour++;
			while(m_hour>=12)
			{
				m_hour = m_hour-12;
			}
		}
	}
	return *this;
}

//重载 后置++ 
watchDerived watchDerived::operator ++ (int)
{
	watchDerived p=*this;
	++(*this);
	while(p.m_sec>=60)
	{
		p.m_sec = p.m_sec-60;
		p.m_min++;
		while(p.m_min>=60)
		{
			p.m_min = p.m_min-60;
			p.m_hour++;
			while(p.m_hour>=12)
			{
				p.m_hour = p.m_hour-12;
			}
		}
	}
	return p;
}

//请完善派生类watchDerived中<<运算符的重载函数
ostream &operator<<(ostream &out, const watchDerived &s)
{
	out << s.m_hour << ":" << s.m_min << ":" << s.m_sec;
	return out;
}
istream &operator>>(istream & in,  watchDerived &s)
{
    in>> s.m_hour >> s.m_min >> s.m_sec;
    return in;
}


int main()
{
    watchDerived s1, s2(11, 59, 59);

    s1 = s2++;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    s1.setzero();
    s2.setzero();

    s1 = ++s2;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    cin>>s1;
    cout << "s1: " << ++s1 << endl;

    return 0;
}
