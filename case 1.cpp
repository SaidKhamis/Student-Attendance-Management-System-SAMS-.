case 1: 
{
	int exit;
        do {
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
	    cout << "Press 0 to Continue / 1 to exit : ";
	    cin >> exit;	
	}
	while(exit==0);
	cout << "  New student added successfully!\n"; 
	break;
}		
