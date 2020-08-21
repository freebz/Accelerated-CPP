#include "Student_info.h"

using std::istream;


istream& Student_info::read(istream& is)
{
    char ch;
    is >> ch; // 학생 정보의 유형 파악

              // 일단은 타입의 새로운 객체를 할당
              // 생성자 Handle<T>(T*)를 사용하여
              // 새롭게 할당한 객체를 가리키는 포인터로 Handle<Core> 객체를 생성
              // Handle<T>::operator= 함수를 호출하여 cp에 Handle<Core> 객체를 할당
    if (ch == 'U')
	cp = new Core(is);
    else
	cp = new Grad(is);

    return is;
}
