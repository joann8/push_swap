/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:53:22 by jacher            #+#    #+#             */
/*   Updated: 2021/03/15 19:19:22 by jacher           ###   ########.fr       */
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

int		check_doublons(t_d *d)
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
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_args(int ac, char **av, t_d *d)
{
	int i;
	int res;

	res = 1;
	if (ac < 2)
		return (-1);
	if (ac > 2)
		res = check_args_several(ac, av, d);
	else
	{
		i = 0;
		while (av[1][i])
		{
			if (av[1][i] == ' ')
				break ;
			i++;
		}
		if (av[1][i] == '\0')
			res = check_args_several(ac, av, d);
		else
			res = check_args_single(av, d);
	}
	return (res);
}
