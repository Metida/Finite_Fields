#ifndef POLY_H
#define POLY_H

#include "ffe.h"

template <int N, int ... Nums>
struct Poly {
    static FFE<N> elements[sizeof ...(Nums)];
    enum { elements_count = sizeof ...(Nums) };
};

template<int N, int... Nums>
FFE<N> Poly<N, Nums ...>::elements[] = { Nums ... };

template<int N, typename P1, typename P2>
struct concat {
};

template<int N, int... Nums1, int... Nums2>
struct concat<N, Poly<N, Nums1 ...>, 
                 Poly<N, Nums2 ...>> {
	typedef Poly<N, Nums1 ..., Nums2 ...> type;
};

//sum

template<int N, typename P1, typename P2>
struct sum {
};

template<int N, int C1, int C2, int... Nums1, int... Nums2>
struct sum<N, Poly<N, C1, Nums1 ...>, Poly<N, C2, Nums2 ...>> {
    typedef typename concat<N, 
                            Poly<N, C1+C2>, 
                            typename sum<N, 
							             Poly<N, Nums1 ...>, 
                                         Poly<N, Nums2 ...>>::type
							>::type type;
};

template<int N, int C1, int C2>
struct sum<N, Poly<N, C1>, Poly<N, C2>> {
    typedef Poly<N, C1 + C2> type;
};

template <int N, int C1, int C2, int... Nums2>
struct sum<N, Poly<N, C1>, Poly<N, C2, Nums2...>> {
    typedef typename concat<N, Poly<N, C1 + C2>, Poly<N, Nums2...>>::type type;
};

template <int N, int C1, int C2, int... Nums1>
struct sum<N, Poly<N, C1, Nums1...>, Poly<N, C2>> {
    typedef typename concat<N, Poly<N, C1 + C2>, Poly<N, Nums1...>>::type type;
};

//mult

template <int N, typename P1, typename P2>
struct mult {
};

template <int N, int C1, int C2, int... Nums1>
struct mult<N, Poly<N, C1, Nums1...>, Poly<N, C2>> {
    typedef typename concat <N,
                            Poly<N, C1 * C2>,
                            typename mult<N, Poly<N, Nums1...>, Poly<N, C2>>::type
                            >::type type;
};

template <int N, int C1, int C2>
struct mult<N, Poly<N, C1>, Poly<N, C2>> {
    typedef Poly<N, C1 * C2> type;
};

template <int N, int C1, int... Nums1, int C2, int... Nums2>
struct mult<N, Poly<N, C1, Nums1...>, Poly<N, C2, Nums2...>> {
    typedef typename sum <N,
                          Poly<N, C1, Nums1...>,
                          typename concat<N,
                                          Poly<N, 0>,
                                          typename mult<N, Poly<N, C1, Nums1...>, Poly<N, Nums2...>>::type
                                          >::type
                          >::type type;
};

#endif
