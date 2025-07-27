#include <check.h>
// #include <limits.h>
#include <stdlib.h>
#include <string.h>

#include "../src/s21_decimal.h"

START_TEST(test_Of_None) {
  ck_assert_int_eq(1,1);
}
END_TEST
void testOfNone(TCase *tc_core) {
  tcase_add_test(tc_core, test_Of_None);
}

Suite *math_suite(void) {
  Suite *testsuite = suite_create("s21_string");
  TCase *tc_core = tcase_create("Core");

  testOfNone(tc_core);

  suite_add_tcase(testsuite, tc_core);

  return testsuite;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = math_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}