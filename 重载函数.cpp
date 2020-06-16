#include  <iostream>
#include  <iomanip>
using  namespace  std;

struct  complex
{
        double  r;
        double  i;
};


complex add(complex& a,complex& b) {
  	complex x;
  	x.r=a.r+b.r;
  	x.i=a.i+b.i;
  	return x;
}
complex add(complex& a,double num) {
  	complex x;
  	x.r=a.r+num;
  	x.i=a.i;
  	return x;
}
complex add(double num,complex& b) {
  	complex x;
  	x.r=num+b.r;
  	x.i=b.i;
  	return x;
}


int  main()
{
        double  num;
        complex  a,  b,  c;
        
        cin  >>  a.r  >>  a.i;
        cin  >>  b.r  >>  b.i;
        cin  >>  num;
        
        c  =  add(a,  b);
        cout  <<  c.r  <<  "+"  <<  c.i  <<  "i"  <<  endl;
        c  =  add(a,  num);
        cout  <<  c.r  <<  "+"  <<  c.i  <<  "i"  <<  endl;
        c  =  add(num,  b);
        cout  <<  c.r  <<  "+"  <<  c.i  <<  "i"  <<  endl;
        
        return 0; 
}
