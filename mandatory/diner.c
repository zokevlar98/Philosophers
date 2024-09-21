/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:36:44 by zqouri            #+#    #+#             */
/*   Updated: 2024/09/21 01:42:41 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philos *philo, char *status)
{
	pthread_mutex_lock(philo->print);
	printf("%ld %d %s\n", get_time_now() - philo->data->start_time, philo->id, status);
	pthread_mutex_unlock(philo->print);
}

void    *routine(void *arg)
{
	t_philos *philo;
	
	philo = (t_philos *)arg;
	if (philo->id % 2 != 0)
		ft_usleep(philo->data->time_to_eat);
	pthread_mutex_lock(philo->monitor);
	philo->last_meal = get_time_now();
	pthread_mutex_unlock(philo->monitor);
	while (1)
	{
		/*get right fork
		get left fork
		eat
		put right fork
		put left fork
		sleep
		tink
		*/
	}
}

void    diner_start(t_philos *philo, int nbr)
{
	int i;

	i = 0;
	while (i < nbr)
	{
		if (pthread_create(philo->philo, NULL, &routine, (void *)philo))
		i++;
	}
}
