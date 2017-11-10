#include <bits/stdc++.h>
   
using namespace std;

#define sz(a) (int)a.size()
#define vi vector <int>
#define pb push_back
#define mp make_pair
#define ll long long        
#define sc scanf
#define pf printf    
#define f first
 
const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);
 
const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
// //////////////////////////////////////////////////////////////////// 
long long a[100001];
long long b[100001];
int sum(long long n) {
	int s=0;
	for (int i=1;i<10;i++) {
		int d=(s%(int(pow(10,i))))/(int(pow(10,i-1)));
		if (d!=n) s+=d;
	}
return s;
} 
vector<long long> c[100001];
vector <string> mas;
int main() {
	int m;
	long long n;
	cin>>n;
	int i=0;
	long long s=n+1;
	while(s>n) {
		s=n-i+sum(n-i);
		i++;				
	}
	if ((n-i+sum(n-i))==n) {
		cout<<1<<endl;
		cout<<n-i<<endl;
	} else {
		cout<<0<<endl;
	}
return 0;
}

