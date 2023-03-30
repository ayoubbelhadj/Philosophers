/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:19:50 by abelhadj          #+#    #+#             */
/*   Updated: 2023/03/30 16:20:49 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	ft_message(philo, "EATING 🍽 .\n", 1);
	pthread_mutex_unlock(&philo->data->lock);
	philo->last_eat = ft_get_time();
	philo->eat++;
	ft_usleep(philo->data->time_to_eat);
}
