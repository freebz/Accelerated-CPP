#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin; using std::setprecision;
using std::cout; using std::string;
using std::endl; using std::streamsize;

int main()
{
    // 학생의 이름을 묻고 입력받음
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // 중간시험과 기말시험의 점수를 묻고 입력받음
    cout << "Please enter you midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    // 과제 점수를 물음
    cout << "Enter all your homework grades, "
	"followed by end-of-file: ";

    // 지금까지 입력된 과제 점수의 개수와 합
    int count = 0;
    double sum = 0;

    // 입력을 위한 변수
    double x;

    // 불변성: 지금까지 count개 점수를 입력받았으며 입력받은 점수의 합은 sum
    while (cin >> x) {
	++count;
	sum += x;
    }

    // 결과를 출력
    
    // 정밀도를 3으로 바꾸고, 바꾸기 전의 정밀도를 반환
    streamsize prec = cout.precision(3);
    cout << "Your final grade is "
	 << 0.2 * midterm + 0.4 * final + 0.4 * sum / count << endl;

    // 정밀도를 원래 값으로 바꿈
    cout.precision(prec);
    
    return 0;
}
