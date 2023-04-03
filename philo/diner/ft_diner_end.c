/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diner_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 03:09:03 by abelhadj          #+#    #+#             */
/*   Updated: 2023/04/03 02:00:41 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_eat_check(t_philo *philo)
{
	if (philo->data->nbr_must_eat > 0)
	{
		if (!philo->finish && philo->eat >= philo->data->nbr_must_eat)
		{
			philo->data->finish++;
		}
		if (philo->data->finish >= philo->data->nbr_philo)
		{
			philo->data->end = 1;
			printf("\033[0;37m	THE %d PHILOSOPHERS HAVE EAT %d TIME.\n",
				philo->data->nbr_philo, philo->data->nbr_must_eat);
			return (1);
		}
	}
	return (0);
}

void	ft_diner_end(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->data->eat);
		if (ft_eat_check(philo))
			return ;
		pthread_mutex_unlock(&philo->data->eat);
		pthread_mutex_lock(&philo->data->die);
		if (philo->data->time_to_die <= (ft_get_time() - philo->last_eat)
			&& ft_current_time(philo) % philo->data->time_to_die == 0)
		{
			philo->data->end = 1;
			ft_message(philo, "DIED 😵\n", 0);
			break ;
		}
		pthread_mutex_unlock(&philo->data->die);
		philo = philo->next;
	}
}
