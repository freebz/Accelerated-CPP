template<class T> class allocator {
public:
    T* allocate(size_t);
    void deallocate(T*, size_t);
    void construct(T*, const T&);
    void destroy(T*);

    // ...
};


template<class In, class For> For uninitialized_copy(In, In, For);
template<class For, class T> void uninitialized_fill(For, For, const T&);
