#include <iostream>
using namespace std;

int main()
{
	char queen[8];
	int i,line=1,n=36,data1,data2,comp1,comp2,flag=0;
	
	cin >> queen;
	cout << endl;
	
	for(i=0;i<8;i++) {
		if(queen[i]<'1' || queen[i]>'8') line = i+1;
		
		if(queen[i]>'0' && queen[i]<'9') n = n-queen[i]+48;
	}
	
	comp1 = queen[line-1] + n;
	comp2 = queen[line-1] - n;
	for(i=0;i<8 && i!=line-1;i++) {
		data1 = queen[i]+i+1;
		data2 = queen[i]-i-1;
		
		if(comp1==data1 || comp2==data2) {
			flag=1;
			break;}
	}
	
	if(flag) cout << "No Answer";
	else cout << n;
	
	return 0;
}
