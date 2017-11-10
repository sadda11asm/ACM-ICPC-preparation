#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define pb push_back
using namespace std;
int main () {
	long long t,i,j,k,s,m,n,r;
	long long a[100001], b[100001];
	cin >> t;
	for (j=1;j<=t;j++) {
		cin >> n>>k;
		for (i=1;i<=n;i++) {
			cin >> a[i];        	
		}
		sort(a+1, a+n+1);
		s=0;
		while (a[n-k+1]>0) {  
			s=s+a[n-k+1];
			r=a[n-k+1];
			for (i=n-k+1;i<=n;i++) {		
				a[i]=a[i]-r;
			}
		  	sort(a+1,a+n+1);
		}           	
		cout << "Case "<<j<<": "<< s <<endl;
	}	
return 0;
}