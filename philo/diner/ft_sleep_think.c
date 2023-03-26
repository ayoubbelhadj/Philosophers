/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep_think.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:21:30 by abelhadj          #+#    #+#             */
/*   Updated: 2023/03/24 02:41:19 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_sleep_think(t_philo *philo)
{
	ft_message(philo, "is sleeping\n");
	usleep(philo->data->time_to_sleep * 1000);
	ft_message(philo, "is thinking\n");
}
