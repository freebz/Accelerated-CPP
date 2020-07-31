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
    
    return 0;
}
