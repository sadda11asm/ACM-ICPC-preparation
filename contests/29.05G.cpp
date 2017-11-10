#include <iostream>
#include <vector>
#include <cmath>
#define pb push_back
using namespace std;
long long a[101];
vector <int> v;
int A(string s){
	int n = s.size();
	if ((s[n-1]=='N')||(s[n-1]=='S')){
		s.erase(s.end());
		return A(s); 
		}
	if (((s[n-1]=='W') || (s[n-1]=='E')) && ((s[n-1]=='N')||(s[n-1]=='S')))
		{
		s.erase(s.end());
		return 2*A(s);
		}
	else   { s.erase(s.end());
		return A(s); }
}
int main () {
	string s;
	unsigned long long t,i,j,l,k,x,r;	
	cin>>s;
	cout<<A(s)<<endl;	
return 0;
}
