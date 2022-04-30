#ifndef CREATOR_H
#define CREATOR_H
#include "../libft/includes/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define ULLOA 0
#define CELIA 1
#define MORGANA 2
#define JAIME   3

#define T1  "🍷🦇MORGANA🦇🍷"
#define T2 "🔥🙅CELIA🙅🔥"
#define T3 "🦢🦹XINEBRA🦹🦢"
#define T4 "🐍👸JOHANNA👸🐍"

#include <stdbool.h>

typedef struct s_groups t_groups;

typedef struct s_player
{
 	char    *name;
 	int		points;
    struct s_player *next;
	t_groups	*group;
}              t_player;

typedef struct s_groups
{
    int total_points;
    t_player *players;
	unsigned short int	id : 2;
	size_t	size;
}               t_groups;

t_groups groups[4];

char	*all_file(FILE *players_file);
t_player	*find_player(char *str);
t_player	*lstnew(char *str);
bool	add_user(char **matrix);
void	ft_add_points();
void	ft_free_matrix(char **split);
void	ft_lstadd_back(t_player **lst, t_player *new);
void scan_add_user(int users_file_fd);
void	display_rank(t_player *win);
void	display_teams(t_groups *team);
t_player	*get_sorted_players();
void	free_player_list(t_player *list);

#endif
