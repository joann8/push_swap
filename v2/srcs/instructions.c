/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:02:55 by jacher            #+#    #+#             */
/*   Updated: 2021/05/11 19:21:52 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

void	update_inst_bis(t_list **src)
{
	t_list	*tmp;
	t_list	*del;

	tmp = *src;
	if ((((ft_strncmp((const char *)tmp->content, "sa", 3) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "sb", 3) == 0))
		|| ((ft_strncmp((const char *)tmp->content, "sb", 3) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "sa", 3) == 0))
	{
		free(tmp->content);
		free(tmp->next->content);
		del = tmp->next;
		tmp->next = tmp->next->next;
		free(del);
		tmp->content = ft_strdup("ss");
	}
	else if ((((ft_strncmp((const char *)tmp->content, "rra", 4) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "rrb", 4) == 0))
		|| ((ft_strncmp((const char *)tmp->content, "rrb", 4) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "rra", 4) == 0))
	{
		free(tmp->content);
		free(tmp->next->content);
		del = tmp->next;
		tmp->next = tmp->next->next;
		free(del);
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
			free(tmp->content);
		free(tmp->next->content);
		del = tmp->next;
		tmp->next = tmp->next->next;
		free(del);
		
			tmp->content = ft_strdup("rr");
		}
		else if ((((ft_strncmp((const char *)tmp->content, "sa", 3) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "sb", 3) == 0))
		|| ((ft_strncmp((const char *)tmp->content, "sb", 3) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "sa", 3) == 0))
	{
		free(tmp->content);
		free(tmp->next->content);
		del = tmp->next;
		tmp->next = tmp->next->next;
		free(del);
		tmp->content = ft_strdup("ss");
	}
	else if ((((ft_strncmp((const char *)tmp->content, "rra", 4) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "rrb", 4) == 0))
		|| ((ft_strncmp((const char *)tmp->content, "rrb", 4) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "rra", 4) == 0))
	{
		free(tmp->content);
		free(tmp->next->content);
		del = tmp->next;
		tmp->next = tmp->next->next;
		free(del);
		tmp->content = ft_strdup("rrr");
	}

	//	else
	//		update_inst_bis(&tmp);
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
