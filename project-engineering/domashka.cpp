#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int main() {
	int n;
	string x,y;
	cout<<"Enter number of coins(between 1 and 30): ";
	cin>>n;
	cout<<"\nEnter order of players ";
	cin>>x>>y;
	if (n%3==0) {
		cout<<"Winner: "<<y<<endl;
	} else {
		cout<<"Winner: "<<x<<endl;
	}
	return 0;
} 
	