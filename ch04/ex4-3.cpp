#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::cin; using std::sort;
using std::cout; using std::streamsize;
using std::endl; using std::string;
using std::setprecision; using std::vector;
using std::domain_error;

// 중간시험 점수, 기말시흠 점수, 종합 과제 점수에서 학생의 중합 점수를 구함
double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// vector<double>의 중앙값을 구함.
// 함수를 호출하면 인수로 제공된 벡터를 통째로 복사
double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();

    if (size == 0)
	throw domain_error("median of an empty vector");

    sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;
    return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

// 중간시흠 점수, 기말시흠 점수, 과제 점수의 벡터로 학생의 종합 점수를 구함.
// 이 함수는 인수를 복사하지 않고 median 함수가 해당 작업을 실행.
double grade(double midterm, double final, const vector<double>& hw)
{
    if (hw.size() == 0)
	throw domain_error("student has done no homework");

    return grade(midterm, final, median(hw));
}

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
    vector<double> homework;
    double x;


    // 불변성: homework는 지금까지 입력받은 과제 점수가 있음
    while (cin >> x)
	homework.push_back(x);
    
    // 최종 점수를 구해서 출력
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
	 << grade(midterm, final, homework)
	 << setprecision(prec) << endl;
    return 0;
}
