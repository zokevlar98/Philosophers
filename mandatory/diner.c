/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:36:44 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/17 03:17:38 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philos *philo, char *status)
{
	if (philo->data->dead)
		return ;
	pthread_mutex_lock(&philo->data->print);
	printf("%ld ", get_time_now() - philo->data->start_time);
	printf("%d %s\n", philo->id, status);
	pthread_mutex_unlock(&philo->data->print);
}

void	*routine(void *args)
{
	t_philos	*tmp;

	tmp = (t_philos *)args;
	if (tmp->id % 2 != 0)
		ft_usleep(10);
	while (tmp->data->dead == 0)
	{
		pthread_mutex_lock(&tmp->data->philos[tmp->id - 1].fork);
		print_status(tmp, "has taken a fork");
		pthread_mutex_lock(&tmp->data->philos[tmp->id % tmp->data->nbr_philo].fork);
		print_status(tmp, "has taken a fork");
		print_status(tmp, "is eating");
		pthread_mutex_lock(&tmp->data->monitor);
		tmp->last_meal = get_time_now();
		pthread_mutex_unlock(&tmp->data->monitor);
		tmp->nbr_meals_per_philo++;
		if (tmp->data->nbr_meals > -1 && (tmp->nbr_meals_per_philo == tmp->data->nbr_meals))
			tmp->data->nbr_philo_meals++;
		ft_usleep(tmp->data->time_to_eat);
		pthread_mutex_unlock(&tmp->data->philos[tmp->id - 1].fork);
		pthread_mutex_unlock(&tmp->data->philos[tmp->id % tmp->data->nbr_philo].fork);
		print_status(tmp, "is thinking");
		print_status(tmp, "is sleeping");
		// if(tmp->data->dead)
		// 	return (NULL);
		ft_usleep(tmp->data->time_to_sleep);
	}
	return (NULL);
}
