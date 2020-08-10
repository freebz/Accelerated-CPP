for (i = 0; i != vs.size(); ++i)
    cout << vs[i].name();


template <class T> class Vec {
public:
    // 11.2.3/308p에서 다룬 typedef 정의문

    Vec() { create(); }
    explicit Vec(size_type n, const T& val = T()) { create(n, val); }

    // 벡터 크기와 인덱스에 관한 새로운 함수들
    size_type size() const { return limit - data; }
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }
private:
    iterator data;
    iterator limit;
};
