#include <iostream>
#include <cmath>
using namespace std;
int main() {
int n,i;
int a[101];
cin >>n;
for (i=1;i<=n;i++) {
	cin >> a[i];
}
int k=0;
for (i=2;i<=n-1;i++) {
	if (a[i]>a[i-1] && a[i]>a[i+1]) {
	k = k+1;
	}
}
cout << k << endl;
return 0;
}