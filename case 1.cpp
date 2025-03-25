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