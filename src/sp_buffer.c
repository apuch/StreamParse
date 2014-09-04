#include <stddef.h>

#include "sp_buffer.h"
#include "debug.h"


int sp_buffer_init(struct sp_buffer_t* buff, const void* data, 
        uint64_t length) {
    int rc = E_OK;
    _Ag(buff != NULL, E_ARGUMENT);
    _Ag(data != NULL, E_ARGUMENT);
    _Ag(length > 0, E_ARGUMENT);

    buff->data = data;
    buff->length = length;

onError:
    return rc;
}

