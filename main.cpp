#include <iostream>
//#include "ffe.h"
//#include "is_prime.h"
#include "poly.h"

using namespace std;

int main(){
    // Test FFE
/*	const long N = 7;
	cout << "N=" << N << endl;
	FFE<N> *a = new FFE<N>(5);
	FFE<N> *b = new FFE<N>(4);
	*a += *b;
	const FFE<N> *c = FFE<N>::ONE();

    // Test is_prime
	bool j = is_prime<11>::value;
*/

    // Test sum


    typedef sum<3, Poly<3, 2>, Poly<3, 2>>::type s;
    cout << s::elements[0] << endl;

}
