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
	string type;
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
	string x[7]={X.period, X.courseTitle, X.faculty, X.room, X.days, X.capacity, X.type};
	Y.period="";
	Y.courseTitle="";
	Y.faculty=""; 
	Y.room="";
	Y.days=""; 
	Y.capacity="";
	Y.type="";
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
	for (int j=0;j<x[6].length();j++) {
		Y.type+=x[6][j];
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
	//cout<<L.period<<endl;
	//cout<<initialOfLesson<<"-"<<finalOfLesson<<endl;
	if (L.days=="M") {
		int k=0;
		//cout<<S.m;
		for (int i=1;i<=S.m;i++) {
			//if (S.M[i].time)
			//cout<<"de"<<endl;
			int initialOfSchedule=(S.M[i].period[0]-48)*10+S.M[i].period[1]-48;
			int finalOfSchedule=(S.M[i].period[8]-48)*10+S.M[i].period[9]-48+1;
			//cout<<initialOfSchedule<<"init"<<endl;
			//cout<<finalOfSchedule<<"final"<<endl;
			if ((initialOfLesson>initialOfSchedule && initialOfLesson<finalOfSchedule) || (finalOfLesson>initialOfSchedule && finalOfLesson<finalOfSchedule)) k++;
		}
		if (k==S.m && k!=0) return 0;
		return 1; 
	}
	if (L.days=="T") {
		int k=0;
		for (int i=1;i<=S.t;i++) {
			//if (S.M[i].time)
			int initialOfSchedule=(S.T[i].period[0]-48)*10+S.T[i].period[1]-48;
			int finalOfSchedule=(S.T[i].period[8]-48)*10+S.T[i].period[9]-48+1;
			cout<<initialOfSchedule<<"init"<<endl;
			cout<<finalOfSchedule<<"final"<<endl;
			if ((initialOfLesson>initialOfSchedule && initialOfLesson<finalOfSchedule) || (finalOfLesson>initialOfSchedule && finalOfLesson<finalOfSchedule)) k++;
		}
		if (k==S.t && k!=0) return 0;
		return 1;
	}
	if (L.days=="W") {
		int k=0;
		for (int i=1;i<=S.w;i++) {
			//if (S.M[i].time)
			int initialOfSchedule=(S.W[i].period[0]-48)*10+S.W[i].period[1]-48;
			int finalOfSchedule=(S.W[i].period[8]-48)*10+S.W[i].period[9]-48+1;
			cout<<initialOfSchedule<<"init"<<endl;
			cout<<finalOfSchedule<<"final"<<endl;
			if ((initialOfLesson>initialOfSchedule && initialOfLesson<finalOfSchedule) || (finalOfLesson>initialOfSchedule && finalOfLesson<finalOfSchedule)) k++;
		}
		if (k==S.w && k!=0) return 0;
		return 1;
	}
	if (L.days=="R") {
        int k=0;
		for (int i=1;i<=S.r;i++) {
			//if (S.M[i].time)
			int initialOfSchedule=(S.R[i].period[0]-48)*10+S.R[i].period[1]-48;
			int finalOfSchedule=(S.R[i].period[8]-48)*10+S.R[i].period[9]-48+1;
			cout<<initialOfSchedule<<"init"<<endl;
			cout<<finalOfSchedule<<"final"<<endl;
			if ((initialOfLesson>initialOfSchedule && initialOfLesson<finalOfSchedule) || (finalOfLesson>initialOfSchedule && finalOfLesson<finalOfSchedule)) k++;
		}
		if (k==S.r && k!=0) return 0;
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
		if (k==S.f && k!=0) return 0;
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
		lessons[i].type="";
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
				if (j==2 && proshelTitle==0) {
					lessons[i].type+=t;
				}
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
		out<<"\n\nThe course title: "+lessons[i].courseTitle+"\n"+lessons[i].type+"\n"+"The course day in weekend: "+lessons[i].days+"\nThe Professors are: "+lessons[i].faculty+"\nThe time is: "+lessons[i].period + "\n" + "The location: "+ lessons[i].room + "\nThe capacity: "+ lessons[i].capacity;
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
void civilCoursesSorting (int numberOfLessons, Lesson lessons[100]) {
	int i;
	Lesson survey[10];
	Lesson math3[10];
	Lesson cad[10];
	Lesson analysis[10];
	Lesson materials[10];
	Lesson geology[10];
	Lesson concrete[10];
	Lesson capstone[10];
	Lesson construction[10];
	Lesson environment[10];
	Lesson highway[10];
	Lesson systems[10];
	Lesson project[10];
	//cout<<lessons[1].courseTitle<<"TTT";
	int k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Surveying 3.0 ") {
			//cout<<"YES"<<endl;
			survey[k]=classLessonAssignment(lessons[i],survey[k]);
			//cout<<survey[k].courseTitle<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Civil Engineering CAD 3.0 ") {
			//cout<<"YES"<<endl;
			cad[k]=classLessonAssignment(lessons[i],cad[k]);
			//cout<<mechanics[k].courseTitle<<endl;			 
			k++;
		}
	}			 
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Structural Analysis I 3.0 ") {
			//cout<<"YES"<<endl;
			analysis[k]=classLessonAssignment(lessons[i],analysis[k]);
			//cout<<programming[k].courseTitle<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Civil Engineering Materials 3.0 ") {
			//cout<<"YES"<<endl;
			materials[k]=classLessonAssignment(lessons[i],materials[k]);
			//cout<<materials[k].courseTitle<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Engineering Mathematics III 3.0 ") {
			//cout<<"YES"<<endl;
			math3[k]=classLessonAssignment(lessons[i],math3[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Engineering Geology and Rock Mechanics 3.0 ") {
			//cout<<"YES"<<endl;
			geology[k]=classLessonAssignment(lessons[i],geology[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Structural Design - Concrete 3.0 ") {
			//cout<<"YES"<<endl;
			concrete[k]=classLessonAssignment(lessons[i], concrete[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Capstone Project 1 3.0 ") {
			//cout<<"YES"<<endl;
			capstone[k]=classLessonAssignment(lessons[i],capstone[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Construction Technologies and Processes 3.0 ") {
			//cout<<"YES"<<endl;
			construction[k]=classLessonAssignment(lessons[i],construction[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Environmental Engineering 3.0 ") {
			//cout<<"YES"<<endl;
			environment[k]=classLessonAssignment(lessons[i],environment[k]);
			//cout<<environment[k].days<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Highway Engineering 3.0 ") {
			//cout<<"YES"<<endl;
			highway[k]=classLessonAssignment(lessons[i],highway[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Environmental Systems 3.0 ") {
			//cout<<"YES"<<endl;
			systems[k]=classLessonAssignment(lessons[i],systems[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Project Management 3.0 ") {
			//cout<<"YES"<<endl;
			project[k]=classLessonAssignment(lessons[i],project[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	////////starting adding courses to 5 different schedules of 5 groups
	//second year 
	Schedule schedule2[2];
	//cout<<"de"<<survey[1].type[0]-48<<endl;
	bool usedS[7];
	bool usedC[7];
	bool usedA[7];
	bool usedM[7];
	for (i=0;i<=1;i++) {
		int s=0;
		int a=0;
		int m=0;
		int c=0;
		schedule2[i].m=0;
		schedule2[i].t=0;
		schedule2[i].w=0;
		schedule2[i].r=0;
		schedule2[i].f=0;
		for (int j=1;j<=8;j++) {
			if ((survey[j].capacity[0]-48)>3) {
				schedule2[i]=addingToSchedule(survey[j], schedule2[i]);
				cout<<schedule2[i].t<<endl;
			} else {
				if (check(survey[j], schedule2[i]) && usedS[j]!=1 && s==0) {
					cout<<"s"<<i<<endl;
					schedule2[i]=addingToSchedule(survey[j], schedule2[i]);
					usedS[j]=1;
					s++;	
				}	
			}
			if ((cad[j].capacity[0]-48)>3) {
				schedule2[i]=addingToSchedule(cad[j], schedule2[i]);
			} else {
				if (check(cad[j], schedule2[i]) && usedC[j]!=1 && c==0) {
					//cout<<"c"<<i<<endl;
					schedule2[i]=addingToSchedule(cad[j], schedule2[i]);
					usedC[j]=1;
					c++;	
				}	
			}
			if ((analysis[j].capacity[0]-48)>3) {
				schedule2[i]=addingToSchedule(analysis[j], schedule2[i]);
			} else {
				if (check(analysis[j], schedule2[i]) && usedA[j]!=1 && a==0) {
					//cout<<"a"<<i<<endl;					
					schedule2[i]=addingToSchedule(analysis[j], schedule2[i]);
					usedA[j]=1;
					a++;	
				}	
			}
			if ((materials[j].capacity[0]-48)>3) {
				schedule2[i]=addingToSchedule(materials[j], schedule2[i]);
			} else {
				if (check(materials[j], schedule2[i]) && usedM[j]!=1 && m==0) {
					//cout<<"m"<<i<<endl;
					schedule2[i]=addingToSchedule(materials[j], schedule2[i]);
					usedM[j]=1;
					m++;	
				}	
			}
			cout<<"math"<<math3[j].type<<" "<<math3[j].type.length()<<endl;
			if ((((math3[j].type[0]-48)==1) && (math3[j].type.length()==2)) || ((math3[j].type[0]-48)+(i+1))==5) {
				schedule2[i]=addingToSchedule(math3[j], schedule2[i]);
			}
		} 
	}
	cout<<"Adding To Schedule Check: "<<schedule2[0].T[1].courseTitle<<endl;
	//third year
	Schedule schedule3[2];
	//cout<<"de"<<survey[1].type[0]-48<<endl;
	bool usedG[7];
	bool usedCo[7];
	for (i=0;i<=1;i++) {
		int g=0;
		int co=0;
		schedule3[i].m=0;
		schedule3[i].t=0;
		schedule3[i].w=0;
		schedule3[i].r=0;
		schedule3[i].f=0;
		for (int j=1;j<=8;j++) {
			if ((geology[j].capacity[0]-48)>4) {
				schedule3[i]=addingToSchedule(geology[j], schedule3[i]);
				cout<<schedule2[i].t<<endl;
			} else {
				if (check(geology[j], schedule3[i]) && usedG[j]!=1 && g==0) {
					schedule3[i]=addingToSchedule(geology[j], schedule3[i]);
					usedG[j]=1;
					g++;	
				}	
			}
			if ((concrete[j].capacity[0]-48)>4) {
				schedule3[i]=addingToSchedule(concrete[j], schedule3[i]);
			} else {
				if (check(concrete[j], schedule3[i]) && usedCo[j]!=1 && co==0) {
					schedule3[i]=addingToSchedule(concrete[j], schedule3[i]);
					usedCo[j]=1;
					co++;	
				}	
			}
			if ((construction[j].capacity[0]-48)>4) {
				schedule3[i]=addingToSchedule(construction[j], schedule3[i]);
			} 
			if ((environment[j].capacity[0]-48)>4) {
				schedule3[i]=addingToSchedule(environment[j], schedule3[i]);
			}
			if ((project[j].type[0]=='4') || project[j].capacity=="160") {
				schedule3[i]=addingToSchedule(project[j], schedule3[i]);
			} 
		} 
	}
	//fourth year
	Schedule schedule4[1];
	//cout<<"de"<<survey[1].type[0]-48<<endl;
	for (i=0;i<=0;i++) {
		schedule4[i].m=0;
		schedule4[i].t=0;
		schedule4[i].w=0;
		schedule4[i].r=0;
		schedule4[i].f=0;
		for (int j=1;j<=8;j++) {
			if ((capstone[j].capacity[0]-48)>2) {
				schedule4[i]=addingToSchedule(capstone[j], schedule4[i]);
			}
			if ((highway[j].capacity[0]-48)>3) {
				schedule4[i]=addingToSchedule(highway[j], schedule4[i]);
			}
			if ((systems[j].capacity[0]-48)>3) {
				schedule4[i]=addingToSchedule(systems[j], schedule4[i]);
			} 
		} 
	}
	//check
	ofstream finalout;
	string s3="finalCivilout.txt";
	finalout.open (s3.c_str());
	finalout<<"SCHEDULE FOR CIVIL MAJOR, 2nd YEAR STUDENTS:";
	for (i=0;i<2;i++) {
		finalout<<"\nGroup "<<i+1<<":";
		finalout<<"\n\nMonday:";
		for (int j=1;j<=schedule2[i].m;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].M[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].M[j].type+"\n" + "The course day in weekend: "+schedule2[i].M[j].days+"\nThe Professors are: "+schedule2[i].M[j].faculty+"\nThe time is: "+schedule2[i].M[j].period + "\n" + "The location: "+ schedule2[i].M[j].room + "\nThe capacity: "+ schedule2[i].M[j].capacity;		 
		}
		finalout<<"\n\nTuesday:";
		for (int j=1;j<=schedule2[i].t;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].T[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].T[j].type+"\n"+"The course day in weekend: "+schedule2[i].T[j].days+"\nThe Professors are: "+schedule2[i].T[j].faculty+"\nThe time is: "+schedule2[i].T[j].period + "\n" + "The location: "+ schedule2[i].T[j].room + "\nThe capacity: "+ schedule2[i].T[j].capacity;		 
		}
		finalout<<"\n\nWednesday:";
		for (int j=1;j<=schedule2[i].w;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].W[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].W[j].type+"\n"+"The course day in weekend: "+schedule2[i].W[j].days+"\nThe Professors are: "+schedule2[i].W[j].faculty+"\nThe time is: "+schedule2[i].W[j].period + "\n" + "The location: "+ schedule2[i].W[j].room + "\nThe capacity: "+ schedule2[i].W[j].capacity;		 
		}                                                                                                                                                                          
		finalout<<"\n\nThursday:";
		for (int j=1;j<=schedule2[i].r;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].R[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].R[j].type+"\n"+"The course day in weekend: "+schedule2[i].R[j].days+"\nThe Professors are: "+schedule2[i].R[j].faculty+"\nThe time is: "+schedule2[i].R[j].period + "\n" + "The location: "+ schedule2[i].R[j].room + "\nThe capacity: "+ schedule2[i].R[j].capacity;		 
		}
		finalout<<"\n\nFriday:";
		for (int j=1;j<=schedule2[i].f;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].F[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].F[j].type+"\n"+"The course day in weekend: "+schedule2[i].F[j].days+"\nThe Professors are: "+schedule2[i].F[j].faculty+"\nThe time is: "+schedule2[i].F[j].period + "\n" + "The location: "+ schedule2[i].F[j].room + "\nThe capacity: "+ schedule2[i].F[j].capacity;		 
		}
	}
	finalout<<"\n\nSCHEDULE FOR CIVIL MAJOR, 3rd YEAR STUDENTS:";
	for (i=0;i<2;i++) {
		finalout<<"\nGroup "<<i+1<<":";
		finalout<<"\n\nMonday:";
		for (int j=1;j<=schedule3[i].m;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].M[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].M[j].type+"\n" + "The course day in weekend: "+schedule3[i].M[j].days+"\nThe Professors are: "+schedule3[i].M[j].faculty+"\nThe time is: "+schedule3[i].M[j].period + "\n" + "The location: "+ schedule3[i].M[j].room + "\nThe capacity: "+ schedule3[i].M[j].capacity;		 
		}
		finalout<<"\n\nTuesday:";
		for (int j=1;j<=schedule3[i].t;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].T[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].T[j].type+"\n"+"The course day in weekend: "+schedule3[i].T[j].days+"\nThe Professors are: "+schedule3[i].T[j].faculty+"\nThe time is: "+schedule3[i].T[j].period + "\n" + "The location: "+ schedule3[i].T[j].room + "\nThe capacity: "+ schedule3[i].T[j].capacity;		 
		}
		finalout<<"\n\nWednesday:";
		for (int j=1;j<=schedule3[i].w;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].W[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].W[j].type+"\n"+"The course day in weekend: "+schedule3[i].W[j].days+"\nThe Professors are: "+schedule3[i].W[j].faculty+"\nThe time is: "+schedule3[i].W[j].period + "\n" + "The location: "+ schedule3[i].W[j].room + "\nThe capacity: "+ schedule3[i].W[j].capacity;		 
		}                                                                                                                                                                          
		finalout<<"\n\nThursday:";
		for (int j=1;j<=schedule3[i].r;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].R[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].R[j].type+"\n"+"The course day in weekend: "+schedule3[i].R[j].days+"\nThe Professors are: "+schedule3[i].R[j].faculty+"\nThe time is: "+schedule3[i].R[j].period + "\n" + "The location: "+ schedule3[i].R[j].room + "\nThe capacity: "+ schedule3[i].R[j].capacity;		 
		}
		finalout<<"\n\nFriday:";
		for (int j=1;j<=schedule3[i].f;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].F[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].F[j].type+"\n"+"The course day in weekend: "+schedule3[i].F[j].days+"\nThe Professors are: "+schedule3[i].F[j].faculty+"\nThe time is: "+schedule3[i].F[j].period + "\n" + "The location: "+ schedule3[i].F[j].room + "\nThe capacity: "+ schedule3[i].F[j].capacity;		 
		}
	}
	finalout<<"\n\nSCHEDULE FOR CIVIL MAJOR, 4th YEAR STUDENTS:";
	for (i=0;i<1;i++) {
		finalout<<"\nGroup "<<i+1<<":";
		finalout<<"\n\nMonday:";
		for (int j=1;j<=schedule4[i].m;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].M[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].M[j].type+"\n" + "The course day in weekend: "+schedule4[i].M[j].days+"\nThe Professors are: "+schedule4[i].M[j].faculty+"\nThe time is: "+schedule4[i].M[j].period + "\n" + "The location: "+ schedule4[i].M[j].room + "\nThe capacity: "+ schedule4[i].M[j].capacity;		 
		}
		finalout<<"\n\nTuesday:";
		for (int j=1;j<=schedule4[i].t;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].T[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].T[j].type+"\n"+"The course day in weekend: "+schedule4[i].T[j].days+"\nThe Professors are: "+schedule4[i].T[j].faculty+"\nThe time is: "+schedule4[i].T[j].period + "\n" + "The location: "+ schedule4[i].T[j].room + "\nThe capacity: "+ schedule4[i].T[j].capacity;		 
		}
		finalout<<"\n\nWednesday:";
		for (int j=1;j<=schedule4[i].w;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].W[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].W[j].type+"\n"+"The course day in weekend: "+schedule4[i].W[j].days+"\nThe Professors are: "+schedule4[i].W[j].faculty+"\nThe time is: "+schedule4[i].W[j].period + "\n" + "The location: "+ schedule4[i].W[j].room + "\nThe capacity: "+ schedule4[i].W[j].capacity;		 
		}                                                                                                                                                                         
		finalout<<"\n\nThursday:";
		for (int j=1;j<=schedule4[i].r;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].R[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].R[j].type+"\n"+"The course day in weekend: "+schedule4[i].R[j].days+"\nThe Professors are: "+schedule4[i].R[j].faculty+"\nThe time is: "+schedule4[i].R[j].period + "\n" + "The location: "+ schedule4[i].R[j].room + "\nThe capacity: "+ schedule4[i].R[j].capacity;		 
		}
		finalout<<"\n\nFriday:";
		for (int j=1;j<=schedule4[i].f;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].F[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].F[j].type+"\n"+"The course day in weekend: "+schedule4[i].F[j].days+"\nThe Professors are: "+schedule4[i].F[j].faculty+"\nThe time is: "+schedule4[i].F[j].period + "\n" + "The location: "+ schedule4[i].F[j].room + "\nThe capacity: "+ schedule4[i].F[j].capacity;		 
		}
	}
	finalout.close();
}
void mechanicalCoursesSorting (int numberOfLessons, Lesson lessons[100]) {
	int i;
	Lesson aided[10];
	Lesson dynamics[10];
	Lesson control[10];
	Lesson heat[10];
	Lesson design[10];
	Lesson aero[10];
	Lesson air[10];
	Lesson geometric[10];
	Lesson capstone[10];
	Lesson clean[10];
	Lesson dynamics2[10];
	Lesson vehicle[10];
	Lesson oscillation[10];
	Lesson math3[10];
	Lesson project[10];
	Lesson mechanics[10];
	Lesson sensors[10];
	//cout<<lessons[1].courseTitle<<"TTT";
	int k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Computer Aided Engineering 3.0 ") {
			//cout<<"YES"<<endl;
			aided[k]=classLessonAssignment(lessons[i],aided[k]);
			//cout<<survey[k].courseTitle<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Machine Dynamics I 3.0 ") {
			//cout<<"YES"<<endl;
			dynamics[k]=classLessonAssignment(lessons[i],dynamics[k]);
			//cout<<mechanics[k].courseTitle<<endl;			 
			k++;
		}
	}			 
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Advanced Control Systems 3.0 ") {
			//cout<<"YES"<<endl;
			control[k]=classLessonAssignment(lessons[i],control[k]);
			//cout<<programming[k].courseTitle<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Heat Transfer 3.0 ") {
			//cout<<"YES"<<endl;
			heat[k]=classLessonAssignment(lessons[i],heat[k]);
			//cout<<materials[k].courseTitle<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Engineering Mathematics III 3.0 ") {
			//cout<<"YES"<<endl;
			math3[k]=classLessonAssignment(lessons[i],math3[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Machine Design 3.0 ") {
			//cout<<"YES"<<endl;
			design[k]=classLessonAssignment(lessons[i],design[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Aerodynamics 3.0 ") {
			//cout<<"YES"<<endl;
			aero[k]=classLessonAssignment(lessons[i], aero[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Heating, Ventilating, and Air Conditioning 3.0 ") {
			//cout<<"YES"<<endl;
			air[k]=classLessonAssignment(lessons[i], air[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Computer Aided Geometric Design 3.0 ") {
			//cout<<"YES"<<endl;
			geometric[k]=classLessonAssignment(lessons[i],geometric[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Capstone project 1 3.0 ") {
			//cout<<"YES"<<endl;
			capstone[k]=classLessonAssignment(lessons[i], capstone[k]);
			//cout<<environment[k].days<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Feasibility Analysis of Clean Energy Technologies 3.0 ") {
			//cout<<"YES"<<endl;
			clean[k]=classLessonAssignment(lessons[i],clean[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Machine Dynamics II 3.0 ") {
			//cout<<"YES"<<endl;
			dynamics2[k]=classLessonAssignment(lessons[i],dynamics2[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Vehicle Propulsion Systems 3.0 ") {
			//cout<<"YES"<<endl;
			vehicle[k]=classLessonAssignment(lessons[i],vehicle[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Oscillation of Mechanical Systems 3.0 ") {
			//cout<<"YES"<<endl;
			oscillation[k]=classLessonAssignment(lessons[i],oscillation[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Project Management 3.0 ") {
			//cout<<"YES"<<endl;
			project[k]=classLessonAssignment(lessons[i],project[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Mechanics of Materials 3.0 ") {
			//cout<<"YES"<<endl;
			mechanics[k]=classLessonAssignment(lessons[i], mechanics[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Sensors and Actuators 3.0 ") {
			//cout<<"YES"<<endl;
			sensors[k]=classLessonAssignment(lessons[i],sensors[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
		

	

	////////starting adding courses to 5 different schedules of 5 groups
	//second year 
	Schedule schedule2[2];
	//cout<<"de"<<survey[1].type[0]-48<<endl;
	bool usedS[7];
	bool usedD[7];
	bool usedA[7];
	bool usedM[7];
	for (i=0;i<=1;i++) {
		int s=0;
		int a=0;
		int m=0;
		int d=0;
		schedule2[i].m=0;
		schedule2[i].t=0;
		schedule2[i].w=0;
		schedule2[i].r=0;
		schedule2[i].f=0;
		for (int j=1;j<=8;j++) {
			if ((aided[j].capacity[0]-48)>2) {
				schedule2[i]=addingToSchedule(aided[j], schedule2[i]);
				cout<<schedule2[i].t<<endl;
			} else {
				if (check(aided[j], schedule2[i]) && usedS[j]!=1 && s==0) {
					cout<<"s"<<i<<endl;
					schedule2[i]=addingToSchedule(aided[j], schedule2[i]);
					usedS[j]=1;
					s++;	
				}	
			}
			if ((dynamics[j].capacity[0]-48)>3) {
				schedule2[i]=addingToSchedule(dynamics[j], schedule2[i]);
			} else {
				if (check(dynamics[j], schedule2[i]) && usedD[j]!=1 && d==0) {
					//cout<<"c"<<i<<endl;
					schedule2[i]=addingToSchedule(dynamics[j], schedule2[i]);
					usedD[j]=1;
					d++;	
				}	
			}
			if ((mechanics[j].capacity[0]-48)>3) {
				schedule2[i]=addingToSchedule(mechanics[j], schedule2[i]);
			} else {
				if (((mechanics[j].type[0]-48)+(i+1))==4 && mechanics[j].type.length()==3) {
					//cout<<"a"<<i<<endl;					
					schedule2[i]=addingToSchedule(mechanics[j], schedule2[i]);
				}	
			}
			if (((sensors[j].capacity[0]-48)>3 && (sensors[j].capacity[0]-48)<5) || (sensors[j].capacity[0]=='1')) {
				schedule2[i]=addingToSchedule(sensors[j], schedule2[i]);
			} else {
				if (check(sensors[j], schedule2[i]) && usedS[j]!=1 && s==0) {
					//cout<<"m"<<i<<endl;
					schedule2[i]=addingToSchedule(sensors[j], schedule2[i]);
					usedS[j]=1;
					s++;
				}	
			}
			if ((((math3[j].type[0]-48)==2) && (math3[j].type.length()==2)) || (math3[j].type[0]=='5')) {
				schedule2[i]=addingToSchedule(math3[j], schedule2[i]);
			}
		} 
	}
	cout<<"Adding To Schedule Check: "<<schedule2[0].T[1].courseTitle<<endl;
	//third year
	Schedule schedule3[2];
	//cout<<"de"<<survey[1].type[0]-48<<endl;
	bool usedH[7];
	bool usedCo[7];
	bool usedP[7];
	bool usedDe[7];
	for (i=0;i<=1;i++) {
		int h=0;
		int co=0;
		int p=0;
		int de=0;
		schedule3[i].m=0;
		schedule3[i].t=0;
		schedule3[i].w=0;
		schedule3[i].r=0;
		schedule3[i].f=0;
		for (int j=1;j<=8;j++) {
			if ((heat[j].capacity[0]-48)>2) {
				schedule3[i]=addingToSchedule(heat[j], schedule3[i]);
				//cout<<schedule2[i].t<<endl;
			} else {
				if (check(heat[j], schedule3[i]) && usedH[j]!=1 && h==0) {
					schedule3[i]=addingToSchedule(heat[j], schedule3[i]);
					usedH[j]=1;
					h++;	
				}	
			}
			if ((design[j].capacity[0]-48)>2) {
				schedule3[i]=addingToSchedule(design[j], schedule3[i]);
			}
			if ((control[j].capacity[0]-48)>2) {
				schedule3[i]=addingToSchedule(control[j], schedule3[i]);
				//cout<<schedule2[i].t<<endl;
			} else {
				if (check(control[j], schedule3[i]) && usedCo[j]!=1 && co==0) {
					schedule3[i]=addingToSchedule(control[j], schedule3[i]);
					usedCo[j]=1;
					co++;	
				}	
			} 
			if ((dynamics2[j].capacity[0]-48)>3) {
				schedule3[i]=addingToSchedule(dynamics2[j], schedule3[i]);
			} else {
				if (check(dynamics2[j], schedule3[i]) && usedDe[j]!=1 && de==0) {
					schedule3[i]=addingToSchedule(dynamics2[j], schedule3[i]);
					usedDe[j]=1;
					de++;	
				}	
			}
			if ((project[j].type[1]=='T'&& project[j].type[0]=='2' && usedP[j]!=1 && p==0) || project[j].capacity=="160") {
				schedule3[i]=addingToSchedule(project[j], schedule3[i]);
				if (project[j].capacity!="160") {
					usedP[j]=1;
					p++;
				}
			} 
		} 
	}
	
	//fourth year
	Schedule schedule4[1];
	//cout<<"de"<<survey[1].type[0]-48<<endl;
	for (i=0;i<=0;i++) {
		schedule4[i].m=0;
		schedule4[i].t=0;
		schedule4[i].w=0;
		schedule4[i].r=0;
		schedule4[i].f=0;
		for (int j=1;j<=8;j++) {
			if ((aero[j].capacity[0]-48)>1) {
				schedule4[i]=addingToSchedule(aero[j], schedule4[i]);
			}
			if ((heat[j].capacity[0]-48)>1) {
				schedule4[i]=addingToSchedule(heat[j], schedule4[i]);
			}
			if ((geometric[j].capacity[0]-48)>1) {
				schedule4[i]=addingToSchedule(geometric[j], schedule4[i]);
			} 
			if ((capstone[j].capacity[0]-48)>1) {
				schedule4[i]=addingToSchedule(capstone[j], schedule4[i]);
			}
			if ((clean[j].capacity[0]-48)>1) {
				schedule4[i]=addingToSchedule(clean[j], schedule4[i]);
			}
		} 
	}
	//check
	ofstream finalout;
	string s3="finalMechanicalout.txt";
	finalout.open (s3.c_str());
	finalout<<"SCHEDULE FOR MECHANICAL MAJOR, 2nd YEAR STUDENTS:";
	for (i=0;i<2;i++) {
		finalout<<"\nGroup "<<i+1<<":";
		finalout<<"\n\nMonday:";
		for (int j=1;j<=schedule2[i].m;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].M[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].M[j].type+"\n" + "The course day in weekend: "+schedule2[i].M[j].days+"\nThe Professors are: "+schedule2[i].M[j].faculty+"\nThe time is: "+schedule2[i].M[j].period + "\n" + "The location: "+ schedule2[i].M[j].room + "\nThe capacity: "+ schedule2[i].M[j].capacity;		 
		}
		finalout<<"\n\nTuesday:";
		for (int j=1;j<=schedule2[i].t;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].T[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].T[j].type+"\n"+"The course day in weekend: "+schedule2[i].T[j].days+"\nThe Professors are: "+schedule2[i].T[j].faculty+"\nThe time is: "+schedule2[i].T[j].period + "\n" + "The location: "+ schedule2[i].T[j].room + "\nThe capacity: "+ schedule2[i].T[j].capacity;		 
		}
		finalout<<"\n\nWednesday:";
		for (int j=1;j<=schedule2[i].w;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].W[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].W[j].type+"\n"+"The course day in weekend: "+schedule2[i].W[j].days+"\nThe Professors are: "+schedule2[i].W[j].faculty+"\nThe time is: "+schedule2[i].W[j].period + "\n" + "The location: "+ schedule2[i].W[j].room + "\nThe capacity: "+ schedule2[i].W[j].capacity;		 
		}                                                                                                                                                                          
		finalout<<"\n\nThursday:";
		for (int j=1;j<=schedule2[i].r;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].R[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].R[j].type+"\n"+"The course day in weekend: "+schedule2[i].R[j].days+"\nThe Professors are: "+schedule2[i].R[j].faculty+"\nThe time is: "+schedule2[i].R[j].period + "\n" + "The location: "+ schedule2[i].R[j].room + "\nThe capacity: "+ schedule2[i].R[j].capacity;		 
		}
		finalout<<"\n\nFriday:";
		for (int j=1;j<=schedule2[i].f;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].F[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].F[j].type+"\n"+"The course day in weekend: "+schedule2[i].F[j].days+"\nThe Professors are: "+schedule2[i].F[j].faculty+"\nThe time is: "+schedule2[i].F[j].period + "\n" + "The location: "+ schedule2[i].F[j].room + "\nThe capacity: "+ schedule2[i].F[j].capacity;		 
		}
	}
	finalout<<"\n\nSCHEDULE FOR MECHANICAL MAJOR, 3rd YEAR STUDENTS:";
	for (i=0;i<2;i++) {
		finalout<<"\nGroup "<<i+1<<":";
		finalout<<"\n\nMonday:";
		for (int j=1;j<=schedule3[i].m;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].M[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].M[j].type+"\n" + "The course day in weekend: "+schedule3[i].M[j].days+"\nThe Professors are: "+schedule3[i].M[j].faculty+"\nThe time is: "+schedule3[i].M[j].period + "\n" + "The location: "+ schedule3[i].M[j].room + "\nThe capacity: "+ schedule3[i].M[j].capacity;		 
		}
		finalout<<"\n\nTuesday:";
		for (int j=1;j<=schedule3[i].t;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].T[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].T[j].type+"\n"+"The course day in weekend: "+schedule3[i].T[j].days+"\nThe Professors are: "+schedule3[i].T[j].faculty+"\nThe time is: "+schedule3[i].T[j].period + "\n" + "The location: "+ schedule3[i].T[j].room + "\nThe capacity: "+ schedule3[i].T[j].capacity;		 
		}
		finalout<<"\n\nWednesday:";
		for (int j=1;j<=schedule3[i].w;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].W[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].W[j].type+"\n"+"The course day in weekend: "+schedule3[i].W[j].days+"\nThe Professors are: "+schedule3[i].W[j].faculty+"\nThe time is: "+schedule3[i].W[j].period + "\n" + "The location: "+ schedule3[i].W[j].room + "\nThe capacity: "+ schedule3[i].W[j].capacity;		 
		}                                                                                                                                                                          
		finalout<<"\n\nThursday:";
		for (int j=1;j<=schedule3[i].r;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].R[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].R[j].type+"\n"+"The course day in weekend: "+schedule3[i].R[j].days+"\nThe Professors are: "+schedule3[i].R[j].faculty+"\nThe time is: "+schedule3[i].R[j].period + "\n" + "The location: "+ schedule3[i].R[j].room + "\nThe capacity: "+ schedule3[i].R[j].capacity;		 
		}
		finalout<<"\n\nFriday:";
		for (int j=1;j<=schedule3[i].f;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].F[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].F[j].type+"\n"+"The course day in weekend: "+schedule3[i].F[j].days+"\nThe Professors are: "+schedule3[i].F[j].faculty+"\nThe time is: "+schedule3[i].F[j].period + "\n" + "The location: "+ schedule3[i].F[j].room + "\nThe capacity: "+ schedule3[i].F[j].capacity;		 
		}
	}
	finalout<<"\n\nSCHEDULE FOR MECHANICAL MAJOR, 4th YEAR STUDENTS:";
	for (i=0;i<1;i++) {
		finalout<<"\nGroup "<<i+1<<":";
		finalout<<"\n\nMonday:";
		for (int j=1;j<=schedule4[i].m;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].M[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].M[j].type+"\n" + "The course day in weekend: "+schedule4[i].M[j].days+"\nThe Professors are: "+schedule4[i].M[j].faculty+"\nThe time is: "+schedule4[i].M[j].period + "\n" + "The location: "+ schedule4[i].M[j].room + "\nThe capacity: "+ schedule4[i].M[j].capacity;		 
		}
		finalout<<"\n\nTuesday:";
		for (int j=1;j<=schedule4[i].t;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].T[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].T[j].type+"\n"+"The course day in weekend: "+schedule4[i].T[j].days+"\nThe Professors are: "+schedule4[i].T[j].faculty+"\nThe time is: "+schedule4[i].T[j].period + "\n" + "The location: "+ schedule4[i].T[j].room + "\nThe capacity: "+ schedule4[i].T[j].capacity;		 
		}
		finalout<<"\n\nWednesday:";
		for (int j=1;j<=schedule4[i].w;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].W[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].W[j].type+"\n"+"The course day in weekend: "+schedule4[i].W[j].days+"\nThe Professors are: "+schedule4[i].W[j].faculty+"\nThe time is: "+schedule4[i].W[j].period + "\n" + "The location: "+ schedule4[i].W[j].room + "\nThe capacity: "+ schedule4[i].W[j].capacity;		 
		}                                                                                                                                                                         
		finalout<<"\n\nThursday:";
		for (int j=1;j<=schedule4[i].r;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].R[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].R[j].type+"\n"+"The course day in weekend: "+schedule4[i].R[j].days+"\nThe Professors are: "+schedule4[i].R[j].faculty+"\nThe time is: "+schedule4[i].R[j].period + "\n" + "The location: "+ schedule4[i].R[j].room + "\nThe capacity: "+ schedule4[i].R[j].capacity;		 
		}
		finalout<<"\n\nFriday:";
		for (int j=1;j<=schedule4[i].f;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].F[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].F[j].type+"\n"+"The course day in weekend: "+schedule4[i].F[j].days+"\nThe Professors are: "+schedule4[i].F[j].faculty+"\nThe time is: "+schedule4[i].F[j].period + "\n" + "The location: "+ schedule4[i].F[j].room + "\nThe capacity: "+ schedule4[i].F[j].capacity;		 
		}
	} 
	finalout.close();
}
void electricalCoursesSorting (int numberOfLessons, Lesson lessons[100]) {
	int i;
	Lesson systems[10];
	Lesson image[10];
	Lesson circuits[10];
	Lesson em[10];
	Lesson design[10];
	Lesson power[10];
	Lesson antennas[10];
	Lesson integr[10];
	Lesson commun[10];
	Lesson capstone[10];
	Lesson plants[10];
	Lesson rf[10];
	Lesson high[10];
	Lesson math3[10];
	Lesson protect[10];
	Lesson mobile[10];
	Lesson project[10];
	Lesson mechanics[10];
	Lesson sensors[10];
	//cout<<lessons[1].courseTitle<<"TTT";
	int k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Signals and Systems 3.0 ") {
			//cout<<"YES"<<endl;
			systems[k]=classLessonAssignment(lessons[i],systems[k]);
			//cout<<survey[k].courseTitle<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Digital Signal and Image Processing 3.0 ") {
			//cout<<"YES"<<endl;
			image[k]=classLessonAssignment(lessons[i],image[k]);
			//cout<<mechanics[k].courseTitle<<endl;			 
			k++;
		}
	}			 
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Microelectronic Devices and Circuits 3.0 ") {
			//cout<<"YES"<<endl;
			circuits[k]=classLessonAssignment(lessons[i],circuits[k]);
			//cout<<programming[k].courseTitle<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Electronic Engineering Design Principles 3.0 ") {
			//cout<<"YES"<<endl;
			design[k]=classLessonAssignment(lessons[i],design[k]);
			//cout<<materials[k].courseTitle<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Engineering Mathematics III 3.0 ") {
			//cout<<"YES"<<endl;
			math3[k]=classLessonAssignment(lessons[i],math3[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Electromagnetics 3.0 ") {
			//cout<<"YES"<<endl;
			em[k]=classLessonAssignment(lessons[i],em[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Power Electronics 3.0 ") {
			//cout<<"YES"<<endl;
			power[k]=classLessonAssignment(lessons[i], power[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Antennas and Propagation 3.0 ") {
			//cout<<"YES"<<endl;
			antennas[k]=classLessonAssignment(lessons[i], antennas[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Digital integrated circuits design 3.0 ") {
			//cout<<"YES"<<endl;
			integr[k]=classLessonAssignment(lessons[i],integr[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Capstone project 1 3.0 ") {
			//cout<<"YES"<<endl;
			capstone[k]=classLessonAssignment(lessons[i], capstone[k]);
			//cout<<environment[k].days<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Digital Communications 3.0 ") {
			//cout<<"YES"<<endl;
			commun[k]=classLessonAssignment(lessons[i],commun[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Power Transmission and Distribution plants 3.0 ") {
			//cout<<"YES"<<endl;
			plants[k]=classLessonAssignment(lessons[i],plants[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="RF and Microwave Circuit Design 3.0 ") {
			//cout<<"YES"<<endl;
			rf[k]=classLessonAssignment(lessons[i],rf[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="High Voltage Engineering 3.0 ") {
			//cout<<"YES"<<endl;
			high[k]=classLessonAssignment(lessons[i],high[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Project Management 3.0 ") {
			//cout<<"YES"<<endl;
			project[k]=classLessonAssignment(lessons[i],project[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Power Systems Protection 3.0 ") {
			//cout<<"YES"<<endl;
			protect[k]=classLessonAssignment(lessons[i], protect[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Sensors and Actuators 3.0 ") {
			//cout<<"YES"<<endl;
			sensors[k]=classLessonAssignment(lessons[i],sensors[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Mobile Communications 3.0 ") {
			//cout<<"YES"<<endl;
			mobile[k]=classLessonAssignment(lessons[i],mobile[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}                                                       		

	

	////////starting adding courses to 5 different schedules of 5 groups
	//second year 
	Schedule schedule2[2];
	//cout<<"de"<<survey[1].type[0]-48<<endl;
	bool usedS[7];
	bool usedSA[7];
	bool usedM[7];
	for (i=0;i<=1;i++) {
		int s=0;
		int sa=0;
		int m=0;
		schedule2[i].m=0;
		schedule2[i].t=0;
		schedule2[i].w=0;
		schedule2[i].r=0;
		schedule2[i].f=0;
		for (int j=1;j<=8;j++) {
			if ((systems[j].capacity[0]-48)>2) {
				schedule2[i]=addingToSchedule(systems[j], schedule2[i]);
				//cout<<schedule2[i].t<<endl;
			} else {
				if (check(systems[j], schedule2[i]) && usedS[j]!=1 && s==0) {
					//cout<<"s"<<i<<endl;
					schedule2[i]=addingToSchedule(systems[j], schedule2[i]);
					usedS[j]=1;
					s++;	
				}	
			}
			if ((circuits[j].capacity[0]-48)>3) {
				schedule2[i]=addingToSchedule(circuits[j], schedule2[i]);
			} else {
				if (check(circuits[j], schedule2[i]) && usedM[j]!=1 && m==0) {
					//cout<<"c"<<i<<endl;
					schedule2[i]=addingToSchedule(circuits[j], schedule2[i]);
					usedM[j]=1;
					m++;	
				}	
			}
			if ((design[j].capacity[0]-48)>3) {
				schedule2[i]=addingToSchedule(design[j], schedule2[i]);
			} else {
				if (((mechanics[j].type[0]-48)+(i+1))==3) {
					//cout<<"a"<<i<<endl;					
					schedule2[i]=addingToSchedule(mechanics[j], schedule2[i]);
				}	
			}
			if ((sensors[j].capacity=="62")) {
				schedule2[i]=addingToSchedule(sensors[j], schedule2[i]);
			} else {
				if (check(sensors[j], schedule2[i]) && usedSA[j]!=1 && sa==0 && j>2) {
					//cout<<"m"<<i<<endl;
					schedule2[i]=addingToSchedule(sensors[j], schedule2[i]);
					usedSA[j]=1;
					sa++;
				}	
			}
			if ((j>3 && (math3[j].capacity[0]==3)) || (math3[j].type[0]=='5')) {
				schedule2[i]=addingToSchedule(math3[j], schedule2[i]);
			}
		} 
	}
	cout<<"Adding To Schedule Check: "<<schedule2[0].T[1].courseTitle<<endl;
	//third year
	Schedule schedule3[3];
	//cout<<"de"<<survey[1].type[0]-48<<endl;
	bool usedIm[7];
	bool usedE[7];
	bool usedP[7];
	bool usedDe[7];
	for (i=0;i<=2;i++) {
		int im=0;
		int e=0;
		int p=0;
		int de=0;
		schedule3[i].m=0;
		schedule3[i].t=0;
		schedule3[i].w=0;
		schedule3[i].r=0;
		schedule3[i].f=0;
		for (int j=1;j<=8;j++) {
			if ((image[j].capacity[0]-48)>2) {
				schedule3[i]=addingToSchedule(image[j], schedule3[i]);
				//cout<<schedule2[i].t<<endl;
			} else {
				if (check(image[j], schedule3[i]) && usedIm[j]!=1 && im==0) {
					schedule3[i]=addingToSchedule(image[j], schedule3[i]);
					usedIm[j]=1;
					im++;	
				}	
			}
			if ((em[j].capacity[0]-48)>2) {
				schedule3[i]=addingToSchedule(em[j], schedule3[i]);
				//cout<<schedule2[i].t<<endl;
			} else {
				if (check(em[j], schedule3[i]) && usedE[j]!=1 && e==0) {
					schedule3[i]=addingToSchedule(em[j], schedule3[i]);
					usedE[j]=1;
					e++;	
				}	
			}
			if ((power[j].capacity[0]-48)>2) {
				schedule3[i]=addingToSchedule(power[j], schedule3[i]);
				//cout<<schedule2[i].t<<endl;
			} else {
				if ((power[j].type[0]-48+i+1)==4) {
					schedule3[i]=addingToSchedule(power[j], schedule3[i]);
				}	
			} 
			if ((integr[j].capacity[0]-48)>3) {
				schedule3[i]=addingToSchedule(integr[j], schedule3[i]);
			} else {
				if ((integr[j].type[0]-48)%3==i) {
					schedule3[i]=addingToSchedule(integr[j], schedule3[i]);
					usedDe[j]=1;
					de++;	
				}	
			}
			if ((project[j].type[1]=='T'&& project[j].type[0]=='1' && usedP[j]!=1 && p==0) || project[j].capacity=="160") {
				schedule3[i]=addingToSchedule(project[j], schedule3[i]);
				if (project[j].capacity!="160") {
					p++;
				}
			} 
		} 
	}
	//fourth year
	Schedule schedule4[1];
	//cout<<"de"<<survey[1].type[0]-48<<endl;
	for (i=0;i<=0;i++) {
		schedule4[i].m=0;
		schedule4[i].t=0;
		schedule4[i].w=0;
		schedule4[i].r=0;
		schedule4[i].f=0;
		for (int j=1;j<=8;j++) {
			if ((antennas[j].capacity[0]-48)>1) {
				schedule4[i]=addingToSchedule(antennas[j], schedule4[i]);
			}
			if ((commun[j].capacity[0]-48)>1) {
				schedule4[i]=addingToSchedule(commun[j], schedule4[i]);
			}
			if ((capstone[j].capacity[0]-48)>1) {
				schedule4[i]=addingToSchedule(capstone[j], schedule4[i]);
			} 
			if ((rf[j].capacity[0]-48)>1) {
				schedule4[i]=addingToSchedule(rf[j], schedule4[i]);
			}
			if ((high[j].capacity[0]-48)>1) {
				schedule4[i]=addingToSchedule(high[j], schedule4[i]);
			}
		} 
	}
	//check
	ofstream finalout;
	string s3="finalElectricalout.txt";
	finalout.open (s3.c_str());
	finalout<<"SCHEDULE FOR ELECTRICAL MAJOR, 2nd YEAR STUDENTS:";
	for (i=0;i<2;i++) {
		finalout<<"\nGroup "<<i+1<<":";
		finalout<<"\n\nMonday:";
		for (int j=1;j<=schedule2[i].m;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].M[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].M[j].type+"\n" + "The course day in weekend: "+schedule2[i].M[j].days+"\nThe Professors are: "+schedule2[i].M[j].faculty+"\nThe time is: "+schedule2[i].M[j].period + "\n" + "The location: "+ schedule2[i].M[j].room + "\nThe capacity: "+ schedule2[i].M[j].capacity;		 
		}
		finalout<<"\n\nTuesday:";
		for (int j=1;j<=schedule2[i].t;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].T[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].T[j].type+"\n"+"The course day in weekend: "+schedule2[i].T[j].days+"\nThe Professors are: "+schedule2[i].T[j].faculty+"\nThe time is: "+schedule2[i].T[j].period + "\n" + "The location: "+ schedule2[i].T[j].room + "\nThe capacity: "+ schedule2[i].T[j].capacity;		 
		}
		finalout<<"\n\nWednesday:";
		for (int j=1;j<=schedule2[i].w;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].W[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].W[j].type+"\n"+"The course day in weekend: "+schedule2[i].W[j].days+"\nThe Professors are: "+schedule2[i].W[j].faculty+"\nThe time is: "+schedule2[i].W[j].period + "\n" + "The location: "+ schedule2[i].W[j].room + "\nThe capacity: "+ schedule2[i].W[j].capacity;		 
		}                                                                                                                                                                          
		finalout<<"\n\nThursday:";
		for (int j=1;j<=schedule2[i].r;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].R[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].R[j].type+"\n"+"The course day in weekend: "+schedule2[i].R[j].days+"\nThe Professors are: "+schedule2[i].R[j].faculty+"\nThe time is: "+schedule2[i].R[j].period + "\n" + "The location: "+ schedule2[i].R[j].room + "\nThe capacity: "+ schedule2[i].R[j].capacity;		 
		}
		finalout<<"\n\nFriday:";
		for (int j=1;j<=schedule2[i].f;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].F[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].F[j].type+"\n"+"The course day in weekend: "+schedule2[i].F[j].days+"\nThe Professors are: "+schedule2[i].F[j].faculty+"\nThe time is: "+schedule2[i].F[j].period + "\n" + "The location: "+ schedule2[i].F[j].room + "\nThe capacity: "+ schedule2[i].F[j].capacity;		 
		}
	}
	finalout<<"\n\nSCHEDULE FOR ELECTRICAL MAJOR, 3rd YEAR STUDENTS:";
	for (i=0;i<3;i++) {
		finalout<<"\nGroup "<<i+1<<":";
		finalout<<"\n\nMonday:";
		for (int j=1;j<=schedule3[i].m;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].M[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].M[j].type+"\n" + "The course day in weekend: "+schedule3[i].M[j].days+"\nThe Professors are: "+schedule3[i].M[j].faculty+"\nThe time is: "+schedule3[i].M[j].period + "\n" + "The location: "+ schedule3[i].M[j].room + "\nThe capacity: "+ schedule3[i].M[j].capacity;		 
		}
		finalout<<"\n\nTuesday:";
		for (int j=1;j<=schedule3[i].t;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].T[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].T[j].type+"\n"+"The course day in weekend: "+schedule3[i].T[j].days+"\nThe Professors are: "+schedule3[i].T[j].faculty+"\nThe time is: "+schedule3[i].T[j].period + "\n" + "The location: "+ schedule3[i].T[j].room + "\nThe capacity: "+ schedule3[i].T[j].capacity;		 
		}
		finalout<<"\n\nWednesday:";
		for (int j=1;j<=schedule3[i].w;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].W[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].W[j].type+"\n"+"The course day in weekend: "+schedule3[i].W[j].days+"\nThe Professors are: "+schedule3[i].W[j].faculty+"\nThe time is: "+schedule3[i].W[j].period + "\n" + "The location: "+ schedule3[i].W[j].room + "\nThe capacity: "+ schedule3[i].W[j].capacity;		 
		}                                                                                                                                                                          
		finalout<<"\n\nThursday:";
		for (int j=1;j<=schedule3[i].r;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].R[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].R[j].type+"\n"+"The course day in weekend: "+schedule3[i].R[j].days+"\nThe Professors are: "+schedule3[i].R[j].faculty+"\nThe time is: "+schedule3[i].R[j].period + "\n" + "The location: "+ schedule3[i].R[j].room + "\nThe capacity: "+ schedule3[i].R[j].capacity;		 
		}
		finalout<<"\n\nFriday:";
		for (int j=1;j<=schedule3[i].f;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].F[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].F[j].type+"\n"+"The course day in weekend: "+schedule3[i].F[j].days+"\nThe Professors are: "+schedule3[i].F[j].faculty+"\nThe time is: "+schedule3[i].F[j].period + "\n" + "The location: "+ schedule3[i].F[j].room + "\nThe capacity: "+ schedule3[i].F[j].capacity;		 
		}
	}
	finalout<<"\n\nSCHEDULE FOR ELECTRICAL MAJOR, 4th YEAR STUDENTS:";
	for (i=0;i<1;i++) {
		finalout<<"\nGroup "<<i+1<<":";
		finalout<<"\n\nMonday:";
		for (int j=1;j<=schedule4[i].m;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].M[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].M[j].type+"\n" + "The course day in weekend: "+schedule4[i].M[j].days+"\nThe Professors are: "+schedule4[i].M[j].faculty+"\nThe time is: "+schedule4[i].M[j].period + "\n" + "The location: "+ schedule4[i].M[j].room + "\nThe capacity: "+ schedule4[i].M[j].capacity;		 
		}
		finalout<<"\n\nTuesday:";
		for (int j=1;j<=schedule4[i].t;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].T[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].T[j].type+"\n"+"The course day in weekend: "+schedule4[i].T[j].days+"\nThe Professors are: "+schedule4[i].T[j].faculty+"\nThe time is: "+schedule4[i].T[j].period + "\n" + "The location: "+ schedule4[i].T[j].room + "\nThe capacity: "+ schedule4[i].T[j].capacity;		 
		}
		finalout<<"\n\nWednesday:";
		for (int j=1;j<=schedule4[i].w;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].W[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].W[j].type+"\n"+"The course day in weekend: "+schedule4[i].W[j].days+"\nThe Professors are: "+schedule4[i].W[j].faculty+"\nThe time is: "+schedule4[i].W[j].period + "\n" + "The location: "+ schedule4[i].W[j].room + "\nThe capacity: "+ schedule4[i].W[j].capacity;		 
		}                                                                                                                                                                         
		finalout<<"\n\nThursday:";
		for (int j=1;j<=schedule4[i].r;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].R[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].R[j].type+"\n"+"The course day in weekend: "+schedule4[i].R[j].days+"\nThe Professors are: "+schedule4[i].R[j].faculty+"\nThe time is: "+schedule4[i].R[j].period + "\n" + "The location: "+ schedule4[i].R[j].room + "\nThe capacity: "+ schedule4[i].R[j].capacity;		 
		}
		finalout<<"\n\nFriday:";
		for (int j=1;j<=schedule4[i].f;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].F[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].F[j].type+"\n"+"The course day in weekend: "+schedule4[i].F[j].days+"\nThe Professors are: "+schedule4[i].F[j].faculty+"\nThe time is: "+schedule4[i].F[j].period + "\n" + "The location: "+ schedule4[i].F[j].room + "\nThe capacity: "+ schedule4[i].F[j].capacity;		 
		}
	}
	finalout.close();
}
void chemicalCoursesSorting (int numberOfLessons, Lesson lessons[100]) {
	int i;
	Lesson intro[10];
	Lesson chem[10];
	Lesson thermo[10];
	Lesson separ[10];
	Lesson transport[10];
	Lesson research[10];
	Lesson process[10];
	Lesson reaction[10];
	Lesson methods[10];
	Lesson capstone[10];
	Lesson flows[10];
	Lesson math3[10];
	Lesson protect[10];
	Lesson project[10];
	Lesson mechanics[10];
	//cout<<lessons[1].courseTitle<<"TTT";
	int k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Introduction to Chemical Engineering 3.0 ") {
			//cout<<"YES"<<endl;
			intro[k]=classLessonAssignment(lessons[i],intro[k]);
			//cout<<survey[k].courseTitle<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Chemistry I 3.0 ") {
			//cout<<"YES"<<endl;
			chem[k]=classLessonAssignment(lessons[i],chem[k]);
			//cout<<mechanics[k].courseTitle<<endl;			 
			k++;
		}
	}			 
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Chemical Engineering Thermodynamics 3.0 ") {
			//cout<<"YES"<<endl;
			thermo[k]=classLessonAssignment(lessons[i],thermo[k]);
			//cout<<programming[k].courseTitle<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Separation Processes-I 3.0 ") {
			//cout<<"YES"<<endl;
			separ[k]=classLessonAssignment(lessons[i],separ[k]);
			//cout<<materials[k].courseTitle<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Engineering Mathematics III 3.0 ") {
			//cout<<"YES"<<endl;
			math3[k]=classLessonAssignment(lessons[i],math3[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Transport Phenomena-II 3.0 ") {
			//cout<<"YES"<<endl;
			transport[k]=classLessonAssignment(lessons[i],transport[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Research Practice 3.0 ") {
			//cout<<"YES"<<endl;
			research[k]=classLessonAssignment(lessons[i], research[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Advanced Process Simulation 3.0 ") {
			//cout<<"YES"<<endl;
			process[k]=classLessonAssignment(lessons[i], process[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Chemical Reaction Engineering 3.0 ") {
			//cout<<"YES"<<endl;
			reaction[k]=classLessonAssignment(lessons[i],reaction[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Capstone project 1 3.0 ") {
			//cout<<"YES"<<endl;
			capstone[k]=classLessonAssignment(lessons[i], capstone[k]);
			//cout<<environment[k].days<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Computational Methods in Chemical Engineering-II 3.0 ") {
			//cout<<"YES"<<endl;
			methods[k]=classLessonAssignment(lessons[i],methods[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Multi-Phase Flows 3.0 ") {
			//cout<<"YES"<<endl;
			flows[k]=classLessonAssignment(lessons[i],flows[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}
	k=1;                                                    
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Project Management 3.0 ") {
			//cout<<"YES"<<endl;
			project[k]=classLessonAssignment(lessons[i],project[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}                                                       
	k=1;
	for (i=1;i<=numberOfLessons;i++) {
		if(lessons[i].courseTitle=="Mechanics of Materials 3.0 ") {
			//cout<<"YES"<<endl;
			mechanics[k]=classLessonAssignment(lessons[i],mechanics[k]);
			//cout<<health[k].days<<"DE"<<endl;			 
			k++;
		}
	}                                                       		

	

	////////starting adding courses to 5 different schedules of 5 groups
	//second year 
	Schedule schedule2[2];
	//cout<<"de"<<survey[1].type[0]-48<<endl;
	bool usedC[7];
	bool usedSA[7];
	bool usedM[7];
	for (i=0;i<=1;i++) {
		int c=0;
		int sa=0;
		int e=0;
		int m=0;
		schedule2[i].m=0;
		schedule2[i].t=0;
		schedule2[i].w=0;
		schedule2[i].r=0;
		schedule2[i].f=0;
		for (int j=1;j<=8;j++) {
			if ((intro[j].capacity[0]-48)>2) {
				schedule2[i]=addingToSchedule(intro[j], schedule2[i]);
				//cout<<schedule2[i].t<<endl;
			}
			if ((chem[j].capacity[0]-48)>2) {
				schedule2[i]=addingToSchedule(chem[j], schedule2[i]);
			} else {
				if (check(chem[j], schedule2[i]) && usedC[j]!=1 && c==0) {
					//cout<<"c"<<i<<endl;
					schedule2[i]=addingToSchedule(chem[j], schedule2[i]);
					usedC[j]=1;
					c++;	
				}	
			}
			if ((thermo[j].capacity[0]-48)>2) {
				schedule2[i]=addingToSchedule(thermo[j], schedule2[i]);
			} else {
				if (((thermo[j].type[0]-48)+(i+1))==3) {
					//cout<<"a"<<i<<endl;					
					schedule2[i]=addingToSchedule(thermo[j], schedule2[i]);
				}	
			}
			if (mechanics[j].capacity=="30" || (mechanics[j].capacity[0]-48)>4) {
				schedule2[i]=addingToSchedule(mechanics[j], schedule2[i]);
			} 
			if (((math3[j].type[0]=='2' && j<3) || (math3[j].type[0]=='1' && j>3))) {
				schedule2[i]=addingToSchedule(math3[j], schedule2[i]);
			}
		} 
	}
	cout<<"Adding To Schedule Check: "<<schedule2[0].T[1].courseTitle<<endl;
	//third year
	Schedule schedule3[3];
	//cout<<"de"<<survey[1].type[0]-48<<endl;
	bool usedIm[7];
	bool usedE[7];
	bool usedP[7];
	bool usedIn[7];
	for (i=0;i<=2;i++) {
		int h=0;
		int co=0;
		int p=0;
		int de=0;
		schedule3[i].m=0;
		schedule3[i].t=0;
		schedule3[i].w=0;
		schedule3[i].r=0;
		schedule3[i].f=0;
		for (int j=1;j<=8;j++) {
			if ((separ[j].capacity[0]-48)>1) {
				schedule3[i]=addingToSchedule(separ[j], schedule3[i]);
				//cout<<schedule2[i].t<<endl;
			} 
			if ((transport[j].capacity[0]-48)>1) {
				schedule3[i]=addingToSchedule(transport[j], schedule3[i]);
			}
			if ((research[j].capacity[0]-48)>0) {
				schedule3[i]=addingToSchedule(research[j], schedule3[i]);
				//cout<<schedule2[i].t<<endl;
			} 
			if ((reaction[j].capacity[0]-48)>1) {
				schedule3[i]=addingToSchedule(reaction[j], schedule3[i]);
			}
			if ((project[j].type[1]=='T'&& project[j].type[0]=='3' && p==0) || project[j].capacity=="160") {
				schedule3[i]=addingToSchedule(project[j], schedule3[i]);
				if (project[j].capacity!="160") {
					p++;
				}
			} 
		} 
	}
	//fourth year
	Schedule schedule4[1];
	//cout<<"de"<<survey[1].type[0]-48<<endl;
	for (i=0;i<=0;i++) {
		schedule4[i].m=0;
		schedule4[i].t=0;
		schedule4[i].w=0;
		schedule4[i].r=0;
		schedule4[i].f=0;
		for (int j=1;j<=8;j++) {
			if ((methods[j].capacity[0]-48)>2) {
				schedule4[i]=addingToSchedule(methods[j], schedule4[i]);
			}
			if ((flows[j].capacity[0]-48)>2) {
				schedule4[i]=addingToSchedule(flows[j], schedule4[i]);
			}
			if ((capstone[j].capacity[0]-48)>2) {
				schedule4[i]=addingToSchedule(capstone[j], schedule4[i]);
			} 
			if ((process[j].capacity[0]-48)>2) {
				schedule4[i]=addingToSchedule(process[j], schedule4[i]);
			}               
		} 
	}
	//check
	ofstream finalout;
	string s3="finalChemicalout.txt";
	finalout.open (s3.c_str());
	finalout<<"SCHEDULE FOR CHEMICAL MAJOR, 2nd YEAR STUDENTS:";
	for (i=0;i<2;i++) {
		finalout<<"\nGroup "<<i+1<<":";
		finalout<<"\n\nMonday:";
		for (int j=1;j<=schedule2[i].m;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].M[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].M[j].type+"\n" + "The course day in weekend: "+schedule2[i].M[j].days+"\nThe Professors are: "+schedule2[i].M[j].faculty+"\nThe time is: "+schedule2[i].M[j].period + "\n" + "The location: "+ schedule2[i].M[j].room + "\nThe capacity: "+ schedule2[i].M[j].capacity;		 
		}
		finalout<<"\n\nTuesday:";
		for (int j=1;j<=schedule2[i].t;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].T[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].T[j].type+"\n"+"The course day in weekend: "+schedule2[i].T[j].days+"\nThe Professors are: "+schedule2[i].T[j].faculty+"\nThe time is: "+schedule2[i].T[j].period + "\n" + "The location: "+ schedule2[i].T[j].room + "\nThe capacity: "+ schedule2[i].T[j].capacity;		 
		}
		finalout<<"\n\nWednesday:";
		for (int j=1;j<=schedule2[i].w;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].W[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].W[j].type+"\n"+"The course day in weekend: "+schedule2[i].W[j].days+"\nThe Professors are: "+schedule2[i].W[j].faculty+"\nThe time is: "+schedule2[i].W[j].period + "\n" + "The location: "+ schedule2[i].W[j].room + "\nThe capacity: "+ schedule2[i].W[j].capacity;		 
		}                                                                                                                                                                          
		finalout<<"\n\nThursday:";
		for (int j=1;j<=schedule2[i].r;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].R[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].R[j].type+"\n"+"The course day in weekend: "+schedule2[i].R[j].days+"\nThe Professors are: "+schedule2[i].R[j].faculty+"\nThe time is: "+schedule2[i].R[j].period + "\n" + "The location: "+ schedule2[i].R[j].room + "\nThe capacity: "+ schedule2[i].R[j].capacity;		 
		}
		finalout<<"\n\nFriday:";
		for (int j=1;j<=schedule2[i].f;j++) {
			finalout<<endl<<"\nThe course title: "+schedule2[i].F[j].courseTitle+"\n"+"The lesson type: "+schedule2[i].F[j].type+"\n"+"The course day in weekend: "+schedule2[i].F[j].days+"\nThe Professors are: "+schedule2[i].F[j].faculty+"\nThe time is: "+schedule2[i].F[j].period + "\n" + "The location: "+ schedule2[i].F[j].room + "\nThe capacity: "+ schedule2[i].F[j].capacity;		 
		}
	}
	finalout<<"\n\nSCHEDULE FOR CHEMICAL MAJOR, 3rd YEAR STUDENTS:";
	for (i=0;i<2;i++) {
		finalout<<"\nGroup "<<i+1<<":";
		finalout<<"\n\nMonday:";
		for (int j=1;j<=schedule3[i].m;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].M[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].M[j].type+"\n" + "The course day in weekend: "+schedule3[i].M[j].days+"\nThe Professors are: "+schedule3[i].M[j].faculty+"\nThe time is: "+schedule3[i].M[j].period + "\n" + "The location: "+ schedule3[i].M[j].room + "\nThe capacity: "+ schedule3[i].M[j].capacity;		 
		}
		finalout<<"\n\nTuesday:";
		for (int j=1;j<=schedule3[i].t;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].T[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].T[j].type+"\n"+"The course day in weekend: "+schedule3[i].T[j].days+"\nThe Professors are: "+schedule3[i].T[j].faculty+"\nThe time is: "+schedule3[i].T[j].period + "\n" + "The location: "+ schedule3[i].T[j].room + "\nThe capacity: "+ schedule3[i].T[j].capacity;		 
		}
		finalout<<"\n\nWednesday:";
		for (int j=1;j<=schedule3[i].w;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].W[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].W[j].type+"\n"+"The course day in weekend: "+schedule3[i].W[j].days+"\nThe Professors are: "+schedule3[i].W[j].faculty+"\nThe time is: "+schedule3[i].W[j].period + "\n" + "The location: "+ schedule3[i].W[j].room + "\nThe capacity: "+ schedule3[i].W[j].capacity;		 
		}                                                                                                                                                                          
		finalout<<"\n\nThursday:";
		for (int j=1;j<=schedule3[i].r;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].R[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].R[j].type+"\n"+"The course day in weekend: "+schedule3[i].R[j].days+"\nThe Professors are: "+schedule3[i].R[j].faculty+"\nThe time is: "+schedule3[i].R[j].period + "\n" + "The location: "+ schedule3[i].R[j].room + "\nThe capacity: "+ schedule3[i].R[j].capacity;		 
		}
		finalout<<"\n\nFriday:";
		for (int j=1;j<=schedule3[i].f;j++) {
			finalout<<endl<<"\nThe course title: "+schedule3[i].F[j].courseTitle+"\n"+"The lesson type: "+schedule3[i].F[j].type+"\n"+"The course day in weekend: "+schedule3[i].F[j].days+"\nThe Professors are: "+schedule3[i].F[j].faculty+"\nThe time is: "+schedule3[i].F[j].period + "\n" + "The location: "+ schedule3[i].F[j].room + "\nThe capacity: "+ schedule3[i].F[j].capacity;		 
		}
	} 
	finalout<<"\n\nSCHEDULE FOR CHEMICAL MAJOR, 4th YEAR STUDENTS:";
	for (i=0;i<1;i++) {
		finalout<<"\nGroup "<<i+1<<":";
		finalout<<"\n\nMonday:";
		for (int j=1;j<=schedule4[i].m;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].M[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].M[j].type+"\n" + "The course day in weekend: "+schedule4[i].M[j].days+"\nThe Professors are: "+schedule4[i].M[j].faculty+"\nThe time is: "+schedule4[i].M[j].period + "\n" + "The location: "+ schedule4[i].M[j].room + "\nThe capacity: "+ schedule4[i].M[j].capacity;		 
		}
		finalout<<"\n\nTuesday:";
		for (int j=1;j<=schedule4[i].t;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].T[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].T[j].type+"\n"+"The course day in weekend: "+schedule4[i].T[j].days+"\nThe Professors are: "+schedule4[i].T[j].faculty+"\nThe time is: "+schedule4[i].T[j].period + "\n" + "The location: "+ schedule4[i].T[j].room + "\nThe capacity: "+ schedule4[i].T[j].capacity;		 
		}
		finalout<<"\n\nWednesday:";
		for (int j=1;j<=schedule4[i].w;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].W[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].W[j].type+"\n"+"The course day in weekend: "+schedule4[i].W[j].days+"\nThe Professors are: "+schedule4[i].W[j].faculty+"\nThe time is: "+schedule4[i].W[j].period + "\n" + "The location: "+ schedule4[i].W[j].room + "\nThe capacity: "+ schedule4[i].W[j].capacity;		 
		}                                                                                                                                                                         
		finalout<<"\n\nThursday:";
		for (int j=1;j<=schedule4[i].r;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].R[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].R[j].type+"\n"+"The course day in weekend: "+schedule4[i].R[j].days+"\nThe Professors are: "+schedule4[i].R[j].faculty+"\nThe time is: "+schedule4[i].R[j].period + "\n" + "The location: "+ schedule4[i].R[j].room + "\nThe capacity: "+ schedule4[i].R[j].capacity;		 
		}
		finalout<<"\n\nFriday:";
		for (int j=1;j<=schedule4[i].f;j++) {
			finalout<<endl<<"\nThe course title: "+schedule4[i].F[j].courseTitle+"\n"+"The lesson type: "+schedule4[i].F[j].type+"\n"+"The course day in weekend: "+schedule4[i].F[j].days+"\nThe Professors are: "+schedule4[i].F[j].faculty+"\nThe time is: "+schedule4[i].F[j].period + "\n" + "The location: "+ schedule4[i].F[j].room + "\nThe capacity: "+ schedule4[i].F[j].capacity;		 
		}
	}
	finalout.close();
}

void nameOfFile (Lesson lessons[100]) {
	//first year schedule
	ofstream out;
	ifstream in;
	string s="first";
	string s1=s+"in.txt";
	string s2=s+"out.txt";
	in.open (s1.c_str());
	out.open (s2.c_str());
	int numberOfLessons = parsing(lessons,in,out);
	coursesSorting(numberOfLessons, lessons);
	in.close();
	out.close();
	string year1="electrical";
	string year2="civil";
	string year3="mechanical";
	string year4="chemical";
	//dividing by majors
	//civil
	ofstream civilOut;
	ifstream civilIn;
	string c1=year2+"in.txt";
	string c2=year2+"out.txt";
	civilIn.open (c1.c_str());
	civilOut.open (c2.c_str());
	numberOfLessons = parsing(lessons,civilIn,civilOut);
	civilCoursesSorting(numberOfLessons, lessons);
	civilIn.close();
	civilOut.close();
	//mechanical
	ofstream mechanicalOut;
	ifstream mechanicalIn;
	string m1=year3+"in.txt";
	string m2=year3+"out.txt";
	mechanicalIn.open (m1.c_str());
	mechanicalOut.open (m2.c_str());
	numberOfLessons = parsing(lessons,mechanicalIn,mechanicalOut);
	mechanicalCoursesSorting(numberOfLessons, lessons);
	mechanicalIn.close();
	mechanicalOut.close();
	//electrical
	ofstream electricalOut;
	ifstream electricalIn;
	string e1=year1+"in.txt";
	string e2=year1+"out.txt";
	electricalIn.open (e1.c_str());
	electricalOut.open (e2.c_str());
	numberOfLessons = parsing(lessons,electricalIn,electricalOut);
	electricalCoursesSorting(numberOfLessons, lessons);
	electricalIn.close();
	electricalOut.close();
	//chemical
	ofstream chemicalOut;
	ifstream chemicalIn;
	string ch1=year4+"in.txt";
	string ch2=year4+"out.txt";
	chemicalIn.open (ch1.c_str());
	chemicalOut.open (ch2.c_str());
	numberOfLessons = parsing(lessons,chemicalIn,chemicalOut);
	chemicalCoursesSorting(numberOfLessons, lessons);
	chemicalIn.close();
	chemicalOut.close();
}

int main() {
	Lesson lessons[100];
	nameOfFile(lessons); 
	return 0;
}