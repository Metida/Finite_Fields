#ifndef FFE_H
#define FFE_H
 
template<long N>
class FFE{
private:
  int value;
  
public:
 	FFE<N>::FFE(int value){
	    	FFE<N>::value = value%N;
	 }
	 
  FFE<N>& FFE<N>::operator+=(const FFE<N>& b){
		  this->value += b.value%N;
		  if (this->value > N)
			   this->value = this->value %N;
		  return *this;
	 }
};

template<long N>
FFE<N> operator+(const FFE<N>& a, const FFE<N>& b){
 	FFE<N> *temp = new FFE<N>(a);
	 return temp += b;
}
 
#endif /* FFE_H */
