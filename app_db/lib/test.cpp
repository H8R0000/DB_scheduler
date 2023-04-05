#include "test.h"

/*
 * Обвязка C для методов класса C++
 */

// Создаем класс test, и получаем указатель на него.
test *test_new() {
    return new test();
}

// Удаляем класс test.
void test_del(test *test) {
    delete test;
}

/*
 * Вызов методов класса.
 */


/*
 * Получение переменных класса.
 */

// Обертка для получения a
int test_get_a(test *test) {
    return test->a;
}

// Обертка для получения b
double test_get_b(test *test) {
    return test->b;
}

// Обертка для получения c
char test_get_c(test *test) {
    return test->c;
} 