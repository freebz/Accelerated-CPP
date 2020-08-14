template <class T> class Ref_handle {
public:
    // 참조 카운트를 포인터처럼 관리
    Ref_handle() : p(0), refptr(new std::size_t(1)) { }
    Ref_handle(T* t) : p(t), refptr(new std::size_t(1)) { }
    Ref handle(const Ref_handle& h) : p(h.p), refptr(h.refptr) {
	++*refptr;
    }

    Ref_handle& operator=(const Ref_handle&);
    ~Ref_handle();

    // 이전과 같음.
    operator bool() const { return p; }
    T& operator*() const {
	if (p)
	    return *p;

	throw std::runtime_error("unbound Ref_handle");
    }
    T* operator->() const {
	if (p)
	    return p;

	throw std::runtime_error("unbound Ref_handle");
    }
private:
    T* p;
    std::size_t* refptr; // 추가됨.
};


template<class T> Ref_handle<T>& Ref_handle<T>::operator=(const Ref_handle& rhs)
{
    ++*rhs.refptr;

    // 상황에 따라 좌변을 할당 해제하고 포인터 소멸
    if (--*refptr == 0) {
	delete refptr;
	delete p;
    }

    // 우변 값들을 복사
    refptr = rhs.prefptr;
    p = rhs.p;

    return *this;
}


template<class T> Ref_handle<T>::~Ref_handle()
{
    if (--*refptr == 0) {
	delete refptr;
	delete p;
    }
}


Student_info s1(cin); // 표준 입력 내용으로 s1을 초기화
Student_info s2 = s1; // 해당 값을 s2로 '복사'
