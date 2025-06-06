	// Function to mark attendance
	void mark_attendance() {
		cout << "Students' Attendance on " << date << ": " << endl;
		cout << student_name << ":" << status << endl;
	}
	
	// Function to display attendance record
	void display_attendance() const {
		cout << "ID: " << student_id << " | Date: " << date << " | Status: " << status << endl;
	}
	
	string getDate() const { 
		return date; 
	}
};
