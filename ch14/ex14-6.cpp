// 이 클래스는 올바르게 동작할까요?
class Str {
    friend std::istream& operator >> (std::istream&, Str&);
public:
    Str& operator+=(const Str& s) {
	data.make_unique();
	std::copy(s.data->begin(), s.data->end(), std::back_inserter(*data));
	return *this;
    }

    // 이전과 같은 인터페이스
    typedef Vec<<char>::size_type>) { }
    Str(const char* cp) : data(new Vec<char>) {
	std::copy(cp, cp + std::strlen(cp), std::back_inserter(*data));
    }

    Str(size_type n, char c) : data(new Vec<char>(n, c)) { }
    template<class In> Str(In i, In j) : data(new Vec<char>) {
	std::copy(i, j, std::back_inserter(*data));
    }

    // 필요에 따라 make_unique 함수 호출
    char& operator[](size_type i) {
	data.make_unique();
	return (*data)[i];
    }
    const char& operator[](size_type i) const { return (*data)[i]; }
    size_type size() const { return data->size(); }
private:
    // 벡터에 Ptr 객체 저장
    Ptr< Vec<char> > data;
};

// 12.3.1/344p 및 12.3.3/347p에서 구현한 것과 같음.
std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);
