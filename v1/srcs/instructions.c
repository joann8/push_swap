/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:02:55 by jacher            #+#    #+#             */
/*   Updated: 2021/03/23 11:48:53 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

void	update_inst_bis(t_list *tmp)
{
	t_list *del;

	if ((((ft_strncmp((const char *)tmp->content, "sa", 2) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "sb", 2) == 0))
		|| ((ft_strncmp((const char *)tmp->content, "sb", 2) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "sa", 2) == 0))
	{
	//	printf("swap\n");
	//		printf("---->1\n");
		del = tmp->next;
	//		printf("---->2\n");
		tmp->next = tmp->next->next;
	//		printf("---->3\n");
	//	free(tmp->content);
	//		printf("---->4\n");
		tmp->content = ft_strdup("ss");
	//		printf("---->5\n");
		free(del);
	//		printf("---->6\n");
	}
	else if ((((ft_strncmp((const char *)tmp->content, "rra", 3) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "rrb", 3) == 0))
		|| ((ft_strncmp((const char *)tmp->content, "rrb", 3) == 0)
		&& ft_strncmp((const char *)tmp->next->content, "rra", 3) == 0))
	{
	//	printf("rrotate\n");
	//		printf("---->1\n");
		del = tmp->next;
	//		printf("---->2\n");
		tmp->next = tmp->next->next;
	//		printf("---->3\n");
		free(del);
	//		printf("---->4\n");
		free(tmp->content);
	//		printf("---->5\n");
		tmp->content = ft_strdup("rrr");
	//		printf("---->6\n");
	}
}

void	update_inst(t_list **l)
{
	t_list *tmp;
	t_list *del;

	//printf("enter update inst\n");
	tmp = *l;
	while (tmp && tmp->next)
	{
		if ((((ft_strncmp((const char *)tmp->content, "ra", 2) == 0)
			&& ft_strncmp((const char *)tmp->next->content, "rb", 2) == 0))
			|| ((ft_strncmp((const char *)tmp->content, "rb", 2) == 0)
			&& ft_strncmp((const char *)tmp->next->content, "ra", 2) == 0))
		{
	//		printf("rotate\n");
	//		printf("---->1\n");
			del = tmp->next;
	//		printf("---->2\n");
			tmp->next = tmp->next->next;
	//		printf("---->3\n");
			//free(tmp->content);
	//		printf("---->4\n");
			tmp->content = ft_strdup("rrr");//attnbetion erreur malloc
	//		printf("---->5\n");
			free(del);
	//		printf("---->6\n");
		}
		else
			update_inst_bis(tmp);
		tmp = tmp->next;
	}
}

void	execute_inst_test(t_list **l, t_d *d)
{
	t_list *tmp;
	t_list *del;

	del = NULL;
	tmp = *l;
	while (tmp)
	{
		if (ft_strncmp((const char *)tmp->content, "ra", 2) == 0)
			ft_rotate_bis(1, 0 , d, &del);
		else if (ft_strncmp((const char *)tmp->content, "rb", 2) == 0)
			ft_rotate_bis(0, 1, d, &del);
		else if (ft_strncmp((const char *)tmp->content, "rr", 2) == 0)
			ft_rotate_bis(1, 1 , d, &del);
		else if (ft_strncmp((const char *)tmp->content, "sa", 2) == 0)
			ft_swap_bis(1, 0 , d, &del);
		else if (ft_strncmp((const char *)tmp->content, "sb", 2) == 0)
			ft_swap_bis(0, 1, d, &del);
		else if (ft_strncmp((const char *)tmp->content, "ss", 2) == 0)
			ft_swap_bis(1, 1 , d, &del);
		else if (ft_strncmp((const char *)tmp->content, "rra", 3) == 0)
			ft_rrotate_bis(1, 0 , d, &del);
		else if (ft_strncmp((const char *)tmp->content, "rrb", 3) == 0)
			ft_rrotate_bis(0, 1, d, &del);
		else if (ft_strncmp((const char *)tmp->content, "rrr", 3) == 0)
			ft_rrotate_bis(1, 1 , d, &del);
		else if (ft_strncmp((const char *)tmp->content, "pa", 2) == 0)
			ft_push_bis(1, 0 , d, &del);
		else if (ft_strncmp((const char *)tmp->content, "pb", 2) == 0)
			ft_push_bis(0, 1, d, &del);
		else
			printf("erreur instructions\n");
		tmp = tmp->next;
	}
}

void	execute_inst(char *str, t_d *d, int a, int b)
{
	int i;

	i = 0;
	while (str[i])
	{
		a = 0;
		b = 0;
		if (str[i + 1] == 'a' || str[i + 2] == 'a' || str[i + 1] == 's'
			|| (str[i + 1] == 'r' && (str[i + 2] == '\n' || str[i + 2] == '\0'
			|| str[i + 2] == 'r')))
			a = 1;
		if (str[i + 1] == 'b' || str[i + 2] == 'b' || str[i + 1] == 's'
			|| (str[i + 1] == 'r' && (str[i + 2] == '\n' || str[i + 2] == '\0'
			|| str[i + 2] == 'r')))
			b = 1;
		if (str[i] == 's')
			ft_swap(a, b, d, &i);
		else if (str[i] == 'p')
			ft_push(a, b, d, &i);
		else if (str[i] == 'r' && (str[i + 2] == '\n' || str[i + 2] == '\0'))
			ft_rotate(a, b, d, &i);
		else
			ft_rrotate(a, b, d, &i);
	}
}

int		check_letters(char *str, int i)
{
	if (str[i] == 's'
		&& (str[i + 1] == 'a' || str[i + 1] == 'b' || str[i + 1] == 's')
		&& (str[i + 2] == '\n' || str[i + 2] == '\0'))
		return (2);
	else if (str[i] == 'p'
		&& (str[i + 1] == 'a' || str[i + 1] == 'b')
		&& (str[i + 2] == '\n' || str[i + 2] == '\0'))
		return (2);
	else if (str[i] == 'r'
		&& (str[i + 1] == 'a' || str[i + 1] == 'b' || str[i + 1] == 'r')
		&& (str[i + 2] == '\n' || str[i + 2] == '\0'))
		return (2);
	else if (str[i] == 'r' && str[i + 1] == 'r'
		&& (str[i + 2] == 'a' || str[i + 2] == 'b' || str[i + 2] == 'r')
		&& (str[i + 3] == '\n' || str[i + 3] == '\0'))
		return (3);
	else
		return (0);
}

int		check_inst(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (check_letters(str, i) > 0)
			i += check_letters(str, i);
		else
			return (-1);
		if (str[i])
			i++;
	}
	return (1);
}
