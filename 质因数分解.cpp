#include  <iostream>
#include  <cmath>
using  namespace  std;

//判断是否为素数
int  isPrime(long  num)
{
long i=2,flag=0;
for(i=2;i<num;i++)
{
	while(num%i==0){
		flag=1;
		break;
	}
}
return flag;

}

//计算质因素分解，
void  factorization(long  n,long *factor, int& numofFactor)
{
long i;
while(n%2==0)
{
	factor[numofFactor]=2;
	numofFactor++;
    n=n/2;
}
while( isPrime(n) )
{
	
	for(i=3;i<n;i++)
    {
        if(n%i==0)
        {
            factor[numofFactor]=i;
            numofFactor++;
            n=n/i;
        }
        
    }
}

if(n!=1)  factor[numofFactor++]=n;

        return;
}

int  main()
{
        long  n;
        long  factor[100];
        int  numofFactor  =  0;
        cin  >>  n;
        factorization(n,  factor,  numofFactor);
        for  (int  i  =  0;  i  <  numofFactor;  i++)
        {
                cout  <<  factor[i]  <<  "  ";
        }
        cout  <<  endl;
        return  0;
}
