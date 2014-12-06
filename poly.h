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
struct sum {
};

/*template<int N, int ... Nums>
struct sum<N, Poly<N, int ... Nums>, > {
};*/


template<int N, int C1, int C2, int... Nums1, int... Nums2>
struct sum<N, Poly<N,C1, Nums1 ...>,
              Poly<N,C2, Nums2 ...>> {
    typedef Poly<N, C1+C2>// ++ ???
        // typename sum<N,
            //Poly<N,Nums1>, Poly<N,Nums2>>::type
            type;
};
/*

template<int N, int C1, int C2>
struct sum<N, Poly<N,C1>, Poly<N, C2>> {

    typedef Poly<N, C1 + C2> type;

};
*/
#endif
