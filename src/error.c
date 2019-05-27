/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 12:45:55 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 11:22:08 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		wrong_file(char *file_name)
{
	ft_putstr("Impossible to open ");
	ft_putendl(file_name);
	return (1);
}

int		wrong_read(char *file_name)
{
	ft_putstr("Impossible to read ");
	ft_putendl(file_name);
	return (1);
}

int		usage(char *prog_name, int ac)
{
	if (ac == 1)
	{
		ft_putstr("usage: ");
		ft_putstr(prog_name);
		ft_putendl(" fdf_maps");
	}
	else
	{
		ft_putstr(prog_name);
		ft_putendl(" too many arguments");
	}
	return (1);
}

int		map_error(char *map_name)
{
	ft_putstr(map_name);
	ft_putendl(" is not a fdf's map");
	return (1);
}

void	mexit(void)
{
	ft_putendl("an error occured");
	exit(1);
}
