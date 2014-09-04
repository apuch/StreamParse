#ifndef SP_BUFFER_H
#define SP_BUFFER_H

#include <stdint.h>

struct sp_buffer_t {
    /** \brief pointer to the data */
    const void* data;
    /** \brief size in bytes */
    uint64_t length;
};

/** \brief initialize buffer struct */
int sp_buffer_init(struct sp_buffer_t* buff, const void* data, 
        uint64_t length);


#endif

