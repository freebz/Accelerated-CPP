template <class T> class Vec {
public:
    Vec& operator=(const Vec&);
    // 이전과 같음.
};


template <class T> class Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
    // 자가 할당 여부 확인
    if (&rhs != this) {
	// 좌변이 지닌 배일이 점유하는 메모리를 해제
	uncreate();

	// 우변이 지닌 요소를 좌변으로 복사
	create(rhs.begin(), rhs.end());
    }
    return *this;
}
