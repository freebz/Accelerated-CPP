string url_ch = "~;/?:@=&$-_.+|*'()," // 초기화
string spaces(url_ch.size(), ' '); // 초기화
string y; // 초기화
y = url_ch; // 할당


vector<string> split(const string&); // 함수 선언문
vector<string> v; // 초기화

// 함수에 진입할 때 split 함수의 매개변수를 line으로 초기화
// 함수에서 빠져나올 때 반환 값을 초기화하고 v에 할당
v = split(line);
