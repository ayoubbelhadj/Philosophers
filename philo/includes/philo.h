/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:15:57 by abelhadj          #+#    #+#             */
/*   Updated: 2023/03/24 16:11:42 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

typedef struct s_philo
{
	int				id;
	t_data			*data;
	pthread_t		thread;
	int				die;
	int				eat;
	long long		last_eat;
	int				finish;
	pthread_mutex_t	fork;
	struct s_philo	*next;
	struct s_philo	*previous;
}	t_philo;

typedef struct s_data
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_must_eat;
	pthread_mutex_t	lock;
	int				finish;
	long			time_start;
}	t_data;

/* DINER */
int		ft_diner(t_philo *philo);
void	ft_eating(t_philo *philo);
void	ft_fork_down(t_philo *philo);
void	ft_fork_up(t_philo *philo, pthread_mutex_t *fork);
void	ft_message(t_philo *philo, char *str);
void	ft_sleep_think(t_philo *philo);

/* INIT */
int		ft_check_arg(int ac, char **av);
void	ft_get_arg(t_data *data, int ac, char **av);
t_philo	*ft_init_philo(t_data *data);
int		ft_init(t_data *data, t_philo *philo);

/* UTILS */
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t num, size_t size);
long	ft_get_time(void);
long	ft_current_time(t_philo *philo);
int		ft_error(char *str);
int		ft_isdigit(int c);

#endif