/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mngt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:41:18 by jacher            #+#    #+#             */
/*   Updated: 2021/05/07 15:41:18 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sort.h"

int	ft_error(void)
{
	write(1, "Error\n", 6);
	//checker la sortie erreur
	return (-1);
}

int ft_print_err(char *s1, char *s2, char *s3, int ret_wanted)
{
	if (s1)
		ft_putstr_fd(s1, 2);
	if (s1)
		ft_putstr_fd(s2, 2);
	if (s1)
		ft_putstr_fd(s3, 2);
	return (ret_wanted);
}
