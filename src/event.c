/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 15:18:28 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 15:37:26 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void	deal_key2(int key, t_moniteur *mtr)
{
	if (key == 15)
	{
		mtr->posx = 0;
		mtr->posy = 0;
		mtr->axey = -4.6;
		mtr->axex = 0;
		mtr->ctr = -0.1;
		mtr->z = 1;
	}
	else if (key == 48)
	{
		if (mtr->projection == 1)
			mtr->projection = 2;
		else
			mtr->projection = 1;
	}
	else if (key == 53)
		exit(1);
}

int			deal_key(int key, t_moniteur *mtr)
{
	if (key == 69)
		mtr->ctr -= 0.1;
	else if (key == 78)
		mtr->ctr += 0.1;
	else if (key == 126)
		mtr->posy -= 10;
	else if (key == 125)
		mtr->posy += 10;
	else if (key == 123)
		mtr->posx -= 10;
	else if (key == 124)
		mtr->posx += 10;
	else if (key == 13)
		mtr->axey += 0.2;
	else if (key == 1)
		mtr->axey -= 0.2;
	else if (key == 0)
		mtr->axex += 0.2;
	else if (key == 2)
		mtr->axex -= 0.2;
	else
		deal_key2(key, mtr);
	print_image(mtr);
	return (0);
}

int			deal_mouse(int button, int x, int y, t_moniteur *mtr)
{
	x = 0;
	y = 0;
	if (button == 5)
	{
		mtr->z += 0.1;
		print_image(mtr);
	}
	else if (button == 4)
	{
		mtr->z -= 0.1;
		print_image(mtr);
	}
	return (0);
}
