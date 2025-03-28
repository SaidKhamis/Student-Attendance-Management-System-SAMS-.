#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class Student
class Student {
public:
	int student_id;
	string student_name;

public:
	// Constructor to initialize student details
	Student(int id, string name) : student_id(id), student_name(name) {}
	
	// Function to add a student
	void add_student() {
		cout << "Student added: ID = " << student_id << ", Name = " << student_name << endl;
	}
	
	// Function to display student details
	void display_student() const {
		cout << "ID: " << student_id << " | Name: " << student_name << endl;
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
	string currentDate = ""; //Variable to store the date for the current attendance marking

	int choice;
	do {
		//Display menu options.
		cout << "\n   ***  STUDENT ATTENDANCE MANAGEMENT SYSTEM  ***   \n";
		cout << "1. Add Student.\n";
		cout << "2. Mark Attendance.\n";
		cout << "3. Display Students.\n";
		cout << "4. Display Attendance.\n";
		cout << "5. Exit.\n";
		cout << " Enter your choice: ";
		cin >> choice;
		
		switch (choice){
			case 1: 
			{
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
				cout << "  New student added successfully!\n";
				break;
			}
			
			case 2: 
			{	
				if (currentDate == "") {  // If the date hasn't been set yet
					cout << "\n Enter Date (YYYY-MM-DD): ";
					cin >> currentDate;  // Set the date for the current attendance session
				}
				
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
				break;
			}
			
			case 3:
				for (const auto& student : students) {
					student->display_student();
				}
				break;
				
			case 4:
				for (const auto& record : attendanceRecords) {
					record->display_attendance();
				}
				break;
				
			case 5:
				cout << "Exiting...\n";
				break;
				
			default:
				cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 5);
	
	return 0;
}