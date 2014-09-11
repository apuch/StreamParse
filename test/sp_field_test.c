#include <check.h>

#include "sp_field.h"
#include "spi_debug.h"
#include "util.h"

static struct {
    struct sp_field_t *f;
    enum sp_type_t t;
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
    const char* name;
    sp_field_name_get(f.f, &name);
    IS_INT_EQ(strcmp("foo", name), 0);
    IS_OK(sp_field_free(field));
} END_TEST

START_TEST ( test_type_uint_be ) {
    IS_OK(sp_field_type_set_uint_be(f.f, 8));
    IS_OK(sp_field_type_get(f.f, &f.t));
    IS_INT_EQ(f.t, SP_TYPE_UINT_BE);

    IS_OK(sp_field_type_set_uint_be(f.f,  1));
    IS_OK(sp_field_type_set_uint_be(f.f, 32));
    IS_ERR(sp_field_type_set_uint_be(NULL, 32), E_ARGUMENT);
    IS_ERR(sp_field_type_set_uint_be(f.f,  0), E_ARGUMENT);
    IS_ERR(sp_field_type_set_uint_be(f.f, 33), E_ARGUMENT);
} END_TEST

START_TEST( test_type_bool ) {
    IS_OK(sp_field_type_set_bool(f.f));
    IS_OK(sp_field_type_get(f.f, &f.t));
    IS_ERR(sp_field_type_set_bool(NULL), E_ARGUMENT);
    IS_INT_EQ(f.t, SP_TYPE_BOOL);
} END_TEST

START_TEST( test_type_blob) {
    IS_OK(sp_field_type_set_blob(f.f, 8));
    IS_OK(sp_field_type_get(f.f, &f.t));
    IS_INT_EQ(f.t, SP_TYPE_BLOB);

    IS_ERR(sp_field_type_set_blob(NULL, 32), E_ARGUMENT);
    IS_ERR(sp_field_type_set_blob(NULL, 65536 * 8), E_ARGUMENT);
    IS_ERR(sp_field_type_set_blob(f.f,  0), E_ARGUMENT);
    IS_ERR(sp_field_type_set_blob(f.f,  65536 * 8 + 1), E_ARGUMENT);
} END_TEST

static size_t _cond_8(struct sp_field_t* field, void* data) {
    return 8;
}

START_TEST( test_cond_set ) {
    IS_OK(sp_field_cond_set(f.f, _cond_8));
    IS_OK(sp_field_cond_set(f.f,  NULL));
    IS_ERR(sp_field_cond_set(NULL, _cond_8), E_ARGUMENT);
} END_TEST

START_TEST( test_width_no_cond ) {
    size_t w;
    IS_OK(sp_field_type_set_bool(f.f));
    IS_OK(sp_field_width_get(f.f, &w)); IS_INT_EQ(w, 1);
    IS_OK(sp_field_type_set_uint_be(f.f, 16));
    IS_OK(sp_field_width_get(f.f, &w)); IS_INT_EQ(w, 16);
    IS_OK(sp_field_type_set_blob(f.f, 64));
    IS_OK(sp_field_width_get(f.f, &w)); IS_INT_EQ(w, 64);
} END_TEST

START_TEST( test_width_cond ) {
    size_t w;
    IS_OK(sp_field_cond_set(f.f, _cond_8));
    IS_OK(sp_field_type_set_bool(f.f));
    IS_ERR(sp_field_width_get(f.f, &w), E_ERROR);
    IS_OK(sp_field_type_set_uint_be(f.f, 16));
    IS_OK(sp_field_width_get(f.f, &w)); IS_INT_EQ(w, 8);
    IS_OK(sp_field_type_set_blob(f.f, 64));
    IS_OK(sp_field_width_get(f.f, &w)); IS_INT_EQ(w, 8);
} END_TEST


TCase* test_sp_field() {
    struct TCase *tc = tcase_create("sp_field");    
    tcase_add_checked_fixture(tc, setUp, tearDown);
    tcase_add_test(tc, test_init);
    tcase_add_test(tc, test_type_uint_be);
    tcase_add_test(tc, test_type_bool);
    tcase_add_test(tc, test_type_blob);
    tcase_add_test(tc, test_cond_set);
    tcase_add_test(tc, test_width_no_cond);
    tcase_add_test(tc, test_width_cond);
    return tc;
}


