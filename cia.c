#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <pthread.h>
#include <netdb.h>
#include <sys/types.h>
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
server_t *load_conf(char *confdir);

int main(int argc, char *argv[])
{
	char buf[MAX_LEN+1];
	char *confdir = "./config.json";
	server_t *serverlist;

	//commandline argument parsing.
	if(argc > 1) for(int64_t i = 1; i < argc ;i++)
	{
		if(!strcmp(argv[i], "-c") || !strcmp(argv[i], "--config"))
		{
			if(i + 1 < argc) {confdir = argv[i+1]; i++;}
			else {printf("Error : not enough parameter given for %s.\n", argv[i]); abort();}
		}
		else {printf("Error : %s is not a valid argument.\n", argv[i]); abort();}
	}

	serverlist = load_conf(confdir);
}

server_t *load_conf(char *confdir)
{
	server_t **serverlist;
	jsmn_parser parser;
	jsmntok_t *tokens;
	FILE *cf;
	off_t filesize;
	int64_t toknum, servercounter;
	char *buf;

	cf = fopen(confdir, "r");
	if(cf == NULL)
	{
		printf("Error : config file %s cannot be opened.\n",confdir);
		abort();
	}
	fseeko(cf, 0, SEEK_END);
	filesize = ftello(cf);
	fseeko(cf, 0, SEEK_SET);
	buf = (char *)malloc(sizeof(char) * filesize);
	if(!fread(buf, sizeof(char), filesize, cf))
	{
		printf("Error : config file %s cannot be readed.\n", confdir);
	}
	jsmn_init(&parser);
	toknum = jsmn_parse(&parser, buf, strlen(buf), NULL, 256);
	tokens = (jsmntok_t *)malloc(sizeof(jsmntok_t) * toknum);
	jsmn_init(&parser);
	jsmn_parse(&parser, buf, strlen(buf), tokens, toknum);

	serverlist = (server_t *)malloc(sizeof(server_t) * (tokens[0].size-1));
	servercounter = 0;
	for(int64_t i = 0; i < toknum; i++)
	{
		//some parsing codes here
	}

	fclose(cf);
	free(buf);
	free(tokens);
	return NULL;
}
