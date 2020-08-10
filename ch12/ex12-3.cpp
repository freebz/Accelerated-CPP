cin >> s // 문자열을 읽는 데 사용한 입력 연산자
cout << s // 문자열을 출력하는 데 사용한 출력 연산자
s[i] // 문자에 접근하는 데 사용한 인덱스 연산자
s1 + s2 // 문자열 2개를 결합하는 데 사용한 더하기 연산자


class Str {
public:
    // 생성자는 이전과 같음.
    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }
private:
    Vec<char> data;
};
