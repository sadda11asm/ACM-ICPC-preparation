#include <bits/stdc++.h>
#define pb push_back
#define fo(i,n) for(int i=0;i<n;i++)
#define ll long long
#define int ll

using namespace std;
vector<int> g[10001];
int c[10001];
int a[10001];
bool used[10001];
queue<int> q;
  main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin>>n;
	for (int i=2;i<=n;i++) {
		cin>>a[i];
		g[i].pb(a[i]);
		g[a[i]].pb(i);
	}
        for (int i=1;i<=n;i++) {
        	cin>>c[i];
        } 
        int count=1;
        int sum=1;
        int i;
        q.push(1);
        while (!q.empty()) {
        	i=q.front();
        	used[i]=1;
        	q.pop();
        	for (int j=0;j<g[i].size();j++) {
        		if (!used[g[i][j]]) {
        			q.push(g[i][j]);
        			count++;
        		}
        		if (c[g[i][j]]!=c[i] && !used[g[i][j]]) {
        			//cout<<g[i][j];
        			//cout<<c[i]<<" "<<c[g[i][j]]<<endl;
        			sum++;
        		}
        	}
        }
        cout<<sum<<endl;		
	return 0;
}