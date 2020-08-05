// s.homework 벡터에서 0이 아닌 요소들의 중앙값을 구합니다.
// 0이 아닌 요소가 없다면 중합 과제 점수를 0점으로 처리
double optimistic_median(const Student_info& s)
{
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

    if (nonzero.empty())
	return grade(s.midterm, s.final, 0);
    else
	return grade(s.midterm, s.final, median(nonzero));
}
