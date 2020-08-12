// 잘못된 구현!
bool compare_grades(Core c1, Core c2)
{
    return c1.grade() < c2.grade();
}


Core c;
Grad g;
Core* p;
Core& r = g;

c.grade(); // Core::grade()에 정적 바인딩
g.grade(); // Grad::grade()에 정적 바인딩
p->grade(); // p가 가리키는 객체 타입에 따라 동적 바인딩
r.grade(); // r이 참조하는 객체 타입에 따라 동적 바인딩
