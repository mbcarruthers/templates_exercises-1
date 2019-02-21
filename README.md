Templates exercises
===================

Most of exercises doesn't require you to run you application (except ex. 1.3). If you can compile it, you're fine.
This is the whole beauty of templates and meta-programming.

Folder/Directory hints contains hints for every question. Look for them if you stuck. If you've never seen
the `static_assert` please read _hints/static_assert_explanation.md_. 

### Part 1 - Templates

1. Write function template called `max()`, which takes 2 arguments and returns greater element of the given values. 
Your function should be able to handle different arguments types, ex. `double` and `int`.

2. Change your max() function so now it should take various number of elements of different types
ex. `int`, `double`, `float`.

3. C++ allows you to compare strings by using `>` `<` operators. 
Default implementation compares string in Lexicographical order [wiki](https://en.wikipedia.org/wiki/Lexicographical_order). 

    Change behavior of your `max()` function so the longest string will be returned instead of lexicographically greater, 
ex. `max("theShortString", "aVeryLooooongString") == "aVeryLooooongString"`.
With default behaviour the first string is returned because the first letter is greater in lexicographical order 
than the first letter of the second string (`t` > `a`).


### Part 2 - Template meta-programming

1. Fibonacci series [wiki](https://en.wikipedia.org/wiki/Fibonacci_number) is the series of numbers, 
which starts from 0, 1, and every next number is a sum of the two preceding ones:

    0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...

    The sequence Fn of Fibonacci numbers is defined by the recurrence relation:

    `f(n) = f(n - 1) + f(n - 2)`

    Write template meta-function `fib` to calculate an n-th number of the Fibonacci series using the above recursive formula.

2. Check if number belongs to the Fibonacci series - for ninjas &#128570;

    Write a template meta-function `is_fib` that returns true if number belongs to Fibonacci series and false otherwise,
    ex:
    ```
      static_assert(is_fib<7>::value == false, "This is not a Fibonacci's number");
      static_assert(is_fib<8>::value, "This is a Fibonacci's number");
    ```
