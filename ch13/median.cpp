// median 함수의 소스 파일
#include <algorithm> // sort 함수의 선언을 가져옴.
#include <stdexcept> // domain_error 예외의 선언을 가져옴.
#include <vector> // vector 타입의 선언을 가져옴.

using std::domain_error;
using std::sort;
using std::vector;

// vector<double> 타입 객체의 중앙값을 구함.
// 이 함수를 호출하면 인수로 전달된 벡터 전체를 복사
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
