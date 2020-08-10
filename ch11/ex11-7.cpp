vector<int> vi;
double d;
d = median(vi); // vi를 median 함수의 매개변수로 복사

string line;
vector<string> words = split(line); // split 함수에서 반환하는 객체를 words로 복사


vector<Student_info> vs;
vector<Student_info> v2 = vs; // vs를 v2로 복사


template <class T> class Vec {
public:
    Vec (const Vec& v); // 복사 생성자
    // 이전과 같음.
};


template <class T> class Vec {
public:
    Vec(const Vec& v) { create(v.begin(), v.end()); }
    // 이전과 같음.
};
