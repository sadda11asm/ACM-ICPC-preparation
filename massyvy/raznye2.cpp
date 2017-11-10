#include <iostream>
#include <cmath>
using namespace std;
int main () 
{
int i,n,j,k;
cin >> n;
int a[102];
for (i=1;i<=n;i++) 
		{
	        cin >> a[i];
		}	
a[n+1]=a[1];
for (i=1;i<=(n-1);i++) 
		{
	        for (j=i+1;j<=n;j++) 
			{
			if (a[i]==a[j]) 
				{
				for (k=j;k<=n;k++)
					{
					a[k]=a[k+1];
					}
				n=n-1;
				}
			}
		if (a[i]==a[n]) n=n-1;
		}
if (a[n-1]==a[n]) n=n-1; 
cout << n << endl;
return 0;
}
