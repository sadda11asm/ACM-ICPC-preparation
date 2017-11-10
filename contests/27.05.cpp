#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define pb push_back
using namespace std;

long long a[11][100001],b[11][100001];

int main () {
	long long t,i,j,l,s,k,x,m,n,r;
		cin >> n>>m;
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				cin>>a[i][j];
			}
		}	
		        k=1;
			s=1;
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				if ((a[i][j]!=a[i-1][j]) && (a[i][j]!=a[i+1][j])&&(a[i][j]!=a[i][j+1])&&(a[i][j]!=a[i][j-1])) {
					b[i][j]=k;
					k=k+1;
				}
				else {  if (b[i][j]>0){
						while((a[i][j]==a[i-1][j]) ^ (a[i][j]==a[i+1][j]) ^ (a[i][j]==a[i][j+1]) ^ (a[i][j]==a[i][j-1])) {
							b[i][j]=k;
							if (a[i][j]==a[i-1][j]) i=i-1;	
							if (a[i][j]==a[i+1][j]) i=i+1;
							if (a[i][j]==a[i][j+1]) j=j+1;
							if (a[i][j]==a[i][j-1]) j=j-1;
						}
						k=k+1;
					}
				}		
			}
		}
		cout<<k<<endl;
	return 0;
}