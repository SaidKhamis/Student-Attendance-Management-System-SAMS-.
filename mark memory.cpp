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