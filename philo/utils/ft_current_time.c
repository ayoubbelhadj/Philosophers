/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:39:40 by abelhadj          #+#    #+#             */
/*   Updated: 2023/03/24 18:01:19 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <sys/time.h>

long	ft_get_time(void)
{
	struct timeval	tp;
	long			time;

	gettimeofday(&tp, NULL);
	time = tp.tv_sec * 1e3 + tp.tv_usec / 1e3;
	return (time);
}

long	ft_current_time(t_philo *philo)
{
	long	time;

	time = ft_get_time() - philo->data->time_start;
	return (time);
}
