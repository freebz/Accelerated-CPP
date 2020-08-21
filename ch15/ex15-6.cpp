class Pic_base {
    // 이전과 같음.
protected:
    static void pad(std::ostream& os, wd_sz beg, wd_sz end) {
	while (beg != end) {
	    os << " ";
	    ++beg;
	}
    }
};
