class base {
public:
    // public 인터페이스
protected:
    // 파생 클래스에서 접근할 수 있는 구현 멤버
private:
    // base 클래스에서만 접근할 수 있는 구현 멤버
};

// base 클래스에 있는 public 인터페이스는 derived 클래스에 있는 인터페이스의 일부
class derived: public base { ... };


class priv_derived: private base { ... };


class derived2: public derived { ... };


class base {
public:
    virtual ~base(){ }
};
