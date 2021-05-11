/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:08:11 by jacher            #+#    #+#             */
/*   Updated: 2021/05/11 19:24:01 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

void	ft_push_b(t_d *d)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while (j < d->size_max && d->b[j].bol == 0)
		j++;
	j--;
	while (i < d->size_max && d->a[i].bol == 0)
		i++;
	if (d->a[i].bol == 0)
		return ;
	d->b[j].nb = d->a[i].nb;
	d->b[j].bol = 1;
	d->a[i].bol = 0;
	d->size_a -= 1;
	d->size_b += 1;
}

void	ft_push_a(t_d *d)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while (j < d->size_max && d->a[j].bol == 0)
		j++;
	j--;
	while (i < d->size_max && d->b[i].bol == 0)
		i++;
	if (d->b[i].bol == 0)
		return ;
	d->a[j].nb = d->b[i].nb;
	d->a[j].bol = 1;
	d->b[i].bol = 0;
	d->size_a += 1;
	d->size_b -= 1;
}

void	ft_push(int bol_a, int bol_b, t_d *d)
{
	if (bol_b == 1)
		ft_push_b(d);
	else if (bol_a == 1)
		ft_push_a(d);
}

void	ft_push_bis(int bol_a, int bol_b, t_d *d, t_list **l)
{
	// A AJOUTER SUR TOUTES LES FONCTIONS t_list	*new;

	if (bol_b == 1)
	{
		ft_push_b(d);
		ft_lstadd_back(l, ft_lstnew((void*)("pb")));
	}
	else if (bol_a == 1)
	{
		ft_push_a(d);
		ft_lstadd_back(l, ft_lstnew((void*)("pa")));
	}
}
