class VCat_Pic : public Pic_base {
    friend Picture vcat(const Picture&, const Picture&);
    Ptr<Pic_base> top, bottom;
    VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b) : top(t), bottom(b) { }

    wd_sz width() const { return std::max(top->width(), bottom->width()); }
    ht_sz height() const { return top->height() + bottom->height(); }
    void display(std::ostream&, ht_sz, bool) const;
};


void VCat_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
    wd_sz w = 0;
    if (row < top->height()) {
	// 위쪽 하위 문자 그림
	top->display(os, row, do_pad);
	w = top->width();
    }
    else if (row < height()) {
	// 아래쪽 하위 문자 그림
	bottom->display(os, row - top->height(), do_pad);
	w = bottom->width();
    }
    if (do_pad)
	pad(os, w, width());
}
