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
