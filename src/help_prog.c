/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   help_prog.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 17:11:51 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 11:33:13 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	show_t_map(t_map *map)
{
	size_t	i;
	int		j;

	ft_putstr("  ");
	ft_putnbr(map->size_x);
	ft_putstr("--");
	ft_putnbr(map->size_y);
	ft_putchar('\n');
	while (map->next)
	{
		i = 0;
		while (i < map->size_x)
		{
			j = ft_nbrlen(map->map[i]);
			if (map->map[i] >= 0)
				ft_putchar(' ');
			if (j == 0)
				ft_putchar(' ');
			ft_putnbr(map->map[i]);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		map = map->next;
	}
}

int		*tab_atoi(char **tab, int size)
{
	int		*tabint;
	int		i;

	i = -1;
	if (!(tabint = malloc(sizeof(int) * size)))
		mexit();
	while (++i < size)
	{
		tabint[i] = ft_atoi(tab[i]);
		free(tab[i]);
	}
	free(tab);
	return (tabint);
}

void	print_image(t_moniteur *mtr)
{
	mlx_destroy_image(mtr->mlx_ptr, mtr->img_ptr);
	mlx_clear_window(mtr->mlx_ptr, mtr->win_ptr);
	mtr->img_ptr = mlx_new_image(mtr->mlx_ptr, WIN_SIZE_X, WIN_SIZE_Y);
	mlx_get_data_addr(mtr->img_ptr, &mtr->bpp, &mtr->s_l, &mtr->endian);
	mtr->image_string = mlx_get_data_addr(mtr->img_ptr, &(mtr->bpp),
										&(mtr->s_l), &(mtr->endian));
	ft_putmap(mtr);
	mlx_put_image_to_window(mtr->mlx_ptr, mtr->win_ptr,
							mtr->img_ptr, 0, 0);
	ft_put_user_interface(mtr);
}

void	ft_set_color(t_moniteur *mtr, int n1)
{
	n1 < 1 ? mtr->font_color = 255 : 0;
	n1 >= 1 && n1 <= 6 ? mtr->font_color = 16777062 : 0;
	n1 > 6 && n1 <= 15 ? mtr->font_color = 13434675 : 0;
	n1 >= 16 && n1 <= 27 ? mtr->font_color = 39219 : 0;
	n1 >= 28 && n1 <= 55 ? mtr->font_color = 3368448 : 0;
	n1 >= 56 && n1 <= 90 ? mtr->font_color = 6710835 : 0;
	n1 > 90 && n1 <= 110 ? mtr->font_color = 6697728 : 0;
	n1 > 110 && n1 <= 130 ? mtr->font_color = 5057289 : 0;
	n1 > 130 && n1 <= 170 ? mtr->font_color = 10066278 : 0;
	n1 > 170 && n1 <= 210 ? mtr->font_color = 9340542 : 0;
	n1 > 210 && n1 <= 240 ? mtr->font_color = 11972521 : 0;
	n1 > 240 && n1 <= 320 ? mtr->font_color = 16184562 : 0;
	n1 > 320 && n1 <= 350 ? mtr->font_color = 16578805 : 0;
	n1 > 280 ? mtr->font_color = 16777215 : 0;
}
