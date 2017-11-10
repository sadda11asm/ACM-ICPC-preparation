#include <iostream>
#include <cmath>
using namespace std;
int main () {
int i,n,a;
cin >> n;
for (i=1; i<=n;i++) {
cin >> a;} 
int kolvo = 0;
for (i=1; a<=n; a++) {
if (a==0) kolvo++;
cout << kolvo << endl;}
return 0;
}
