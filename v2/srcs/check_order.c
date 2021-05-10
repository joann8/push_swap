/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:39:59 by jacher            #+#    #+#             */
/*   Updated: 2021/05/10 18:04:34 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int	check_int_order_a_range(t_s *s, int low, int high)
{
	int i;
	int max;

	i = low;
	max = I_MIN;
	while (i < high)
	{
		if (s[i].nb >= max)
			max = s[i].nb;
		else
			return (-1);
		i++;
	}
	return (1);
}

int	check_int_order_a(t_d *d)
{
	int i;
	int max;

	i = d->size_max - d->size_a;
	max = I_MIN;
	while (i < d->size_max)
	{
		if (d->a[i].nb >= max)
			max = d->a[i].nb;
		else
			return (-1);
		i++;
	}
	return (1);
}

int	check_int_order_b_range(t_s *s, int low, int high)
{
	int i;
	int min;

	i = low;
	min = I_MAX;
	while (i < high)
	{
		if (s[i].nb <= min)
			min = s[i].nb;
		else
			return (-1);
		i++;
	}
	return (1);
}

int	check_int_order_b(t_d *d)
{
	int i;
	int min;

	i = d->size_max - d->size_b;
	min = I_MAX;
	while (i < d->size_max)
	{
		if (d->b[i].nb <= min)
			min = d->b[i].nb;
		else
			return (-1);
		i++;
	}
	return (1);
}

int	check_order(t_d *d)
{
	if (check_int_order_a(d) == 1
		&& check_int_order_b(d) == 1
		&& d->size_a == d->size_max)
		return (1);
	return (-1);
}
