int *p;


int (*fp)(int);


int next(int n)
{
    return n + 1;
}


// 두 실행문은 같은 의미
fp = &next;
fp = next;


// 두 실행문은 같은 의미
i = (*fp)(i);
i = fp(i);


double analysis(const vector<Student_info>&)


double (*analysis)(const vector<Student_info>&)


typedef double (*analysis_fp)(const vector<Student_info>&);


// get_analysis_ptr 함수는 분석 함수를 가리키는 포인터를 반환
analysis_fp get_analysis_ptr();


double (*get_analysis_ptr())(const vector<Student_info>&);


template<class In, class Pred>
In find_if(In begin, In end, Pred f)
{
    while (begin != end && !f(*begin))
	++begin;

    return begin;
}


bool is_negative(int n)
{
    return n < 0;
}


vector<int>::iterator i = find_if(v.begin(), v.end(), is_negative);
