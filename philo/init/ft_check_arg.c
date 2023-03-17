/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:55:12 by abelhadj          #+#    #+#             */
/*   Updated: 2023/03/14 18:09:50 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	int	ft_notdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '+' && ft_isdigit(str[i + 1]))
			{
			}
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_arg(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (ft_error("Check your arguments.\n"));
	if (ft_notdigit(av[1]) || ft_notdigit(av[2]) || ft_notdigit(av[3])
		|| ft_notdigit(av[4]))
		return (ft_error("One of your arg is not a num or a time.\n"));
	if (ac == 6 && ft_notdigit(av[5]))
		return (ft_error("One of your arg is not a num or a time.\n"));
	if (ft_atoi(av[1]) < 0 || ft_atoi(av[1]) > INT_MAX)
		return (ft_error("wrong num of philo.\n"));
	if (ft_atoi(av[2]) < 60 || ft_atoi(av[1]) > INT_MAX)
		return (ft_error("wrong time to die.\n"));
	if (ft_atoi(av[3]) < 60 || ft_atoi(av[1]) > INT_MAX)
		return (ft_error("wrong time to eat.\n"));
	if (ft_atoi(av[4]) < 60 || ft_atoi(av[1]) > INT_MAX)
		return (ft_error("wrong time to sleep.\n"));
	if (ac == 6 && (ft_atoi(av[5]) <= 0 || ft_atoi(av[1]) > INT_MAX))
		return (ft_error("wrong num of must eat.\n"));
	return (0);
}
