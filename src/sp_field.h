#ifndef SP_FIELD_H
#define SP_FIELD_H

enum sp_type_t {
    SP_TYPE_BOOL,
    SP_TYPE_INT_BE,
};

struct sp_field_t;

struct sp_field_t* sp_field_init(const char* name);

int sp_field_free(struct sp_field_t*);

#endif
