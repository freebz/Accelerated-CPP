// 임의적 접근

template<class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
    while (begin < end) {
	// 범위의 중간 지점 찾기
	Ran mid = begin + (end - begin) / 2;

	// 중간 지점을 기준으로 어느 부분이 x를 포함하는지 확인하고
	// 해당 부분에만 탐색을 계속 진행
	if (x < *mid)
	    end = mid;
	else if (*mid < x)
	    begin = mid + 1;
	// 이 지점에 도달하면 *mid == x이므로 탐색 종료
	else return true;
    }
    return false;
}
