while (i != students.size()) {
    // 여기까지 i 값은 변하지 않음.
    i++;
}


for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
    cout << students[i].name << endl;


for (vector<Student_info>::const_iterator iter = students.begin();
        iter != students.end(); ++iter) {
    cout << (*iter).name << endl;
}


container-type::const_iterator
container-type::iterator


vector<Student_info>::const_iterator iter = students.begin();


iter != students.end()


cout << (*iter).name


(*iter).name
iter->name


for (vector<Student_info>::const_iterator iter = students.begin();
        iter != students.end(); ++iter) {
    cout << iter->name << endl;
}


students.erase(students.begin() + i);
