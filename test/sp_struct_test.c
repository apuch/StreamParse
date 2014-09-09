#include <check.h>

#include "sp_struct.h"
#include "util.h"

static struct sp_struct_t* _s;

START_TEST ( init) {
    _s = sp_struct_init("foo");
    IS_TRUE( _s != NULL);
    IS_OK(sp_struct_free(_s));
} END_TEST

TCase* test_sp_struct() {
    struct TCase *tc = tcase_create("sp_struct");
    tcase_add_test(tc, init );
    return tc;
};
