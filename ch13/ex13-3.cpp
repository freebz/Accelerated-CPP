string Core::name() const { return n; }
double Core::grade() const
{
    return ::grade(midterm, final, homework);
}
istream& Core::read_common(istream& in)
{
    // 학생 이름과 시험 점수를 입력받아 저장
    in >> n >> midterm >> final;
    return in;
}
istream& Core::read(istream& in)
{
    read_common(in);
    read_hw(in, homework);
    return in;
}


istream& Grad::read(istream& in)
{
    read_common(in);
    in >> thesis;
    read_hw(in, homework);
    return in;
}


istream& Grad::read(istream& in)
{
    Core::read_common(in);
    in >> thesis;
    read_hw(in, Core::homework);
    return in;
}


double Grad::grade() const
{
    return min(Core::grade(), thesis);
}


return min(grade(), thesis);  // 무한루프
