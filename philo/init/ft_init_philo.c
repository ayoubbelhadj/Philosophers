/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:03:57 by abelhadj          #+#    #+#             */
/*   Updated: 2023/03/30 20:55:36 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	newphilo(t_data *data, t_philo **philo, int i)
{
	t_philo	*new_philo;

	new_philo = malloc(sizeof(t_philo));
	if (!new_philo)
	{
		ft_error("ALLOCATION.\n");
		return ;
	}
	new_philo->last_eat = data->time_start;
	new_philo->id = i;
	new_philo->finish = 0;
	new_philo->eat = 0;
	new_philo->data = data;
	pthread_mutex_init(&new_philo->fork, NULL);
	if (!*philo)
	{
		new_philo->next = new_philo;
		new_philo->previous = new_philo;
		*philo = new_philo;
		return ;
	}
	new_philo->previous = (*philo)->previous;
	new_philo->next = *philo;
	(*philo)->previous->next = new_philo;
	(*philo)->previous = new_philo;
}

t_philo	*ft_init_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 1;
	philo = NULL;
	pthread_mutex_init(&data->lock, NULL);
	while (i <= data->nbr_philo)
	{
		newphilo(data, &philo, i);
		i++;
	}
	return (philo);
}
