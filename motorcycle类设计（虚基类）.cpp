#include  "iostream"
using  namespace  std;

class vehicle
{
private:
	int maxspeed,weight;
public:
	vehicle();
	vehicle(int m,int w){maxspeed=m; weight=w; cout<<"vehicle constructor called. maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;};
	~vehicle(){cout<<"vehicle destructor called. maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;};
	void run(){cout<<"vehicle run"<<endl;};
	void stop(){cout<<"vehicle stop"<<endl;};
};



class bicycle:virtual public vehicle
{
private:
	int height;
public:
	bicycle(int h){height=h; cout<<"bicycle constructor called. height:"<<height<<endl;};
	~bicycle(){cout<<"bicycle destructor called. height:"<<height<<endl;};
};



class motorcar:virtual public vehicle
{
private:
	int seatnum;
public:
	motorcar(int s){seatnum=s; cout<<"motorcar constructor called. seatnum:"<<seatnum<<endl;};
	~motorcar(){cout<<"motorcar destructor called. seatnum:"<<seatnum<<endl;};
};



class motorcycle:public bicycle,public motorcar
{
public:
	motorcycle(int h,int s,int m,int w):vehicle(m,w),bicycle(h),motorcar(s){cout<<"motorcycle constructor called"<<endl;};
	~motorcycle(){cout<<"motorcycle destructor called"<<endl;};
};



int  main(int  argc,  char  *argv[])
{
        motorcycle  m(1,  2,  3,  4);//1表示height，2表示setnum，3表示maxspeed，4表示weight
        m.run();
        m.stop();
        return  0;
}
