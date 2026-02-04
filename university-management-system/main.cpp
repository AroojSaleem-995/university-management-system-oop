#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Person { protected:
string name, cnic; public:
Person() : name("\0"), cnic("\0") {} Person(string n, string c) : name(n), cnic(c) {} void get_data() {
cout <<"\tEnter Name: "; cin.ignore();
getline(cin, name);
cout << "\tEnter CNIC (format XXXXX-XXXXXXX-X): "; getline(cin, cnic);
}
void display() {
cout << "\tYour Name: " << name << endl << "\tYour CNIC # " << cnic << endl;
}
};
class Admin { //abstract class public:
virtual void set_salary()=0; virtual void set_fee() =0;
};
class Student : public Person ,public Admin{ protected:
string roll_no, section, department, course_title[10], dob,grade[10]; int semester, no_of_courses;
double marks[10], gpa[10], credit_hours[10];
 

char c; public:
int get_no_of_courses(){ return no_of_courses;
}
void get_data() { Person::get_data();
cout << "\tEnter date of birth: "; cin >> dob;
cout << "\tEnter roll number: "; cin >> roll_no;
cout << "\tEnter semester: "; cin >> semester; cin.ignore();
cout << "\tEnter section: "; getline(cin, section);
cout << "\tEnter department: "; getline(cin, department);
cout<<"\tDo you want to check your GPA :"; cin>>c;
cin.ignore(); if(c=='y' || c== 'Y'){
cout << "\tEnter Number of Courses: "; cin >> no_of_courses;
cin.ignore();
for (int i = 0; i < no_of_courses; i++) { cout << "\tEnter the course title: "; getline(cin, course_title[i]);
cout << "\tPlease enter your marks of this course: "; cin >> marks[i];
cout << "\tEnter your Credit hours of this Course: "; cin >> credit_hours[i];
cin.ignore();
}
cal_gpa();
} else no_of_courses = 0;
}
double* get_gpa(){ return gpa;
}
double* get_credit_hours(){ return credit_hours;
}
void cal_gpa() { if(no_of_courses >0){
for (int i = 0; i < no_of_courses; i++) { if (marks[i] >= 85){
 


gpa[i] = 4.0; grade[i]="A";}
else if (marks[i] >= 80){ gpa[i] = 3.7; grade[i]="A-";}
else if (marks[i] >= 75){ gpa[i] = 3.3; grade[i]="B+";}
else if (marks[i] >= 70){ gpa[i] = 3.0; grade[i]="B";}
else if (marks[i] >= 65){ gpa[i] = 2.7; grade[i]="B-";}
else if (marks[i] >= 60){ gpa[i] = 2.3; grade[i]="C+";}
else if (marks[i] >= 58){ gpa[i] = 2.0; grade[i]="C";}
else if (marks[i] >= 55){ gpa[i] = 1.7; grade[i]="C-";}
else if (marks[i] >= 50){ gpa[i] = 1.5; grade[i]="D";}
else{
gpa[i] = 0.0; grade[i]="F";}
}
}
else
cout<<"\tYou have entered no of courses 0 so there is no GPA calculated "<<endl;
}
void set_fee() {
cout << "\tIf you are a Regular Student press 1, for Self support press 2: "; cin >> c;
if (department == "Software engineering" || department == "SE") { if (c == '1')
cout << "\tYour Total Fee is 50,000 Rs" << endl; else if (c == '2')
cout << "\tYour Total Fee is 95,000 Rs" << endl;
} else if (department == "Computer Science" || department == "CS") { if (c == '1')
cout << "\tYour Total Fee is 50,000 Rs" << endl;
else if (c == '2')
cout << "\tYour Total Fee is 85,000 Rs" << endl;
} else if (department == "Electronic engineering" || department == "EE") { if (c == '1')
cout << "\tYour Total Fee is 50,000 Rs" << endl; else if (c == '2')
cout << "\tYour Total Fee is 85,000 Rs" << endl;
} else if (department == "Business Administration" || department == "BA") { if (c == '1')
cout << "\tYour Total Fee is 50,000 Rs" << endl; else if (c == '2')
cout << "\tYour Total Fee is 85,000 Rs" << endl;
} else if (department == "Physics" || department == "Phy") { if (c == '1')
cout << "\tYour Total Fee is 50,000 Rs" << endl; else if (c == '2')
cout << "\tYour Total Fee is 85,000 Rs" << endl;
} else if (department == "Education" || department == "Edu") { if (c == '1')
cout << "\tYour Total Fee is 50,000 Rs" << endl; else if (c == '2')
cout << "\tYour Total Fee is 85,000 Rs" << endl;
} else
cout << "\tDepartment not recognized!" << endl;
}
void set_salary(){
//no implementation required in this class
}
void display() {
cout << "\tYou have entered the following information:" << endl; Person::display();
cout << "\tDate of Birth: " << dob << endl << "\tRoll #: " << roll_no << endl << "\tSemester: " << semester << endl << "\tSection: " << section << endl << "\tDepartment: " << department << endl; if (no_of_courses > 0) {
cout << "\tGPA for the courses:" << endl; for (int i = 0; i < no_of_courses; i++) {
cout << "\tYou have "<< gpa[i] <<" GPA in the Course " <<course_title[i] << endl<<"\tYour Grade is "<<grade[i]<< " in the Course " <<course_title[i] << endl;
}
}
else
cout<<"\tNo GPA Calculated "<<endl;
}
};
class Professor : public Person, public Admin { protected:

string designation, qualification, department; double salary, medical, house_rent ;
public:
void get_data() { Person::get_data();
cout << "\tEnter your designation: "; getline(cin, designation);
cout << "\tEnter qualification: "; getline(cin, qualification);
cout << "\tEnter Department: "; getline(cin, department);
}
void set_salary() {
if (designation == "Permanent Instructor" || designation == "permanent instructor") { salary = 200000;
} else if (designation == "Visiting Instructor" || designation == "visiting instructor") { salary = 150000;
} else if (designation == "Contractual Instructor" || designation == "contractual instructor") { salary = 170000;
} else
cout<<"\tDesignation not Recoganized! "<<endl; medical = 0.25 * salary;
house_rent = 0.1 * salary;
}
void set_fee(){
//no implementation required in this class
}
void display() {
cout << "\tYou have entered the following information:" << endl; Person::display();
cout << "\tYour Designation : " << designation << "\n\tYour Qualification : " << qualification << "\n\tYour Department : " << department << endl;
cout << "\tYour Salary is " << (salary + medical + house_rent) << endl;
}
};
class Staff : public Admin, public Person { protected:
string designation, department, hire_date; double salary,house_rent,medical ; public:
void get_data() { Person::get_data();
cout << "\tEnter hire date: "; getline(cin, hire_date);
cout << "\tEnter Department: "; getline(cin, department);
 

cout << "\tEnter your designation: "; getline(cin, designation);
}
void set_salary() {
if (designation == "DC" || designation == "dc") { salary = 150000;
} else if (designation == "HOD" || designation == "hod") { salary = 300000;
} else if (designation == "lab assistant" || designation == "Lab Assistant") { salary = 100000;
} else if (designation == "security guard" || designation == "Security Guard") { salary = 50000;
} else if (designation == "cleaner" || designation == "Cleaner") { salary = 30000;
} else if (designation == "engineer" || designation == "Engineer") { salary = 150000;
} else {
cout << "\tDesignation not recognized!" << endl; return;
}
medical = 0.25 * salary; house_rent = 0.1 * salary;
}
void set_fee() {
// No implementation required in this class
}
void display() {
cout << "\tYou have entered the following information:" << endl; Person::display();
cout << "\tDesignation: " << designation << "\n\tDepartment: " << department << "\n\tHire Date: " << hire_date << endl;
cout << "\tYour Salary is " << (salary + medical + house_rent) << endl;
}
};
class Department { protected:
string timetable[5][5]; double cgpa; Student* S; Professor* P;
public:
Department(Student* sobj, Professor* pobj){ this->S=sobj;
this->P=pobj;
}
void get_data() {
 

char c, x;
cout << "Are you a student (y/n)? "; cin >> c;
if (c == 'y' || c == 'Y') { S->get_data();
cout<<"\tDo you want to check your CGPA (y/n)? "; cin>>x;
if(x=='y' || x=='Y') CGPA();
cout<<"\tDo you want to check your Semester Fee (y/n)? "; cin>>x;
if(x=='y' || x=='Y') S->set_fee();
} else if (c == 'n' || c == 'N') {
// If not a student, check if the user is a professor cout << "Are you a Professor (y/n)? ";
cin >> c;
if (c == 'y' || c == 'Y') { P->get_data();
cout<<"\tDo you want to check your Salary (y/n)? "; cin>>x;
if(x=='y' || x=='Y') P->set_salary();
} else {
cout << "Invalid option selected!" << endl;
}
} else {
cout << "Invalid option selected!" << endl;
}
}
void set_timetable() {
cout << "Enter the timetable (3 rows for days, 3 columns for time slots):" << endl; cin.ignore();
for (int i = 0; i < 3; i++) {
cout << "Day " << i + 1 << ":" << endl; for (int j = 0; j < 3; j++) {
cout << "\tSlot " << j + 1 << " (Enter time and details): "; getline(cin, timetable[i][j]);
}
}
}
void CGPA() { S->cal_gpa();
double creditPoints = 0, creditHour = 0; if (S->get_no_of_courses() > 0) {
 

for (int i = 0; i < S->get_no_of_courses(); i++) {
creditPoints = creditPoints + ( S->get_gpa()[i] * S->get_credit_hours()[i]); creditHour = creditHour + S->get_credit_hours()[i];
}
cgpa = creditPoints / creditHour;
}
else
cgpa = 0.0;
}
void display() { char c;
cout << "Are you a Student (y/n)? "; cin >> c;
if (c == 'y' || c == 'Y') { S->display();
cout << "\tYour CGPA is: " << cgpa << endl; cout << "Timetable:" << endl;
for (int i = 0; i < 3; i++) {
cout << "Day " << i + 1 << ":"; for (int j = 0; j < 3; j++) {
cout << " " << timetable[i][j];
}
cout << endl;
}
} else if (c == 'n' || c == 'N') {
cout << "Are you a Professor (y/n)? "; cin >> c;
if (c == 'y' || c == 'Y') { P->display();
cout << "Timetable:" << endl; for (int i = 0; i < 3; i++) {
cout << "Day " << i + 1 << ":"; for (int j = 0; j < 3; j++) {
cout << " " << timetable[i][j];
}
cout << endl;
}
} else {
cout << "Invalid option selected!" << endl;
}
} else {
cout << "Invalid option selected!" << endl;
}
}
};
 

class User { private:
string username[10], password[10], pass; char ch;
public:
User(){
for(int i=0; i<10; i++){ username[i]="";
password[i]="";
}
}
void set_data(){ for(int i=0;i<10;i++){ if(username[i]==""){
cout<<"Set your username: "; cin>>username[i]; cout<<"Set your password: "; cin>>password[i];
cout << "User registered successfully." << endl; storeData(username[i],password[i]);  loadData();
return;
}
}
}
void storeData( string uname,string pwd) { ofstream fout("userID.txt", ios::app);
if (fout.is_open()) {
fout << uname << " " << pwd << endl; fout.close();
} else {
cout << "Unable to open file for writing." << endl;
}
}
void loadData() { ifstream fin("userID.txt"); string uname, pwd;
int index = 0;
while (fin >> uname >> pwd) { if (index < 10) { username[index] = uname; password[index] = pwd; index++;
}
}
 

fin.close();
}
void updateFile() { ofstream fout("userID.txt"); if (fout.is_open()) {
for (int i = 0; i < 10; i++) { if (username[i] != "") {
fout << username[i] << " " << password[i] << endl;
}
}
fout.close();
} else {
cout << "Unable to open file for writing." << endl;
}
}
bool login(string uname, string pwd) { loadData();
bool found = false;
for (int i = 0; i < 10; i++) { if (uname == username[i]) { found = true;
if (pwd == password[i]) {
cout << "Login successful" << endl; return true;
}
else {
cout << "Invalid password. Do you want to change your password? (y/n): "; cin >> ch;
if (ch == 'y') {
cout << "Enter new password: "; cin >> pass;
password[i] = pass; updateFile();
cout << "Your password is updated successfully." << endl; return true;
}
else {
cout << "Thank you for the response." << endl; return false;
}
}
}
}
if (!found) {
cout << "Username not found." << endl;
 

return false;
}
}
};
void afterlogin()
{
Admin *a0,*a1,*a2; Student s;
char c, x;
cout << "Are you Student? (press 1), Professor? (press 2), Staff? (press 3) , From department? (press4): "; cin >> c;
if (c == '1') {
cout<<"---------Student Class	"<<endl;
a0=&s; s.get_data();
cout<<"\tDo you want to check your Semester Fee (y/n)? "; cin>>x;
if(x=='y' || x=='Y') s.set_fee();
cout<<"\tDo you want to check your Result (y/n)? "; cin>>x;
if(x=='y' || x=='Y') s.cal_gpa();
s.display();
}
else if (c == '2') {
cout<<"---------Professor Class	"<<endl;
Professor p; a1=&p; p.get_data();
cout<<"\tDo you want to check your Salary (y/n)? "; cin>>x;
if(x=='y' || x=='Y') p.set_salary(); p.display();
}
else if (c == '3') {
cout<<"---------Staff Class	"<<endl;
Staff st; a2=&st; st.get_data();
cout<<"\tDo you want to check your Salary (y/n)? "; cin>>x;
if(x=='y' || x=='Y') st.set_salary();
 

st.display();
}
else if(c== '4'){
cout<<"---------Department Class	"<<endl;
Student s;
Professor p;
Department d(&s,&p); d.set_timetable(); d.get_data();
system("cls");
d.display();
}
else {
cout << "\tInvalid option selected!" << endl;
}
return;
}
int main() { User person; int choice;
string username, password;
cout << "\t\t\t\t-------Welcome to FATIMA JINNAH WOMEN UNIVERSITY	" << endl;
cout<<"New User(press 1) or have an account(press 2)?"; cin>>choice;
if(choice==1){ person.set_data();
cout<<"\nnow login to your account"<<endl; cout<<"Enter Username: ";
cin>>username; cout<<"Enter Password: "; cin>>password;
if(person.login(username,password)==true) afterlogin();
}
else if(choice==2){ cout<<"Username: "; cin>>username; cout<<"password: "; cin>>password;
if(person.login(username,password)==true) afterlogin();
}
system("pause"); return 0;
}
