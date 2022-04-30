/* Lectura del archivo, contamos con que el archivo vendrá bien formateado pq lo hacemos nosotros
 * split con \n es suficiente, para guardar los nombres en un array  de structuras type player:
 * typedef struct s_player
 * {
 * 		short int group;
 * 		int		points;
 * 
 * }
 * t_player		g_player;
 * 
 * Y además habrá un array de 4 para los grupos, cada uno de ellos con un array de sus players y el total de puntos de la coalición
 * Los resultados se mostrarán por pantalla con cada input que le pasemos el imput será comando: "Añadir ", siguiente comando:*/
#include "creator.h"
#include <signal.h>
#include <unistd.h>
t_groups groups[4];
void	rename_backup()
{
	printf ("Bye bye\n");
	system ("mv .backup .backup.bak");
	system ("touch .backup");
	exit(0);
}


int main(int argc, char **argv)
{
	signal(SIGINT, rename_backup);
    int  fd_player_file;
    char *str = NULL;
    char **matrix;
    char    aux_str[1000];

    for(int i = 0; i < 4; i++)
    {
        groups[i].players = NULL;
        groups[i].total_points = 0;
		groups[i].id = i;
		groups[i].size = 0;
    }
   
    if ( argc != 2)
        exit(printf("ERROR ARGUMENTS\n"));

    fd_player_file= open (argv[1], O_RDWR);
    while(get_next_line(fd_player_file, &str))
    {
        matrix= ft_split(str, ' ');
        free(str);
		if (matrix[0] == NULL)
			continue ;
        add_user(matrix);
        free(matrix[1]);
        free(matrix);
    }
    while (1)
    {
		t_player	*sorted_players;

		sorted_players = get_sorted_players();
		display_rank(sorted_players);
		free_player_list(sorted_players);

        printf("INTRODUZCA UN COMANDO :\n");
        while (scanf("%s", aux_str) == -1)
        {
            freopen("/dev/tty", "rw", stdin);
            printf("\nINTRODUZCA UN COMANDO :\n");
        }
        if (!ft_strcmp(aux_str, "ADD_POINTS"))
            ft_add_points();
        else if(!ft_strcmp(aux_str, "ADD_PLAYER"))
            scan_add_user(fd_player_file);
        else if(!ft_strcmp(aux_str, "LIST"))
            scan_add_user(fd_player_file);
        else
            printf("%s : incorrect command\n", aux_str);
    }
    return (0);
}
