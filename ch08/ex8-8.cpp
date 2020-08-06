vector<int> v;

// 표준 입력에서 int를 읽어 v에 추가
copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));


getline(ci, s) // 데이터를 문자열 타입으로 읽음.
cin >> s.name >> s.midterm >> s.final; // 1개의 문자열 타입과 2개의 double 타입을 읽음.


// v 벡터의 각 요소를 공백으로 구분하여 출력
copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));


// 요소 사이의 구분 없음!
copy(v.begin(), v.end(), ostream_iterator<int>(cout));
