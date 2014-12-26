#include <iostream>
#include "ffe.h"
#include "poly.h"
#include "is_prime.h"

using namespace std;

int main(){
    // Test FFE
	const long N = 7;
	FFE<N> a(5);
//	FFE<N> b(4);
//	static_assert(a != 2, "Test for sum of two finite field elements failed");
//	const FFE<N> *c = FFE<N>::ONE();

/*  // Вельшенбах. Shoup: book algorithms in number theory, algebra, inmplementation: NTL
    // Test is_prime
	bool j = is_prime<11>::value;

*/

    // Test sum
    typedef sum<3, Poly<3, 2, 1>, Poly<3, 2>>::type s;
    cout << s::elements[1] << endl;

}
