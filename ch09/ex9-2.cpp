struct Student_info {
    std::string name;
    double medterm, final;
    std::vector<double> homework;

    std::istream read(std::istream&); // 추가됨.
    double grade() const; // 추가됨.
};


istream Student_info::read(istream& in)
{
    in >> name >> midterm >> final;
    read_hw(in, homework);
    return in;
}


double Student_info::grade() const
{
    return ::grade(midterm, final, homework);
}


double Student_info::grade() const { ... } // 멤버 함수 버전
double grade(const Student_info&) { ... } // 4.2.2/113p에서 살펴본 기존 버전
