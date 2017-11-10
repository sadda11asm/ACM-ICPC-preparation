#include <iostream>
#include <cmath>
using namespace std;
int main () {
int a, b;
cin >> a; 
cin >> b; 
int k = ((a/b+a%b+b%a+b/a)*(a/b+b/a)-((a/b)*(a%b)+(b/a)*(b%a)))/(a/b+b/a);
int a1= (a/b)*(b%a)+(a%b)*(b/a)+(a/b)+(a%b)+(b/a)+(b%a)- k;
int b2=b+1;
int a2=a1+1;
int k2 = ((a2/b2+a2%b2+b2%a2+b2/a2)*(a2/b2+b2/a2)-((a2/b2)*(a2%b2)+(b2/a2)*(b2%a2)))/(a2/b2+b2/a2);
int a3= (a2/b2)*(b2%a2)+(a2%b2)*(b2/a2)+(a2/b2)+(a2%b2)+(b2/a2)+(b2%a2)- k2;
cout << a3-2 << endl;
return 0;
}