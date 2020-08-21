class Pic_base {
    // 소멸자를 제외한 public 인터페이스 없음.
    typedef std::vector<std::string>::size_type ht_sz;
    typedef std::string::size_type wd_sz;

    // 이 클래스는 추상 기본 클래스
    virtual wd_sz width() const = 0;
    virtual ht_sz height() const = 0;
    virtual void display(std::ostream&, ht_sz, bool) const = 0;
public:
    virtual ~Pic_base() { }
};

class Frame_Pic : public Pic_base {
    // public 인터페이스 없음.
    Ptr<Pic_base> p;
    Frame_Pic(const Ptr<Pic_base>& pic) : p(pic) { }

    wd_sz width() const;
    ht_sz height() const;
    void display(std::ostream&, ht_sz, bool) const;
};


class VCat_Pic : public Pic_base {
    Ptr<Pic_base> top, bottom;
    VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b) : top(t), bottom(b) { }

    wd_sz width() const;
    ht_sz height() const;
    void display(std::ostream&, ht_sz, bool) const;
};

class HCat_Pic : public Pic_base {
    Ptr<Pic_base> left, right;
    HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r) : left(l), right(r) { }

    wd_sz width() const;
    ht_sz height() const;
    void display(std::ostream&, ht_sz, bool) const;
};


class String_Pic : public Pic_base {
    std::vector<std::string> data;
    String_Pic(const std::vector<std::string>& v) : data(v) { }

    wd_sz width() const;
    ht_sz height() const;
    void display(std::ostream&, ht_sz, bool) const;
};
