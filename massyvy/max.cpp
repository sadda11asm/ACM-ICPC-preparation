#include <iostream>
#include <cmath>
using namespace std;
int main () 
{
int n,i;
cin >> n;
int a[36];
for (i=1;i<=n;i++) 
		{
		cin >> a[i];
		}
int max=a[1];
for (i=2;i<=n;i++) 
		{
		if (a[i]> max) {
			       max = a[i];
			       }  
		}
cout << max << endl;
return 0;
}