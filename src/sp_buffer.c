#include <stddef.h>

#include "sp_buffer.h"
#include "debug.h"


int sp_buffer_init(struct sp_buffer_t* buff, const char* data, 
        uint64_t length) {
    int rc = E_OK;
    _Ag(buff != NULL, E_ARGUMENT);
    _Ag(data != NULL, E_ARGUMENT);
    _Ag(length > 0, E_ARGUMENT);

    buff->data = data;
    buff->length = length * 8;
    buff->index = 0;

onError:
    return rc;
}

