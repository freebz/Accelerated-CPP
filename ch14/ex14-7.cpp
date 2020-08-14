template<class T> void Ptr<T>::make_unique()
{
    if (*refptr != 1) {
	--*refptr;
	refptr = new size_t(1);
	p = p ? p->clone() : 0; // 여기가 문제
    }
}


template<class T> T* clone(const T* tp)
{
    return tp->clone();
}


template<class T> void Ptr<T>::make_unique()
{
    if (*refptr != 1) {
	--*refptr;
	refptr = new size_t(1);
	p = p ? clone(p) : 0; // 멤버가 아닌 전역 버전의 clone 함수를 호출
    }
}


// Ptr< Vec<char> > 객체 동작에 필수적
template<> Vec<char>* clone(const Vec<char>* vp)
{
    return new Vec<char>(*vp);
}
