#include <check.h>

#include "util.h"
#include "sp_buffer.h"

START_TEST ( creation ) {
    const char* data = "xxxx";
    struct sp_buffer_t b;
    IS_OK(sp_buffer_init(&b, data, 4));
    IS_INT_EQ(b.length, 4 * 8);
    IS_INT_EQ(b.index, 0);
    IS_P_EQ(b.data, data);
} END_TEST


TCase* test_sp_buffer() {
    struct TCase *tc = tcase_create("sp_buffer");    
    tcase_add_test(tc, creation);
    return tc;
}

