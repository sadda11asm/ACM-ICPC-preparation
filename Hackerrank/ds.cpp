#include <bits/stdc++.h>
#define pb push_back
#define fo(i,n) for(int i=0;i<n;i++)
#define ll long long
#define int ll
#define f first
//#define s second

using namespace std;
//int b[10002];
//vector<int> hei[300001];
//vector<int> g[300001];
//vector<int> f[300001];
//pair<int, pair<int, int> > a[1000];
//int a[300001];
bool a[3]; 
int gcd(int n, int m) {
	if (n==0) return m;
	if (m==0) return n;
        int k= (max(n,m)% min(m,n));
	return gcd(k,min(m,n)); 
}
 main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n,m;
	cin>>n>>m;
	cout<<gcd(n,m);	 	
	return 0;
}
		
