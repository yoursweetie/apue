#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int
main()
{
    int fp;
    while((fp = open("testfp", O_CREAT | O_RDWR | O_TRUNC, 0666)) > 0)
    //while((fp = creat("./testfp", 0666)) > 0)
    {
        printf("fd = %d\n", fp);
    }

    return 0;
}
