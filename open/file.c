#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFSIZE 1024

int
main(int argc, char **argv)
{
    int fp_src = 0;
    int fp_dest = 0;
    //char *src = argv[1];
    //char *dest = argv[2];
    ssize_t nbytes = 0;
    char *buf[BUFFSIZE];

    if (argc != 3)
    {
        fprintf(stdout, "usage: %s src_file dest_file\n", argv[0]);
        exit(1);
    }

    if ((fp_src = open(argv[1], O_RDWR)) < 0)
    {
        perror("open_src()");
        exit(1);
    }

    if ((fp_dest = creat(argv[2], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
    {
        perror("creat_dest()");
        exit(1);
    }

    while ((nbytes = read(fp_src, buf, BUFFSIZE)) > 0)
    {
        //write(STDOUT_FILENO, buf, nbytes);
        write(fp_dest, buf, nbytes);
    }

    close(fp_dest);
    close(fp_src);
    exit(0);
}
