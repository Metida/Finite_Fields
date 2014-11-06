#ifndef IS_PRIME_H
#define IS_PRIME_H

#include <iostream>

constexpr bool is_prime_recursive(size_t number, size_t c){
  return (c*c > number) ? true : 
           (number % c == 0) ? false : 
              is_prime_recursive(number, c+1);
}
 
constexpr bool is_prime_func(size_t number){
  return (number <= 1) ? false : is_prime_recursive(number, 2);
}

#endif

//http://blog.biicode.com/template-metaprogramming-cpp-ii/
//http://cpptruths.blogspot.ru/2011/07/want-speed-use-constexpr-meta.html
