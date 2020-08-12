class Core {
public:
    // Core 클래스의 기본 생성자
    Core() : midterm(0), final(0) { }

    // istream으로 Core 객체 생성
    Core(std::istream& is) { read(is); }

    // 중략
};

class Grad : public Core {
public:
    // 두 생성자 모두 암묵적으로 Core::Core()를 사용하여
    // 객체가 기본 클래스에서 상속한 부분을 초기화
    Grad() : thesis(0) { }

    Grad(std::istream& is) { read(is); }
    // 중략
};


Grad g;


Grad g(cin);
