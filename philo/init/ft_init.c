/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:49:41 by abelhadj          #+#    #+#             */
/*   Updated: 2023/03/16 15:47:28 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_init(t_data *data)
{
	int	nbr_philo;

	nbr_philo = data->nbr_philo;
	data->philo = ft_calloc(nbr_philo, sizeof(t_philo));
	data->forks = ft_calloc(nbr_philo, sizeof(pthread_mutex_t));
	if (!data->philo || !data->forks)
		return (1);
	ft_mutex(data);
}
