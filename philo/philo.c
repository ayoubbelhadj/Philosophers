/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:11:27 by abelhadj          #+#    #+#             */
/*   Updated: 2023/03/30 22:23:08 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;

	if (ft_check_arg(ac, av))
		return (1);
	data = malloc(sizeof(t_data));
	ft_get_arg(data, ac, av);
	philo = ft_init_philo(data);
	if (!philo)
		return (1);
	if (ft_diner(philo))
		return (ft_error("Problem in Thread creation\n"));
	ft_diner_end(philo);
	return (0);
}
