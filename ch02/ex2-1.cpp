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

    // 다시 작성할 부분
    return 0;
}
