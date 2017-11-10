#include <iostream>
#include <cmath>
using namespace std;
int main () {
int n;
cin >> n;
int a[101];
int i;
for (i=1; i<=n; i++) {
	cin >> a[i];
}
for (i=1; i<=n; i++) {
	if (a[i]%2 == 0) {
	cout << a[i] << " ";
	}
}
return 0;
}

