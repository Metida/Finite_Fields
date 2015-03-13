#ifndef FFE_H
#define FFE_H

#include <iostream>
#include "is_prime.h"

using std::ostream;

template<long N>
class FFE{
private:
  int value;

public:
  FFE(int value){
    static_assert(is_prime_func(N), "Field order must be a prime number");
    FFE<N>::value = value % N;
  }

  static const FFE<N> ONE(){
    return FFE<N>(1);
  }

  static const FFE<N> ZERO(){
  	return FFE<N>(0);
  }

  FFE<N>& operator+=(const FFE<N>& b){
    this->value += b.value%N;
    if (this->value > N)
      this->value = this->value %N;
    return *this;
  }

  FFE<N>& operator*=(const FFE<N>& b){
    this->value *= b.value%N;
    this->value = this->value%N;
    return *this;
  }

    template<long M>
    friend
    ostream & operator<<(ostream& os, const FFE<M>& ffe){
        return os << ffe.value;
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
