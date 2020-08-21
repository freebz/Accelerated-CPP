class String_Pic : public Pic_base {
    friend class Picture;
    std::vector<std::string> data;
    String_Pic(const std::vector<std::string>& v) : data(v) { }

    ht_sz height() const { return data.size(); }
    wd_sz width() const;
    void display(std::ostream&, ht_sz, bool) const;
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
