#include <string.h>

#include "spi_field.h"
#include "spi_util.h"
#include "spi_debug.h"


struct sp_field_t* sp_field_init(const char* name) {
    if (name == NULL) return NULL;

    struct sp_field_t *f = _CALLOC(struct sp_field_t,1);
    f->name = strdup(name);
    return f;
}

int sp_field_free(struct sp_field_t* f) {
    if (f) {
        free(f->name);
        free(f);
    }
    return E_OK;
}

int sp_field_name_get(struct sp_field_t* f, const char** name) {
    if (f == NULL  || name == NULL) return E_ARGUMENT;
    *name = f->name;
    return E_OK;
}


int sp_field_type_set_uint_be(struct sp_field_t* f, size_t width) {
    int rc = E_OK;
    _Ag(f != NULL, E_ARGUMENT);
    _Ag(width >= 1 && width <= 32, E_ARGUMENT);
    f->type = SP_TYPE_UINT_BE;
    f->data = width;
onError:
    return rc;
}

int sp_field_type_set_bool(struct sp_field_t* f) {
    if (f == NULL) return E_ARGUMENT;
    f->type = SP_TYPE_BOOL;
    f->data = 0;
    return E_OK;
}

int sp_field_type_get(struct sp_field_t* f, enum sp_type_t* t) {
    int rc = E_OK;
    _Ag(f != NULL, E_ARGUMENT);
    _Ag(t != NULL, E_ARGUMENT);
    *t = f->type;
onError:
    return rc;
}

