template <class T> class Vec {
public:
    // 11.2.3/308p에서 다룬 typedef 정의문

    Vec() { create(); }
    explicit Vec(size_type n, const T& val = T()) { create(n, val); }
    
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size type i) const { return data[i]; }
    size_type size() const { return limit - data; }

    // 반복자를 반환하는 새로운 함수
    iterator begin() { return data; } // 추가됨.
    const_iterator begin() const { return data; } // 추가됨.

    iterator end() { return limit; } // 추가됨.
    const_iterator end() const { return limit; } // 추가됨.
private:
    iterator data;
    iterator limit;
};
