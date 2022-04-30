/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:30:55 by javgonza          #+#    #+#             */
/*   Updated: 2022/04/29 11:46:45 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <creator.h>
t_player	*lstnew(char *str)
{
    t_player	*a;

	a = malloc(sizeof(t_player));
	if (!a)
		return (NULL);
	a->name = str;
    a->points = 0;
	a->next = NULL;
	return (a);
}
