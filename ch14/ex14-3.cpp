class Student_info {
public:
    Student_info() { }
    Student_info(std::istream& is) { read(is); }
    // 복사 생성자, 할당 연산자, 소멸자가 더 이상 필요하지 않음.

    std::istream& read(std::istream&);

    std::string name() const {
	if (cp)
	    return cp->name();
	else
	    throw std::runtime_error("uninitialized Student");
    }

    double grade() const {
	if (cp)
	    return cp->grade();
	else
	    throw std::runtime_error("uninitialized Student");
    }

    static bool compare(const Student_info& s1, const Student_info& s2) {
	return s1.name() < s2.name();
    }
private:
    Handle<Core> cp;
};


istream& Student_info::read(istream& is)
{
    char ch;
    is >> ch; // 학생 정보의 유형 파악

              // 일단은 타입의 새로운 객체를 할당
              // 생성자 Handle<T>(T*)를 사용하여
              // 새롭게 할당한 객체를 가리키는 포인터로 Handle<Core> 객체를 생성
              // Handle<T>::operator= 함수를 호출하여 cp에 Handle<Core> 객체를 할당
    if (ch == 'U')
	cp = new Core(is);
    else
	cp = new Grad(is);

    return is;
}
