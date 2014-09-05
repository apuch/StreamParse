#ifndef UTIL_H
#define UTIL_H

#define IS_OK(x) ck_assert_int_ge(x, 0)
#define IS_ERR(x, y) ck_assert_int_eq(x,y)
#define IS_TRUE(x) ck_assert(x)
#define IS_INT_EQ(x,y) ck_assert_int_eq(x,y)
#define IS_P_EQ(x,y) ck_assert_ptr_eq(x,y)
#endif

