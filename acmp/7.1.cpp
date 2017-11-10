#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[1000], b[1000], c[1000];
int main () {
string s1,s2,s3;
int j;
do {
	cin>>s1;
} while(!' ');
do {
	cin>>s2;
} while(!' ');
do {
	cin>>s3;
} while(!' ');
if ((s1.size()>s2.size()) && (s1.size()>s3.size())) cout<<s1<<endl;
else {
	if ((s2.size()>s3.size()) && (s2.size()>s1.size())) cout<<s2<<endl; 
	else {
		if ((s3.size()>s1.size()) && (s3.size()>s2.size())) cout<<s3<<endl; 
		else {
	for  (int i=0;i<(s1.size()+s2.size());i++) {
		a[i+1]=(int)s1[i];
		b[i+1]=(int)s2[i];
		c[i+1]=(int)s3[i];
	}
	for (int i=0;i<(s1.size()+s2.size());i++) {
		if (a[i]>b[i]) {
			for (j=1;j<=s2.size();j++) b[j]=0;
		}
		if (b[i]>a[i]) {
			for (j=1;j<=s1.size();j++) a[j]=0;
		}
		if (b[i]>c[i]) {
			for (j=1;j<=s3.size();j++) c[j]=0;
		}	
		if (c[i]>a[i]) {
			for (j=1;j<=s1.size();j++) a[j]=0;
                }
		if (a[i]>c[i]) {
			for (j=1;j<=s3.size();j++) c[j]=0;
		}				
		if (c[i]>b[i]) {
			for (j=1;j<=s2.size();j++) b[j]=0;
		}
	}
	if (a[1]!=0) cout<<s1<<endl; else {
        if (b[1]!=0) cout<<s2<<endl;   else {
        if (c[1]!=0) cout<<s3<<endl;         }
}
}
}
}
return 0;
}
