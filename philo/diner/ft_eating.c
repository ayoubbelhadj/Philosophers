/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:19:50 by abelhadj          #+#    #+#             */
/*   Updated: 2023/03/24 16:19:15 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_eating(t_philo *philo)
{
	ft_message(philo, "is eating\n");
	philo->last_eat = ft_get_time();
	philo->eat++;
	usleep(philo->data->time_to_eat * 1000);
}
