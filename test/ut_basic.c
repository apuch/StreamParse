#include <check.h>
#include <unistd.h>

START_TEST( ut_fail  ) {
    ck_assert_str_eq("foo", "bar");
} END_TEST

START_TEST( ut_win ) {
    ck_assert_str_eq("foo", "foo");
} END_TEST
    
TCase* test_ut_basic() {
    struct TCase *tc = tcase_create("unittest_basic");    
    //tcase_add_test(tc, ut_fail);
    tcase_add_test(tc, ut_win);
    return tc;
}

