/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex_3_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:35:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/13 23:53:57 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int			special_3_b_third(t_d *d, t_list **l, int ref)
{
	if (d->b[ref + 2].nb > d->b[ref].nb
		&& d->b[ref].nb > d->b[ref + 1].nb)
	{
		ft_rotate_bis(0, 1, d, l);
		ft_swap_bis(0, 1, d, l);
		ft_rrotate_bis(0, 1, d, l);
		ft_swap_bis(0, 1, d, l);
		return (ft_push_on_a(d, l, 3));
	}
	else if (d->b[ref + 2].nb > d->b[ref + 1].nb
		&& d->b[ref + 1].nb > d->b[ref].nb)
	{
		ft_swap_bis(0, 1, d, l);
		ft_rotate_bis(0, 1, d, l);
		ft_swap_bis(0, 1, d, l);
		ft_rrotate_bis(0, 1, d, l);
		ft_swap_bis(0, 1, d, l);
		return (ft_push_on_a(d, l, 3));
	}
	return (0);
}

int			special_3_b_bis(t_d *d, t_list **l, int ref)
{
	if (d->b[ref].nb > d->b[ref + 2].nb
		&& d->b[ref + 2].nb > d->b[ref + 1].nb)
	{
		ft_rotate_bis(0, 1, d, l);
		ft_swap_bis(0, 1, d, l);
		ft_rrotate_bis(0, 1, d, l);
		return (ft_push_on_a(d, l, 3));
	}
	else if (d->b[ref + 1].nb > d->b[ref + 2].nb
		&& d->b[ref + 2].nb > d->b[ref].nb)
	{
		ft_swap_bis(0, 1, d, l);
		ft_rotate_bis(0, 1, d, l);
		ft_swap_bis(0, 1, d, l);
		ft_rrotate_bis(0, 1, d, l);
		return (ft_push_on_a(d, l, 3));
	}
	return (special_3_b_third(d, l, ref));
}

int			special_3_b(t_d *d, t_list **l)
{
	int ref;

	ref = d->size_max - d->size_b;
	if (d->b[ref].nb > d->b[ref + 1].nb
		&& d->b[ref + 1].nb > d->b[ref + 2].nb)
	{
		ft_push_on_a(d, l, 3);
		return (1);
	}
	else if (d->b[ref + 1].nb > d->b[ref].nb
		&& d->b[ref].nb > d->b[ref + 2].nb)
	{
		ft_swap_bis(0, 1, d, l);
		ft_push_on_a(d, l, 3);
		return (1);
	}
	return (special_3_b_bis(d, l, ref));
}
