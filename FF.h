//???
#ifndef FF.h
#define FF.h


class FFE<long N> {
    int a;

    FFE operator+=(FFE const & b){
        return (a%N+b%N)%N;

    FFE operator*=(FFE const & a, FFE const & b) {
       if (!a || !b) return 0;
       if (a&1) return (b + ::mult<N>(a-1,b))%N;
       return (::mult<N>(a/2,b)*2)%N;
};

#endif
