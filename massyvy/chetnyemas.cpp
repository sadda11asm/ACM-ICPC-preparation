#include <iostream>
#include <cmath>
using namespace std;
int main() {
int n;
cin >> n;
int a[101];
int i;
for (i = 0; i<=(n-1); i++) {
	cin >> a[i];}
for (i = 0; i<=(n-1); i++) {
	if (i%2==0) {
		cout << a[i] << " ";
	}
}
return 0;
}