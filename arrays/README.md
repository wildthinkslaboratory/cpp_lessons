## Arrays

In python we ususally use `lists` for arrays, unless we're working with NumPy or Casadi which have their own array objects. In `c++` we have a few options.

- `std::vector`
- `std::array`
- c-style arrays

`array.cpp` shows you a few ways (there are more) to initialize and use these different kinds of arrays.

### Compile and Run

To compile this file, move into the `arrays` directory and type

```
g++ -o arrays arrays.cpp
```

This runs the `g++` compiler (`clang`) on the source code `arrays.cpp` and puts the compiled code in the output file `arrays`. To run the code type

```
./arrays
```

### `inline` keyword

When a `c++` program is compiled, each function is compiled seperately,
the execution code for the various functions are then linked. So on
execution, you might be executing one function and then you get to a point
in the code where there is no more execution code, just a pointer (link) to
a different function that you now load into memory and run.

An `inline` function is not compiled into a function, instead the function is
copied into the calling function and compiled as part of the larger
function. You can see why you wouldn't want to do this with a larger more
complex function. You will have multiple copies of the same execution code
everywhere the function is called. But for short functions, it can lead to
faster execution times because it avoids the need to go look up the code
during execution. The size of the final executable would be slightly larger
because of the extra copies of the function.

The compiler will inline many functions automatically if it thinks it will
improve performance.

**SUMMARY:** - short frequently used functions are inlined - long complex functions are not
