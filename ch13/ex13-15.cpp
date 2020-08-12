vector<Core> students;
Grad g(cin); // Grad 객체 생성
students.push_back(g); //students에 g의 Core 클래스에서 상속한 부분을 저장


void Core::regrade(double d) { final = d; }
void Grad::regrade(double d1, double d2) { final = d1; thesis = d2; }


r.regrade(100); // Core::regrade 함수 호출
r.regrade(100, 100); // Core::regrade 함수는 한 개의 인수를 가지므로 컴파일 오류


r.regrade(100); // Grad::regrade 함수는 인수 2개가 있으므로 컴파일 오류
r.regrade(100, 100); // Grad::regrade 함수 호출


r.Core::regrade(100); // Core::regrade 함수 호출


virtual void Core::regrade(double d, double = 0) { final = d; }
