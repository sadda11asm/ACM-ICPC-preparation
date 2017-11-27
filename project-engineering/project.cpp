#include <bits/stdc++.h>
   
using namespace std;
          
class Lesson {
	public:
	string period;
	string courseTitle;
	string faculty;
	string room;
	string days;
	string capacity;
};

class Schedule {
	public:
	Lesson M[10];
	Lesson T[10];
	Lesson W[10];
	Lesson R[10];
	Lesson F[10];
	int m,t,w,r,f;
}; 	 
Lesson classLessonAssignment (Lesson X, Lesson Y) {
	string x[6]={X.period, X.courseTitle, X.faculty, X.room, X.days, X.capacity};
	Y.period="";
	Y.courseTitle="";
	Y.faculty=""; 
	Y.room="";
	Y.days=""; 
	Y.capacity="";
	for (int j=0;j<x[0].length();j++) {
		Y.period+=x[0][j];
	}
        for (int j=0;j<x[1].length();j++) {
		Y.courseTitle+=x[1][j];
		//cout<<x[1][j]<<endl;
	}
	for (int j=0;j<x[2].length();j++) {
		Y.faculty+=x[2][j];
	}
	for (int j=0;j<x[3].length();j++) {
		Y.room+=x[3][j];
	}
	for (int j=0;j<x[4].length();j++) {
		Y.days+=x[4][j];
	}
	for (int j=0;j<x[5].length();j++) {
		Y.capacity+=x[5][j];
	}
	return Y;
}

Schedule addingToSchedule(Lesson X, Schedule S) {
	if (X.days=="M") {
		S.m++;
		S.M[S.m]=X;
	}
	if (X.days=="T") {
		S.t++;
		S.T[S.t]=X;
	}
	if (X.days=="W") {
		S.w++;
		S.W[S.w]=X;
	}
	if (X.days=="R") {
		S.r++;
		S.R[S.r]=X;
	}
	if (X.days=="F") {
		S.f++;
		S.F[S.f]=X;
	}
	return S;			
}
bool check(Lesson L, Schedule S) {
	int m=0,t=0,w=0,r=0,f=0;
	int initialOfLesson=(L.period[0]-48)*10+L.period[1]-48;
	int finalOfLesson=(L.period[8]-48)*10+L.period[9]-48+1;
	//cout<<L.period<<"FF"<<endl;
	//cout<<initialOfLesson<<"-"<<finalOfLesson<<endl;
	if (L.days=="M") {
		int k=0;
		for (int i=1;i<=S.m;i++) {
			//if (S.M[i].time)
			int initialOfSchedule=(S.M[i].period[0]-48)*10+S.M[i].period[1]-48;
			int finalOfSchedule=(S.M[i].period[8]-48)*10+S.M[i].period[9]-48+1;
			if ((initialOfLesson>initialOfSchedule && initialOfLesson<finalOfSchedule) || (finalOfLesson>initialOfSchedule && finalOfLesson<finalOfSchedule)) k++;
		}
		if (k==S.m) return 0;
		return 1; 
	}
	if (L.days=="T") {
		int k=0;
		for (int i=1;i<=S.t;i++) {
			//if (S.M[i].time)
			int initialOfSchedule=(S.T[i].period[0]-48)*10+S.T[i].period[1]-48;
			int finalOfSchedule=(S.T[i].period[8]-48)*10+S.T[i].period[9]-48+1;
			if ((initialOfLesson>initialOfSchedule && initialOfLesson<finalOfSchedule) || (finalOfLesson>initialOfSchedule && finalOfLesson<finalOfSchedule)) k++;
		}
		if (k==S.t) return 0;
		return 1;
	}
	if (L.days=="W") {
		int k=0;
		for (int i=1;i<=S.w;i++) {
			//if (S.M[i].time)
			int initialOfSchedule=(S.W[i].period[0]-48)*10+S.W[i].period[1]-48;
			int finalOfSchedule=(S.W[i].period[8]-48)*10+S.W[i].period[9]-48+1;
			if ((initialOfLesson>initialOfSchedule && initialOfLesson<finalOfSchedule) || (finalOfLesson>initialOfSchedule && finalOfLesson<finalOfSchedule)) k++;
		}
		if (k==S.w) return 0;
		return 1;
	}
	if (L.days=="R") {
        int k=0;
		for (int i=1;i<=S.r;i++) {
			//if (S.M[i].time)
			int initialOfSchedule=(S.R[i].period[0]-48)*10+S.R[i].period[1]-48;
			int finalOfSchedule=(S.R[i].period[8]-48)*10+S.R[i].period[9]-48+1;
			if ((initialOfLesson>initialOfSchedule && initialOfLesson<finalOfSchedule) || (finalOfLesson>initialOfSchedule && finalOfLesson<finalOfSchedule)) k++;
		}
		if (k==S.r) return 0;
		return 1;
	}
	if (L.days=="F") {
        int k=0;
		for (int i=1;i<=S.f;i++) {
			//if (S.M[i].time)
			int initialOfSchedule=(S.F[i].period[0]-48)*10+S.F[i].period[1]-48;
			int finalOfSchedule=(S.F[i].period[8]-48)*10+S.F[i].period[9]-48+1;
			if ((initialOfLesson>initialOfSchedule && initialOfLesson<finalOfSchedule) || (finalOfLesson>initialOfSchedule && finalOfLesson<finalOfSchedule)) k++;
		}
		if (k==S.f) return 0;
		return 1;
	}
}
int parsing (Lesson lessons[100], ifstream& in, ofstream& out) {
	string abbreveation;
	string t;
	string s;
	string word;
	int i;
	for (i=1;i<100;i++) {
		lessons[i].period="";
		lessons[i].courseTitle="";
		lessons[i].faculty="";
		lessons[i].room="";
		lessons[i].days="";
		lessons[i].capacity="";
	}
	i=1;
	int numberOfLessons=0;
	while(in>>s) {
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
				in>>t;
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
	for (i=1;i<=numberOfLessons;i++) {
		//out<<lessons[i].period+"\n";
		out<<"\n\nThe course title: "+lessons[i].courseTitle+"\n"+"The course day in weekend: "+lessons[i].days+"\nThe Professors are: "+lessons[i].faculty+"\nThe time is: "+lessons[i].period + "\n" + "The location: "+ lessons[i].room + "\nThe capacity: "+ lessons[i].capacity;
	} 	
	return numberOfLessons;
}

void coursesSorting (int numberOfLessons, Lesson lessons[100]) {
	int i;
	Lesson math[10];
	Lesson programming[10];
	Lesson materials[10];
	Lesson mechanics[10];
	Lesson health[10];
	//cout<<lessons[1].courseTitle<<"TTT";
	int k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Engineering Mathematics I 3.0 ") {
			//cout<<"YES"<<endl;
			math[k]=classLessonAssignment(lessons[i],math[k]);
			//cout<<math[k].courseTitle<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Engineering Mechanics 3.0 ") {
			//cout<<"YES"<<endl;
			mechanics[k]=classLessonAssignment(lessons[i],mechanics[k]);
			//cout<<mechanics[k].courseTitle<<endl;			 
			k++;
		}
	}			 
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Programming for Engineers 3.0 ") {
			//cout<<"YES"<<endl;
			programming[k]=classLessonAssignment(lessons[i],programming[k]);
			//cout<<programming[k].courseTitle<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Engineering Materials 3.0 ") {
			//cout<<"YES"<<endl;
			materials[k]=classLessonAssignment(lessons[i],materials[k]);
			//cout<<materials[k].courseTitle<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Occupal & Environment Health and Safety 3.0 ") {
			//cout<<"YES"<<endl;
			health[k]=classLessonAssignment(lessons[i],health[k]);
			cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}

	////////starting adding courses to 5 different schedules of 5 groups
	Schedule schedule[5];
	for (i=0;i<=4;i++) {
		schedule[i].m=0;
		schedule[i].t=0;
		schedule[i].w=0;
		schedule[i].r=0;
		schedule[i].f=0;
		schedule[i]=addingToSchedule(math[6], schedule[i]);
		schedule[i]=addingToSchedule(mechanics[6], schedule[i]);
		schedule[i]=addingToSchedule(health[1], schedule[i]);
		schedule[i]=addingToSchedule(materials[1], schedule[i]);
		schedule[i]=addingToSchedule(programming[6], schedule[i]);
	}
	//cout<<"Adding To Schedule Check: "<<schedule[0].M[1].courseTitle<<endl;
	
	/*bool used1[5];
	for (i=0;i<=4;i++) {
		for (int j=1;j<=5;j++) {
			if (!used1[j] && check(math[j], schedule[i])) {
				schedule[i]=addingToSchedule(math[j], schedule[i]);
				//cout<<"Does not clash"<<endl;
				used1[j]=1;
				break;
			}	
		}
	}
	bool used2[5];
	for (i=0;i<=4;i++) {
		for (int j=1;j<=5;j++) {
			if (!used2[j] && check(mechanics[j], schedule[i])) {
				schedule[i]=addingToSchedule(mechanics[j], schedule[i]);
				//cout<<"Does not clash"<<endl;
				used2[j]=1;
				break;
			}	
		}
	}
	bool used3[5];
	for (i=0;i<=4;i++) {
		for (int j=1;j<=5;j++) {
			if (!used3[j] && check(materials[j], schedule[i])) {
				schedule[i]=addingToSchedule(materials[j], schedule[i]);
				//cout<<"Does not clash"<<endl;
				used3[j]=1;
				break;
			}	
		}
	}
	bool used4[5];
	for (i=0;i<=4;i++) {
		for (int j=1;j<=5;j++) {
			if (!used4[j] && check(health[j], schedule[i])) {
				schedule[i]=addingToSchedule(health[j], schedule[i]);
				//cout<<"Does not clash"<<endl;
				used4[j]=1;
				break;
			}	
		}
	}
	bool used5[5];
	for (i=0;i<=4;i++) {
		for (int j=1;j<=5;j++) {
			if (!used5[j] && check(programming[j], schedule[i])) {
				schedule[i]=addingToSchedule(programming[j], schedule[i]);
				cout<<"Does not clash"<<endl;
				used5[j]=1;
				break;
			}	
		}
	} */
	for (i=0;i<=4;i++) { 
		int a[5]={1,2,3,4,5};
		schedule[i]=addingToSchedule(math[a[i]], schedule[i]);
		schedule[i]=addingToSchedule(programming[a[(i+1)%5]], schedule[i]);
		schedule[i]=addingToSchedule(materials[a[(i+2)%5]+1], schedule[i]);
		schedule[i]=addingToSchedule(mechanics[a[(i+3)%5]], schedule[i]);
		schedule[i]=addingToSchedule(health[a[(i+4)%5]+1], schedule[i]);
 	}

	//check
	ofstream finalout;
	string s3="finalout.txt";
	finalout.open (s3.c_str());
	for (i=0;i<5;i++) {
		finalout<<"\nGroup "<<i+1<<":";
		finalout<<"\n\nMonday:";
		for (int j=1;j<3;j++) {
			if (j==1) {
				finalout<<endl<<j<<"\nLecture";
			} else {
				finalout<<endl<<j<<"\nTutorial";
			}
			finalout<<"\nThe course title: "+schedule[i].M[j].courseTitle+"\n"+"The course day in weekend: "+schedule[i].M[j].days+"\nThe Professors are: "+schedule[i].M[j].faculty+"\nThe time is: "+schedule[i].M[j].period + "\n" + "The location: "+ schedule[i].M[j].room + "\nThe capacity: "+ schedule[i].M[j].capacity;		 
		}
		finalout<<"\n\nTuesday:";
		for (int j=1;j<3;j++) {
			if (j==1) {
				finalout<<endl<<j<<"\nLecture";
			} else {
				finalout<<endl<<j<<"\nTutorial";
			}
			finalout<<"\nThe course title: "+schedule[i].T[j].courseTitle+"\n"+"The course day in weekend: "+schedule[i].T[j].days+"\nThe Professors are: "+schedule[i].T[j].faculty+"\nThe time is: "+schedule[i].T[j].period + "\n" + "The location: "+ schedule[i].T[j].room + "\nThe capacity: "+ schedule[i].T[j].capacity;		 
		}
		finalout<<"\n\nWednesday:";
		for (int j=1;j<3;j++) {
			if (j==1) {
				finalout<<endl<<j<<"\nLecture";
			} else {
				finalout<<endl<<j<<"\nTutorial";
			}
			finalout<<"\nThe course title: "+schedule[i].W[j].courseTitle+"\n"+"The course day in weekend: "+schedule[i].W[j].days+"\nThe Professors are: "+schedule[i].W[j].faculty+"\nThe time is: "+schedule[i].W[j].period + "\n" + "The location: "+ schedule[i].W[j].room + "\nThe capacity: "+ schedule[i].W[j].capacity;		 
		}
		finalout<<"\n\nThursday:";
		for (int j=1;j<3;j++) {
			if (j==1) {
				finalout<<endl<<j<<"\nLecture";
			} else {
				finalout<<endl<<j<<"\nTutorial";
			}
			finalout<<"\nThe course title: "+schedule[i].R[j].courseTitle+"\n"+"The course day in weekend: "+schedule[i].R[j].days+"\nThe Professors are: "+schedule[i].R[j].faculty+"\nThe time is: "+schedule[i].R[j].period + "\n" + "The location: "+ schedule[i].R[j].room + "\nThe capacity: "+ schedule[i].R[j].capacity;		 
		}
		finalout<<"\n\nFriday:";
		for (int j=1;j<3;j++) {
			if (j==1) {
				finalout<<endl<<j<<"\nLecture";
			} else {
				finalout<<endl<<j<<"\nTutorial";
			}
			finalout<<"\nThe course title: "+schedule[i].F[j].courseTitle+"\n"+"The course day in weekend: "+schedule[i].F[j].days+"\nThe Professors are: "+schedule[i].F[j].faculty+"\nThe time is: "+schedule[i].F[j].period + "\n" + "The location: "+ schedule[i].F[j].room + "\nThe capacity: "+ schedule[i].F[j].capacity;		 
		}
	}
	finalout.close();

}
void nameOfFile (Lesson lessons[100], string s) {
	ofstream out;
	ifstream in;
	string s1=s+"in.txt";
	string s2=s+"out.txt";
	in.open (s1.c_str());
	out.open (s2.c_str());
	int numberOfLessons = parsing(lessons,in,out);
	coursesSorting(numberOfLessons, lessons);
	in.close();
	out.close();
}

int main() {
	Lesson first[100];
	Lesson second[100];  	
	string year1="first";
	string year2="second";
	nameOfFile(first, year1);
	//nameOfFile(second, year2); 
	return 0;
}