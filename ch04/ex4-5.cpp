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
using std::max;

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

struct Student_info {
    string name;
    double midterm, final;
    vector<double> homework;
}; // 세미콜론을 잊지 않도록 주의

istream& read(istream& is, Student_info& s)
{
    // 학생의 이름, 중간시험 점수, 기말시험 점수를 읽어 저장
    is >> s.name >> s.midterm >> s.final;
    read_hw(is, s.homework); // 학생의 모든 과제를 읽어 저장
    return is;
}

double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    // 학생의 이름과 모든 점수를 읽어 저장하고 가장 긴 이름을 찾음.
    while (read(cin, record)) {
	maxlen = max(maxlen, record.name.size());
	students.push_back(record);
    }

    // 학생 정보를 알파벳순으로 정렬.
    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
	// 이름과 오른쪽 공백을 포함하여 maxlen + 1개의 문자를 출력.
	cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

	// 최종 점수를 계산하여 출력.
	try {
	    double final_grade = grade(students[i]);
	    streamsize prec = cout.precision();
	    cout << setprecision(3) << final_grade
		 << setprecision(prec);
	}
	catch (domain_error e) {
	    cout << e.what();
	}
	cout << endl;
    }
    return 0;
}
