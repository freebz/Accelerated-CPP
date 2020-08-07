#include <iostream>

using std::cout; using std::endl;

int main()
{
    int x = 5;

    // p는 x를 가리킴.
    int* p = &x;
    cout << "x = " << x << endl;

    // p를 이용해 x 값을 변경
    *p = 6;
    cout << "x = " << x << endl;

    return 0;
}
