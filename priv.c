#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_CONFIG_FILE "/etc/priv.commands"
#define DEFAULT_UID 1000

int main(int argc, char* argv[])
{
	int uid;
	if(argc != 2)
	{
		fprintf(stderr, "Error: priv only takes one argument\n");
		return 1;
	}
	else if(access(DEFAULT_CONFIG_FILE, R_OK) != 0)
	{
		fprintf(stderr, "Error: %s is either not readable or does not exist\n", DEFAULT_CONFIG_FILE);
		return 2;
	}
	else if((uid = getuid()) != DEFAULT_UID)
	{
		fprintf(stderr, "Error: the user executing this program with uid %i does not match the allowed uid %i, permission denied\n", uid, DEFAULT_UID);
		return 3;
	}

	// start reading the file
	FILE* fp;
	fp = fopen(DEFAULT_CONFIG_FILE, "r");
	char temp_array[50], character = 0;

	for(int i = 0; character != EOF; i++)
	{
		character = getc(fp);
		if(character == '\n')
		{
			temp_array[i] = '\0';
			if(strcmp(argv[1], temp_array) == 0)
			{
				setuid(0);
				system(argv[1]);
				return 0;
			}
			else
			{
				i = -1;
			}
		}
		else temp_array[i] = character;
	}

	fprintf(stderr, "Error: the command you entered was not found in %s\n", DEFAULT_CONFIG_FILE);
	return 4;

}
