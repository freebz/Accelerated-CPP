Student_Info s; // 빈 Student_Info
Student_Info s2(cin); // cin을 잆어 s2를 초기화


class Student_Info {
public:
    Student_Info(); // 빈 Student_Info 객체를 생성
    Student_Info(std::istream&); // 스트림을 읽어 Student_Info 객체를 생성
    // 중략
};


Student_Info::Student_Info(): midterm(0), final(0) { }


Student_Info::Student_Info(istream& is) { read(is); }
