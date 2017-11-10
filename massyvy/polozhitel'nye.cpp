#include <iostream>
#include <cmath>
using namespace std;
int main () {
int n,i;
cin >> n;
int a[10001];
for (i=1; i<=n; i++) {
	cin >> a[i];
}
int k=0;
for (i=1; i<=n; i++) {
	if (a[i]>0) { k=k+1; 
	}
}
cout << k << endl;
return 0;
}