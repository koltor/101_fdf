/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 12:11:45 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 12:15:09 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_SIZE_X 2500
# define WIN_SIZE_Y 1500

# include "mlx.h"
# include "math.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_map
{
	size_t			size_x;
	size_t			size_y;
	int				*map;
	struct s_map	*next;
	struct s_map	*prev;
}					t_map;

typedef struct		s_moniteur
{
	char			*name;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;

	char			*image_string;
	int				bpp;
	int				s_l;
	int				endian;

	int				font_color;
	int				backgroundcolor;
	double			ctr;

	double			z;
	size_t			posx;
	double			posy;
	double			axex;
	double			axey;
	double			axez;

	struct s_map	*map;
	int				projection;
}					t_moniteur;

enum	e_bool
{
	true = 0,
	false = 1
};

typedef enum e_bool	t_bool;

int					wrong_file(char *file_name);
int					wrong_read(char *file_name);
int					usage(char *prog_name, int ac);
int					full_ac(char *prog_name);
int					map_error(char *map_name);
void				mexit();

int					deal_key(int key, t_moniteur *mtr);
int					deal_mouse(int button, int x, int y, t_moniteur *mtr);

void				show_t_map(t_map *map);
void				ft_cleanscreen(t_moniteur *mtr);
int					fill_pixel(t_moniteur *mtr, int x, int y);
void				ft_set_color(t_moniteur *mtr, int n1);

int					*tab_atoi(char **tab, int size);
void				ft_put_user_interface(t_moniteur *mtr);
void				ft_putmap(t_moniteur *mtr);
void				print_image(t_moniteur *mtr);
int					algo_bresenham(double index[4], t_moniteur *m);

t_bool				ft_count_and_check(char *str, size_t *ref, size_t *res);
#endif
