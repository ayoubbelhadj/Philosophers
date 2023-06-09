/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:49:41 by abelhadj          #+#    #+#             */
/*   Updated: 2023/03/24 00:21:10 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_init(t_data *data, t_philo *philo)
{
	philo = ft_init_philo(data);
	if (!philo)
		return (1);
	return (0);
}
