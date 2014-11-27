#ifndef FFE_H
#define FFE_H

#include <is_prime.h>
 
template<long N>
class FFE{
private:
  int value;
  
public:
  FFE<N>::FFE(int value){
    static_assert(is_prime_func(N), "Field order must be a prime number");
    FFE<N>::value = value%N;
  }
  
  static const FFE<N>* ONE(){
    return new FFE<N>(1);
  }
  
  static const FFE<N>* ZERO(){
  	return new FFE<N>(0);
  }
  	 
  FFE<N>& FFE<N>::operator+=(const FFE<N>& b){
    this->value += b.value%N;
    if (this->value > N)
      this->value = this->value %N;
    return *this;
  }
	
  FFE<N>& FFE<N>::operator*=(const FFE<N>& b){
    this->value *= b.value%N;
    this->value = this->value%N;
    return *this;
  }
};

template<long N>
FFE<N> operator+(const FFE<N>& a, const FFE<N>& b){
 	FFE<N> temp = FFE<N>(a);
	return temp += b;
}

template<long N>
FFE<N> operator*(const FFE<N>& a, const FFE<N>& b){
	FFE<N> temp = FFE<N>(a);
	return temp *= b;
}
 
#endif /* FFE_H */

http://en.cppreference.com/w/cpp/types/enable_if
