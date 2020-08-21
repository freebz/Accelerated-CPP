// 구현에만 사용하는 private 클래스
class Pic_base { };

class String_Pic : public Pic_base { };
class Frame_Pic : public Pic_base { };
class VCat_Pic : public Pic_base { };
class HCat_Pic : public Pic_base { };

// public 인터페이스 및 함수
class Picture {
public:
    Picture(const std::vector<std::string>& = std::vector<std::string>());
private:
    Ptr<Pic_base> p;
};


Picture p; // 비어 있는 Picture 객체


vector<string> vs;
Picture p = vs;


hcat(frame(p), p)


p.frame().hcat(p)


Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);
