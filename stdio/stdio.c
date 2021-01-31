#include "apue.h"
int
main()
{
//	int c;
//	while ((c = getc(stdin)) != EOF)
//	{
//		putc(c, stdout);
//	}
//	c = getc(stdin);
//	putc(c, stdout);

	int n;
	char buf[10];
	while ((n = read(STDIN_FILENO, buf, 1)) > 0)
	{
		printf("n = %d\n", n);
		for (int i = 0; i < 10; i++)
		{
			putc(buf[i], stdout);
		}
		printf("\n*********************\n");
	}
	exit(0);
}
