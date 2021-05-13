/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_update.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:02:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/14 00:17:44 by jacher           ###   ########.fr       */
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

int		update_doublons(t_list **l)
{
	t_list *tmp;
	t_list *del;
	t_list *prev;
	t_list *begin;

	tmp = *l;
	prev = *l;
	begin = *l;
	while (tmp && tmp->next)
	{
		if (update_doublons_check(tmp) == 1)
		{
			del = tmp;
			if (tmp == begin)
			{
				tmp = tmp->next->next;
				*l = tmp;
			}
			else
			{
				tmp = tmp->next->next;
				prev->next = tmp;
			}
			ft_lstdelone((del->next), &free);
			ft_lstdelone(del, &free);
		}
		else
		{
			prev = tmp;
			tmp = tmp->next;
		}
	}
	return (0);
}

void	update_inst_third(t_list **tmp)
{
	t_list *del;

	if ((((ft_strncmp((const char *)(*tmp)->content, "rra", 4) == 0)
		&& ft_strncmp((const char *)(*tmp)->next->content, "rrb", 4) == 0))
		|| ((ft_strncmp((const char *)(*tmp)->content, "rrb", 4) == 0)
		&& ft_strncmp((const char *)(*tmp)->next->content, "rra", 4) == 0))
	{
		free((*tmp)->content);
		free((*tmp)->next->content);
		del = (*tmp)->next;
		(*tmp)->next = (*tmp)->next->next;
		free(del);
		(*tmp)->content = ft_strdup("rrr");
	}
}

void	update_inst_bis(t_list **tmp)
{
	t_list *del;

	if ((((ft_strncmp((const char *)(*tmp)->content, "sa", 3) == 0)
		&& ft_strncmp((const char *)(*tmp)->next->content, "sb", 3) == 0))
		|| ((ft_strncmp((const char *)(*tmp)->content, "sb", 3) == 0)
		&& ft_strncmp((const char *)(*tmp)->next->content, "sa", 3) == 0))
	{
		free((*tmp)->content);
		free((*tmp)->next->content);
		del = (*tmp)->next;
		(*tmp)->next = (*tmp)->next->next;
		free(del);
		(*tmp)->content = ft_strdup("ss");
	}
	else
		update_inst_third(tmp);
}

int		update_inst(t_list **l)
{
	t_list *tmp;
	t_list *del;

	tmp = *l;
	while (tmp && tmp->next)
	{
		if ((((ft_strncmp((const char *)tmp->content, "ra", 3) == 0)
			&& ft_strncmp((const char *)tmp->next->content, "rb", 3) == 0))
			|| ((ft_strncmp((const char *)tmp->content, "rb", 3) == 0)
			&& ft_strncmp((const char *)tmp->next->content, "ra", 3) == 0))
		{
			free(tmp->content);
			free(tmp->next->content);
			del = tmp->next;
			tmp->next = tmp->next->next;
			free(del);
			tmp->content = ft_strdup("rr");
		}
		else
			update_inst_bis(&tmp);
		if (tmp->content == NULL)
			return (-1);
		tmp = tmp->next;
	}
	update_doublons(l);
	return (0);
}
