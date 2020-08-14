int main()
{
    vector< Handle<Core> > students; // 타입 변경됨.
    Handle<Core> record; // 타입 변경됨.
    char ch;
    string::size_type maxlen = 0;

    // 데이터를 읽고 저장
    while (cin >> ch) {
	if (ch == 'U')
	    record = new Core; // Core 객체 할당
	else
	    record = new Grad; // Grad 객체 할당

	record->read(cin); // Handle<T>::-> 연산자 함수 호출 후 가상 함수 호출
	maxlen = max(maxlen, record->name().size()); // Handle<T>::-> 연산자 함수 호출
	students.push_back(record);
    }

    // const Handle<Core>& 타입으로 동작하도록 compare 함수를 다시 작성해야 함.
    sort(students.begin(), students.end(), compare_Core_handles);

    // 이름과 점수 출력
    for (vector< Handle<Core> >::size_type i = 0; i != students.size(); ++i) {
	// 함수를 호출하려고 Handle 객체 students[i]를 역참조
	cout << students[i]->name() << string(maxlen + 1 - students[i]->name().size(), ' ');
	try {
	    double final_grade = students[i]->grade();
	    streamsize prec = cout.precision();
	    cout << setprecision(3) << final_grade << setprecision(prec) << endl;
	}
	catch (domain_error e) {
	    cout << e.what() << endl;
	};
	// delete문 삭제
    }
    return 0;
}
