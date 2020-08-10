template<class T>
class Thing {
    friend std::istream& operator >> (std::istream&, Thing&);
    // 중략
};
