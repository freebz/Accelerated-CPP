class Student_info {
public:
    operator double() const;
    // 중략
};


vector<Student_info> vs;
// vs를 채우는 과정은 생략

double d = 0;

for (int i = 0; i != vs.size(); ++i)
    d += vs[i]; // vs[i]가 double 타입으로 자동 변환

cout << "Average grade: " << d / vs.size() << endl;


if (cin >> x) { /* 생략 */ }


cin >> x;
if (cin) { /* 생략 */ }


int x;
cin << x; // cin >> x;라고 작성해야 함.
