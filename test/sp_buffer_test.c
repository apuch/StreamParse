#include <check.h>
#include <stdbool.h>

#include "debug.h"
#include "sp_buffer.h"
#include "util.h"

static const char* _data4 = "\xAF\x0E\x12\x34";
static struct sp_buffer_t _b, _b1;

static void initData4() {
    IS_OK(sp_buffer_init(&_b, _data4, 4));
}

START_TEST ( creation ) {
    initData4();
    IS_INT_EQ(_b.length, 4 * 8);
    IS_INT_EQ(_b.index, 0);
    IS_P_EQ(_b.data, _data4);
} END_TEST

START_TEST ( createView ) {
    initData4();
    IS_OK(sp_buffer_init_view(&_b1, &_b, 1, 2));
    IS_INT_EQ(_b1.length, 2 * 8);
    IS_INT_EQ(_b1.index, 0);
    IS_P_EQ(_b1.data, _data4 + 1);

    IS_OK(sp_buffer_init_view(&_b1, &_b, 1, 3));
    IS_INT_EQ(_b1.length, 3 * 8);
} END_TEST


START_TEST (createViewInvalid ) {
    initData4();
    IS_ERR(sp_buffer_init_view(&_b1, NULL, 1, 2), E_ARGUMENT);
    IS_ERR(sp_buffer_init_view(NULL, &_b, 1, 2), E_ARGUMENT);
    IS_ERR(sp_buffer_init_view(&_b1, &_b, 4, 2), E_RANGE);
    IS_ERR(sp_buffer_init_view(&_b1, &_b, 1, 4), E_RANGE);
} END_TEST

START_TEST ( readBools ) {
    initData4();
    bool values[] = {
        1,0,1,0,1,1,1,1,
        0,0,0,0,1,1,1,0,
        0,0,0,1,0,0,2,0,
        0,0,1,1,0,1,0,0};
    bool v;
    for (int i = 0; i < 4 * 8; ++i) {
        IS_OK(sp_buffer_read_bool(&_b, &v));
        IS_INT_EQ(i+1, _b.index);
        IS_INT_EQ(values[i], v);
    }
    IS_ERR(sp_buffer_read_bool(&_b, &v), E_RANGE);
} END_TEST

START_TEST ( readUIntsBE ) {
    initData4();
    uint64_t v;
    IS_OK(sp_buffer_read_uint_be(&_b, &v, 4 )); IS_INT_EQ(v, 0xA);
    IS_OK(sp_buffer_read_uint_be(&_b, &v, 8 )); IS_INT_EQ(v, 0xF0);
    IS_OK(sp_buffer_read_uint_be(&_b, &v, 4 )); IS_INT_EQ(v, 0xE);
    IS_OK(sp_buffer_read_uint_be(&_b, &v, 16)); IS_INT_EQ(v, 0x1234);
} END_TEST


TCase* test_sp_buffer() {
    struct TCase *tc = tcase_create("sp_buffer");    
    tcase_add_test(tc, creation);
    tcase_add_test(tc, createView);
    tcase_add_test(tc, createViewInvalid);
    tcase_add_test(tc, readBools);
    tcase_add_test(tc, readUIntsBE);
    return tc;
}

