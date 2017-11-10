#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define pb push_back
using namespace std;
vector <int> v;
long long a[100001],b[11][100001];

int main () {
	long long t,i,j,l,s,k,x,m,n,r;
	cin >> n>>k;
	s=0;  m=0;
	for (i=1;i<=n;i++) {
		cin >> a[i];
		for (j=1;j<=n-1;j++) {
			if (a[i]!=a[j])  {
				v.pb(a[i]);
		                s=s+1;
			        m=m+1;
			}
`			else if ((a[i]=a[j]) && (s>=k)) {
				s=s+1;					
			}			