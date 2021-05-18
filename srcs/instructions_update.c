/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_update.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:02:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/15 12:28:17 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

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
	return (0);
}
