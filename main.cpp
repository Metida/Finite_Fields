#include <iostream>
//#include "template.h"
using namespace std;

template<long N>
class FFE {
private:
	int value;
public:
//	FFE (int a):value(a);
	FFE(int);
	const FFE<N> operator+(const FFE<N>& b){
		return (value%N+b%N)%N;
	}

	const FFE<N> operator*(const FFE<N>& b) {
		if (!value || !b) return 0;
		if (value&1) return (b + ::mult<N>(value-1,b))%N;
		return (::mult<N>(value/2,b)*2)%N;
	}
	
};

template <long N>	
    FFE<N>::FFE(int value){
    	if (value<N)
    	FFE<N>::value = value;
    	else
    	FFE<N>::value = value%N; 
    }

    
int main(){
	const long N = 7;
	cout << "N=" << N <<endl;
	FFE<N> *a = new FFE<N>(5);
	FFE<N> *b = new FFE<N>(4);
//	cout << a << "+" << b << "=" << a+b << endl;
//	cout << a << "*" << b << "=" << a*b << endl;

    system("pause");
}
