#ifndef SPI_BUFFER_H
#define SPI_BUFFER_H

#include "sp_field.h"

struct sp_field_t {
    /** arbitrary name */
    char* name;
    /** the type of the field */
    enum sp_type_t type;
    /** meaning depends on type */
    int data;
};

#endif

