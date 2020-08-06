#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::ostream_iterator;

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


template <class Out> // 변경됨.
void split(const string& str, Out os) { // 변경됨.
    typedef string::const_iterator iter;
    iter i = str.begin();

    while (i != str.end()) {
	// 선행 공백 무시
	i = find_if(i, str.end(), not_space);

	// 다음 단어의 끝은 찾음.
	iter j = find_if(i, str.end(), space);

	// [i, j] 범위의 문자를 복사
	if (i != str.end())
	    *os++ = string(i, j); // 변경됨.

	i = j;
    }
}


int main()
{
    string s;
    while (getline(cin, s))
	split(s, ostream_iterator<string>(cout, "\n"));

    return 0;
}
