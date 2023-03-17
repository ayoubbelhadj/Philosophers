/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:11:27 by abelhadj          #+#    #+#             */
/*   Updated: 2023/03/14 18:27:54 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ft_check_arg(ac, av) == 1)
		return (1);
	ft_get_arg(&data, ac, av);
	if (!ft_init(&data))
		return (0);

}
