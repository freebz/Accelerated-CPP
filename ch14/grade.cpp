#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"

using std::domain_error;
using std::vector;

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
