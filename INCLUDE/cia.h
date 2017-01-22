#ifndef CIA
#define CIA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <pthread.h>
#include <netdb.h>
#include <sys/types.h>

#define MAX_LEN 1024

extern char *nickname;
extern char *username;
extern char *realname;

typedef struct server_t
{
	intptr_t socket;
	char *name;
	char *url;
	char *port;
	char *encoding;
	char **channel;
	char **loginscript;
} server_t;

#include "confparse.h"

#endif
