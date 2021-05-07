/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_several.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:53:22 by jacher            #+#    #+#             */
/*   Updated: 2021/05/07 16:19:50 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int		check_str_several(char **av, int i)
{
	int					j;
	long unsigned int	res;
	int					bol_neg;

	res = 0;
	bol_neg = 0;
	j = 0;
	while ((av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == ' ')
		j++;
	if (av[i][j] == '-' || av[i][j] == '+')
	{
		if (av[i][j] == '-')
			bol_neg = 1;
		j++;
	}
	if (av[i][j] == '\0')
		return (-1);
	while (ft_isdigit(av[i][j]) == 1)
	{
		res = res * 10 + av[i][j] - 48;
		j++;
	}
	if (av[i][j] != '\0' || res > (long unsigned int)INT_MAX + bol_neg)
		return (-1);
	return (1);
}

int		check_input_several(char **av, int start)
{
	int					i;

	i = start;
	while (av[i])
	{
		if (check_str_several(av, i) == -1)
			return (-1);
		i++;
	}
	return (1);
}

void	assign_input_several(int ac, char **av, t_d *d, int start)
{
	int i;
	int j;

	i = start;
	j = 0;
	while (av[i])
	{
		d->a[j].nb = ft_atoi(av[i]);
		d->a[j].bol = 1;
		d->b[j].nb = 0;
		d->b[j].bol = 0;
		i++;
		j++;
	}
	d->size_a = ac - start;
	d->size_max = ac - start;
	d->size_b = 0;
}

int		check_args_several(int ac, char **av, t_d *d, int start)
{
	if (check_input_several(av, start) == -1)
		return (ft_error());
	d->a = malloc(sizeof(t_s) * (ac - start));
	if (d->a == NULL)
		return (ft_error());
	d->b = malloc(sizeof(t_s) * (ac - start));
	if (d->b == NULL)
	{
		free(d->a);
		return (ft_error());
	}
	assign_input_several(ac, av, d, start);
	return (ac - start);
}
