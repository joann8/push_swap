/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex_4_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:35:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/13 23:55:42 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int			special_4_b_third(t_d *d, t_list **l, int nb, int ref)
{
	if (d->b[ref + 2].nb > d->b[ref].nb
		&& d->b[ref].nb > d->b[ref + 1].nb
		&& d->b[ref + 1].nb > d->b[ref + 3].nb)
	{
		ft_rotate_bis(0, 1, d, l);
		ft_swap_bis(0, 1, d, l);
		ft_rrotate_bis(0, 1, d, l);
		ft_swap_bis(0, 1, d, l);
		return (ft_push_on_a(d, l, 4));
	}
	else if (d->b[ref + 2].nb > d->b[ref + 1].nb
		&& d->b[ref + 1].nb > d->b[ref].nb
		&& d->b[ref].nb > d->b[ref + 3].nb)
	{
		ft_swap_bis(0, 1, d, l);
		ft_rotate_bis(0, 1, d, l);
		ft_swap_bis(0, 1, d, l);
		ft_rrotate_bis(0, 1, d, l);
		ft_swap_bis(0, 1, d, l);
		return (ft_push_on_a(d, l, nb));
	}
	return (0);
}

int			special_4_b_bis(t_d *d, t_list **l, int nb, int ref)
{
	if (d->b[ref].nb > d->b[ref + 2].nb
		&& d->b[ref + 2].nb > d->b[ref + 1].nb
		&& d->b[ref + 1].nb > d->b[ref + 3].nb)
	{
		ft_rotate_bis(0, 1, d, l);
		ft_swap_bis(0, 1, d, l);
		ft_rrotate_bis(0, 1, d, l);
		return (ft_push_on_a(d, l, nb));
	}
	else if (d->b[ref + 1].nb > d->b[ref + 2].nb
		&& d->b[ref + 2].nb > d->b[ref].nb
		&& d->b[ref].nb > d->b[ref + 3].nb)
	{
		ft_swap_bis(0, 1, d, l);
		ft_rotate_bis(0, 1, d, l);
		ft_swap_bis(0, 1, d, l);
		ft_rrotate_bis(0, 1, d, l);
		return (ft_push_on_a(d, l, nb));
	}
	return (special_4_b_third(d, l, nb, ref));
}

int			special_4_b(t_d *d, t_list **l, int nb)
{
	int ref;

	ref = d->size_max - d->size_b;
	if (d->b[ref].nb > d->b[ref + 1].nb
		&& d->b[ref + 1].nb > d->b[ref + 2].nb
		&& d->b[ref + 2].nb > d->b[ref + 3].nb)
		return (ft_push_on_a(d, l, 4));
	else if (d->b[ref + 1].nb > d->b[ref].nb
		&& d->b[ref].nb > d->b[ref + 2].nb
		&& d->b[ref + 2].nb > d->b[ref + 3].nb)
	{
		ft_swap_bis(0, 1, d, l);
		return (ft_push_on_a(d, l, nb));
	}
	return (special_4_b_bis(d, l, nb, ref));
}
