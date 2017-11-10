#include <iostream>
#include <cmath>
using namespace std;
int main() {
int n;
cin >> n; 
int m=n%1440;
int k=m/60;
int t=m%60;
cout << k <<" "<< t << endl; 
return 0;
}
