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
				cout << "  Student added successfully!\n";
				break;
			}