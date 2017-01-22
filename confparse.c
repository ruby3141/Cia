#include "confparse.h"

server_t *load_conf(char *confdir)
{
	server_t *serverlist;
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
	return serverlist;
}
