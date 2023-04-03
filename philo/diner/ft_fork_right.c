/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:20:41 by abelhadj          #+#    #+#             */
/*   Updated: 2023/04/03 00:19:11 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_fork_right(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	pthread_mutex_lock(&philo->data->lock);
	if (philo->data->end)
		return ;
	ft_message(philo, "TAKE THE RIGHT FORK 🥄.\n", 3);
	pthread_mutex_unlock(&philo->data->lock);
}
