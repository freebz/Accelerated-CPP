s1 + s2 + s3


Str operator+(const Str&, const Str&);


s = s + s1;
s += s1;


class Str {
    // 12.3.2/347p에서 구현한 입력 연산자
    friend std::istream& operator>>(std::istream&, Str&);
public:
    Str& operator+=(const Str& s) {
	std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
	return *this;
    }

    // 이전과 같음.
    typedef Vec<char>::size_type size_type;
    Str() { }
    Str(size_type n, char c) : data(n, c) { }
    Str(const char* cp) {
	std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
    }
    template<class In> Str(In b, In e) {
	std::copy(b, e, std::back_inserter(data));
    }

    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }
    size_type size() const { return data.size(); }
private:
    Vec<char> data;
};

// 12.3.1/344p에서 구현한 출력 연산자 및 12.3.3/347p에서 구현한 operator+ 함수
std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);


Str operator+(const Str& s, const Str& t) {
    Str r = s;
    r += t;
    return r;
}
