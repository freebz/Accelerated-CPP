// 양방향 접근

template<class Bi>
void reverse(Bi begin, Bi end)
{
    while (begin != end) {
	--end;
	if (begin != end)
	    swap(*begin++, *end);
    }
}
