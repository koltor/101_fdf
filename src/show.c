/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   show.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 12:18:36 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 16:02:32 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int			fill_pixel(t_moniteur *mtr, int x, int y)
{
	int pos;

	pos = WIN_SIZE_X * (y + mtr->posy) * 4 + (x + mtr->posx) * 4;
	if (pos > 0 && pos < WIN_SIZE_X * WIN_SIZE_Y * 4 &&
		((x + mtr->posx) * 4) < WIN_SIZE_X * 4 && ((x + mtr->posx) * 4) > 0)
	{
		(mtr->image_string)[pos + 2] = mtr->font_color / 256 / 256; //r
		(mtr->image_string)[pos + 1] = mtr->font_color / 256; // v
		(mtr->image_string)[pos] = mtr->font_color % 256; //b
		return (0);
	}
	return (1);
}

static void	ft_putline(t_moniteur *mtr, t_map *map, int i, int j)
{
	double		n[4];
	int			ofs[2];

	ofs[0] = WIN_SIZE_X / 2 - mtr->z * 5;
	ofs[1] = WIN_SIZE_Y / 2 - mtr->z * 10;
	if (j + 1 < (int)map->size_x)
	{
		n[0] = (j * mtr->z - (map->size_x) + mtr->map->map[j] * mtr->ctr) + ofs[0];
		n[1] = (i * mtr->z - (map->size_y) + mtr->map->map[j] * mtr->ctr) + ofs[1];
		n[2] = ((j + 1) * mtr->z - map->size_x + mtr->map->map[j + 1] * mtr->ctr) + ofs[0];
		n[3] = (i * mtr->z - map->size_y + mtr->map->map[j + 1] * mtr->ctr) + ofs[1];
		algo_bresenham(n, mtr);
	}
	if (i + 1 < (int)map->size_y)
	{
		n[0] = (j * mtr->z - (map->size_x) + mtr->map->map[j] * mtr->ctr) + ofs[0];
		n[1] = (i * mtr->z - (map->size_y) + mtr->map->map[j] * mtr->ctr) + ofs[1];
		n[2] = (j * mtr->z - map->size_x + mtr->map->next->map[j] * mtr->ctr) + ofs[0];
		n[3] = ((i + 1) * mtr->z - map->size_y + mtr->map->next->map[j] * mtr->ctr) + ofs[1];
		algo_bresenham(n, mtr);
	}
}

static void	ft_putline_iso(t_moniteur *mtr, t_map *map, int i, int j)
{
	double		n[4];
	int			ofsx;
	int			ofsy;

	ofsx = WIN_SIZE_X / 2 - map->size_x / 2;
	ofsy = WIN_SIZE_Y / 2;
	if (j + 1 < (int)map->size_x)
	{
		n[0] = (-i * mtr->z + j * mtr->z) + ofsx;
		n[1] = (i * mtr->z * 2 / 3 + j * mtr->z * 2 / 3 - mtr->map->map[j] * -mtr->ctr) + ofsy;
		n[2] = (-i * mtr->z + (j + 1) * mtr->z) + ofsx;
		n[3] = (i * mtr->z * 2 / 3 + (j + 1) * mtr->z * 2 / 3 - mtr->map->map[j] * -mtr->ctr) + ofsy;
		algo_bresenham(n, mtr);
	}
	if (i + 1 < (int)map->size_y)
	{
		n[0] = (-i * mtr->z + j * mtr->z) + ofsx;
		n[1] = (i * mtr->z * 2 / 3 + j * mtr->z * 2 / 3 - mtr->map->map[j] * -mtr->ctr) + ofsy;
		n[2] = (-(i + 1) * mtr->z + j * mtr->z) + ofsx;
		n[3] = ((i + 1) * mtr->z * 2 / 3 + j * mtr->z * 2 / 3 - mtr->map->next->map[j] * -mtr->ctr) + ofsy;
		algo_bresenham(n, mtr);
	}
}

void		ft_putmap(t_moniteur *mtr)
{
	int			i;
	int			j;
	t_map		*map;

	i = -1;
	map = mtr->map;
	while (++i < (int)map->size_y)
	{
		j = -1;
		while (++j < (int)map->size_x)
		{
			ft_set_color(mtr, mtr->map->map[j]);
			if (mtr->projection == 2)
				ft_putline(mtr, map, i, j);
			else
				ft_putline_iso(mtr, map, i, j);
		}
		mtr->map = mtr->map->next;
	}
	mtr->map = map;
}

void		ft_put_user_interface(t_moniteur *mtr)
{
	int		color;
	void	*mp;
	void	*wp;

	mp = mtr->mlx_ptr;
	wp = mtr->win_ptr;
	color = 16777215;
	mlx_string_put(mp, wp, 10, 10, color, mtr->name);
	mlx_string_put(mp, wp, 10, 40, color, "changer de projection: tab |");
	mlx_string_put(mp, wp, 300, 40, color, ft_itoa(mtr->projection));
	mlx_string_put(mp, wp, 10, 70, color, "niveau de contraste: +\\-   |");
	mlx_string_put(mp, wp, 300, 70, color, ft_itoa(-mtr->ctr));
	mlx_string_put(mp, wp, 10, 100, color, "zoom: molette              |");
	mlx_string_put(mp, wp, 300, 100, color, ft_itoa(mtr->z));
	mlx_string_put(mp, wp, 10, 130, color, "se deplacer: HGBD          |");
	mlx_string_put(mp, wp, 10, 160, color, "reinitialiser: R           |");
	mlx_string_put(mp, wp, 10, 190, color, "rotationX: D\\S             |");
	mlx_string_put(mp, wp, 300, 190, color, ft_itoa(mtr->axex));
}
