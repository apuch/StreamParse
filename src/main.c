#include <stdio.h>
#include "debug.h"

static int do_fail() {
    return E_ERROR;
}

static int do_win() {
    return E_OK;
}

int main(int argc, char** argv) {
    printf("Hello, World\n");
    _E(do_fail());
    _E(do_win());

    TR_CRIT("crit");
    TR_ERR("err");
    TR_INFO("info");
    TR_DEBUG("debug");
    TR_SPAM("spam");
    
    return 0;
}

