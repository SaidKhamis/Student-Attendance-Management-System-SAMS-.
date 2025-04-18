case 5: {
  //delete student
  cout << " - STUDENT'S LIST - ";
  for (const auto& student : students) {
    student->display_student();
  }
  int id;
  cout << "Enter student ID to delete: ";
  cin >> id;

  for (auto it=students.begin(); it!=students.end(); it++) {
    if((*it)->student_id==id){
      students.erase(it);
      cout << "Student deleted successfully!\n";
    }
  }
  break; 
}
