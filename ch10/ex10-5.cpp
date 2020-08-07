const char hello[] = { 'H', 'e', 'l', 'l', 'o', '\0' };


// 표준 라이브러리 함수 구현 예
size_t strlen(const char* p)
{
    size_t size = 0;
    while (*p++ != '\0')
	++size;

    return size;
}


string s(hello);


string s("Hello");


string s(hello, hello + strlen(hello));
