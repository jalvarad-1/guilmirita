/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:30:47 by javgonza          #+#    #+#             */
/*   Updated: 2022/04/29 18:12:04 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <creator.h>

static t_player *find_name_in_list(t_player *player_group, char *name)
{
	t_player	*found_player;

	found_player = player_group;
    while(found_player)
    {
        if (!ft_strcmp(found_player->name, name))
            return(found_player);
        found_player = found_player->next;
    }
	return (NULL);
}

t_player	*find_player(char *str)
{
	size_t	i;
    t_player *player;

	i = 0;
	while (i < 4)
	{
		printf("\nOK to here %d!\n", groups[i].total_points);
		player = find_name_in_list(groups[i].players, str);
		if (player != NULL) 
			return (player);
		i++;
	}
	return (NULL);
}
