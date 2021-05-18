/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:53:22 by jacher            #+#    #+#             */
/*   Updated: 2021/05/10 16:00:52 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int		check_doublons(t_d *d, t_res *r)
{
	int i;
	int j;

	i = 0;
	while (i < d->size_a)
	{
		j = i + 1;
		while (j < d->size_a)
		{
			if (d->a[i].nb == d->a[j].nb)
			{
				if (r->f_err == 1)
					ft_print_err("Error: doublon input\n", NULL, NULL, -1);
				else
					ft_error();
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		look_for_flags(int ac, char **av, t_res *r)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (ft_strncmp(av[i], "-nb", 3) == 0)
			r->f_nb = 1;
		else if (ft_strncmp(av[i], "-err", 4) == 0)
			r->f_err = 1;
		else if (ft_strncmp(av[i], "-see", 4) == 0)
			r->f_see = 1;
		else if (ft_strncmp(av[i], "-col", 4) == 0)
			r->f_col = 1;
		else
			break ;
		i++;
	}
	if (i == ac)
		return (-1);
	return (i);
}

int		check_args_help(int ac, char **av, t_d *d, int start)
{
	int	i;

	i = 0;
	while (av[start][i])
	{
		if (av[start][i] == ' ')
			break ;
		i++;
	}
	if (av[start][i] == '\0')
		return (check_args_several(ac, av, d, start));
	else
		return (check_args_single(av, d, start));
}

int		check_args(int ac, char **av, t_d *d, t_res *r)
{
	int res;
	int start;

	res = 1;
	start = 1;
	if (ac < 2)
		return (-1);
	if ((start = look_for_flags(ac, av, r)) == -1)
		return (-1);
	if (ac - start > 1)
		res = check_args_several(ac, av, d, start);
	else
		res = check_args_help(ac, av, d, start);
	if (res == -2 && r->f_err == 1)
		ft_print_err("Error: wrong format for input\n", NULL, NULL, -1);
	else if (res == -2 && r->f_err == 0)
		ft_error();
	else if (res != -1 && check_doublons(d, r) == -1)
	{
		free(d->a);
		free(d->b);
		return (-1);
	}
	return (res);
}
