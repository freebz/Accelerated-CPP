class Student_info {
public:
    // 인터페이스
    double grade() const;
    std::istream& read(std::istream&);
private:
    // 구현
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};


class Student_info {
public:
    double grade() const;
    // 중략
};


struct Student_info {
    double grade() const; // 기본적으로 public
    // 중략
};


class Student_info {
    std::string name; // 기본적으로 private
    // 다른 private 멤버
public:
    double grade() const;
    // 다른 public 멤버
};


struct Student_info {
private:
    std::string name;
    // 다른 private 멤버
public:
    double grade() const;
    // 다른 public 멤버
};
