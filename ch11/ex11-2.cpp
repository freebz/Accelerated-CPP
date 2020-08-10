template <class T> class Vec {
public:
    // 인터페이스
private:
    // 구현
};


template <class T> class Vec {
public:
    // 인터페이스
private:
    T* data; // Vec의 첫 번째 요소를 가리키는 포인터
    T* limit; // Vec의 마지만 요소 다음을 가리키는 포인터
};


Vec<int> v;
