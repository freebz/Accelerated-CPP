bool compare(const Core& c1, const Core& c2)
{
    return c1.name() < c2.name();
}


Grad g(cin); // Grad 객체 생성
Grad g2(cin); // Grad 객체 생성

Core c(cin); // Core 객체 생성
Core c2(cin); // Core 객체 생성

compare(g, g2); // Grad 객체 2개 비교
compare(c, c2); // Core 객체 2개 비교
compage(g, c); // Grad 객체와 Core 객체 비교
