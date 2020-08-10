template <class T> class Vec {
public:
    size_type size() const { return avail - data; } // 변경됨.
    iterator end() { return avail; } // 변경됨.
    const_iterator end() const { return avail; } // 변경됨.
    void push_back(const T& val) {
	if (avail == limit) // 필요하다면 저장 공간 확보
	    grow();

	unchecked_append(val); // 새로운 요소 추가
    }
private:
    iterator data; // Vec의 첫 번째 요소를 가리키는 포인터(이전과 같음)
    iterator avail; // 마지막으로 만든 요소의 다음을 가리키는 포인터
    iterator limit; // 사용할 수 있는 마지막 요소의 다음을 가리키는 포인터
    // 클래스 인터페이스 및 구현의 나머지 부분(이전과 같음)
};
