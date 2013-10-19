#include <iostream>
//#include "template.h"

class FFE<long N> {
    int a;

    FFE operator+=(FFE const & b){
        return (a%N+b%N)%N;

    FFE operator*=(FFE const & a, FFE const & b) {
       if (!a || !b) return 0;
       if (a&1) return (b + ::mult<N>(a-1,b))%N;
       return (::mult<N>(a/2,b)*2)%N;
};
	

using namespace std;

int main()
{
  /*  const long N = 7;
    cout << "N=" << N <<endl;
    long int a = 6, b = 3;
    cout << a << "+" << b << "=" << ::add<N>(a,b) << endl;
    cout << a << "*" << b << "=" << ::mult<N>(a,b) << endl;

*/
    system("pause");
}
