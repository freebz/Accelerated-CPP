// 학생의 과락 여부를 결정하는 서술 함수
bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}


// 첫 번째 버전: 기준 점수를 통과한 학생과 통과하지 못한 학생의 정보를 공유
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> pass, fail;

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
	if (fgrade(students[i]))
	    fail.push_back(students[i]);
	else
	    pass.push_back(students[i]);
    }
    students = pass;
    return fail;
}


// 두 번째 버전: 원하는 결과를 얻을 수 있지만 성능 저하가 우려됨.
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::size_type i = 0;

    // 불변성: students 벡터의 [0, i) 범위에 있는 요소들은 과목을 통과한 학생들의 정보
    while (i != students.size()) {
	if (fgrade(students[i])) {
	    fail.push_back(students[i]);
	    students.erase(students.begin() + i);
	}
	else
	    ++i;
    }
    return fail;
}


// 이 코드는 잘못된 최적화 때문에 제대로 동작하지 않음.
vector<Student_info>::size_type size = students.size();

while (i != size) {
    if (fgrade(students[i])) {
	fail.push_back(students[i]);
	students.erase(students.begin() + i);
    }
    else
	++i;
 }
