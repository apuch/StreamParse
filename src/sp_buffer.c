#include <stddef.h>

#include "sp_buffer.h"
#include "debug.h"

static int read_bool(struct sp_buffer_t *buff) {
    int r = buff->data[buff->index / 8] & (1 << (7 - (buff->index & 0x7)));
    buff->index += 1;
    return r ? 1 : 0;
}

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

int sp_buffer_init_view(struct sp_buffer_t *buff, 
        const struct sp_buffer_t *src, uint64_t offset, uint64_t length) {
    int rc = E_OK;
    _Ag(buff != NULL, E_ARGUMENT);
    _Ag(src != NULL, E_ARGUMENT);
    _Ag((offset & 0x07) == 0 && (length & 0x07) == 0, E_ALIGNMENT);
    _Ag(offset + length <= src->length, E_RANGE);

    buff->length = length;
    buff->data = src->data + offset / 8;
    buff->index = 0;


onError:
    return rc;
}

int sp_buffer_read_bool(struct sp_buffer_t *buff, bool* value) {
    int rc = E_OK;
    _Ag(buff != NULL, E_ARGUMENT);
    _Ag(value != NULL, E_ARGUMENT);
    _Ag(buff->index < buff->length, E_RANGE);
    *value = read_bool(buff);
onError:
    return rc;
}

int sp_buffer_read_uint_be(struct sp_buffer_t *buff,uint64_t* value,size_t s) {
    int rc = E_OK;
    _Ag(buff != NULL, E_ARGUMENT);
    _Ag(s > 0 && s <= 64, E_ARGUMENT);
    _Ag(buff->index + s <= buff->length, E_RANGE);
    *value = 0;
    while ((buff->index & 0x07) != 0 && s > 0) {
        *value = (*value << 1) + read_bool(buff);
        s -= 1;
    }
    while (s >= 8) {
        *value = (*value << 8) + buff->data[buff->index / 8];
        buff->index += 8;
        s -= 8;
    }
    while (s > 0) {
        *value = (*value << 1) + read_bool(buff);
        s -= 1;
    }
    
onError:
    return rc;
}
