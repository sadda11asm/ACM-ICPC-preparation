#include <iostream>
#include <cmath>
using namespace std;
int main () {
int n, a3, a2, a1;
cin >> n;
a3 = n/60;
if ((n%60) > 34) { a3 = a3 + 1; a2 = 0; a1 = 0;} else {
a2 = (n%60)/10;
if ((n%60)%10 > 8) {a2= a2 + 1; a1 = 0;} else {
a1 = (n%60)%10;           }}
cout << a1 << ' ' << a2 << ' ' << a3 << endl;	
return 0;
}