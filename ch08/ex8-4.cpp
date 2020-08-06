// 순차적 읽기 및 쓰기 접근

template<class For, class X>
void replace(For beg, For end, const X& x, const X& y)
{
    while (beg != end) {
	if (*beg == x)
	    *beg = y;

	++beg;
    }
}
