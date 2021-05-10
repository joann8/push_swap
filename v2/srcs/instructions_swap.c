/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:08:11 by jacher            #+#    #+#             */
/*   Updated: 2021/05/10 17:14:52 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

void	ft_swap_a(t_d *d)
{
	int tmp;
	int	i;

	i = 0;
	while (d->a[i].bol == 0 && i < d->size_max - 1)
		i++;
	if (d->a[i].bol == 1 && d->a[i + 1].bol == 1)
	{
		tmp = d->a[i].nb;
		d->a[i].nb = d->a[i + 1].nb;
		d->a[i + 1].nb = tmp;
	}
}

void	ft_swap_b(t_d *d)
{
	int tmp;
	int	i;

	i = 0;
	while (d->b[i].bol == 0 && i < d->size_max - 1)
		i++;
	if (d->b[i].bol == 1 && d->b[i + 1].bol == 1)
	{
		tmp = d->b[i].nb;
		d->b[i].nb = d->b[i + 1].nb;
		d->b[i + 1].nb = tmp;
	}
}

void	ft_swap(int bol_a, int bol_b, t_d *d)
{
	if (bol_a == 1)
		ft_swap_a(d);
	if (bol_b == 1)
		ft_swap_b(d);
}

void	ft_swap_bis(int bol_a, int bol_b, t_d *d, t_list **l)
{
	if (bol_a == 1)
	{
		ft_swap_a(d);
		ft_lstadd_back(l, ft_lstnew((void *)("sa")));
	}
	if (bol_b == 1)
	{
		ft_swap_b(d);
		ft_lstadd_back(l, ft_lstnew((void *)("sb")));
	}
}
