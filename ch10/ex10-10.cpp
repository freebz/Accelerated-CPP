// 의도적으로 유효하지 않은 포인터를 반환하는 함수
// 이러한 방식으로 코드를 작성하지 마세요!
int* invalid_pointer()
{
    int x;
    return &x; // 재앙 그 자체!
}


// 정삭적으로 동작하는 함수
int* pointer_to_static()
{
    static int x;
    return &x;
}


int* p = new int(42);


++p; // 이제 *p는 43


delete p;


int* pointer_to_dynamic()
{
    return new int(0);
}


T* p = new T[n];
vector<T> v(p, p + n);
delete[] p;


char* duplicate_chars(const char* p) {
    // 공간을 할당할 때 null 문자를 고려한 하나의 공간을 추가해야 함.
    size_t length = strlen(p) + 1;

    char* result = new char[length];

    // 새로 할당한 공간에 복사한 후 첫 번째 요소를 가리키는 포인터를 반환
    copy(p, p + length, result);
    return result;
}
