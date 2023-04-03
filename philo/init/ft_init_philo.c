/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:03:57 by abelhadj          #+#    #+#             */
/*   Updated: 2023/04/02 23:39:40 by abelhadj         ###   ########.fr       */
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
	data->end = 0;
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->eat, NULL);
	pthread_mutex_init(&data->die, NULL);
	while (i <= data->nbr_philo)
	{
		newphilo(data, &philo, i);
		i++;
	}
	return (philo);
}
