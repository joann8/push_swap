/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex_bis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:35:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/13 17:23:11 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"
#include <stdio.h>

int		put_on_a(t_d *d, t_list **l, t_pack *p, int moved)
{
	int count;

	count = 0;
	while (moved < p->on_a)
	{
		if (d->b[d->size_max - d->size_b].nb <= p->mid_value)
		{
			if (count == p->on_b - 1 && moved == p->on_a - 1)
				ft_swap_bis(0, 1, d, l);
			else
			{
				ft_rotate_bis(0, 1, d, l);
				count++;
			}
		}
		else
		{
			ft_push_bis(1, 0, d, l);
			moved++;
		}
	}
	while (p->on_a < d->size_b / 2 && count > 0)
	{
		ft_rrotate_bis(0, 1, d, l);
		count--;
	}
	return (1);
}

int		put_on_b(t_d *d, t_list **l, t_pack *p, int moved)
{
	int count;

	count = 0;
	while (moved < p->on_b)
	{
		if (d->a[d->size_max - d->size_a].nb > p->mid_value)
		{
			if (count == p->on_a - 1 && moved == p->on_b - 1)
				ft_swap_bis(1, 0, d, l);
			else
			{
				ft_rotate_bis(1, 0, d, l);
				count++;
			}
		}
		else
		{
			ft_push_bis(0, 1, d, l);
			moved++;
		}
	}
	while (p->on_b < d->size_a / 2 && count > 0)
	{
		ft_rrotate_bis(1, 0, d, l);
		count--;
	}
	return (1);
}

int		define_pack_help(int mid_value, int pack_half, int size, t_pack *pack)
{
	pack->mid_value = mid_value;
	pack->size = size;
	if (pack->size % 2 == 0)
	{
		pack->pair = 0;
		pack->on_a = pack_half;
		pack->on_b = pack_half;
	}
	else
	{
		pack->pair = 1;
		pack->on_a = pack_half + 1;
		pack->on_b = pack_half;
	}
	return (1);
}

int		define_pack(t_s *s, int low, int high, t_pack *pack)
{
	int test;
	int i;
	int j;
	int count;
	int pack_half;

	if ((pack_half = (high - low) / 2) < 1)
		return (-1);
	i = low;
	while (i < high)
	{
		count = 0;
		test = s[i].nb;
		j = low;
		while (j < high)
		{
			if (s[j].nb <= test)
				count++;
			j++;
		}
		if (count == pack_half)
			return (define_pack_help(s[i].nb, pack_half, high - low, pack));
		i++;
	}
	return (-1);
}
