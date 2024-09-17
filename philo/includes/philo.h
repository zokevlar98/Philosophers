/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 03:15:28 by zqouri            #+#    #+#             */
/*   Updated: 2024/09/18 00:26:24 by zqouri           ###   ########.fr       */
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
    int             id;
    int				nbr_meals_per_philo;
    long            last_meal;
    pthread_t       philo;
    pthread_mutex_t *fork;
    pthread_mutex_t *monitor;
    pthread_mutex_t *print;
	struct s_philo	*next;
}   t_philos;

typedef struct s_data
{
    int		nbr_philo;
    int		nbr_meals;
	long	time_to_die;
    long	time_to_eat;
    long	time_to_sleep;
    long	start_time;
    struct s_philos	*philos;
}   t_data;

//utils
long long ft_atoi(char *str);

//parsing
t_data *parsing(int ac, char **av);
int     check_args(char **av);
# endif