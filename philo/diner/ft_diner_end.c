/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diner_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 03:09:03 by abelhadj          #+#    #+#             */
/*   Updated: 2023/03/30 22:06:04 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_diner_end(t_philo *philo)
{
	while (1)
	{
		if (philo->data->nbr_must_eat > 0)
		{
			if (!philo->finish && philo->eat >= philo->data->nbr_must_eat)
			{
				philo->data->finish++;
				philo->finish = 1;
			}
			if (philo->data->finish >= philo->data->nbr_philo)
			{
				printf("\033[0;37m	THE %d PHILOSOPHERS HAVE EAT %d TIME.\n",
					philo->data->nbr_philo, philo->data->nbr_must_eat);
				return ;
			}
		}
		if (philo->data->time_to_die <= (ft_get_time() - philo->last_eat)
			&& ft_current_time(philo) % philo->data->time_to_die == 0)
		{
			ft_message(philo, "DIED 😵\n", 0);
			break ;
		}
		philo = philo->next;
	}
}
