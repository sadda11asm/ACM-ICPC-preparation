#include <iostream>;
#include <cmath>;
using namespace std;
int main()
{
	int n;
	cin >>n;
	int k=n%10;
	int m=(n%100)/10;
	int t=n/100;
	cout << t+m+k << endl;
	return 0;
}
