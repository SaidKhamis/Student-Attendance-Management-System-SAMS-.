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
				cout << "\nEnter Student ID: ";
				cin >> id;
				cin.ignore();
				cout << "Enter Student Name: ";
				getline(cin, name);
				
				Student* newStudent = new Student(id, name);
				newStudent->add_student();
				students.push_back(newStudent);
				break;
			}
			
			case 2: 
			{	
				if (currentDate == "") {  // If the date hasn't been set yet
					cout << "Enter Date (YYYY-MM-DD): ";
					cin >> currentDate;  // Set the date for the current attendance session
				}
				
				int id;
				string status;
				cout << "Enter Student ID: ";
				cin >> id;
				cout << "Enter Status (Present/Absent): ";
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