#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <pthread.h>
#include <netdb.h>
#include "jsmn.h"

#define MAX_LEN 1024

char *nickname;
char *username;
char *realname;

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

//function prototypes
server_t **load_conf(char *confdir);

int main(int argc, char *argv[])
{
	char buf[MAX_LEN+1];
	char *confdir = "./config.json";
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

	//serverlist = load_conf(confdir);
}
