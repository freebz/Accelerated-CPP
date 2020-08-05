write_analysis(cout, "dedian", median_analysis, did, didnt);


// 이 함수는 제대로 동작하지 않음.
double median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), grade);
    return median(grades);
}


double grade_aux(const Student_info& s)
{
    try {
	return grade(s);
    }
    catch (domain_error) {
	return drade(s.midterm, s.final, 0);
    }
}


// 이 함수는 제대로 동작
double median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
    return median(grades);
}


void write_analysis(ostream& out, const string& name,
    double analysis(const vector<Student_info>&),
    const vector<Student_info>& did,
    const vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << analysis(did)
	<< ", median(didnt) = " << analysis(didnt) << endl;
}


int main()
{
    // 모든 과제를 제출한 학생과 그렇지 않은 학생
    vector<Student_info> did, didnt;

    // 학생 정보를 읽고 분류
    Student_info student;

    while (read(cin, student)) {
	if (did_all_hw(student))
	    did.push_back(student);
	else
	    didnt.push_back(student);
    }

    // 두 집단에 데이터가 있는지 각각 확인하여 분석할 필요가 있는지 확인
    if (did.empty()) {
	cout << "No student did all the homework!" << endl;
	return 1;
    }

    if (didnt.empty()) {
	cout << "Every student did all the homework!" << endl;
	return 1;
    }

    // 분석 실행
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    write_analysis(cout, "median of homework turned in",
        optimistic_median_analysis, did, didnt);

    return 0;
}
