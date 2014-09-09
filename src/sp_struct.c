#include <containers.h>

#include "sp_struct.h"
#include "spi_util.h"
#include "debug.h"


struct sp_struct_t {
    char* name;
    Vector* fields;
};

struct sp_struct_t* sp_struct_init(const char* name) {
    int rc = E_OK;
    struct sp_struct_t* s = NULL;
    _Ag(name != NULL, E_ARGUMENT);
    s = _CALLOC(struct sp_struct_t, 1);
    s->fields = iVector.Create(sizeof(struct sp_field_t), 5);
    s->name = strdup(name);

onError:
    if (rc != 0) {
        sp_struct_free(s);
        s = NULL;
    }
    return s;
}

int sp_struct_free(struct sp_struct_t *s) {
    if (s != NULL) {
        iVector.Finalize(s->fields);
        free(s->name);
        free(s);
    }
    return E_OK;
}
