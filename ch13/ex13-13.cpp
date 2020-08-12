class Core {
    friend class Student_info;
protected:
    virtual Core* clone() const { return new Core(*this); }
    // 이전과 같음.
};


class Grad {
protected:
    Grad* clone() const { return new Grad(*this); }
    // 이적과 같음.
};


Student_info::Student_info(const Student_info& s) : cp(0)
{
    if (s.cp) cp = s.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& s)
{
    if (&s != this) {
	delete cp;
	if (s.cp)
	    cp = s.cp->clone();
	else
	    cp = 0;
    }
    return *this;
}
