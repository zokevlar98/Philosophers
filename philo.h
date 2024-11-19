/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 03:15:28 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/19 01:45:32 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philos
{
	int						id;
	int						nbr_meals_per_philo;
	_Atomic unsigned long	last_meal;
	pthread_t				philo;
	pthread_mutex_t			fork;
	pthread_mutex_t			*fork_l;
	struct s_data			*data;
}	t_philos;

typedef struct s_data
{
	int				nbr_philo;
	_Atomic int		nbr_philo_meals;
	int				nbr_meals;
	unsigned long	time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	unsigned long	start_time;
	_Atomic int		dead;
	pthread_mutex_t	print;
	struct s_philos	*philos;
}	t_data;

long long		ft_atoi(char *str);
unsigned long	get_time_now(void);
void			ft_usleep(unsigned long time);
t_data			*parsing(int ac, char **av);
int				check_args(char **av);
t_data			*init_philos(t_data *data, int n);
void			print_status(t_philos *philo, char *status);
void			destroy_mutexs(t_data *data, int n);
void			*routine(void *args);
int				start_simulation(t_data *data);
t_data			*init(t_data *data);

#endif