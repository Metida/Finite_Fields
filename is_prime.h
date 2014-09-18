#ifndef IS_PRIME_H
#define IS_PRIME_H

struct false_type {
  typedef false_type type;
  enum { value = 0 };
};
 
struct true_type {
  typedef true_type type;
  enum { value = 1 };
};
 
template<bool condition, class T, class U>
struct if_ {
  typedef U type;
};
 
template <class T, class U>
struct if_<true, T, U> {
  typedef T type;
};
 
template<size_t N, size_t c> 
struct is_prime_impl { 
  typedef typename if_<(c*c > N),
                       true_type,
                       typename if_<(N % c == 0),
                                    false_type,
                                    is_prime_impl<N, c+1> >::type >::type type;
  enum { value = type::value };
};
 
template<size_t N> 
struct is_prime {
  enum { value = is_prime_impl<N, 2>::type::value };
};
 
template <>
struct is_prime<0> {
  enum { value = 0 };
};
 
template <>
struct is_prime<1> {
  enum { value = 0 };
};
