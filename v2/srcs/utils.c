/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:53:22 by jacher            #+#    #+#             */
/*   Updated: 2021/05/11 19:13:13 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

void	ft_free_list(t_list *l)
{
	t_list *tmp;
	t_list *del;

	tmp = l;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
	//	free(del->content);
		free(del);
	}
}

void	ft_free_data(t_d *d)
{
	free(d->a);
	free(d->b);
}

void	init_flags(t_res *r)
{
	r->f_nb = 0;
	r->f_err = 0;
	r->f_see = 0;
	r->f_col = 0;
}
