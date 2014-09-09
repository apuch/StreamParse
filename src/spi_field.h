#ifndef SPI_BUFFER_H
#define SPI_BUFFER_H

#include "sp_field.h"

struct sp_field_t {
    char* name;
    enum sp_type_t type;
    size_t offset;
};

#endif

