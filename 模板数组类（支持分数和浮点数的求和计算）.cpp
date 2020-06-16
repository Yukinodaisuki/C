#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Array
{
//请完成类的设计
private:
	vector<T> arr;
public:
	Array(int n) {};
	void input(int n)
	{
		for(int i=0;i<n;i++)
		{
			T tmp;
			cin>>tmp;
			arr.push_back(tmp);
		}
	};
	T &operator [] (int x) {return arr[x];};
};



class Fract
{
//请完成类的设计
public:
	int n,m,sign;
	Fract(int x=0,int y=1);
	void show();
	Fract &operator += (Fract &p);
	friend istream &operator>>(istream &is, Fract &p);
};

Fract::Fract(int x,int y)
{
	int min,i;
	if(x*y<0) sign=-1;
	else sign=1;
	
	if(x<0) x=-x;
	if(y<0) y=-y;
	if(x<y) min=x;
	else min=y;
	
	for(i=min;i>1;i--)
	{
		if(x%i==0 && y%i==0)
		{
			x=x/i;
			y=y/i;
		}
	}
	n=sign*x;
	m=y;
}
void Fract::show()
{
	if(n==0) cout<<0<<endl;
	else if(m==1) cout<<n<<endl;
	else cout<<n<<"/"<<m<<endl;
}
Fract& Fract::operator += (Fract &p)
{
	Fract ar(n*(p.m)+m*(p.n),m*(p.m));
	return *this=ar;
}
istream &operator>>(istream &is, Fract &p)
{
	int x, y;
    is>>x>>y;
    Fract temp(x,y);
    p.n=temp.n; p.m=temp.m;
    return is;
}


int main()
{
    unsigned int n;
    cin >> n;
    Array<double> db(n);
    db.input(n);
    double dbsum(0.0);
    for (unsigned int i = 0; i < n; i++)
        dbsum += db[i];
    cout << dbsum << endl;

    cin >> n;
    Array<Fract> fr(n);
    fr.input(n);
    Fract frsum(0, 1);
    for (unsigned int i = 0; i < n; i++)
        frsum += fr[i];
    frsum.show();
}
