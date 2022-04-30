#include <stdio.h>
#include <stdlib.h>
#include <creator.h>

static void add_user_to_file(int fd, char **matrix)
{
	write(fd, "\n", 1);
	write(fd, matrix[0], ft_strlen(matrix[0]));
	write(fd, " ", 1);
	write(fd, matrix[1], ft_strlen(matrix[1]));
	write(fd, "\n", 1);
}

void scan_add_user(int users_file_fd)
{
    char user[100];
    char group[100];
    char *matrix[2];

    printf("Nombre y GRUPO:\n");
    scanf("%s %s", user, group);
    matrix[0] = ft_strdup(user);
    matrix[1]  = group;
    if (add_user(matrix) == true)
		add_user_to_file(users_file_fd, matrix);
}
