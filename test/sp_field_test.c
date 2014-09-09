#include <check.h>

#include "sp_field.h"
#include "util.h"

START_TEST (init) {
    struct sp_field_t* f = sp_field_init("foo");
    IS_TRUE(f != NULL);
    IS_OK(sp_field_free(f));
} END_TEST

TCase* test_sp_field() {
    struct TCase *tc = tcase_create("sp_field");    
    tcase_add_test(tc, init);
    return tc;
}
