#ifndef SP_FIELD_H
#define SP_FIELD_H

#include <stdbool.h>

enum sp_type_t {
    SP_TYPE_BOOL,
    SP_TYPE_UINT_BE,
    SP_TYPE_BLOB,
};

struct sp_field_t;

typedef size_t (*sp_field_cond_t)(struct sp_field_t* field, void* data); 

struct sp_field_t* sp_field_init(const char* name);

int sp_field_free(struct sp_field_t*);

int sp_field_name_get(struct sp_field_t*, const char**);

int sp_field_type_set_uint_be(struct sp_field_t*, size_t width);
int sp_field_type_set_bool(struct sp_field_t*);
int sp_field_type_set_blob(struct sp_field_t*, size_t width);
int sp_field_type_get(struct sp_field_t*, enum sp_type_t*);

int sp_field_cond_set(struct sp_field_t*, sp_field_cond_t);

int sp_field_width_get(struct sp_field_t*, size_t*);

#endif
