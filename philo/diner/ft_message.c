/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 02:29:17 by abelhadj          #+#    #+#             */
/*   Updated: 2023/04/04 23:09:53 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_message(t_philo *philo, char *str, int flag)
{
	long	time;

	time = ft_current_time(philo);
	if (flag == 1)
		printf("\033[0;32m%ld PHILO %d %s", time, philo->id, str);
	else if (flag == 2)
		printf("\033[0;37m%ld PHILO %d %s", time, philo->id, str);
	else if (flag == 3)
		printf("\033[0;34m%ld PHILO %d %s", time, philo->id, str);
	else if (flag == 4)
		printf("\033[0;30m%ld PHILO %d %s", time, philo->id, str);
	else if (flag == 0)
		printf("\033[0;101m%ld PHILO %d %s", time, philo->id, str);
}
