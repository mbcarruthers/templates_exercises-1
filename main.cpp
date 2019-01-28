#include <cassert>
#include <string>
#include <iostream>
// Implement your solutions here.

template<typename T>
constexpr T max( T a , T b ) {
  return b < a ? a : b;
}

template<typename T , typename U>
constexpr auto max( T a , U b) -> decltype(b < a ? a : b )
{
    return b < a ? a : b;
}

template<typename T , typename... Types>
 constexpr auto max( T t , T t2 , Types... types ) -> decltype( max(max(t,t2) , types...) ) {
    return max( max(t,t2), types...);
}

template<typename T , typename U , typename... Types>
 constexpr auto max( T t , U u , Types... types ) -> decltype( max(max(t , u) , types...) ) {
    return max( max(t , u) , types... );
}
template<typename T , typename U , typename V , typename... Types>
constexpr auto max( T t , U u , V v , Types... types ) -> decltype( max( max(t , u , v) , types...))
{
    return max( max(t , u , v) , types...);
}
int main( void )  {
  using namespace std::string_literals;

  // Just uncomment the section that you are currently working on.
  // At the very end, this file should compile with all checks enabled.

  // Ex. 1.1
  // Write max function that compares different types.
  static_assert(::max(4, 5) == 5, "Not working for types of the same type");
  static_assert(::max(3, 4.7) == 4.7, "Not working for int and doubles ");
  static_assert(::max(3.f, 42.7) == 42.7, "The third one isn't working");

  // Ex. 1.2
  // Write max function that compares multiple values of different types.
  static_assert(::max(4, 5, 6, 7.6) == 7.6, "variadic templated max isn't working");
  static_assert(::max(4, 5, 6.f, 700.6, 234.34) == 700.6, "");

  // Ex. 1.3
  // Add overload which returns the longest string.
//  assert(::max("aaaa"s, "bb"s) == "aaaa"s);
//  assert(::max("aaaa"s, "bb"s, "veryLongString"s) == "veryLongString"s);
//  assert("aaaa"s < "b"s); // But outside the max() we want our default behaviour back.

  // Ex 2.1
  // Compute Fibonacci numbers.
//  static_assert(fib<5>::value == 5, "");
//  static_assert(fib<6>::value == 8, "");
//  static_assert(fib<8>::value == 21, "");
//  static_assert(fib<10>::value == 55, "");
//  static_assert(fib<15>::value == 610, "");

  // Ex. 2.2 - optional
  // Check if a number exists in Fibonacci series.
//  static_assert(is_fib<0>::value, "");
//  static_assert(is_fib<1>::value, "");
//  static_assert(is_fib<5>::value, "");
//  static_assert(is_fib<7>::value == false, "");
//  static_assert(is_fib<8>::value, "");
//  static_assert(is_fib<10>::value == false, "");
//  static_assert(is_fib<13>::value, "");
//  static_assert(is_fib<144>::value, "");

  return 0;
}
