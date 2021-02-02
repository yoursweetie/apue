//2021-02-02
//calculate the size of file
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv)
{
    int count = 0;
    FILE* fp = NULL;

    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        exit(0);
    }

    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        fclose(fp);
        perror("fopen()");
        exit(1);
    }

    while(fgetc(fp) != EOF)
    {
        count++;
    }
    fprintf(stdout, "%s size = %dbyte(s)\n", argv[1], count);

    fclose(fp);

    exit(1);
}
