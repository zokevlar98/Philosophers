/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 03:15:28 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/13 22:14:25 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>
# include <pthread.h>
# include <sys/time.h>

/*
**  STRUCTURES
nbr_philo   time_to_die time_to_eat time_to_sleep [nbr_meals]
		./philo 5 800 200 200
*/
typedef struct s_philos
{
	int				id;
	int				nbr_meals_per_philo;
	long			last_meal;
	pthread_t		philo;
	pthread_mutex_t	fork;
	// pthread_mutex_t monitor;
	struct s_data	*data;
	// struct s_philos	*next;
}	t_philos;

typedef struct s_data
{
	int				nbr_philo;
	_Atomic		int	nbr_philo_meals;
	int				nbr_meals;
	long			time_to_die;
	long			time_to_eat;
	// pthread_mutex_t	*forks;
	long			time_to_sleep;
	long			start_time;
	_Atomic int				dead;
	pthread_mutex_t	print;
	struct s_philos	*philos;
}	t_data;

//utils
long long		ft_atoi(char *str);
unsigned long	get_time_now(void);
void			ft_usleep(unsigned long time);

//parsing
t_data			*parsing(int ac, char **av);
int				check_args(char **av);

//philo
t_data			*init_philos(t_data *data, int n);
void			diner_start(t_philos *philo, int nbr);
int				death_checker(t_philos *philo, int n);
void			print_status(t_philos *philo, char *status);
//test
void			affiche(t_data *data);
void			*routine1(void *args);

# endif