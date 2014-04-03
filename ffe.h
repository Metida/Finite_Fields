#ifndef FFE_H
#define FFE_H
 
template<long N>
class FFE{
private:
  int value;
public:
  FFE(int);
  FFE<N>& operator +=(const FFE<N>& b){
    return FFE<N>((value%N + b.value%N)%N);
  }
  
  FFE<N> operator +(const FFE<N>& b){
    return value += b;
  }
};

template<long N>
FFE<N>::FFE(int value){
  FFE<N>::value = value%N;
}
 
#endif /* FFE_H */
