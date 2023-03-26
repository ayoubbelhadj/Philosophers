/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:20:41 by abelhadj          #+#    #+#             */
/*   Updated: 2023/03/24 02:41:35 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_fork_up(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	ft_message(philo, "has taken a fork\n");
}
