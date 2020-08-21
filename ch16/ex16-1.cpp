Picture histogram(const vector<Student_info>& students) {
    Picture names;
    Picture grades;

    // 각 학생을 대상으로 동작을 실행
    for (vector<Student_info>::const_iterator it = students.begin();
	it != students.end(); ++it) {
	// 이름들을 수직 결합한 문자 그림과 점수들을 수직 결합한 문자 그림을 각각 생성
	names = vcat(names, vector<string>(1, it->name()));
	grades = vcat(grades, vector<string>(1, " " + string(it->grade() / 5, '=')));
    }

    // 생성한 두 문자 그림을 수평 결합
    return hcat(names, grades);
}


int main()
{
    vector<Student_info> students;
    Student_info s;

    // 이름과 점수를 읽음.
    while (s.read(cin))
	students.push_back(s);

    // 학생들을 알파벳순으로 정렬
    sort(students.begin(), students.end(), Student_info::compare);

    // 이름과 히스토그램을 출력
    cout << frame(histogram(students)) << endl;
    return 0;
}
