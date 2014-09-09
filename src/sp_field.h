#ifndef SP_FIELD_H
#define SP_FIELD_H

enum sp_type_t {
    SP_TYPE_BOOL,
    SP_TYPE_UINT_BE,
};

struct sp_field_t;

struct sp_field_t* sp_field_init(const char* name);

int sp_field_free(struct sp_field_t*);

int sp_field_name_get(struct sp_field_t*, const char**);

int sp_field_type_set_uint_be(struct sp_field_t*, size_t width);
int sp_field_type_set_bool(struct sp_field_t*);
int sp_field_type_get(struct sp_field_t*, enum sp_type_t*);

#endif
