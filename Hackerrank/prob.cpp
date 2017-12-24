#include <bits/stdc++.h>
#define pb push_back
#define fo(i,n) for(int i=0;i<n;i++)
#define ll long long
#define int ll

using namespace std;
vector<int> g[100001];
int wei[100001];
int a[100001];
int r[100001];
bool c[100001];
  main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	/*int n, l ,w;
	cin>>n>>l>>w;
	fo(i,n) {
		int p, w;
		cin>>p>>w;
		g[i+1].pb(p);
		g[p].pb(i+1);
		wei[i]=w;

	}*/
	int n;
	int maxx=0;
	int max2=0;
	int record=0;
	cin>>n;
	fo(i,n) {
		cin>>a[i];
		if (a[i] > maxx) {
			record++;
			c[a[i]]=1;
			max2=maxx;
			maxx=a[i];
		} else if (a[i] > max2) r[maxx]++;
	}
	int ans=a[0];
	int maxdif =record;
	for(int i=1;i<n;i++) {
		if (r[a[i]]+record>=maxdif && !c[a[i]] && a[i]<ans) {
			maxdif=r[a[i]]+record;	
		        ans=a[i];
		}
		if ((r[a[i]]-1+record)>=maxdif && c[a[i]] && a[i]<ans) {
			maxdif=r[a[i]]-1+record;
			ans=a[i]; 
		}
	}
	cout<<ans<<endl;
	return 0;
}
		
