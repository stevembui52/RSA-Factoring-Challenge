#include <stdio.h>
#include <stdlib.h>


void factorize(int n)
{
	int i;

	i = 2;
	while (i <= (n / i))
	{
		if (n % i == 0)
		{
			printf("%d=%d*%d\n", n, i, n / i);
		}
		i++;
	}
}

int main(int argc, char *argv[])
{
	int n = 99;
	char *input_file;
	FILE *fd;
	char line[256];

	if (argc < 2)
	{
		printf("Usage: factors %s\n", argv[1]);
		return (1);
	}
	input_file = argv[1];
	fd  = fopen(input_file, "r");
	if (fd == NULL)
	{
		perror("Error opening file");
		return (1);
	}
       	while (fgets(line, sizeof(line), fd) != NULL)
	{
		int n = atoi(line);
		factorize(n);
    	}
	fclose(fd);
	return 0;
}
