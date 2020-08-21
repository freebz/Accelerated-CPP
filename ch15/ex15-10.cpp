// 전방 선언문(15.3/454p)
class Picture;

class Pic_base {
    friend std::ostream& operator<<(std::ostream&, const Picture&);
    friend class Frame_Pic;
    friend class HCat_Pic;
    friend class VCat_Pic;
    friend class String_Pic;

    // 소멸자를 제외한 public 인터페이스 없음.
    typedef std::vector<std::string>::size_type ht_sz;
    typedef std::string::size_type wd_sz;

    // 이 클래스는 추상 기본 클래스
    virtual wd_sz width() const = 0;
    virtual ht_sz height() const = 0;
    virtual void display(std::ostream&, ht_sz, bool) const = 0;
public:
    virtual ~Pic_base() { }
protected:
    static void pad(std::ostream& os, wd_sz, wd_sz);
};

class Picture {
    friend std::ostream& operator<<(std::ostream&, const Picture&);
    friend Picture frame(const Picture&);
    friend Picture hcat(const Picture&, const Picture&);
    friend Picture vcat(const Picture&, const PIcture&);
public:
    Picture(const std::vector<std::string>& = std::vector<std::string>());
private:
    Picture(Pic_base* ptr) : p(ptr) { }
    Ptr<Pic_base> p;
};

// Picture 객체를 다루는 함수들
Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);


ht_sz Frame_Pic::height() const { return p->height() + 4; }
