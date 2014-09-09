#include <string.h>

#include "spi_field.h"
#include "spi_util.h"
#include "debug.h"


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


