//copy from src to dest

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv)
{	
	int ch = 0;
	FILE* src = NULL;
	FILE* dest = NULL;

	if(argc != 3)
	{
		fprintf(stderr, "Usage: ./myls src dest!\n");
		exit(1);
	}

	src = fopen(argv[1], "r");
	if(src == NULL)
	{
		fclose(src);
		perror("fopen()");
		exit(1);
	}

	dest = fopen(argv[2], "w");
	if(dest == NULL)
	{
		fclose(dest);
		perror("fopen()");
		exit(1);
	}

	while(1)
	{
		ch = fgetc(src);
		if(ch == EOF)
			break;
		fputc(ch, dest);
	}

	fclose(dest);
	fclose(src);

	exit(0);
}
