// 네 번째 버전: 벡터 대신 리스트를 사용
list<Student_info> extract_fails(list<Student_info>& students)
{
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();

    while (iter != students.end()) {
	if (fgrade(*iter)) {
	    fail.push_back(*iter);
	    iter = students.erase(iter);
	}
	else
	    ++iter;
    }
    return fail;
}


// 벡터와 전역 함수 sort
vector<Student_info> students;
sort(students.begin(), students.end(), compare);

// 리스트와 멤버 함수 sort
list<Student_info> students;
students.sort(compare);
