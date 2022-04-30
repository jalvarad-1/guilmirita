/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_player_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:19:40 by javgonza          #+#    #+#             */
/*   Updated: 2022/04/29 18:24:56 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <creator.h>

void	free_player_list(t_player *list)
{
	t_player	*list_pointer;
	t_player	*next_pointer;

	list_pointer = list;
	while (list_pointer != NULL)
	{
		next_pointer = list_pointer->next;
		free(list_pointer);
		list_pointer = next_pointer;
	}
}
