#include <bits/stdc++.h>
#define fo(i,n) for(int i=1;i<=n;i++)
#define ll long long
#define int ll
#define sc scanf
#define pf printf
using namespace std;

int n,k;
int a[100001];
int tree[400004];
//int tree2[400001];//4*n
void build(int v, int l, int r) {
	if (l==r) {
		tree[v]=a[l];
	} else {
		int mid=(l+r)/2;
		build(v+v,l, mid);
		build(v+v+1, mid+1, r);
		tree[v]=tree[v+v]+tree[v+v+1];
	}
}
/*void build2(int v, int l, int r) {
	if (l==r) {
		tree2[v]=a[l];
	} else {
		int mid=(l+r)/2;
		build2(v+v,l, mid);
		build2(v+v+1, mid+1, r);
		tree2[v]=max(tree2[v+v],tree2[v+v+1]);
	}
}*/
int getsum(int v, int l, int r, int ql, int qr) {
	if (ql<=l && r<=qr)  {
		return tree[v];
	}
	if (r<ql || l>qr) {
		return 0;
	}
	int mid=(l+r)/2;
	return getsum(v+v, l, mid, ql, qr)+getsum(v+v+1, mid+1,r, ql, qr);
}
/*int getmax(int v, int l, int r, int ql, int qr) {
	if (ql<=l && r<=qr)  {
		return tree2[v];
	}
	if (r<ql || l>qr) {
		return -100001;
	}
	int mid=(l+r)/2;
	return max(getmax(v+v, l, mid, ql, qr),getmax(v+v+1, mid+1,r, ql, qr));
}*/
int update(int v, int l, int r, int ql, int qr, int val) {
	if (l==r) {
		tree[v]=val;
	} else { 
		int mid = (l+r)/2;
		if (mid<ql) {
			if (mid+1>qr) {
			} else {
				update(v+v+1,mid+1,r,ql,qr,val);
			}
		} else {
			update(v+v,l, mid, ql,qr,val);
			if (mid+1>qr) {
			} else {
				update(v+v+1,mid+1,r,ql,qr,val);
			}
		}
		tree[v]=tree[v+v]+tree[v+v+1];
	}                
}
/*int update2(int v, int l, int r, int pos, int val) {
	if (l==r) {
		tree2[v]=val;
	} else {
		int mid =(l+r)/2;
		if (pos<=mid) {
			update2(v+v, l, mid, pos, val);
		} else {
			update2(v+v+1, mid+1, r, pos, val);
		}
		tree2[v]=max(tree2[v+v],tree2[v+v+1]);
	}                
}*/
 main() {
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout); 
	sc("%lld%lld",&n, &k);
	for (int i=0;i<k;i++) {
		char c;
		sc(" %c",&c);
		if (c=='Q') {
			int l,r;
			sc("%lld%lld", &l, &r);
			pf("%lld\n",getsum(1,1,n,l,r));
		} 
		if (c=='A') {
			int l,r,x;
			sc("%lld%lld%lld", &l, &r, &x);
			update(1,1,n,l,r,x);
		}
	}
	return 0;
}
		
