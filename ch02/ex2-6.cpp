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

	const std::string::size_type cols = greeting.size() + pad * 2 + 2;
	
	std::string::size_type c = 0;
	// 불변성: 현재 행에서 c개 문자를 출력
	while (c != cols) {
	    if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
		std::cout << "*";
	    } else {
		// 하나 이상의 테두리 외 문자를 출력
	    }
	    // 불변성을 참으로 유지하려고 c 값을 변경
	    c++;
	}
	
	// 하나의 행을 출력하면 불변성은 거짓
	std::cout << std::endl;

	// r을 증가시키면 불변성은 다시 참
	++r;
    }
    // 따라서 이 지점이서 불변성은 참
    
    return 0;
}
