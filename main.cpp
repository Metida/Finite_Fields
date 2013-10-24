#include <iostream>
//#include "template.h"
using namespace std;

template<long N>
class FFE {
public:
	FFE (int);

	FFE<N> operator+=(FFE<N> const & b){
		return (a%N+b%N)%N;
	}

	FFE<N> operator*=(FFE<N> const & a, FFE<N> const & b) {
		if (!a || !b) return 0;
		if (a&1) return (b + ::mult<N>(a-1,b))%N;
		return (::mult<N>(a/2,b)*2)%N;
	}
	
};
tenplate <long N>	
    FFE<N>::FFE<N>(int value){
    	if (a<N)
    	FFE<N>::value = value;
    	else
    	FFE<N>::value = value%N; 
    }
    
int main(){
	const long N = 7;
	cout << "N=" << N <<endl;
	FFE<N> a = new FFE<N>(5);
	FFE<N> b = new FFE<N>(4);
	cout << a << "+" << b << "=" << a+b << endl;
	cout << a << "*" << b << "=" << a*b << endl;

    system("pause");
}
