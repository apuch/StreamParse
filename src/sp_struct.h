#ifndef SP_STRUCT_H
#define SP_STRUCT_H

#include <stdlib.h>

struct sp_struct_t;

struct sp_struct_t* sp_struct_init(const char* name);

int sp_struct_free(struct sp_struct_t* s);

#endif

