#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_WHITELIST_FILE "/etc/priv.commands"
#define ALLOWED_UID 1000
#define DEFAULT_ARRAY_SIZE 50

int main(int argc, char* argv[])
{
	int uid;

	if(argc < 2)
	  {
		fprintf(stderr, "Error: priv needs at least one argument\n");

		return 1;
	  }
	else if(access(DEFAULT_WHITELIST_FILE, R_OK) != 0)
	  {
		fprintf(stderr, "Error: %s is either not readable or does not exist\n", DEFAULT_WHITELIST_FILE);

		return 1;
	  }
	else if((uid = getuid()) != ALLOWED_UID)
	  {
		fprintf(stderr, "Error: the user executing this program with uid %i does not match the allowed uid %i, permission denied\n", uid, ALLOWED_UID);

		return 1;
	  }

	char command[DEFAULT_ARRAY_SIZE];

	memset(command, 0, DEFAULT_ARRAY_SIZE);

	if(argc == 2)
	  {
		strcpy(command, argv[1]);
	  }
	else
	  {
		for(int i = 1; i < argc; i++)
		  {
			strcat(command, argv[i]);

			if(i != (argc-1)) strcat(command, " ");
		  }
	  }

	// start reading the file
	FILE* fp;

	fp = fopen(DEFAULT_WHITELIST_FILE, "r");

	char temp_array[DEFAULT_ARRAY_SIZE], character = 0;

	for(int i = 0; character != EOF; i++)
	  {
		character = getc(fp);

		if(character == '\n')
		  {
			temp_array[i] = '\0';

			if(strcmp(command, temp_array) == 0)
			  {
				setuid(0);

				system(command);

				return 0;
			  }
			else
			  {
				i = -1;
			  }
		  }

		else temp_array[i] = character;
	  }

	fprintf(stderr, "Error: the command you entered was not found in %s\n", DEFAULT_WHITELIST_FILE);

	return 1;

}
