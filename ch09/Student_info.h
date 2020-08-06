#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h 헤더 파일
#include <iostream>
#include <string>
#include <vector>

class Student_info {
public:
    std::string name() const { return n; }
    bool valid() const { return !homework.empty(); }

    std::istream& read(std::istream&);
    
    double grade() const;
private:
    std::string n;
    double midterm, final;
    std::vector<double> homework;

    std::istream& read_hw(std::istream& in, std::vector<double>& hw);
};

bool compare(const Student_info&, const Student_info&);

#endif
