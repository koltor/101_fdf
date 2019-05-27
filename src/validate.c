/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   validate.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 14:04:52 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/23 15:59:26 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static	t_bool	ft_str_is_digit_or_space(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (((str[i] < '0' && str[i] != ' ') || str[i] > '9') && str[i] != '-')
			return (false);
		if (i > 0 && str[i] == '-')
			if (str[i - 1] == '-')
				return (false);
		i++;
	}
	return (true);
}

t_bool			ft_count_and_check(char *str, size_t *ref, size_t *res)
{
	if (*ref == 0)
		*ref = nb_word(str, ' ');
	*res = nb_word(str, ' ');
	if (ft_str_is_digit_or_space(str))
		return (false);
	if (*res != *ref)
		return (false);
	return (true);
}
