/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:30:53 by javgonza          #+#    #+#             */
/*   Updated: 2022/04/29 11:46:37 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <creator.h>
void	ft_lstadd_back(t_player **lst, t_player *new)
{
	t_player	*aux;

	if (!*lst)
		*lst = new;
	else
	{
		aux = *lst;
		while (lst)
		{
			if (!aux->next)
			{
				aux->next = new;
				break ;
			}
			aux = aux->next;
		}
	}
}
