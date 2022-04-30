/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sorted_players.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:17:36 by javgonza          #+#    #+#             */
/*   Updated: 2022/04/29 18:18:08 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <creator.h>
#include <limits.h>

static t_player	*get_highest_score_player()
{
	size_t		i;
	int			highest_score;
	t_player	*list_pointer;
	t_player	*p;

	highest_score = groups[0].players->points;
	p = groups[0].players;
	i = 0;
	while (i < 4)
	{
		list_pointer = groups[i].players;
		while (list_pointer != NULL)
		{
			if (list_pointer->points > highest_score)
			{
				highest_score = list_pointer->points;
				p = list_pointer;
			}
			list_pointer = list_pointer->next;
		}
		i++;
	}
	return (p);
}

static bool	check_player_exists_in_list(t_player *p, t_player *list)
{
	while (list != NULL)
	{
		if (ft_strcmp(p->name, list->name) == 0)
			return (true);
		list = list->next;
	}
	return (false);
}

static t_player	*get_highest_score_player_under_score_and_not_in_list(int limit, t_player *list)
{
	size_t		i;
	int			highest_score;
	t_player	*list_pointer;
	t_player	*p;

	highest_score = INT_MIN;
	i = 0;
	while (i < 4)
	{
		list_pointer = groups[i].players;
		while (list_pointer != NULL)
		{
			if (list_pointer->points >= highest_score && list_pointer->points <= limit && check_player_exists_in_list(list_pointer, list) == false)
			{
				highest_score = list_pointer->points;
				p = list_pointer;
			}
			list_pointer = list_pointer->next;
		}
		i++;
	}
	return (p);
}

t_player	*get_sorted_players()
{
	t_player	*sorted_players;
	t_player	*player;
	t_player	*new_player;
	size_t		i;
	int			high_score;
	t_player	*list_pointer;

	player = get_highest_score_player();
	new_player = lstnew(player->name);
	new_player->points = player->points;
	new_player->group = player->group;
	sorted_players = new_player;
	high_score = new_player->points;

	i = 0;
	while (i < 4)
	{
		list_pointer = groups[i].players;
		while (list_pointer != NULL)
		{
			if (i == 3 && list_pointer->next == NULL) //Todos sabemos por que esto esta aqui
				break ;
			player = get_highest_score_player_under_score_and_not_in_list(high_score, sorted_players);
			high_score = player->points;
			new_player = lstnew(player->name);
			new_player->points = player->points;
			new_player->group = player->group;
			ft_lstadd_back(&sorted_players, new_player);
			list_pointer = list_pointer->next;
		}
		i++;
	}
	return (sorted_players);
}
