/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 16:53:45 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 15:02:43 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_map	*get_the_map(int f, size_t ref, size_t size_y)
{
	t_map	*list;
	char	*temp;

	if (!(list = malloc(sizeof(t_map))))
		mexit();
	list->prev = NULL;
	while (get_next_line(f, &temp) > 0)
	{
		if (ft_count_and_check(temp, &ref, &list->size_x))
			return (NULL);
		if (!(list->map = tab_atoi(ft_strsplit(temp, ' '), ref)))
			mexit();
		if (!(list->next = malloc(sizeof(t_map))))
			mexit();
		list->next->prev = list;
		list = list->next;
		free(temp);
		size_y++;
	}
	list->next = NULL;
	while (list->prev)
		list = list->prev;
	list->size_y = size_y;
	return (list);
}

void	initial_mtr(t_moniteur *mtr, char *str)
{
	mtr->name = str;
	mtr->backgroundcolor = 0;
	mtr->z = 1;
	mtr->ctr = -0.1;
	mtr->posx = 1;
	mtr->axey = -4.6;
	mtr->axex = 0;
	mtr->posy = 0;
	mtr->projection = 1;
	mtr->mlx_ptr = mlx_init();
	mtr->win_ptr = mlx_new_window(mtr->mlx_ptr, WIN_SIZE_X, WIN_SIZE_Y, str);
	mtr->img_ptr = mlx_new_image(mtr->mlx_ptr, WIN_SIZE_X, WIN_SIZE_Y);
}

int		main(int ac, char **av)
{
	t_moniteur	mtr;
	int			f;

	if (ac == 1 || ac > 2)
		return (usage(av[0], ac));
	else if ((f = open(av[1], O_RDONLY)) == -1)
		return (wrong_file(av[1]));
	else if (read(f, &mtr.name, 0) == -1)
		return (wrong_read(av[1]));
	else if (!(mtr.map = get_the_map(f, 0, 0)))
		return (map_error(av[1]));
	initial_mtr(&mtr, av[1]);
	print_image(&mtr);
	ft_put_user_interface(&mtr);
	mlx_hook(mtr.win_ptr, 2, 1, deal_key, &mtr);
	mlx_mouse_hook(mtr.win_ptr, deal_mouse, &mtr);
	mlx_loop(mtr.mlx_ptr);
	return (0);
}
