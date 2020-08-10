// 아직 컴파일하지 않은 코드
istream& operator>>(istream& is, Str& s)
{
    // 기존의 값 제거
    s.data.clear(); // 컴파일 오류! data는 private임. 선행 공백을 읽고 버림.
    char c;

    // 조건을 판별하는 것 외의 동작은 없음.
    while (is.get(c) && isspace(c));

    // 읽을 문자가 남아 있다면 다음 공백 문자에 도달할 때까지 문자를 읽음.
    if (is) {
	do s.data.push_back(c); // 컴파일 오류! data는 private임.
	while (is.get(c) && !isspace(c));

	// 공백을 읽었다면 다시 스트림에 남겨둠.
	if (is)
	    is.unget();

    }
    return is;
}


class Str {
    friend std::istream& operator>>(std::istream&, Str&);
    // 이전과 같음.
};
