istream& Student_info::read(istream& is) {
    delete cp; // 이전 객체가 있으면 삭제

    char ch;
    is >> ch; // 학생 정보의 유형 파악

    if (ch == 'U') {
	cp = new Core(is);
    }
    else {
	cp = new Grad(is);
    }

    return is;
}
