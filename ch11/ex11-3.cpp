Vec<Student_info> vs; // 기본 생성자를 사용
Vec<double> vs(100); // 벡터 크리를 전달받은 생성자를 사용


template <class T> class Vec {
public:
    Vec() { create(); }
    explicit Vec(std::size_t n, const T& val = T()) { create(n, val); }
    // 나머지 인터페이스
private:
    T* data;
    T* limit;
};


Vec<int> vi(100); // 정상: 명시적으로 Vec를 생성
Vec<int> vi = 100; // 오류: 암묵적으로 Vec를 생성(11.3.3/318p)하고 vi에 복사
