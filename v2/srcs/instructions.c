/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:02:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/10 17:33:57 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

void	update_inst_bis(t_list *tmp)
{
	t_list *del;

	if ((((ft_strncmp((const char *)tmp->content, "sa", 3) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "sb", 3) == 0))
		|| ((ft_strncmp((const char *)tmp->content, "sb", 3) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "sa", 3) == 0))
	{
		del = tmp->next;
		tmp->next = tmp->next->next;
		tmp->content = ft_strdup("ss");
		free(del);
	}
	else if ((((ft_strncmp((const char *)tmp->content, "rra", 4) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "rrb", 4) == 0))
		|| ((ft_strncmp((const char *)tmp->content, "rrb", 4) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "rra", 4) == 0))
	{
		del = tmp->next;
		tmp->next = tmp->next->next;
		free(del);
		free(tmp->content);
		tmp->content = ft_strdup("rrr");
	}
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
			del = tmp->next;
			tmp->next = tmp->next->next;
			tmp->content = ft_strdup("rrr");
			free(del);
		}
		else
			update_inst_bis(tmp);
		if (tmp->content == NULL)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int		execute_inst(char *line, t_d *d)
{
	if (ft_strncmp(line, "ra", 3) == 0)
		ft_rotate(1, 0, d);
	else if (ft_strncmp(line, "rb", 3) == 0)
		ft_rotate(0, 1, d);
	else if (ft_strncmp(line, "rr", 3) == 0)
		ft_rotate(1, 1, d);
	else if (ft_strncmp(line, "sa", 3) == 0)
		ft_swap(1, 0, d);
	else if (ft_strncmp(line, "sb", 3) == 0)
		ft_swap(0, 1, d);
	else if (ft_strncmp(line, "ss", 3) == 0)
		ft_swap(1, 1, d);
	else if (ft_strncmp(line, "rra", 4) == 0)
		ft_rrotate(1, 0, d);
	else if (ft_strncmp(line, "rrb", 4) == 0)
		ft_rrotate(0, 1, d);
	else if (ft_strncmp(line, "rrr", 4) == 0)
		ft_rrotate(1, 1, d);
	else if (ft_strncmp(line, "pa", 3) == 0)
		ft_push(1, 0, d);
	else if (ft_strncmp(line, "pb", 3) == 0)
		ft_push(0, 1, d);
	else
		return (-1);
	return (0);
}
