#include <iostream>
#include <cmath>
using namespace std;
int main () {
int i,n;
int a[36];
cin >> n;
for (i=1;i<=n;i++) 
	{
	cin >> a[i];
	}
if (n%2==0) {
	   for (i=1;i<=(n/2);i++) 
			{a[i]=a[i]+a[n+1-i];
			}	
	   for (i=(n/2+1);i<=n;i++) 
			{a[i]=a[n+1-i]-a[i];
			}
	   for (i=1;i<=(n/2);i++) 
			{a[i]=a[i]-a[n+1-i];
			}
	   } else if (n%2==1) {  
		  for (i=1;i<=((n-1)/2);i++) 
			{a[i]=a[i]+a[n+1-i];
			}	
	   	  for (i=(n+3)/2;i<=n;i++) 
			{a[i]=a[n+1-i]-a[i];
			}
		  for (i=1;i<=((n-1)/2);i++) 
			{a[i]=a[i]-a[n+1-i];
			}
		  	      }
for (i=1;i<=n;i++) {
                   cout << a[i] << " ";
		   }
return 0;
}
