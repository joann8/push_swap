/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex_special_bis.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:35:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/13 20:33:57 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int			special_5(t_d *d, t_list **l, char c)
{
	int ref;

	if (c == 'a')
	{
		ref = d->size_max - d->size_a;
		if (d->a[ref + 3].nb < d->a[ref + 4].nb)
			return (special_4_a(d, l));
		return (0);
	}
	else if (c == 'b')
	{
		ref = d->size_max - d->size_b;
		if (d->b[ref + 3].nb > d->b[ref + 4].nb)
			return (special_4_b(d, l, 5));
		return (0);
	}
	return (0);
}

int			special_6(t_d *d, t_list **l, char c)
{
	int ref;

	if (c == 'a')
	{
		ref = d->size_max - d->size_a;
		if (d->a[ref + 3].nb < d->a[ref + 4].nb
			&& d->a[ref + 4].nb < d->a[ref + 5].nb)
			return (special_4_a(d, l));
		return (0);
	}
	else if (c == 'b')
	{
		ref = d->size_max - d->size_b;
		if (d->b[ref + 3].nb > d->b[ref + 4].nb
			&& d->b[ref + 4].nb > d->b[ref + 5].nb)
			return (special_4_b(d, l, 6));
		return (0);
	}
	return (0);
}

int			special_7(t_d *d, t_list **l, char c)
{
	int ref;

	if (c == 'a')
	{
		ref = d->size_max - d->size_a;
		if (d->a[ref + 3].nb < d->a[ref + 4].nb
			&& d->a[ref + 4].nb < d->a[ref + 5].nb
			&& d->a[ref + 5].nb < d->a[ref + 6].nb)
			return (special_4_a(d, l));
		return (0);
	}
	else if (c == 'b')
	{
		ref = d->size_max - d->size_b;
		if (d->b[ref + 3].nb > d->b[ref + 4].nb
			&& d->b[ref + 4].nb > d->b[ref + 5].nb
			&& d->b[ref + 5].nb > d->b[ref + 6].nb)
			return (special_4_b(d, l, 7));
		return (0);
	}
	return (0);
}
