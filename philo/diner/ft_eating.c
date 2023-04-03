/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:19:50 by abelhadj          #+#    #+#             */
/*   Updated: 2023/04/03 00:18:50 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	if (philo->data->end)
		return ;
	ft_message(philo, "EATING 🍽 .\n", 1);
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_lock(&philo->data->die);
	philo->last_eat = ft_get_time();
	pthread_mutex_unlock(&philo->data->die);
	pthread_mutex_lock(&philo->data->eat);
	philo->eat++;
	pthread_mutex_unlock(&philo->data->eat);
	ft_usleep(philo->data->time_to_eat);
}
