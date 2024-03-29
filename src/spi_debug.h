#ifndef SPI_DEBUG_H
#define SPI_DEBUG_H

#include "sp_debug.h"

void _debug_tr_log(const char* file, int line, int level, const char* msg, ...);

#define LOG_LEVEL_NONE  0
#define LOG_LEVEL_CRIT  1
#define LOG_LEVEL_ERR   2
#define LOG_LEVEL_INFO  3
#define LOG_LEVEL_DEBUG 4
#define LOG_LEVEL_SPAM  5

#ifndef LOG_LEVEL
    #ifndef LOG_LEVEL_DEF
    #define LOG_LEVEL LOG_LEVEL_INFO
    #else
    #define LOG_LEVEL LOG_LEVEL_DEF
    #endif
#endif

#define __TRACE(lvl, ...) \
    _debug_tr_log( __FILE__, __LINE__, lvl, __VA_ARGS__)

#if LOG_LEVEL >= 1
#define TR_CRIT(...) __TRACE(1, __VA_ARGS__)
#else 
#define TR_CRIT(...)
#endif

#if LOG_LEVEL >= 2
#define TR_ERR(...) __TRACE(2, __VA_ARGS__)
#else 
#define TR_ERR(...)
#endif

#if LOG_LEVEL >= 3
#define TR_INFO(...) __TRACE(3, __VA_ARGS__)
#else 
#define TR_INFO(...)
#endif

#if LOG_LEVEL >= 4
#define TR_DEBUG(...) __TRACE(4, __VA_ARGS__)
#else 
#define TR_DEBUG(...)
#endif

#if LOG_LEVEL >= 5
#define TR_SPAM(...) __TRACE(5, __VA_ARGS__)
#else 
#define TR_SPAM(...)
#endif


#define _E(x) do { int rc = x; \
                   if (rc < E_OK) { \
                       TR_ERR("%s failed with %d", #x, rc); \
                   }\
                } while (0)

#define _Eg(x) do { int rc = x; \
                   if (rc < E_OK) { \
                       TR_ERR("%s failed with %d", #x, rc); \
                       goto onError; \
                   }\
                } while (0)

#define _Ag(x, code) do { int _rc = (x); \
                   if (!_rc) { \
                       TR_ERR("assertion %s failed", #x); \
                       rc = code; \
                       goto onError; \
                   }\
                } while (0)

#endif
