/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_single.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:53:22 by jacher            #+#    #+#             */
/*   Updated: 2021/03/16 12:05:55 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int		check_str_single(char *av, int *j)
{
	long unsigned int	res;
	int					bol_neg;

	res = 0;
	bol_neg = 0;
	while ((av[*j] >= 9 && av[*j] <= 13) || av[*j] == ' ')
		*j += 1;
	if (av[*j] == '-' || av[*j] == '+')
	{
		if (av[*j] == '-')
			bol_neg = 1;
		*j += 1;
	}
	if (av[*j] == '\0')
		return (-1);
	while (ft_isdigit(av[*j]) == 1)
	{
		res = res * 10 + av[*j] - 48;
		*j += 1;
	}
	if ((av[*j] != '\0' && av[*j] != ' ')
		|| res > (long unsigned int)INT_MAX + bol_neg)
		return (-1);
	return (1);
}

int		check_input_single(char *av, int *count)
{
	int		i;

	i = 0;
	while (av[i])
	{
		if (av[i] == ' ')
			i++;
		else
		{
			if (check_str_single(av, &i) == -1)
				return (-1);
			*count += 1;
		}
	}
	return (1);
}

void	assign_input_single(int count, char *av, t_d *d)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (av[i])
	{
		if (av[i] == ' ')
			i++;
		else
		{
			d->a[j].nb = ft_atoi(av + i);
			d->a[j].bol = 1;
			d->b[j].nb = 0;
			d->b[j].bol = 0;
			while (av[i] && av[i] != ' ')
				i++;
			j++;
		}
	}
	d->size_a = count;
	d->size_max = count;
	d->size_b = 0;
}

int		check_args_single(char **av, t_d *d)
{
	int count;

	count = 0;
	if (check_input_single(av[1], &count) == -1)
		return (ft_error());
	d->a = malloc(sizeof(t_s) * (count));
	if (d->a == NULL)
		return (ft_error());
	d->b = malloc(sizeof(t_s) * (count));
	if (d->b == NULL)
	{
		free(d->a);
		return (ft_error());
	}
	assign_input_single(count, av[1], d);
	if (check_doublons(d) == -1)
	{
		free(d->a);
		free(d->b);
		return (ft_error());
	}
	return (count);
}
