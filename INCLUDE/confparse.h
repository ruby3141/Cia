#ifndef CONFPARSE
#define CONFPARSE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <sys/types.h>
#include "cia.h"
#include "jsmn.h"


server_t *load_conf(char *confdir);

#endif
