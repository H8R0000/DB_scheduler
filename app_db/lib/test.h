#include <iostream>
#include <string.h>

class test {
public:
    int a = 5;
    double b = 5.12345;
    char c = 'X';

};

#ifdef __cplusplus
extern "C" {
#endif

    test *test_new();
    void test_del(test *test);

    int test_get_a(test *test);
    double test_get_b(test *test);
    char test_get_c(test *test);

#ifdef __cplusplus
}
#endif