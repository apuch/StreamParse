#include <check.h>

#include "sp_field.h"
#include "spi_debug.h"
#include "util.h"

static struct {
    struct sp_field_t *f;
} f; 

static void setUp() {
    f.f = sp_field_init("foo");
}

static void tearDown() {
    sp_field_free(f.f);
}

START_TEST (test_init) {
    struct sp_field_t* field = sp_field_init("foo");
    IS_TRUE(field != NULL);
    IS_OK(sp_field_free(field));
} END_TEST

START_TEST ( test_type_uint_be ) {
    IS_OK(sp_field_type_set_uint_be(f.f, 8));
    enum sp_type_t type;
    IS_OK(sp_field_type_get(f.f, &type));
    IS_INT_EQ(type, SP_TYPE_UINT_BE);

    IS_OK(sp_field_type_set_uint_be(f.f,  1));
    IS_OK(sp_field_type_set_uint_be(f.f, 32));
    IS_ERR(sp_field_type_set_uint_be(f.f,  0), E_ARGUMENT);
    IS_ERR(sp_field_type_set_uint_be(f.f, 33), E_ARGUMENT);
} END_TEST


TCase* test_sp_field() {
    struct TCase *tc = tcase_create("sp_field");    
    tcase_add_checked_fixture(tc, setUp, tearDown);
    tcase_add_test(tc, test_init);
    tcase_add_test(tc, test_type_uint_be);
    return tc;
}


