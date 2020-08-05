bood did_all_hw(const Student_info& s)
{
    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}


vector<Student_info> did, didnt;
Student_info student;

// 학생 정보를 읽고 과제를 모두 제출한 학생과 그렇지 않은 학생을 분류
while (read(cin, student)) {
    if (did_all_hw(student))
	did.push_back(student);
    else
	didnt.push_back(student);
}

// 두 집단에 데이터가 있는지 각각 확인
if (did.empty()) {
    cout << "No student did all the homework!" << endl;
    return 1;
}

if (didnt.empty()) {
    cout << "Every student did al the homework!" << endl;
    return 1;
}
