#include <stdexcept>
#include "Core.h"
#include "grade.h"
#include "median.h"

using std::istream;
using std::vector;
using std::domain_error;
using std::string;
using std::min;


string Core::name() const { return n; }
double Core::grade() const
{
    return ::grade(midterm, final, homework);
}

istream& Core::read_common(istream& in)
{
    // 학생의 이름과 시험 점수를 입력받아 자장
    in >> n >> midterm >> final;
    return in;
}

istream& Core::read(istream& in)
{
    read_common(in);
    read_hw(in, homework);
    return in;
}

istream& Grad::read(istream& in)
{
    read_common(in);
    in >> thesis;
    read_hw(in, homework);
    return in;
}

double Grad::grade() const
{
    return min(Core::grade(), thesis);
}

istream& Core::read_hw(istream& in, vector<double>& hw)
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

bool compare(const Core& c1, const Core& c2)
{
    return c1.name() < c2.name();
}
