# fantestic
A minimal unit testing framework for C.

## Usage

The testing framework only consists the [test.c](test.c) and [test.h](test.h) files, so they can easily be copied the project which should be tested. Since the test.c file already contains the main function, there is nothing required beyond writing test. 

A new test case can be written using the `TEST` macro:
```C
#include "test.h"

TEST(example_test) {
  // write your test code here
}
```

This macro registers the test function in a global array of test functions during runtime before the `main()` is called. Once all tests are registered, the `main()` function executes each registered test from the global test array and prints the name of each test. 

The testing framework also supplies commonly needed helper functions to compare results and to pass or fail a test. The success of a test case is handled through the return value of the test function. Therefore, to finish of a successful test, the `PASS()` macro can be used for this. A complete test case can look like this:

```C
#include "test.h"

TEST(example_test) {
  int actual = 1;
  int expected = function_to_be_tested();
  ASSERT_EQUALS_INT(expected, actual);
  PASS();
}
```

Should an assertion fail, an error message containing the location of the statement as well as the both values (should this be feasable). 

It is also possible to directly fail a test:

```C
#include "test.h"

TEST(fail_test) {
  FAIL();
}
```

More examples can be found in the [example.c](example.c) file. 

## Requirements

Only a C89 compliant C compiler with support for the `__attribute__((constructor))` is needed. Any somewhat modern GCC, Clang and ICC should support this. 

## License

This project is licensed under the BSD 3-clause license. A copy of this can be found in the [LICENSE](LICENSE) file.
