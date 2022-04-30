#include <stdlib.h>
#include <stdio.h>
#include <creator.h>

void	ft_free_matrix(char **split)
{
    int i = 0;
    if (!split)
        return ;
    while(split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

