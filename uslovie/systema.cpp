#include <iostream>
#include <cmath>
using namespace std;
int main () {
int a, b;
cin >> a >> b;
if ((b != 0) and (b != 1) and (a != 0) and (a != 1)) {if ((a / b == a) or (b / a == b)) {cout << "NO"<< endl;} else {cout <<"YES"<< endl;}} else
{if (b == a) {cout <<"YES"<< endl;}  else {cout << "NO"<< endl;}}
return 0;
}