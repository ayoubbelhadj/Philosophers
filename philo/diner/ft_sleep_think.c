/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep_think.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:21:30 by abelhadj          #+#    #+#             */
/*   Updated: 2023/03/30 16:21:25 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_sleep_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	ft_message(philo, "SLEEPING 😴.\n", 4);
	pthread_mutex_unlock(&philo->data->lock);
	ft_usleep(philo->data->time_to_sleep);
	pthread_mutex_lock(&philo->data->lock);
	ft_message(philo, "THINKING 🤔.\n", 2);
	pthread_mutex_unlock(&philo->data->lock);
}
