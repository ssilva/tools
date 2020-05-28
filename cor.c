#define _GNU_SOURCE // For getline(), strsep()
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define RED		"\x1B[31m"
#define GREEN	"\x1B[32m"
#define YELLOW	"\x1B[33m"
#define BLUE	"\x1B[34m"
#define MAGENTA	"\x1B[35m"
#define CYAN	"\x1B[36m"
#define WHITE	"\x1B[37m"
#define RESET	"\x1B[0m"
#define NUM_OF_COLORS 6

// Colorize stdin
//
// $ gcc -std=c11 -Wall -Wextra -Wpedantic -O2 -o cor cor.c
// $ some-other-program | ./cor
//
int main()
{
	const char delim[] = " "; // can be multiple chars
	const char *colors[NUM_OF_COLORS] = {RED, GREEN, YELLOW, BLUE, MAGENTA, WHITE};

	char *line = NULL;
	size_t size;

	while (getline(&line, &size, stdin) >= 0)
	{
		char *token = NULL;
		uint8_t i = 0;

		while ((token = strsep(&line, delim)))
		{
			if (i != 0) printf(delim);
			printf("%s%s", colors[i], token);
			
			if (i < NUM_OF_COLORS - 1) i++;
		}
	}

	printf(RESET);

	return 0;
}
