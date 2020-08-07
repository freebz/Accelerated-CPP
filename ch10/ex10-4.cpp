double coords[3];


const size_t NDim = 3;
double coords[NDim];


*coords = 1.5;


vector<double> v;
copy(coords, coords + NDim, back_inserter(v));


vector<double> v(coords, coords + NDim);


// 윤년은 고려하지 않음.
const int month_lengths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
