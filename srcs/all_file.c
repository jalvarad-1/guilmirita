/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:30:51 by javgonza          #+#    #+#             */
/*   Updated: 2022/04/29 11:46:23 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <creator.h>

char	*all_file(FILE *players_file)
{
    char *buffer = NULL;
    char *real_buffer= NULL;
    char *aux = NULL;
    size_t line_buf_size = 0;
    real_buffer = ft_calloc(1, 1);
    while (getline(&buffer, &line_buf_size, players_file) >0)
    {
        aux = real_buffer;
        real_buffer = ft_strjoin(aux, buffer);
        free(aux);
    }
    return (real_buffer);
}
