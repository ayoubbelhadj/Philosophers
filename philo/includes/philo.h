/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:15:57 by abelhadj          #+#    #+#             */
/*   Updated: 2023/03/16 15:48:11 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <pthread.h>


typedef struct s_philo
{
	int			id;
	t_data		*data;
	pthread_t	thread;
	int			die;
	long long	last_eat;
}	t_philo;

typedef struct s_data
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_must_eat;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	int				finish;
}	t_data;

/* INIT */
int		ft_check_arg(int ac, char **av);
void	ft_get_arg(t_data *data, int ac, char **av);
int		ft_init(t_data *data);

/* UTILS */
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t num, size_t size);
int		ft_error(char *str);
int		ft_isdigit(int c);

#endif