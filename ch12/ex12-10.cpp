class Str {
public:
    // 그럴듯하지만 문제가 발생할 수 있는 변환 동작
    operator char*(); // 추가됨.
    operator const char*() const; // 추가됨. 이전과 같음.
private:
    Vec<char> data;
};


Str s;
// ...
ifstream in(s); // 희망 사항: s를 변환한 후 스트림 s를 사용할 수 있게 함.


Str s;
ifstream is(s); // 암묵적 변환: 배열의 할당을 해제하려면 어떻게 해야 합니까?
