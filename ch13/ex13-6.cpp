bool compare_grades(const Core& c1, const Core& c2)
{
    return c1.grade() < c2.grade();
}


class Core {
public:
    virtual double grade() const; // virtual 추가
    // 중략
};
