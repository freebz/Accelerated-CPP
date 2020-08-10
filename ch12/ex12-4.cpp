cin >> s;


cin.operator>>(s);


s.operator>>(cin);


s >> cin;


std::istream& operator>>(std::istream&, Str&); // 추가됨.
std::ostream& operator<<(std::ostream&, const Str&) ; // 추가됨.


ostream& operator<<(ostream& os, const Str& s)
{
    for (Str::size_type i = 0; i != s.size(); ++i)
	os << s[i];

    return os;
}


class Str {
public:
    size_type size() const { return data.size(); }
    // 이전과 같음.
};
