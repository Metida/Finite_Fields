#include <iostream>
#include "poly.h"
#include "ffe.h"

using namespace std;

int main(){

//  Test is_prime
//  bool j = is_prime_func<11>;

    typedef FFE<7, 5> a;
    typedef FFE<7, 4> b;

    // Test sum
    typedef FFE<7, 2> ref_res1;
    typedef FFE_sum<7, a, b>::type res1;
    static_assert(FFE_equals<7, res1, ref_res1>::value, "Sum for FFE error");

    // Test diff
    typedef FFE<7, 6> ref_res2;
    typedef FFE_diff<7, b, a>::type res2;
    static_assert(FFE_equals<7, res2, ref_res2>::value, "Diff for FFE error");
    

    typedef sum<5, Poly<5, 1, 2, 1>, Poly<5, 1, 1, 1>>::type s;
    for (int i = 0; i < s::elements_count; i++)
        cout << s::elements[i];
    cout << endl;

    typedef mult<3, Poly<3, 1, 2, 1>, Poly<3, 1, 1, 1>>::type m;
    for (int i = 0; i < m::elements_count; i++)
        cout << m::elements[i];
    cout << endl;

}
