#include "monty.h"
/**
 * main - program entry
 * @ac: argument count
 * @av: string array of cmdline arguments
 * Return: EXIT_SUCCESS if program runs successfully, else EXIT_FAILURE
 */
int main(int ac, char **av)
{
	FILE *file;
	char *file_path, ch;

	if (ac == 2)
	{
		file_path = av[1];
		printf("File path is: %s\n", file_path);
		/*open file*/
		file = fopen(file_path, "r");
		if (file == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", file_path);
			return (EXIT_FAILURE);
		}
		/*read content*/
		while (!feof(file))
		{
			ch = fgetc(file);
			printf("%c", ch);
		}
		/*close file*/
		fclose(file);
	}
	else    /*arg count is less than or more than 2*/
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
