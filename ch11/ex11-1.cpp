// 벡터를 만듭니다.
vector<Student_info> vs; // 빈 벡터
vector<double> v(100); // 100개의 요소가 있는 벡터

// 벡터가 사용하는 타입의 이름을 얻음.
vector<Student_info>::const_iterator b, e;
vector<Student_info>::size_type i = 0;

// size 함수와 인덱스 연산자를 사용하여 벡터의 각 요소를 탐색
for (i = 0; i != vs.size(); ++i)
    cout << vs[i].name();

// 첫 번째 요소와 마지만 요소의 다음을 가리키는 반복자를 반환
b = vs.begin();
e = vs.end();
