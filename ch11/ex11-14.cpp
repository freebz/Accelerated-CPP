template <class T> class Vec {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;

    Vec() { create(); }
    explicit Vec(size_type n, const T& t = T()) { create(n, t); }

    Vec(const Vec& v) { create(v.begin(), v.end()); }
    Vec& operator=(const Vec&); // 11.3.2/315p에서 정의
    ~Vec() { uncreate(); }

    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    void push_back(const T& t) {
	if (avail == limit)
	    grow();
	unchecked_append(t);
    }

    size_type size() const { return avail - data; } // 변경됨.

    iterator begin() { return data; }
    const_iterator begin() const { return data; }

    iterator end() { return avail; } // 변경됨.
    const_iterator end() const { return avail; } // 변경됨.
private:
    iterator data; // Vec가 갖는 첫 번째 요소
    iterator avail; // Vec가 갖는 마지만 요소의 다음
    iterator limit; // 할당된 메모리의 다음

    // 메모리 할당을 위한 기능
    allocator<T> alloc; // 메모리 할당을 다루는 객체

    // 기저 배열의 할당 및 초기화
    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    // 배열에 있는 요소들을 소멸시키고 메모리를 비움.
    void uncreate();

    // push_back 함수를 지원하는 함수
    void grow();
    void unchecked_append(const T&);
};


template <class T> void Vec<T>::create()
{
    data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val)
{
    data = alloc.allocate(n);
    limit = avail = data + n;
    uninitialized_fill(data, limit, val);
}

template <class T> void Vec<T>::create(const_iterator i, const_iterator j)
{
    data = alloc.allocate(j - i);
    limit = avail = uninitialized_copy(i, j, data);
}


template <class T> void Vec<T>::uncreate()
{
    if (data) {
	// 생성된 요소들을 역순으로 소멸
	iterator it = avail;
	while (it != data)
	    alloc.destroy(--it);

	// 할당된 모든 저장 공간을 반환
	alloc.deallocate(data, limit - data);
    }
    // 비어 있는 Vec을 가리키도록 포인터를 재설정
    data = limit = avail = 0;
}


template <class T> void Vec<T>::grow()
{
    // 저장 공간을 늘릴 때는 현재 사용하는 저장 공간의 2배를 할당
    size_type new_size = max(2 * (limit - data), ptrdiff_t(1));

    // 새로운 저장 공간을 할당하고 기존 요소들을 새로운 저장 공간에 복사
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = uninitialized_copy(data, avail, new_data);

    // 기존의 저장 공간을 반환
    uncreate();

    // 새롭게 할당한 저장 공간을 가리키려고 포인터 재설정
    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

// avail은 할당되었지만 아직 초기화되지 않은 저장 공간을 가리킨다고 가정
template <class T> void Vec<T>::unchecked_append(const T& val)
{
    alloc.construct(avail++, val);
}
