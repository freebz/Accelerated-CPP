class student_info {
public:
    double grade() const;
    std::istream& read(std::istream&); // 정의문 변경 필요
    std::string name() const { return n; } // 추가됨.
private:
    std::string n; // 변경됨.
    double midterm, final;
    std::vector<double> homework;
};


bool compare(const Student_Info& x, const Student_Info& y)
{
    return x.name() < y.name();
}
