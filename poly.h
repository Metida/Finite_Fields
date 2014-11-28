#ifndef POLY_H
#define POLY_H

template <int N, int ... Nums>
struct Poly {
	static FFE<N> elements[sizeof ...(Nums)];
	enum { elements_count = sizeof ...(Nums) };
};

template<int N, int ... Nums>
FFE<N> Poly<N, Nums ...>::elements[] = { Nums ... };

#endif
