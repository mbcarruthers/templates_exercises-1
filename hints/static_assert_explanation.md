This exercise depends heavily on `static_assert` feature introduced in C++11. 
If you are already familiar with `assert` function, logic is very similar.
Both functions stop your application. The only difference is that `static_assert` is a compile time
feature, where `assert` is checked during runtime.

You can use `static_assert` for checking compile time assumptions, ex. check if `int` on your
machine has 4-bytes - `static_assert(sizeof(int) == 4, "int on that machine has unexpected size")`
or check if machine is 64-bit machine `static_assert(sizeof(void*) == 8, "This is not a 64-bit machine")`.

You can also use it for template evaluation, ex: 

`static_assert(std::is_same<int, double>::value, "What a surprise!");`

GCC produces the following error:
```
/tmp/main.cpp: In function ‘int main()’:
/tmp/main.cpp:10:3: error: static assertion failed: What a surprise!
   static_assert(std::is_same<int, double>::value, "What a surprise!");
   ^~~~~~~~~~~~~
```

Static assert can also be used for evaluating a compile-time variables ex.
```
  const static int x = 2 * 2;
  static_assert(x == 4, "That would be weird.");
```

or functions (with small exception):

```
constexpr int mul(int a, int b){
  return a * b;
}

static_assert(mul(2, 3) == 6, "Nothing interesting here.");
```

As you can see, function above is marked as `constexpr` which is required to be able to use it in 
`static_assert` expression. Without it compiler produces error similar to that:

```
/tmp/main.cpp:72:1: error: non-constant condition for static assertion
 static_assert(mul(2, 3) == 6, "Nothing interesting here.");
 ^~~~~~~~~~~~~
/tmp/main.cpp:72:18: error: call to non-constexpr function ‘int mul(int, int)’
 static_assert(mul(2, 3) == 6, "Nothing interesting here.");
               ~~~^~~~~~
```

Right now you know everything that is needed go and solve some exercises.