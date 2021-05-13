/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex_special.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:35:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/14 00:00:45 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int		ft_push_on_a(t_d *d, t_list **l, int nb)
{
	while (nb > 0)
	{
		ft_push_bis(1, 0, d, l);
		nb--;
	}
	return (1);
}

void	look_for_special_a(t_d *d, t_list **l, t_pack *new_pack)
{
	if (new_pack->on_a == 2)
	{
		if (d->a[d->size_max - d->size_a].nb
				> d->a[d->size_max - d->size_a + 1].nb)
			ft_swap_bis(1, 0, d, l);
	}
	else if (new_pack->on_a == 3)
	{
		if (special_3_a(d, l) == 0)
			algo_push_swap(d, l, 1, new_pack);
	}
	else if (new_pack->on_a == 4)
	{
		if (special_4_a(d, l) == 0)
			algo_push_swap(d, l, 1, new_pack);
	}
	else
		algo_push_swap(d, l, 1, new_pack);
}

void	look_for_special_b(t_d *d, t_list **l, t_pack *new_pack)
{
	if (new_pack->on_b == 2)
	{
		if (d->b[d->size_max - d->size_b].nb
				< d->b[d->size_max - d->size_b + 1].nb)
			ft_swap_bis(0, 1, d, l);
		ft_push_bis(1, 0, d, l);
		ft_push_bis(1, 0, d, l);
	}
	else if (new_pack->on_b == 3)
	{
		if (special_3_b(d, l) == 0)
			algo_push_swap(d, l, 2, new_pack);
	}
	else if (new_pack->on_b == 4)
	{
		if (special_4_b(d, l, 4) == 0)
			algo_push_swap(d, l, 2, new_pack);
	}
	else
		algo_push_swap(d, l, 2, new_pack);
}
