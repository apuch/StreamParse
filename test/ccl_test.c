#include <check.h>

#include "containers.h"

START_TEST( vector_test ) {
    Vector *v;
    ck_assert((v = iVector.Create(sizeof(int), 20)) != NULL) ;
    ck_assert_int_eq(iVector.GetElementSize(v), sizeof(int));
    for (int i = 0; i < 30; ++i) {
        ck_assert(iVector.Add(v, &i) > 0);
    }
    for (int i = 0; i < 30; ++i) {
        int *j = (int*)iVector.GetElement(v, i);        
        ck_assert(j != NULL);
        ck_assert_int_eq(i, *j);
    }
    ck_assert(iVector.Finalize(v) > 0);
} END_TEST

TCase* test_lib_ccl() {
    struct TCase *tc = tcase_create("unittest_basic");    
    tcase_add_test(tc, vector_test);
    return tc;
}
