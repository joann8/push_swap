/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:53:22 by jacher            #+#    #+#             */
/*   Updated: 2021/05/07 18:30:12 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

void	ft_free_list(t_list *l)
{
	t_list *tmp;
	t_list *del;

	tmp = l;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
}


void	ft_free_data(t_d *d)
{
	free(d->a);
	free(d->b);
}

void	init_flags(t_res *r)
{
	r->f_nb = 0;
	r->f_err = 0;
	r->f_see = 0;
	r->f_col = 0;
}

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
					ft_print_err("Error: doublon input for value '", ft_itoa(d->a[i].nb), "'\n", -1);
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
			break;
		i++;
	}
	if (i == ac)
		return (-1);
	return (i);
}

int		check_args(int ac, char **av, t_d *d, t_res *r)
{
	int i;
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
	{
		i = 0;
		while (av[start][i])
		{
			if (av[start][i] == ' ')
				break ;
			i++;
		}
		if (av[start][i] == '\0')
			res = check_args_several(ac, av, d, start);
		else
			res = check_args_single(av, d, start);
	}
	if (check_doublons(d, r) == -1)
	{
		free(d->a);
		free(d->b);
		return (-1);
	}
	return (res);
}
