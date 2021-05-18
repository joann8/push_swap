/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_doublons.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:02:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/15 12:57:35 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int		update_doublons_check(t_list *tmp)
{
	if (((ft_strncmp((const char *)tmp->content, "ra", 3) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "rra", 4) == 0)
		|| ((ft_strncmp((const char *)tmp->content, "rra", 4) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "ra", 3) == 0)
		|| ((ft_strncmp((const char *)tmp->content, "rb", 3) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "rrb", 4) == 0)
		|| ((ft_strncmp((const char *)tmp->content, "rrb", 4) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "rb", 3) == 0)
		|| ((ft_strncmp((const char *)tmp->content, "pa", 3) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "pb", 3) == 0)
		|| ((ft_strncmp((const char *)tmp->content, "pb", 3) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "pa", 3) == 0)
		|| ((ft_strncmp((const char *)tmp->content, "sa", 3) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "sa", 3) == 0)
		|| ((ft_strncmp((const char *)tmp->content, "ss", 3) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "ss", 3) == 0)
		|| ((ft_strncmp((const char *)tmp->content, "rr", 3) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "rrr", 3) == 0))
		return (1);
	else
		return (0);
}

void	update_doublons_help(t_list **tmp, t_list **begin, t_list **prev,
			t_list **l)
{
	t_list *del;

	del = *tmp;
	*tmp = (*tmp)->next->next;
	if (del == *begin)
		*l = *tmp;
	else
		(*prev)->next = *tmp;
	ft_lstdelone(del->next, &free);
	ft_lstdelone(del, &free);
}

int		update_doublons(t_list **l)
{
	t_list *tmp;
	t_list *prev;
	t_list *begin;

	tmp = *l;
	prev = *l;
	begin = *l;
	while (tmp && tmp->next)
	{
		if (update_doublons_check(tmp) == 1)
			update_doublons_help(&tmp, &begin, &prev, l);
		else
		{
			prev = tmp;
			tmp = tmp->next;
		}
	}
	return (0);
}
