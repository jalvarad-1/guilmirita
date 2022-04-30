/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:02:56 by javgonza          #+#    #+#             */
/*   Updated: 2022/04/29 18:55:10 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <creator.h>

void	ft_add_points()
{
    char buf[200];
	char *str;
    int i;
    t_player *the_player;

    printf("\nINTRODUZCA UN player y puntos:\n");
    while (scanf("%s %i", buf, &i) < 2)
    {
        freopen("/dev/tty", "rw", stdin);
        printf("\nINTRODUZCA UN player y puntos:\n");
    }
	str = ft_strdup(buf);
    the_player = find_player(str);
	if (the_player == NULL)
	{
		printf ("ERROR: The player is not in the list\n");
		return ;
	}
    the_player->points += i;
	the_player->group->total_points += i;


	int		backup_fd;
	char	*points_str;

	backup_fd = open(".backup", O_WRONLY | O_APPEND, 0666);
	if (backup_fd == -1)
		printf ("BACKUP FILE DOES NOT EXIST\n");
	write(backup_fd, "ADD_POINTS", sizeof("ADD_POINTS") - 1);
	write(backup_fd, "\n", 1);
	write(backup_fd, str, ft_strlen(str));
	write(backup_fd, "\n", 1);
	points_str = ft_itoa(i);
	write(backup_fd, points_str, ft_strlen(points_str));
	write(backup_fd, "\n", 1);
	free(points_str);
	close(backup_fd);
}
