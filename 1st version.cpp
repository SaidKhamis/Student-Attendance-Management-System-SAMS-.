#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Base class Student
class Student {
private:
	int student_id;
	string student_name;

public:
	// Constructor to initialize student details
	Student(int id, string name) : student_id(id), student_name(name) {}
	
	// Function to add a student
	void add_student() {
		cout << " Student(s) Added Successfully.\n";
	}
	
	// Function to display student details
	void display_student() const {
		cout << "  " << student_id << " | " << student_name << endl;
	}
};

// Derived class Attendance
class Attendance : public Student {
private:
	string date;
	string status;  // "Present" or "Absent"

public:
	// Constructor to initialize attendance details
	Attendance(int id, string name, string date, string status): Student(id, name), date(date), status(status) {}
	
	// Function to mark attendance
	void mark_attendance() {
		cout << "Attendance for " << student_name << " on " << date << ": " << status << endl;
	}
	
	// Function to display attendance record
	void display_attendance() const {
		cout << "ID: " << student_id << " | Date: " << date << " | Status: " << status << endl;
	}
	
	string getDate() const { 
		return date; 
	}
};

int main() {
	vector<Student*> students;
	vector<Attendance*> attendanceRecords;
	string currentDate; //Variable to store the date for the current attendance marking

	int choice;
	do {
		system("cls");
		//Display menu options.
		cout << "\n   ***  STUDENT ATTENDANCE MANAGEMENT SYSTEM  ***   \n";
		cout << "1. Add Student.\n";
		cout << "2. Mark Attendance.\n";
		cout << "3. Display Students.\n";
		cout << "4. Display Attendance.\n";
		cout << "5. Delete Student.\n";
		cout << "6. Exit.\n";
		cout << " Enter your choice: ";
		cin >> choice;
		
		switch (choice){
			case 1: 
			{	
				int exit;
				do{
					//Add new student
					int id;
					string name;
					cout << "\n Enter Student ID: ";
					cin >> id;
					cin.ignore();
					cout << " Enter Student Name: ";
					getline(cin, name);
				
					Student* newStudent = new Student(id, name);
					students.push_back(newStudent);
					
					cout << "\nPress 0-continue or 1-close : ";
					cin >> exit;
				}	while(exit==0);		
				cout << students.add_student();	
				break;
			}
			
			case 2: 
			{	
				cout << "\n Enter Date (DD-MM-YYYY): ";
				cin >> currentDate;  // Set the date for the current attendance session

				int exit2;
				do {
				   int id;
				   string status;
				   cout << " Enter Student ID: ";
				   cin >> id;
				   cout << " Enter Status (Present/Absent): ";
				   cin >> status;
				
				   // Find the student by ID
				   for (auto& student : students) {
					if (student->student_id == id) {
						Attendance* newAttendance = new Attendance(id, student->student_name, currentDate, status);
						newAttendance->mark_attendance();
						attendanceRecords.push_back(newAttendance);
						break;
					}
				 }
					cout << "\n Enter 0 to Continue or 1 to Exit : ";
					cin >> exit2;
				}
					while(exit2==0);
				break;
			}
			
			case 3:	{
				cout << "\n -- STUDENT'S LIST -- \n";
				for (const auto& student : students) {
					student->display_student();
				}		
				break;				
			}		
				
			case 4:
				for (const auto& record : attendanceRecords) {
					record->display_attendance();
				}
				break;
			
			case 5:
				cout << "\n -- STUDENT'S LIST -- \n";
				for (const auto& student : students) {
					student->display_student();
				}
				 int id;
				 cout << "\n Enter Student ID to delete: ";
				 cin >> id;
				 
				 for(auto it=students.begin(); it!=students.end(); it++){
				 	if((*it)->student_id==id){
				 		students.erase(it);
				 		cout << " Student deleted successfully!\n";
					 }
				 }
				 break;
				 
			case 6:
				cout << "\n  Thank you for using the Students Attendance Management System, Good Bye..\n";
				break;
				
			default:
				cout << "\n Invalid choice. Please try again.\n";
	      }
		system("pause");
	} while (choice != 6);
	
	return 0;
}
