/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diner.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:28:03 by abelhadj          #+#    #+#             */
/*   Updated: 2023/03/30 22:17:47 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routin(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (1)
	{
		ft_fork_right(philo, &philo->fork);
		ft_fork_left(philo, &philo->next->fork);
		ft_eating(philo);
		ft_fork_down(philo);
		ft_sleep_think(philo);
	}
}

int	ft_diner(t_philo *philo)
{
	int	i;

	i = 1;
	while (i <= philo->data->nbr_philo)
	{
		if (pthread_create(&philo->thread, NULL, &routin, philo))
			return (1);
		philo = philo->next;
		i++;
		usleep(100);
	}
	return (0);
}
