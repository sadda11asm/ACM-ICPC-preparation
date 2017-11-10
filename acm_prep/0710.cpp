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
vector <string> mas;
int main() {
	long long a[100001];
	int b[100001];
	long long n;
	cin>>n;
	long long min = 100001;
	long long max = 0;
	for (long long i=0;i<n;i++) {
		cin>>a[i];
		b[i]=0;
	}
	long long sum=0;
	long long sum2=0;
	for (long long i =0; i<n;i++) {
		if (a[i]==i) {
			sum++;
			b[i]=1;	
		}
	}
	for (long long i=0;i<n;i++) {		
		if (a[a[i]]==i && b[i]==0) {
			sum2+=2;
			break;
		}	
	}
	if (n>1) {
		if (sum2==2) {
			long long sumover=sum+sum2;
			cout<<sumover;
		} else {
			if (sum!=n) {
			long long sumover = sum+1;
			cout<<sumover;
			}
			else {
				cout<<sum<<endl;
			}
		}
        } else {
		cout<<1<<endl;
	}
	return 0;
}
