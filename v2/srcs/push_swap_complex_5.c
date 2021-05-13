/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex_5.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:35:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/13 16:21:25 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int			special_5_a(t_d *d, t_list **l)
{
	int ref;

	ref = d->size_max - d->size_a;
	if (d->a[ref].nb < d->a[ref + 1].nb
		&& d->a[ref + 1].nb < d->a[ref + 2].nb
		&& d->a[ref + 2].nb < d->a[ref + 3].nb
		&& d->a[ref + 3].nb < d->a[ref + 4].nb)
		return (1);
	else if (d->a[ref + 1].nb < d->a[ref].nb
		&& d->a[ref].nb < d->a[ref + 2].nb
		&& d->a[ref + 2].nb < d->a[ref + 3].nb
		&& d->a[ref + 3].nb < d->a[ref + 4].nb)
	{
		ft_swap_bis(1, 0, d, l);
		return (1);
	}
	else if (d->a[ref].nb < d->a[ref + 2].nb
		&& d->a[ref + 2].nb < d->a[ref + 1].nb
		&& d->a[ref + 1].nb < d->a[ref + 3].nb
		&& d->a[ref + 3].nb < d->a[ref + 4].nb)
	{
		ft_rotate_bis(1, 0, d, l);
		ft_swap_bis(1, 0, d, l);
		ft_rrotate_bis(1, 0, d, l);
		return (1);
	}
	else if (d->a[ref + 1].nb < d->a[ref + 2].nb
		&& d->a[ref + 2].nb < d->a[ref].nb
		&& d->a[ref].nb < d->a[ref + 3].nb
		&& d->a[ref + 3].nb < d->a[ref + 4].nb)
	{
		ft_swap_bis(1, 0, d, l);
		ft_rotate_bis(1, 0, d, l);
		ft_swap_bis(1, 0, d, l);
		ft_rrotate_bis(1, 0, d, l);
		return (1);
	}
	else if (d->a[ref + 2].nb < d->a[ref].nb
		&& d->a[ref].nb < d->a[ref + 1].nb
		&& d->a[ref + 1].nb < d->a[ref + 3].nb
		&& d->a[ref + 3].nb < d->a[ref + 4].nb)
	{
		ft_rotate_bis(1, 0, d, l);
		ft_swap_bis(1, 0, d, l);
		ft_rrotate_bis(1, 0, d, l);
		ft_swap_bis(1, 0, d, l);
		return (1);
	}
	else if (d->a[ref + 2].nb < d->a[ref + 1].nb
		&& d->a[ref + 1 ].nb < d->a[ref].nb
		&& d->a[ref].nb < d->a[ref + 3].nb
		&& d->a[ref + 3].nb < d->a[ref + 4].nb)
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

int			ft_push_on_a(t_d *d, t_list **l, int nb)
{
	while (nb > 0)
	{
		ft_push_bis(1, 0, d, l);
		nb--;
	}
	return (1);
}

int			special_5_b(t_d *d, t_list **l)
{
	int ref;

	ref = d->size_max - d->size_b;
	if (d->b[ref].nb > d->b[ref + 1].nb
		&& d->b[ref + 1].nb > d->b[ref + 2].nb
		&& d->b[ref + 2].nb > d->b[ref + 3].nb
		&& d->b[ref + 3].nb > d->b[ref + 4].nb)
		return (ft_push_on_a(d, l, 5));
	else if (d->b[ref + 1].nb > d->b[ref].nb
		&& d->b[ref].nb > d->b[ref + 2].nb
		&& d->b[ref + 2].nb > d->b[ref + 3].nb
		&& d->b[ref + 3].nb > d->b[ref + 4].nb)
	{
		ft_swap_bis(0, 1, d, l);
		return (ft_push_on_a(d, l, 5));
	}
	else if (d->b[ref].nb > d->b[ref + 2].nb
		&& d->b[ref + 2].nb > d->b[ref + 1].nb
		&& d->b[ref + 1].nb > d->b[ref + 3].nb
		&& d->b[ref + 3].nb > d->b[ref + 4].nb)
	{
		ft_rotate_bis(0, 1, d, l);
		ft_swap_bis(0, 1, d, l);
		ft_rrotate_bis(0, 1, d, l);
		return (ft_push_on_a(d, l, 5));
	}
	else if (d->b[ref + 1].nb > d->b[ref + 2].nb
		&& d->b[ref + 2].nb > d->b[ref].nb
		&& d->b[ref].nb > d->b[ref + 3].nb
		&& d->b[ref + 3].nb > d->b[ref + 4].nb)
	{
		ft_swap_bis(0, 1, d, l);
		ft_rotate_bis(0, 1, d, l);
		ft_swap_bis(0, 1, d, l);
		ft_rrotate_bis(0, 1, d, l);
		return (ft_push_on_a(d, l, 5));
	}
	else if (d->b[ref + 2].nb > d->b[ref].nb
		&& d->b[ref].nb > d->b[ref + 1].nb
		&& d->b[ref + 1].nb > d->b[ref + 3].nb
		&& d->b[ref + 3].nb > d->b[ref + 4].nb)
	{
		ft_rotate_bis(0, 1, d, l);
		ft_swap_bis(0, 1, d, l);
		ft_rrotate_bis(0, 1, d, l);
		ft_swap_bis(0, 1, d, l);
		return (ft_push_on_a(d, l, 5));
	}
	else if (d->b[ref + 2].nb > d->b[ref + 1].nb
		&& d->b[ref + 1].nb > d->b[ref].nb
		&& d->b[ref].nb > d->b[ref + 3].nb
		&& d->b[ref + 3].nb > d->b[ref + 4].nb)
	{
		ft_swap_bis(0, 1, d, l);
		ft_rotate_bis(0, 1, d, l);
		ft_swap_bis(0, 1, d, l);
		ft_rrotate_bis(0, 1, d, l);
		ft_swap_bis(0, 1, d, l);
		return (ft_push_on_a(d, l, 5));
	}

	return (0);
}
