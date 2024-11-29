//write a c++ program that accepts students information and assessment for seven courses from the user and display thier result//

//Name : LETERA TUJO
//ID NUMBER : 0677/15
//SECTION : B



#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

string calculateGrade(double a, double b, double c, double d);
void decoredouble();
void decoredoublebelow();
void decoresingle();
double calculatecourse(double e,double f,double g, double h);

int main(){
   // int coursesum = 0;
	bool loop = true;
	int course_num = 7;

	string fname, lname, gender,age,year, id, dep;


	
	cout << "### WELCOME TO HARAMAYA UNIVERSITY ####\n";
	cout << "### DETAIL STUDENT INFORMATION AND THEIR GRADE ####" << endl;
	string courses[20], grades[20], tempcourse;
	double labassignment, mid, assignment, finall, credithours, ects, gpa[20];
	int cors;
    double  cgpa = 0;
	while(loop){

		cout<<"\n\nEnter the following information about the student";
		cout<<"\nFirst Name: ";
		cin>>fname;
		cout<<"\nLast Name: ";
		cin>>lname;
		cout<<"\nSex (M/F): ";
	    cin>>gender;
        cout << "\nage :";
        cin >> age;
        
    	cout<<"\nyear:";
		cin>>year;
		cout<<"\nId: ";
		cin>>id;
		cout<<"\nDepartment: ";
		cin>>dep;
        cout<<"\n\nHow many courses do you take: \n";
        cin>>cors; 
		for (int i = 0; i < cors; i++) {

			cout << "\n Enter Course name: ";
	    	cin>>courses[i];
			cout << "\n enter credit hours :";
            cin >> credithours;
            cout << "\n ETCS :";
            cin >>ects;
            cout << "\nEnter Course Assessements :\n";
	        cout << "\nenter value of  lab assignment between (0-10) " << tempcourse << " :";
			cin >> labassignment;
            cout << "\n enter value of mid between (0-30) " << tempcourse<< " :";
			cin >> mid;
			cout << "\nenter value of assignment between (0-10) " << tempcourse<<":";
			cin >> assignment;
			cout << "\nenter value of final exam between (0-50) " << tempcourse<< ":";
			cin >> finall;

        
            grades[i] = calculateGrade(labassignment, mid, assignment, finall);
            gpa[i]= calculatecourse(labassignment,mid, assignment, finall);
            cgpa = cgpa + gpa[i]/cors;
		}

        decoredouble();
        cout << "\nfull name :" << fname << " " << lname ;
      //  decoresingle();
        cout << "   ID number :" << id;
        cout << "  \n\n  sex :" << gender;
        cout << "        age :" << age;
        cout << "\n\n department :" << dep;
        cout<<  "        year :"<<year<<"\n";
        
        decoresingle();
		
        cout<<"\n";
        cout<<"\n|Course Name|"<<"|grade|"<<"|Grade values|" <<"|C.H|" <<"|ETCS|";
        decoresingle();
		    for( int i=0; i<cors; i++){

			cout << "\n|"<<courses[i]<<"|   | "<<grades[i]<<"|   | "<<gpa[i]<<"|  | "<<credithours<<"| | "<<ects<<"|";
			cout << "\t";
			cout << "\n";
			decoredoublebelow();
			
		}
       cout<<"\n\n\t   Gpa == "<<cgpa;
         
        string check;
        cout << "\n\nTo exit enter s else enter any key\n\n";
        cin >> check;
        if (check == "s" || check == "S") 
		break;

	}

	cout<<"\n Thank you !";

	return 0;
}
string calculateGrade(double labassignment, double mid, double assignment, double final){

	double sum = labassignment+mid+assignment+final;

	if(sum<0 && sum>100) return "null";
	else if(sum>=0 && sum<40)
	return "F";
    else if(sum>=40 && sum<=49)
	return "D";
    else if(sum>=50 && sum<=54)
	return "C-";
    else if(sum>=55 && sum<=59)
	return "C";
	else if(sum>=60 && sum<=64)
	return "C+";
	else if(sum>=65 && sum<=69)
	return "B-";
	else if(sum>=70 && sum<=74)
	return "B";
	else if(sum>=75 && sum<=79) return "B+";
    else if(sum>=80 && sum<=84) return "A-";
    else if(sum>=85 && sum<=89) return "A";
    else if(sum>=90 && sum<=100) return "A+";
}
double calculatecourse(double labassignment, double mid, double assignment, double final){
	double sum = labassignment+mid+assignment+final;
	if(sum<0 && sum>100) 
	return 0.0;
	else if(sum>=0 && sum<40)
	return 0;
    else if(sum>=40 && sum<=49)
	return 1;
    else if(sum>=50 && sum<=54)
	return 1.75;
    else if(sum>=55 && sum<=59)
	return 2;
	else if(sum>=60 && sum<=64)
	return 2.5;
	else if(sum>=65 && sum<=69)
	return 2.75;
	else if(sum>=70 && sum<=74)
	return 3;
	else if(sum>=75 && sum<=79) return 3.5;
    else if(sum>=80 && sum<=84) return 3.75;
    else if(sum>=85 && sum<=89) return 4;
    else if(sum>=90 && sum<=100) return 4;
}
void decoredouble() {
	cout << "\n\n=========================================================================================";
}
void decoredoublebelow() {
	cout << "========================================================================================";
}
void decoresingle() {
	cout << "----------------------------------------------------------------------------------------";
	} 