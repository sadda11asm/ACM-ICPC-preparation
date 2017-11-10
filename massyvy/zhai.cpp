#include <iostream>
#include <cmath>
using namespace std;
int main () 
{
int i,n,j,k,t;
cin >> n;
int a[1001];
for (i=1;i<=n;i++) 
		{
	        cin >> a[i];
		}	
t=1;
i=1;
do  
	{
	a[i]=0;
	i+=1;
	}   
while (a[i]!=t);
for (i=1;i<=n;i++) 
		{cout << a[i] << " ";}
return 0;
}