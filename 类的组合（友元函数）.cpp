#include  <iostream>
using  namespace  std;
//�������ﲹ����Boat��Car�Ķ���
class Car;
class Boat
{
private:
	int weight;
public:
	Boat(int w) : weight(w){};

	friend int totalweight(Boat& b,Car& c);
};

class Car
{
private:
	int weight;
public:
	Car(int w) : weight(w){};

	friend int totalweight(Boat& b,Car& c);
};

int  totalweight(Boat& b,Car& c)
{
        return  b.weight+c.weight;
}


int  main()
{
        Boat  b(100);
        Car  c(200);
        cout<<totalweight(  b,  c)<<endl;
        return  0;
}
