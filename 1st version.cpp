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
	// Function to add a student
	void add_student() {
		char exit = 'n';
		do{
		    	cout << "Enter Student's ID: ";
		    	cin >> student_id;
		    	cout << "Enter Student's Name: ";
		   	cin >> student_name;

           		bool exist = false;
			string line;
			
           		//Opening file and check if the the entered student already exists in the list to avoid duplications. 
			ifstream Student_File_Check("Students.txt"){
				if(Student_File_Check.is_open()){
					//Checking the first line
					while(getline(Student_File_Check, line)) {
						//If find the content that resemble the entered Student ID then condition is false and while statement terminates and exist = false, otherwise the while loop statement got executed.
						if(line.find("Student_ID: " + student_id) != string::npos) {
							//Check the next line for Student Name after getting the ID not found in the list.
							getline(Student_File_Check, line);
							//Checking if the name is there in the file
							if(line.find("Name: " + student_name) != string::npos) {
								//if all if-statements are true, then exist  set to true means the entered Data are not yet pubished.
								return (exist = true);
								break;
							}
						}
					}
					Student_File_Check.close();
				}
			}
			
		    if(exist){
			    cout << "Error: The Entered Student's Details already exists.\n";
			    return;
		    } else{
				ofstream Student_File("Students.txt", ios::app); /*Create or Open the file. with append mode to add new content in the end of an existing file and hence to
	                        avoid data overwritten in the file*/
		                if(Student_File.is_open()) { 
			             Student_File << "\nStudent_ID: " << student_id << endl;
			             Student_File << " | Name: " << student_name << endl;
			             Student_File.close();
		                }  
		               else {
			             cout << "\nError: Unable to open the file, Please Try again later.";
		               }
			}
			
			do {
			     cout << "\nDo you wish to continue (y/n) : \n";
			     cin >> exit;
			     exit = tolower(exit); //Converting the enterd character Y/y or N/n to small letter.
			} while(exit!='y' && exit!='n');  //Allow only y and n, if not the program will iterate and need a user to enter again another character.
		}
		while(exit=='y');
		cout << "Thanks for your Coperation, You are welcome.\n";
		
		return;
	}
	
	// Function to display student details
	void display_student() const {
		ifstream Read_File("Students.txt");
                string line;

		//Reading from the file and display 
                if(Read_File.is_open()) {
			int number = 1;
			cout << "\n  --  STUDENTS' LIST  --  \n";
			while (getline(Read_File, line)) {
				cout << n << "." << line << endl;
				number++;
                        }
                        Read_File.close();
                } else {
			cout << "Unable to open the file, Please Try Again..\n";
                }
                return;
	}

// Derived class Attendance
class Attendance : public Student {
private:
	string date;
	string status;
        
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
				display_student();
				break;
			
			
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
