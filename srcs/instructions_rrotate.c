/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rrotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:08:11 by jacher            #+#    #+#             */
/*   Updated: 2021/05/13 12:08:52 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

void	ft_rrotate_a(t_d *d)
{
	int tmp1;
	int tmp2;
	int	i;

	i = 0;
	while (d->a[i].bol == 0 && i < d->size_max)
		i++;
	if (d->size_max - i <= 1)
		return ;
	tmp1 = d->a[i].nb;
	d->a[i].nb = d->a[d->size_max - 1].nb;
	i++;
	while (i < d->size_max)
	{
		tmp2 = d->a[i].nb;
		d->a[i].nb = tmp1;
		tmp1 = tmp2;
		i++;
	}
}

void	ft_rrotate_b(t_d *d)
{
	int tmp1;
	int tmp2;
	int	i;

	i = 0;
	while (d->b[i].bol == 0 && i < d->size_max)
		i++;
	if (d->size_max - i <= 1)
		return ;
	tmp1 = d->b[i].nb;
	d->b[i].nb = d->b[d->size_max - 1].nb;
	i++;
	while (i < d->size_max)
	{
		tmp2 = d->b[i].nb;
		d->b[i].nb = tmp1;
		tmp1 = tmp2;
		i++;
	}
}

void	ft_rrotate(int bol_a, int bol_b, t_d *d)
{
	if (bol_a == 1)
		ft_rrotate_a(d);
	if (bol_b == 1)
		ft_rrotate_b(d);
}

void	ft_rrotate_bis(int bol_a, int bol_b, t_d *d, t_list **l)
{
	t_list	*new;
	char	*tmp;

	if (bol_a == 1)
	{
		if (d->size_a < 2)
			return ;
		ft_rrotate_a(d);
		tmp = ft_strdup("rra");
		new = ft_lstnew(tmp);
		ft_lstadd_back(l, new);
	}
	if (bol_b == 1)
	{
		if (d->size_b < 2)
			return ;
		ft_rrotate_b(d);
		tmp = ft_strdup("rrb");
		new = ft_lstnew(tmp);
		ft_lstadd_back(l, new);
	}
}
