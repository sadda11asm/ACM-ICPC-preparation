#include <iostream>
using namespace std;
int main()
{
	int n,m,t;
	cin >>n;
	m=(n+1)%2;
	switch (m) {
	case 0: 
	t=n+1;  break;
	case 1:
	t=n+2;        break;
	}
	cout <<t<<endl;
	return 0;
}
