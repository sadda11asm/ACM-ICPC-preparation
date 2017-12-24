#include <bits/stdc++.h>

using namespace std;

int n;
int tree[120000];//4*n
//if the sum of some interval is needed
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
int getsum(int v, int l, int r, int ql, int qr) {
	if (l==r) {
		return tree[v];
	}
	if (r<ql || l>qr) {
		return 0;
	}
	int mid=(l+r)/2;
	return getsum(v+v, l, mid, ql, qr)+getsum(v+v+1, mid+1,r, ql, qr);
}
int update(int v, int l, int r, int pos, int val) {
	if (l==r) {
		tree[v]=val;
	} else {
		int mid =(l+r)/2;
		if (pos<=mid) {
			update(v+v, l, mid, pos, val);
		} else {
			update (v+v+1, mid+1, r, pos, val);
		}
		tree[v]=tree[v+v]+tree[v+v+1];
	}                
} 	
