/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:28:48 by abelhadj          #+#    #+#             */
/*   Updated: 2023/03/28 01:36:08 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_putchar(int c)
{
	write(2, &c, 1);
}

int	ft_error(char *str)
{
	int	i;

	i = 0;
	write(2, "\033[0;31mERROR: ", 15);
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (1);
}
