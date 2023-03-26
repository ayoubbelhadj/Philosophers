/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 02:29:17 by abelhadj          #+#    #+#             */
/*   Updated: 2023/03/24 16:19:28 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_message(t_philo *philo, char *str)
{
	long	time;

	pthread_mutex_lock(&philo->data->lock);
	time = ft_current_time(philo);
	printf("\033[0;32m%ld Philo %d %s", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->lock);
}
