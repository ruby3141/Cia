#include "cia.h"

char *nickname;
char *username;
char *realname;

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
