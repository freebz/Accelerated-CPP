class Picture {
public:
    Picture(const std::vector<std::string>& = std::vector<std::string>());
private:
    Ptr<Pic_base> p;
};

Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
PIcture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);


Picture frame(const Picture& pic) {
    Pic_base* ret = new Frame_Pic(pic.p);
    // 반환되는 것은 무엇인가요?
}


class Picture {
    Ptr<Pic_base> p;
    Picture(Pic_base* ptr): p(ptr) { }
    // 이전과 같음.
};


Picture frame(const Picture& pic)
{
    return new Frame_Pic(pic.p);
}


// 새로운 Frame_Pic 객체 생성
Pic_base* temp1 = new Frame_Pic(pic.p);

// Pic_base* 객체로 Picture 객체 생성
Picture temp2(temp1);

// Picture 클래스의 복사 생성자를 호출할 Picture 객체 반환
return temp2;


Picture hcat(const Picture& l, const Picture& r)
{
    return new HCat_Pic(l.p, r.p);
}

Picture vcat(const Picture& t, const Picture& b)
{
    return new VCat_Pic(t.p, b.p);
}


Picture::Picture(const vector<string>& v): p(new String_Pic(v)) { }


ostream& operator<<(ostream& os, const Picture& picture)
{
    const Pic_base::ht_sz ht = picture.p->height();
    for (Pic_base::ht_sz i = 0; i != ht; ++i) {
	picture.p->display(os, i, false);
	os << endl;
    }
    return os;
};
