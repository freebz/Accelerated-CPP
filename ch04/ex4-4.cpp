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
using std::domain_error; using std::istream;

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

// 중간시험 점수, 기말시흠 점수, 종합 과제 점수에서 학생의 중합 점수를 구함
double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// 중간시흠 점수, 기말시흠 점수, 과제 점수의 벡터로 학생의 종합 점수를 구함.
// 이 함수는 인수를 복사하지 않고 median 함수가 해당 작업을 실행.
double grade(double midterm, double final, const vector<double>& hw)
{
    if (hw.size() == 0)
	throw domain_error("student has done no homework");

    return grade(midterm, final, median(hw));
}

// 입력 스트림에서 과제 점수를 읽어서 vector<double>에 넣음.
istream& read_hw(istream& in, vector<double>& hw)
{
    if (in) {
	// 이전 내용을 제거.
	hw.clear();

	// 과제 점수를 읽음.
	double x;
	
	while (in >> x)
	    hw.push_back(x);

	// 다음 학생의 점수 입력 작업을 고려해 스트림을 지움.
	in.clear();
    }
    return in;
}

int main()
{
    // 학생의 이름을 묻고 입력받음
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // 중간시험과 기말시험의 점수를 묻고 읽음.
    cout << "Please enter you midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    // 과제 점수를 물음.
    cout << "Enter all your homework grades, "
	"followed by end-of-file: ";
    vector<double> homework;

    // 과제 점수를 읽음.
    read_hw(cin, homework);
    
    // 종합 점수를 계산해 생성.
    try {
	double final_grade = grade(midterm, final, homework);
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
	     << final_grade << setprecision(prec) << endl;
    }
    catch (domain_error) {
	cout << endl << "You must enter your grades. "
	    "Please try again." << endl;
	return 1;
    }
    return 0;
}
