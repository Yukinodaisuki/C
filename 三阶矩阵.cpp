#include <iostream>

using namespace std;

int main()
{
	int a[3][3],b[3][3],c[3][3]={0};
	int i,j,n;
	
	//������� 
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
		cin >> a[i][j];
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
		cin >> b[i][j];
	}
	
	//������� 
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			for(n=0;n<3;n++)
				c[i][j] += a[i][n]*b[n][j];
		
	//������ 
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
		cout << c[i][j] <<' ';
		if(j >= 2) cout << endl;
	}
	
	return 0;
}
