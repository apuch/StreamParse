#ifndef SP_BUFFER_H
#define SP_BUFFER_H

#include <stdint.h>

struct sp_buffer_t {
    /** \brief pointer to the data */
    const char* data;
    /** \brief size in bits */
    uint64_t length;
    /** \brief index in bits */
    uint64_t index;
};

/** \brief initialize buffer struct */
int sp_buffer_init(struct sp_buffer_t* buff, const char* data, 
        uint64_t length);


#endif

