#include <creator.h>

//🦉🦂🔪⚔

#define C1_BLUE "\033[0;36m"
#define C2_YEL "\033[1;33m"
#define C3_PURP "\033[0;35m"
#define C4_GREEN "\033[0;32m"
#define RESET "\033[0m"

static void blue(void) 
{
  printf(C1_BLUE);
}
static void yellow(void)
{
  printf(C2_YEL);
}
static void green(void)
{
  printf(C4_GREEN);
}
static void purple(void)
{
  printf(C3_PURP);
}
static void reset (void) 
{
  printf(RESET);
}

static void send_message(int index, char *name, int points, int team_id)
{
	char *array_teams[4]		= {T1, T2, T3, T4};
	void (*array_ptr[5])(void)	= {&purple, &green, &blue, &yellow, &reset};

	if (index == 1)
	{
		(array_ptr[team_id])();
		printf("[ %2i ] %25s va ganando con %i puntos. 🔪🦂¡Dadle picanegra!🦂🔪 \n", index, name, points);
		printf("     -----------------------------------------------------------------\n");
		(array_ptr[4])();
		return ;
	}
	(array_ptr[team_id])();
	printf("[ %2i ] %25s con %4i puntos.  ---Equipo: %25s ---\n", index, name, points, array_teams[team_id]);
	printf("     -----------------------------------------------------------------\n");
	(array_ptr[4])();
}

void	display_rank(t_player *win)
{
	int index;

	index = 0;
	while(win)
	{
		index++;
		send_message(index, win->name, win->points, win->group->id);		
		win = win->next;
	}
}

void	display_teams(t_groups *team)
{
	char *array_teams[4] = {T1, T2, T3, T4};

	printf("	🛡  Equipo: %s en cabeza con %i puntos  🛡	\n", array_teams[team->id], team->total_points);
}

/*
int main(void)
{
	t_groups *mor;
	t_groups *xin;
	
	t_player *win;
	t_player *win1;

	mor = ft_calloc(1, sizeof(t_groups));
	mor->id = 0;
	win = ft_calloc(1, sizeof(t_player));
	win->group = mor;
	win->name = NULL;
	win->next = NULL;

	xin = ft_calloc(1, sizeof(t_groups));
	xin->id = 2;
	win1 = ft_calloc(1, sizeof(t_player));
	win1->name = NULL;
	win1->next = NULL;
	win1->group = xin;

	win->next = win1;

	display_teams(mor);
	display_rank(win);

	return (0);
}
*/
