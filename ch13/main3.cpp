#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Core.h"

using std::cin; using std::setprecision;
using std::cout; using std::sort;
using std::domain_error; using std::streamsize;
using std::endl; using std::string;
using std::max; using std::vector;


bool compare_Core_ptrs(const Core* cp1, const Core* cp2)
{
    return compare(*cp1, *cp2);
}


int main()
{
    vector<Core*> students; // 객체가 아닌 포인터를 저장
    Core* record; // 일시적 변수는 반드시 포인터 타입
    char ch;
    string::size_type maxlen = 0;

    // 데이터를 읽고 저장
    while (cin >> ch) {
	if (ch == 'U')
	    record = new Core; // Core 객체 할당
	else
	    record = new Grad; // Grad 객체 할당
	record->read(cin); // 가상 함수 호출
	maxlen = max(maxlen, record->name().size()); // 역참조
	students.push_back(record);
    }

    // 포인터로 동작하는 compare 함수를 전달
    sort(students.begin(), students.end(), compare_Core_ptrs);

    // 이름과 점수 출력
    for (vector<Core*>::size_type i = 0; i != students.size(); ++i) {
	// 함수를 호출하려고 포인터인 students[i]를 역참조
	cout << students[i]->name() << string(maxlen + 1 - students[i]->name().size(), ' ');
	try {
	    double final_grade = students[i]->grade();
	    streamsize prec = cout.precision();
	    cout << setprecision(3) << final_grade << setprecision(prec) << endl;
	}
	catch (domain_error e) {
	    cout << e.what() << endl;
	}
	delete students[i]; // 읽어 들인 객체의 할당을 해제
    }
    return 0;
}
