#include "Picture.h"

using std::ostream;
using std::endl;
using std::string;
using std::max;
using std::vector;


Picture frame(const Picture& pic)
{
    return new Frame_Pic(pic.p);
}

Picture hcat(const Picture& l, const Picture& r)
{
    return new HCat_Pic(l.p, r.p);
}

Picture vcat(const Picture& t, const Picture& b)
{
    return new VCat_Pic(t.p, b.p);
}

Picture::Picture(const vector<string>& v): p(new String_Pic(v)) { }

ostream& operator<<(ostream& os, const Picture& picture)
{
    const Pic_base::ht_sz ht = picture.p->height();
    for (Pic_base::ht_sz i = 0; i != ht; ++i) {
	picture.p->display(os, i, false);
	os << endl;
    }
    return os;
};

Pic_base::wd_sz String_Pic::width() const {
    Pic_base::wd_sz n = 0;
    for (Pic_base::ht_sz i = 0; i != data.size(); ++i)
	n = max(n, data[i].size());
    return n;
}

void String_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
    wd_sz start = 0;

    // 아직 범위 안에 있다면 행을 출력
    if (row < height()) {
	os << data[row];
	start = data[row].size();
    }

    // 필요하다면 공백 추가
    if (do_pad)
	pad(os, start, width());
}

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

void HCat_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
    left->display(os, row, do_pad || row <right->height());
    right->display(os, row, do_pad);
}

void Frame_Pic::display(ostream& os, ht_sz row, bool do_pad) const
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
