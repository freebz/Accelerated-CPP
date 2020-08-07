#include <iostream>

using std::cout; using std::endl;

int main(int argc, char** argv)
{
    // 명령 프롬프트에 입력한 인ㅜㅅ가 존재하면 출력
    if (argc > 1) {
	// 첫 번째 인수를 출력
	// 공백 하나와 함께 나머지 인수들을 각각 출력
	cout << argv[1];

	for (int i = 2; i != argc; ++i)
	    cout << " " << argv[i]; // argv[i]는 char* 타입
    }
    cout << endl;
    return 0;
}
