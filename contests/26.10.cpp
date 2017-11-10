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
/*long long s[501];
long long a[501]; 

vector <string> mas;

int main() {
	int n;
	long long k;
	cin>>n>>k;
	for (int i=0;i<n;i++) {
		cin>>a[i];
	}
	int sila=a[0];
	long long t=0;
	int x1=0;
	int x2=1;
	int j=1;
	int count=1;
	int maxi =a[0];
	int num =0;
	for (int i=1;i<n;i++) {
		if (a[i]>maxi) {
			maxi=a[i];
			num=i;
		}
	}	
	while(t!=k && j!=num) {
		if (a[x1]>a[x2]) {
			s[x1]++;
			count =x2;
			x2=(j+1)%n;
			t=s[x1];
			j=x2;
			sila=a[x1];
		} else {
			s[x2]++;
			count=x1;
			x1=(j+1)%n;
			j=x1;
			t=s[x2];
			sila = a[x2];
		}
	}
	if (count<num) {
		cout<<sila<<endl;
	}  else {
		cout<<maxi<<endl;
	}
	return 0;
}*/
int s[1001];
int d[1001]; 

vector <string> mas;

int main() {
	int n;
	int k;
	cin>>n;
	for (int i=0;i<n;i++) {
		cin>>s[i]>>d[i];
	}
	k=s[0];
	int j=1;
	while(j!=n) {
		for (int i=0;i<1001;i++) {
			if ((s[j]+i*d[j]) > k) {
				k=s[j]+i*d[j];
				j++;
				break;
			}
		}
	}
	cout<<k<<endl;		 
	return 0;
}