template<int N, int c>
struct is_prime_recursive
{
  static constexpr bool value = (c*c > N) ? true : 
           (N % c == 0) ? false : 
              is_prime_recursive<N, c+1>::value;
};
 
template<int N>
struct is_prime
{
  static constexpr bool value = (N <= 1) ? false : is_prime_recursive<N, 2>::value;
};

/*
template <>
struct is_prime<1>
{
  static constexpr bool value = 0;
};

template <>
struct is_prime<0>
{
  static constexpr bool value = 0;
};
*/

int main()
{
   bool j = is_prime<11>::value; // Computed at run-time
}
