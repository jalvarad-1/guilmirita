#include "creator.h"

static void	add_user_to_group(int group_id, char **matrix)
{
	t_groups		*group;
	t_player	*new_player;

	group = &groups[group_id];
	new_player = lstnew(matrix[0]);
	new_player->group = group;
	ft_lstadd_back(&group->players, new_player);
	group->size++;
}

bool	add_user(char **matrix)
{
    if(!ft_strcmp(matrix[1], "ULLOA"))
		add_user_to_group(ULLOA, matrix);
//        ft_lstadd_back(&groups[0].players, lstnew(matrix[0]));
    else if(!ft_strcmp(matrix[1], "CELIA"))
		add_user_to_group(CELIA, matrix);
  //      ft_lstadd_back(&groups[1].players, lstnew(matrix[0]));
    else if(!ft_strcmp(matrix[1], "MORGANA"))
		add_user_to_group(MORGANA, matrix);
    //    ft_lstadd_back(&groups[2].players, lstnew(matrix[0]));
    else if(!ft_strcmp(matrix[1], "JAIME"))
		add_user_to_group(JAIME, matrix);
      //  ft_lstadd_back(&groups[3].players, lstnew(matrix[0]));
    else
    {
        free(matrix[0]);
        printf("INCORRECT GROUP\n");
		return (false);
    }
	return (true);
}
