/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:36:44 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/12 20:30:24 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philos *philo, char *status)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %d %s\n", get_time_now() - philo->data->start_time, philo->id, status);
	pthread_mutex_unlock(&philo->data->print);
}

void    *routine(void *arg)
{
	t_philos *philo;
	
	philo = (t_philos *)arg;
	if (philo->id % 2 != 0)
		ft_usleep(100);
	while (1)
	{
		if (philo->data->dead)
			break ;
		pthread_mutex_lock(&philo->fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(&(philo + 1)->fork);
		print_status(philo, "has taken a fork");
		print_status(philo, "is eating");
		philo->last_meal = get_time_now();
		ft_usleep(philo->data->time_to_eat);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&(philo + 1)->fork);
		print_status(philo, "is thinking");
		print_status(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
	}
	return (NULL);
}

void    diner_start(t_philos *philo, int nbr)
{
	int i;

	i = 0;
	while (i < nbr)
	{
		if (pthread_create(&philo->philo, NULL, &routine, (void *)philo))
		i++;
	}
}
