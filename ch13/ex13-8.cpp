class Core {
public:
    Core() : midterm(0), final(0) { }
    Core(std::istream& is) { read(is); }

    std::string name() const;

    // 13.1.2/366p에서 정의
    virtual std::istream& read(std::istream&);
    virtual double grade() const;
protected:
    // 파생 클래스에서 접근할 수 있음.
    std::istream& read_common(std::istream&);
    double midterm, final;
private:
    // Core 클래스에서만 접근할 수 있음.
    std::string n;
};

class Grad : public Core {
public:
    Grad() : thesis(0) { }
    Grad(std::istream& is) { read(is); }

    // 13.1.2/366p에서 정의
    // 참고: grade 함수와 read 함수는 상속받은 가상 함수
    double grade() const;
    std::istream read(std::istream&);
private:
    double thesis;
};

bool compare(const Core&, const Core&);
