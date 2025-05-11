#include <iostream>
#include <fstream> //Get environment to apply file based storage
#include <sstream> //To allow variables as stream
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
		char exit;
		do{
			cout << "\nEnter Student ID: ";
		        cin >> student_id;
		        cout << "\nEnter Student's Name: ";
		        cin >> student_name;
		
		        ofstream Student_File("Students.txt", ios::app); /*Create or Open the file. with append mode to avoid data overwritten in the file*/
		        if(Student_File.isopen()) {
			     Student_File << "Student_ID: " << student_id;
			     Student_File << "\nName: " << student_name;
			     Student_File.close();
		 	     cout << "Student Added Successfully.\n";
		       }  
		       else {
			     cout << "\nError: Unable to open the file, Please Try again later.";
		       }

			
			do {
			     cout << "\nDo you wish to continue (y/n) : ";
				
			     cin >> exit;
			     exit = tolower(exit); //Converting the enterd character Y/y or N/n to small letter.
			} while(exit!='y' && exit!='n');  //Allow only y and n, if not the program will iterate and need a user to enter again another character.
		}
		while(exit=='y');
	}
	
	// Function to display student details
	void display_student() const {
		ifstream Student_file("Students.txt");
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

        // Getter to set date during marking
	string getDate() const { 
		return date; 
	}
};

        

int main() {
	string currentDate; //Variable to store the date for the current attendance marking

	int choice;
	do {
		system("cls"); // Command to clean the window suraface after one iteration.
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
			    add_student();
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
		system("pause"); // Command to stop the results after one iteration so a user can see rssults before it get cleaned.
	} while (choice != 6);
	
	return 0;
}
