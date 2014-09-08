#ifndef SP_BUFFER_H
#define SP_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

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

/** \brief create a view of an existing container

*/
int sp_buffer_init_view(struct sp_buffer_t *buff, 
    const struct sp_buffer_t *src, uint64_t offset, uint64_t length);

/** \brief read a bool and advance index by one */
int sp_buffer_read_bool(struct sp_buffer_t *buff, bool* value);

/** \brief read uint and inc. index accordingly */
int sp_buffer_read_uint_be(struct sp_buffer_t *buff, uint64_t* value,size_t s);

#endif

