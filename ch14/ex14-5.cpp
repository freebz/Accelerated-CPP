template<class T> class Ptr {
public:
    // 필요하면 조건에 따라 객체를 복사하는 새로운 멤버 함수
    void make_unique() {
	if (*refptr != 1) {
	    --*refptr;
	    refptr = new size_t(1);
	    p = p ? p->clone() : 0;
	}
    }

    // 나머지 부분은 클래스 이름을 제외하면 Ref_handle 클래스와 같음.
    Ptr() : p(0), refptr(new size_t(1)) { }
    Ptr(T* t) : p(t), refptr(new size_t(1)) { }
    Ptr(const ptr& h) : p(h.p), refptr(h.refptr) { ++refptr; }

    Ptr& operator=(const Ptr&); // 14.2/413p과 비슷하게 구현
    ~Ptr(); // 14.2/413p와 비슷하게 구현
    operator bool() const { return p; }
    T& operator*() const; // 14.2/413p과 비슷하게 구현
    T* operator->() const; // 14.2/413p과 비슷하게 구현
private:
    T* p;
    std::size_t* refptr;
};


Student_info s1;
read(cin, s1); // s1에 값을 할당
Student_info s2 = s1; // s1의 값을 s2로 복사
read(cin, s2); // s2에 값을 할당, s2 값만 재설정되며 s1 값은 그대로임.


void Student_info::regrade(double final, double thesis)
{
    // 객체를 바꾸기 전 복사본을 생성
    cp.make_unique();

    if (cp)
	cp->regrade(final, thesis);

    else
	throw run_time_error("regrade of unknown student");
}
