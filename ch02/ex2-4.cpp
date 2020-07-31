#include <iostream>
#include <string>

int main()
{
    // 이름을 물음
    std::cout << "Please enter your first name: ";

    // 이름을 입력
    std::string name;
    std::cin >> name;

    // 출력하는 메시지 구성
    const std::string greeting = "Hello, " + name + "!";

    // 인사말과 한 쪽 테두리 사이의 공백 개수
    const int pad = 1;

    // 출력할 행의 전체 개수
    const int rows = pad * 2 + 3;

    // 입력과 출력을 구분
    std::cout << std::endl;

    // rows만큼의 행을 출력

    // 불변성: 지금까지 r개 행을 출력    
    int r = 0;

    // r을 0으로 설정하려면 불변성은 참
    while (r != rows) {
	// 이 지점이서 불변성은 참
	// 하나의 행을 출력하면 불변성은 거짓
	std::cout << std::endl;

	// r을 증가시키면 불변성은 다시 참
	++r;
    }
    // 따라서 이 지점이서 불변성은 참
    
    return 0;
}
