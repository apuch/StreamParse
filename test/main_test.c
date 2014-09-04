
#include <check.h>

TCase* test_ut_basic();
TCase* test_lib_ccl();

Suite* test_suite() {
    Suite* s = suite_create("test_suite");

    suite_add_tcase(s, test_ut_basic());
    suite_add_tcase(s, test_lib_ccl());
    return s;
}


int main(int argc, char** argv) {
    int num_failed;
    Suite* s = test_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    num_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (num_failed == 0) ? 0 : 1;
}
    
