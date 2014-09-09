#ifndef SP_STRUCT_H
#define SP_STRUCT_H

#include <stdlib.h>

enum sp_type_t {
    SP_TYPE_BOOL,
    SP_TYPE_INT_BE,
};

struct sp_field_t {
    const char* name;
    enum sp_type_t type;
    size_t offset;
};

struct sp_struct_t;

struct sp_struct_t* sp_struct_init(const char* name);

int sp_struct_free(struct sp_struct_t* s);

#endif

