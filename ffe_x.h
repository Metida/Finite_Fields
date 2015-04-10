#ifndef FFE_X_H
#define FFE_X_H

#include <iostream>

using std::ostream;

template<long N>
class FFE_x {
private:
    int value;

public:
    FFE_x(int value) {
        static_assert(is_prime_func(N), "Field order must be a prime number");
        FFE_x<N>::value = value % N;
    }

    FFE_x<N>& operator+=(const FFE_x<N>& b) {
        this->value += b.value%N;
        if (this->value > N)
            this->value = this->value %N;
        return *this;
    }

    FFE_x<N>& operator*=(const FFE_x<N>& b) {
        this->value *= b.value%N;
        this->value = this->value%N;
        return *this;
    }

    friend
    ostream & operator<<(ostream& os, const FFE_x<N>& ffe) {
        return os << ffe.value;
    }

};

template<long N>
FFE_x<N> operator+(const FFE_x<N>& a, const FFE_x<N>& b) {
    FFE<N> temp = FFE<N>(a);
    return temp += b;
}

template<long N>
FFE_x<N> operator*(const FFE_x<N>& a, const FFE_x<N>& b) {
    FFE_x<N> temp = FFE_x<N>(a);
    return temp *= b;
}

#endif /* FFE_X_H */
