/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 03:15:28 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/18 00:12:16 by zqouri           ###   ########.fr       */
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

/*
**  STRUCTURES
nbr_philo   time_to_die time_to_eat time_to_sleep [nbr_meals]
		./philo 5 800 200 200
*/
typedef struct s_philos
{
	int				id;//init
	int				nbr_meals_per_philo;//init
	unsigned long	last_meal;//start_simulation
	// pthread_t		philo;//start_simulation
	pthread_mutex_t	fork;//init
	pthread_mutex_t	*fork_l;//init
	struct s_data	*data;//init
}	t_philos;

typedef struct s_data
{
	int				nbr_philo;//parsing
	_Atomic int		nbr_philo_meals;
	int				nbr_meals;//parsing
	long			time_to_die;//parsing
	long			time_to_eat;//parsing
	long			time_to_sleep;//parsing
	unsigned long	start_time;//start_simulation
	_Atomic int		dead;//parsing
	pthread_mutex_t	print;//init
	pthread_mutex_t	monitor;//init
	struct s_philos	*philos;//init
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