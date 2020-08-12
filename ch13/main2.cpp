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


int main()
{
    vector<Grad> students; // 벡터의 타입 변경
    Grad record; // read 함수로 읽을 타입 변경
    string::size_type maxlen = 0;

    // 데이터를 읽고 저장
    while (record.read(cin)) { // Core 객체가 아닌 Grad 객체를 읽음
	maxlen = max(maxlen, record.name().size());
	students.push_back(record);
    }

    // 학생 기록을 알파벳 순으로 정렬
    sort(students.begin(), students.end(), compare);

    // 이름과 점수 출력
    for (vector<Grad>::size_type i = 0; i != students.size(); ++i) {
	cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
	try {
	    double final_grade = students[i].grade(); // Grad::grade
	    streamsize prec = cout.precision();
	    cout << setprecision(3) << final_grade << setprecision(prec) << endl;
	}
	catch (domain_error e) {
	    cout << e.what() << endl;
	}
    }
    return 0;
}
