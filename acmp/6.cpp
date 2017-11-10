#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define pb push_back
using namespace std;
int a[5],b[5];
int main () {
	string s;
	string s1=" ABCDEFGH";
	string s2=" 12345678";
	cin>>s;
	int r=0;
	while (r<1) {	
		int n;
		int k=0;
		for (int i=1;i<=8;i++) {
			if (s[0]!=s1[i]) k=k+1;
		}
		if (k==8) {cout<<"ERROR"<<endl;break;}
	        k=0;
		for (int i=1;i<=8;i++) {
			if (s[3]!=s1[i]) k=k+1;
		}
		if (k==8) {cout<<"ERROR"<<endl;break;}
	        k=0;
		for (int i=1;i<=8;i++) {
			if (s[1]!=s2[i]) k=k+1;
		}
		if (k==8) {cout<<"ERROR"<<endl;break;}
	        k=0;
		for (int i=1;i<=8;i++) {
			if (s[4]!=s2[i]) k=k+1;
		}
		if (k==8) {cout<<"ERROR"<<endl;break;}
		if (s[2]!='-')  {cout<<"ERROR"<<endl;break;}
		for (int i=0;i<=4;i++) {
			a[i+1]=(int)s[i];	
		}
		if ((abs(a[1]-a[4])==1 && abs(a[2]-a[5])==2) || (abs(a[1]-a[4])==2 && abs(a[2]-a[5])==1)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		r=r+1;
	}
return 0;
}
		
	