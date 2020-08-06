#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Student_info.h"

using std::cin; using std::setprecision;
using std::cout; using std::sort;
using std::domain_error; using std::streamsize;
using std::endl; using std::string;
using std::max; using std::vector;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // 데이터를 읽어 저장
    while (record.read(cin)) { // 변경됨.
	maxlen = max(maxlen, record.name().size()); // 변경됨.
	students.push_back(record);
    }

    // 학생 정보를 알파벳 순으로 정렬
    sort(students.begin(), students.end(), compare);

    // 이름과 점수를 출력
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
	cout << students[i].name()
	     << string(maxlen + 1 - students[i].name().size(), ' '); // 변경됨.
	try {
	    double final_grade = students[i].grade(); // 변경됨.
	    streamsize prec = cout.precision();
	    cout << setprecision(3) << final_grade << setprecision(prec) << endl;
	}
	catch (domain_error e) {
	    cout << e.what() << endl;
	}
    }
    return 0;
}
