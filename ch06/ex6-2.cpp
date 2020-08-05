// 인수가 공백일 때는 true, 그렇지 않을 때는 false를 반환
bool space(char c)
{
    return isspace(c);
}

// 인수가 공백일 때는 false, 그렇지 않을 때는 true를 반환
bool not_space(char c)
{
    return !isspace(c);
}

vector<string> split(const string& str)
{
    typedef string::const_iterator iter;
    vector<string> ret;
    iter i = str.begin();

    while (i != str.end()) {
	// 선행 공백을 무시
	i = find_if(i, str.end(), not_space);

	// 다음 단어의 끝을 찾음.
	iter j = find_if(i, str.end(), space);

	// [i, j] 범위의 문자열 복사
	if (i != str.end())
	    ret.push_back(string(i, j));

	i = j;
    }
    return ret;
}
