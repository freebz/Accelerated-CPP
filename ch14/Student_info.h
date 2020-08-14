#ifndef Student_info_h
#define Student_info_h


#include "Core.h"

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


#endif
