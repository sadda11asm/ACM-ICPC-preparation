#include <iostream>
#include <cmath>
using namespace std;
int main () {
int a;
cin >> a;
if (a != 0) { if (a/abs(a) == 1) {cout << "1"<<endl;} else  {cout << "-1"<<endl;}} else {cout <<"0"<<endl;}
return 0; 
}