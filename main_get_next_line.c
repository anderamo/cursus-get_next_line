/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:42:07 by aamorin-          #+#    #+#             */
/*   Updated: 2021/06/10 12:18:38 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int	get_next_line(int fd, char **line);

/*
int	main(int argc, char **argv)
{
	int		fd;
	char	*text = 0;

	fd = open(argv[1], O_RDONLY, 0);
	printf("%d", get_next_line(fd, &text));
	return (0);
}
*/
int main()
{
	int             fd;
	int             i;
	int             j;
	char    *line = 0;
	char    *lineadress[66];
	j = 1;
	printf("\n==========================================\n");
	printf("========== TEST 1 : The Alphabet =========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/alphabet", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		lineadress[j - 1] = line;
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	printf("%d",j);
	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 66)
		printf("\nRight number of lines\n");
	else if (j != 66)
		printf("\nNot Good - Wrong Number Of Lines\n");
	while (--j > 0)
		free(lineadress[j - 1]);
	j = 1;

	printf("\n==========================================\n");
	printf("========= TEST 2 : Empty Lines ===========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/empty_lines", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	printf("%d",j);
	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 9)
		printf("\nRight number of lines\n");
	else if (j != 9)
		printf("\nNot Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("======== TEST 3 : The Empty File =========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/empty_file", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	printf("%d",j);
	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 1)
		printf("\nRight number of lines\n");
	else if (j != 1)
		printf("\nNot Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("========= TEST 4 : One New Line ==========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/1_newline", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	printf("%d",j);
	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 2)
		printf("\nRight number of lines\n");
	else if (j != 2)
		printf("\nNot Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("========= TEST 5 : Four New Lines ========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/4_newlines", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	printf("%d",j);
	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 5)
		printf("\nRight number of lines\n");
	else if (j != 5)
		printf("\nNot Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("============== TEST 6 : 42 ===============\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/41_char", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	if (!(fd = open("files/42_char", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{

		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	if (!(fd = open("files/43_char", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	printf("%d",j);
	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 1)
		printf("\nRight number of lines\n");
	else if (j != 1)
		printf("\nNot Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("============= TEST 7 : Marge =============\n");
	printf("==========================================\n\n");

	int fd2;

	if (!(fd = open("files/mix_marge1", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	if (!(fd2 = open("files/mix_marge2", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while (j < 8)
	{
		if ((i = get_next_line(fd, &line)) > 0)
			printf("%s\n", line);
		free(line);
		j++;
	}
	while (j < 13)
	{
		if ((i = get_next_line(fd2, &line)) > 0)
			printf("%s\n", line);
		free(line);
		j++;
	}
	if ((i = get_next_line(fd, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd2, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd2, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd2, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	while (j < 23)
	{
		if ((i = get_next_line(fd2, &line)) > 0)
			printf("%s\n", line);
		free(line);
		j++;
	}
	get_next_line(fd2, &line);
	printf("%s\n", line);
	free(line);
	j++;
	while (j < 25)
	{
		if ((i = get_next_line(fd, &line)) > 0)
			printf("%s\n", line);
		free(line);
		j++;
	}
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	close(fd);
	close(fd2);
	printf("%d",j);
	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 25)
		printf("\nRight number of lines\n");
	else if (j != 25)
		printf("\nNot Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("========= TEST 8 : Wrong Input ===========\n");
	printf("==========================================\n\n");

	if (get_next_line(180, &line) == -1)
		printf("Well Done, you return -1 if read fails\n\n");
	else
		printf("Not Good, you don't return -1 if read fails\n\n");
	return (0);
}
