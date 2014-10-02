#include <iostream>
#include "ffe.h"
#include "is_prime.h"
using namespace std;

/*
	const FFE<N> mult(const FFE<N>&a, const FFE<N>& b) {
		if (!value || !b.value) return FFE<N>(0);
		if (value&1) return FFE<N>((b.value + ::mult<N>(value-1, b.value))%N);
		return FFE<N>((::mult<N>(value/2, b.value)*2)%N);
	}
*/

int main(){
	const long N = 7;
	cout << "N=" << N << endl;
	FFE<N> *a = new FFE<N>(5);
	FFE<N> *b = new FFE<N>(4);
	*a += *b;
	const FFE<N> *c = FFE<N>::ONE();
	bool j = is_prime<11>::value;
}
