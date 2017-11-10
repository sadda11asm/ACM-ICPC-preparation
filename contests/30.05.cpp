#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long a[10000000],b[10000000],c[1000000],d[1000000];
int main () {
	long long t,j,l,s,x,m,n,r;
	cin>>t;
	for (j=1;j<=t;j++) {
		do {
			cin>>n;
			for (int i=1;i<=n;i++) {
				cin>>a[i];
				a[i]=a[i]%n;		 
			}
			int i=1;
			while ((i<=n)) {
				if (a[i]==0) {
					cout<<1<<endl;
					cout<<i<<endl;
					break;
				} 		
				i++;
			}	while ((i<=n));
			b[1]=a[1];
			for (int i=2;i<=n;i++) b[i]=a[i]+b[i-1];
			i=1;
			do {
				if ((b[i]%n)==0){
					cout<<i<<endl;
					for (m=1;m<=i;m++) {
						cout<<m<<" ";
					
					}
				break;
				}
				i++;
			} while ((i<=n));
			i=1;
			do {
				s=b[i]%n;
				c[s]++;
				if (c[s]==2) {
					cout <<i-d[s]<<endl;
					for (m=d[s]+1;m<=i;m++) cout<<m<<" ";
				break;
				}
				d[s]=i; 
				i++;
			} while ((i<=n));	 
		} while (!cout);
	} 
return 0;
} 	
				
