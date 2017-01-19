#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <pthread.h>
#include <netdb.h>
#include "jsmn.h"

#define MAX_LEN 1024

int8_t *nickname;
int8_t *username;
int8_t *realname;

typedef struct server_t
{
	intptr_t socket;
	int8_t *name;
	int8_t *url;
	int8_t *port;
	int8_t *encoding;
	int8_t **channel;
	int8_t **loginscript;
} server_t;

//function prototypes
server_t **load_conf(int8_t *confdir);

int64_t main(int64_t argc, int8_t *argv[])
{
	int8_t buf[MAX_LEN+1];
	int8_t *confdir = "./config.json"
	server_t **serverlist;

	//commandline argument parsing.
	if(argc > 1) for(int64_t i = 1; i < argc ;i++)
	{
		if(!strcmp(argv[i], "-c") || !strcmp(argv[i], "--config"))
		{
			if(i + 1 < argc) {confdir = argv[i+1]; i++;}
			else {printf("Error : not enough parameter given for %s.\n", argv[i]); return 1;}
		}
		else {printf("Error : %s is not a valid argument.\n", argv[i]); return 1;}
	}

	serverlist = load_conf(confdir);
}
