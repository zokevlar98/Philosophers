/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:36:44 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/17 00:08:34 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philos *philo, char *status)
{
	if (philo->data->dead)
		return ;
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %d %s\n", get_time_now() - philo->data->start_time, philo->id, status);
	pthread_mutex_unlock(&philo->data->print);
}

void	*routine(void *args)
{
	t_philos	*tmp;

	tmp = (t_philos *)args;
	if (tmp->id % 2 != 0)
		ft_usleep(100);
	while (tmp->data->dead == 0)
	{
		if (pthread_mutex_lock(&tmp->data->philos[tmp->id - 1].fork))
			break ;
		print_status(tmp, "has taken a fork");
		if (pthread_mutex_lock(&tmp->data->philos[tmp->id % tmp->data->nbr_philo].fork))
			break;
		print_status(tmp, "has taken a fork");
		print_status(tmp, "is eating");
		tmp->last_meal = get_time_now();
		tmp->nbr_meals_per_philo++;
		if (tmp->data->nbr_meals > -1 && (tmp->nbr_meals_per_philo == tmp->data->nbr_meals))
			tmp->data->nbr_philo_meals++;
		ft_usleep(tmp->data->time_to_eat);
		if (pthread_mutex_unlock(&tmp->data->philos[tmp->id - 1].fork))
			break;
		if (pthread_mutex_unlock(&tmp->data->philos[tmp->id % tmp->data->nbr_philo].fork))
			break;
		print_status(tmp, "is thinking");
		print_status(tmp, "is sleeping");
		ft_usleep(tmp->data->time_to_sleep);
	}
	return (NULL);
}
