#ifndef FFE_H
#define FFE_H

//#include "is_prime.h"

template <int x>
struct int_ {
    static const int value = x;
};

template <bool x>
struct bool_ {
    static const bool value = x;
};

template <int N, int x>
struct FFE {
public:
    enum { value = x % N };
    typedef int_<value> type;
};

template <int N, typename P1, typename P2>
struct FFE_sum {
};

template <int N, int x, int y>
struct FFE_sum<N, FFE<N, x>, FFE<N, y>> {
    typedef FFE<N, x + y> type;
};

template <int N, typename P1, typename P2>
struct FFE_diff {
};

template <int N, int x, int y>
struct FFE_diff<N, FFE<N, x>, FFE<N, y>> {
    enum { t = (x - y < 0) ? x - y + N : x - y };
    typedef FFE<N, t> type;
};

template <int N, typename P1, typename P2>
struct FFE_mult {
};

template <int N, int x, int y>
struct FFE_mult<N, FFE<N, x>, FFE<N, y>> {
    typedef FFE<N, x * y> type;
};


template<int N, typename P1, typename P2>
struct FFE_equals {
};

template <int N, int x, int y>
struct FFE_equals <N, FFE<N, x>, FFE<N, y>> {
    enum { value = FFE<N, x>::type::value == FFE<N, y>::type::value };
    typedef bool_<value> type;
};


#endif /* FFE_H */
