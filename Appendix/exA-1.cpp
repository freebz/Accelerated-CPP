int* p, q;


double (*get_analysis_ptr())(const vector<Student_info>&);


int* p;
int q;


// vector<Student_info>& 타입의 인수가 있고 double 타입을 반환하는
// 함수의 타입 이름으로 analysis_fp를 정의
typedef double (*analysis_fp)(const vector<Student_info>&);
analysis_fp get_analysis_ptr();


const char * const * const * cp;


double (*get_analysis_ptr())(const vector<Student_info>&);
