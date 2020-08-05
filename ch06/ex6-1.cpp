for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it)
    ret.push_back(*it);


ret.insert(ret.end(), bottom.begin(), bottom.end());


copy(bottom.begin(), bottom.end(), back_inserter(ret));


// 오류: ret는 반복자가 아님.
copy(bottom.begin(), bottom.end(), ret);


// 오류: ret.end()에는 어떠한 요소도 없음.
copy(bottom.begin(), bottom.end(), ret.end());
