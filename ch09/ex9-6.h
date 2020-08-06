class Student_Info {
public:
    std::string name() const { return n; }
    bool valid() const { return !homework.empty(); }

    // 9.2.1/254p에서 정의한 read함수에서 name을 n으로 변경 필요
    std::istream& read(std::istream&);

    // 9.2.1/254p에서 정의한 것과 같음.
    double grade() const;
private:
    std::string n;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
