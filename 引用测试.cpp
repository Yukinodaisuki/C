#include <iostream>
using namespace std;

void prime(int& x)
{
	x++;
	return;
}

int main()
{
	int x=2;
	
	prime(x);
	
	cout<<x;
	
	return 0;
}
