class Frame_Pic : public Pic_base {
    friend Picture frame(const Picture&);
    Ptr<Pic_base> p;
    Frame_Pic(const Ptr<Pic_base>& pic) : p(pic) { }

    wd_sz width() const { return p->width() + 4; }
    ht_sz height() const { return p->height() + 4; }
    void display(std::ostream&, ht_sz, bool) const;
};


void Frame_Pic::display(ostream& os, ht_sz row, do_pad) const
{
    if (row >= height()) {
	// 범위를 벗어남.
	if (do_pad)
	    pad(os, 0, width());
    }
    else {
	if (row == 0 || row == height() - 1) {
	    // 최상단 행 또는 최하단 행
	    os << string(width(), '*');
	}
	else if (row == 1 || row == height() - 2) {
	    // 최상단에서 두 번째 행 또는 최하단에서 두 번째 행
	    os << "*";
	    pad(os, 1, width() - 1);
	    os << "*";
	}
	else {
	    // 내부의 문자 그림에 해당하는 행
	    os << "* ";
	    p->display(os, row - 2, true);
	    os << " *";
	}
    }
}
