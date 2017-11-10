#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long a[10000000],b[10000000],c[101];
int main () {
	long long t,i,j,l,s,k,x,m,n,r;
	
	cin>>n>>m;
	for (i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (i=1;i<=m;i++) {
		cin>>b[i];
	}
	for (i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			if ((((a[i]/1000)%10)+((a[i]/10000)%10)+(a[i]/100000))==(b[j]%10+(b[j]/10)%10+(b[j]/100)%10)) {
				cout<<"AT"<<" "<<a[i]<<" "<<b[j]<<endl;
				for (int k=i;k<=n-1;k++) {
					a[k]=a[k+1];
					a[n]=0;
					n=n-1;
				}
				for (int k=i;k<=m-1;k++) {
					b[k]=b[k+1];
					b[m]=0;
					m=m-1;
				}
			}
			if ((((b[j]/1000)%10)+((b[j]/10000)%10)+(b[j]/100000))==(a[i]%10+(a[i]/10)%10+(a[i]/100)%10)) {
				cout<<"TA"<<" "<<b[j]<<" "<<a[i]<<endl;
				for (int k=i;k<=n-1;k++) {
					a[k]=a[k+1];
					a[n]=0;
					n=n-1;
				}
				for (int k=i;k<=m-1;k++) {
					b[k]=b[k+1];
					b[m]=0;
					m=m-1;
				}
			}
		}
	}
return 0;				
}
	