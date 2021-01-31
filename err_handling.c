#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
int
main()
{
	int fd;
	fd = open("./helloopen.txt", O_RDWR);
    //printf("open fd = %d\n", fd);
	printf("open errno = %d\n", errno);
	perror("open");
	char hello[] = "hello open!\n";
	//printf("sizeof(hello array) = %d\n",sizeof(hello));
	int a =	write(fd, hello, sizeof(hello) - 1);
	perror("write");
	close(fd);
	printf("write bytes = %d\n", a);
	printf("errno = %d\n", errno);
	return 0;
}
