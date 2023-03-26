/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:11:27 by abelhadj          #+#    #+#             */
/*   Updated: 2023/03/25 21:25:56 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	free_philo(t_philo *philo)
{
	t_philo	*tmp;

	if (philo)
	{
		tmp = philo->next;
		while (tmp != philo)
		{
			tmp = tmp->next;
			free(tmp->previous);
		}
		free(tmp);
		philo = NULL;
	}
}

int	death(t_philo *philo)
{
	while (1)
	{
		if (ft_get_time() - philo->last_eat >= philo->data->time_to_die
			&& ft_current_time(philo) % philo->data->time_to_die == 0)
		{
			ft_message(philo, "is die\n");
			break ;
		}
		if (philo->data->nbr_must_eat > 0)
		{
			if (philo->data->finish >= philo->data->nbr_philo)
			{
				pthread_mutex_lock(&philo->data->lock);
				break ;
			}
			if (philo->eat >= philo->data->nbr_must_eat && !philo->finish)
			{
				philo->finish = 1;
				philo->data->finish++;
			}
		}
		philo = philo->next;
	}
	return (1);
}


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
		return (1);
	if (death(philo))
	{
		free_philo(philo);
		free(data);
	}
	return (0);
}
