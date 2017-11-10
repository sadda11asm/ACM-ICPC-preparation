#include <bits/stdc++.h>
   
using namespace std;


          
class Lesson {
	public:
	string period;
	string courseTitle;
	string faculty;
	string room;
	string credits;
	string days;
	string capacity;
};
Lesson lessons[1000]; 	 


int main() {
	string name;
	int n;
	cout<<"Enter yout name: "<<endl;
	cin>>name;
	cout<<"Enter the preferred number of credits: "<<endl;
	cin>>n;
	int number;
	if (n%6==0) number=n/6;
	else number=n/6+1;
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string abbreveation;
	string t;
	string s;
	string word;
	int i;
	for (i=1;i<1000;i++) {
		lessons[i].period="";
		lessons[i].courseTitle="";
		lessons[i].faculty="";
		lessons[i].room="";
		lessons[i].credits="";
		lessons[i].days="";
		lessons[i].capacity="";
	}
	i=1;
	int numberOfLessons;
	while(cin>>s) {
		if (s=="BENG"||s=="ECE"||s=="ECHE"||s=="EEE"||s=="EME") {
			numberOfLessons++;
			int j=0;
			int konec=0;
			int jey=-1;
			int jay=0;
			int proshelTitle=0;
			int proshelCapacity=0;
			int proshelFaculty=0;
			do {
				cin>>t;
				j++;
				if (j>=3 && proshelTitle==0) {
					lessons[i].courseTitle+=t;
					lessons[i].courseTitle+=" ";
				}
				if (proshelTitle==1) {
					jey++;
					if (jey==3) {
						lessons[i].days+=t;
					}
					if (jey==4 || jey==5 || jey==6) {
						lessons[i].period+=t;
						lessons[i].period+="";
					}
					if (jey==8) {
						lessons[i].capacity+=t;
						proshelCapacity=1;
					}
				}
				if (proshelCapacity==1 && (t=="Orange" || t[1]=='.')) {
					proshelFaculty=1;
					jay=0;
				}
				if (proshelCapacity==1 && proshelFaculty==0) {
					jay++;
					string t1=t+" ";
					if (jay>=2) {
						lessons[i].faculty+=t1;
					} 
				}
				if (proshelFaculty==1) {
					konec=1;
					lessons[i].room+=t;
					lessons[i].room+=" ";
				}
				if (t=="3.0") {
					proshelTitle=1;
				}
			} while (konec==0);
		i++;  
		}
	}
	for (i=1;i<20;i++) {
		//cout<<lessons[i].room+"\n";
		cout<<"The course title: "+lessons[i].courseTitle+"\n"+"The course day in weekend: "+lessons[i].days+"\nThe Professors are:"+lessons[i].faculty+"\nThe time is: "+lessons[i].period + "\n" + "The location: "+ lessons[i].room + "\nThe capacity: "+ lessons[i].capacity<<endl;
	}  				
	return 0;
}