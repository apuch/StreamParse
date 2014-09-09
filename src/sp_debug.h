#ifndef SP_DEBUG_H
#define SP_DEBUG_H

/** \brief Generic error return code */
enum DebugCode_t {
    /** \brief all okay, nothing happened */
    E_OK = 0,
    /** \brief generic error, dont try to use it to often */
    E_ERROR = -1,
    /** \brief invalid argument .. NULL-pointer and such */
    E_ARGUMENT = -2,
    /** \brief out of range */
    E_RANGE = -3,
    /** \brief alignment is wrong */
    E_ALIGNMENT = -4,
};


#endif

