#ifndef Ptr_h
#define Ptr_h

#include <cstddef>
#include <stdexcept>

template<class T> class Ptr {
public:
    void make_unique();

    // 나머지 부분은 클래스 이름을 제외하면 Ref_handle 클래스와 같음.
    Ptr() : p(0), refptr(new size_t(1)) { }
    Ptr(T* t) : p(t), refptr(new size_t(1)) { }
    Ptr(const Ptr& h) : p(h.p), refptr(h.refptr) { ++refptr; }

    Ptr& operator=(const Ptr&);
    ~Ptr();
    operator bool() const { return p; }
    T& operator*() const {
	if (p)
	    return *p;

	throw std::runtime_error("unbound Ptr");
    }
    T* operator->() const {
	if (p)
	    return p;

	throw std::runtime_error("unbound Ptr");
    }
private:
    T* p;
    std::size_t* refptr;
};


template<class T> T* clone(const T* tp)
{
    return tp->clone();
}

template<class T> void Ptr<T>::make_unique()
{
    if (*refptr != 1) {
	--*refptr;
	refptr = new std::size_t(1);
	p = p ? clone(p) : 0;
    }
}

template<class T> Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
{
    ++*rhs.refptr;

    // 상황에 따라 좌변을 할당 해제하고 포인터 소멸
    if (--*refptr == 0) {
	delete refptr;
	delete p;
    }

    // 우변 값들을 복사
    refptr = rhs.refptr;
    p = rhs.p;

    return *this;
}

template<class T> Ptr<T>::~Ptr()
{
    if (--*refptr == 0) {
	delete refptr;
	delete p;
    }
}


#endif
