/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex_4_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:35:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/13 23:55:00 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int			special_4_a_third(t_d *d, t_list **l, int ref)
{
	if (d->a[ref + 2].nb < d->a[ref].nb
		&& d->a[ref].nb < d->a[ref + 1].nb
		&& d->a[ref + 1].nb < d->a[ref + 3].nb)
	{
		ft_rotate_bis(1, 0, d, l);
		ft_swap_bis(1, 0, d, l);
		ft_rrotate_bis(1, 0, d, l);
		ft_swap_bis(1, 0, d, l);
		return (1);
	}
	else if (d->a[ref + 2].nb < d->a[ref + 1].nb
		&& d->a[ref + 1].nb < d->a[ref].nb
		&& d->a[ref].nb < d->a[ref + 3].nb)
	{
		ft_swap_bis(1, 0, d, l);
		ft_rotate_bis(1, 0, d, l);
		ft_swap_bis(1, 0, d, l);
		ft_rrotate_bis(1, 0, d, l);
		ft_swap_bis(1, 0, d, l);
		return (1);
	}
	return (0);
}

int			special_4_a_bis(t_d *d, t_list **l, int ref)
{
	if (d->a[ref].nb < d->a[ref + 2].nb
		&& d->a[ref + 2].nb < d->a[ref + 1].nb
		&& d->a[ref + 1].nb < d->a[ref + 3].nb)
	{
		ft_rotate_bis(1, 0, d, l);
		ft_swap_bis(1, 0, d, l);
		ft_rrotate_bis(1, 0, d, l);
		return (1);
	}
	else if (d->a[ref + 1].nb < d->a[ref + 2].nb
		&& d->a[ref + 2].nb < d->a[ref].nb
		&& d->a[ref].nb < d->a[ref + 3].nb)
	{
		ft_swap_bis(1, 0, d, l);
		ft_rotate_bis(1, 0, d, l);
		ft_swap_bis(1, 0, d, l);
		ft_rrotate_bis(1, 0, d, l);
		return (1);
	}
	return (special_4_a_third(d, l, ref));
}

int			special_4_a(t_d *d, t_list **l)
{
	int ref;

	ref = d->size_max - d->size_a;
	if (d->a[ref].nb < d->a[ref + 1].nb
		&& d->a[ref + 1].nb < d->a[ref + 2].nb
		&& d->a[ref + 2].nb < d->a[ref + 3].nb)
		return (1);
	else if (d->a[ref + 1].nb < d->a[ref].nb
		&& d->a[ref].nb < d->a[ref + 2].nb
		&& d->a[ref + 2].nb < d->a[ref + 3].nb)
	{
		ft_swap_bis(1, 0, d, l);
		return (1);
	}
	return (special_4_a_bis(d, l, ref));
}
