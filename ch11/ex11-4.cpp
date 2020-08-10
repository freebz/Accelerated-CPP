template <class T> class Vec {
public:
    typedef T* iterator; // 추가됨.
    typedef const T* const_iterator; // 추가됨.
    typedef size_t size_type; // 추가됨.
    typedef T value_type; // 추가됨.
    typedef std::ptrdiff_t difference_type; 추가됨.
    typedef T& reference; // 추가됨.
    typedef const T& const_reference; // 추가됨.

    Vec() { create(); }
    explicit Vec(size_type n, const T& val = T()) { create(n, val); }
    // 나미지 인터페이스
private:
    iterator data; // 변경됨.
    iterator limit; // 변경됨.
};
