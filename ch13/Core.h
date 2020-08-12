#ifndef Core_h
#define Core_h


#include <iostream>
#include <string>
#include <vector>


class Core {
    friend class Student_info;
public:
    Core() : midterm(0), final(0) { }
    Core(std::istream& is) { read(is); }
    virtual ~Core() { }

    std::string name() const;

    // 13.1.2/366p에서 정의
    virtual std::istream& read(std::istream&);
    virtual double grade() const;
protected:
    virtual Core* clone() const { return new Core(*this); }
    // 파생 클래스에서 접근할 수 있음.
    std::istream& read_common(std::istream&);
    double midterm, final;
    std::vector<double> homework;
    std::istream& read_hw(std::istream&, std::vector<double>&);
private:
    // Core 클래스에서만 접근할 수 있음.
    std::string n;
};

class Grad : public Core {
public:
    Grad() : thesis(0) { }
    Grad(std::istream& is) { read(is); }

    double grade() const;
    std::istream& read(std::istream&);
protected:
    Grad* clone() const { return new Grad(*this); }
private:
    double thesis;
};

bool compare(const Core&, const Core&);

#endif
