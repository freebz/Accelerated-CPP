int main() {
    string s;

    // 문자열을 한 행씩 입력받아 분할
    while (getline(cin, s)) {
	vector<string> v = split(s);

	// 벡터 v에 저장한 단어를 각각 출력
	for (vector<string>::size_type i = 0; i != v.size(); ++i)
	    cout << v[i] << endl;
    }
    return 0;
}


int main()
{
    string s;

    while (cin >> s)
	cout << s << endl;

    return 0;
}
