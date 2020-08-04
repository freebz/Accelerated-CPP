// 세 번째 버전: 인덱스 대산 반복자를 사용하지만 여전히 성능 저하가 우려됨.
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();
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


// 앞 코드는 잘못된 최적화 때문에 제대로 동작하지 않음.
vector<Student_info>::iterator iter = students.begin(), end_iter = students.end();

while (iter != end_iter) {
    // 중략
}
