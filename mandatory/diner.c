/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:36:44 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/18 18:12:28 by zqouri           ###   ########.fr       */
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

int	check_death(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == data->nbr_philo)
			i = 0;
		if (data->nbr_meals != -1 && (data->nbr_philo_meals == data->nbr_philo))
		{
			data->dead = 1;
			return (1);
		}
		pthread_mutex_lock(&data->monitor);
		if ((long)(get_time_now() - data->philos[i].last_meal) > data->time_to_die)
		{
			data->dead = 1;
			pthread_mutex_lock(&data->print);
			printf("%ld %d %s\n", get_time_now() - data->start_time, data->philos[i].id, "is dead");
			return (1);
		}
		pthread_mutex_unlock(&data->monitor);
		i++;
	}
	return (0);
}

void	*routine(void *args)
{
	t_philos	*tmp;

	tmp = (t_philos *)args;
	if (tmp->id % 2 != 0)
		ft_usleep(20);
	while (1)
	{
		pthread_mutex_lock(tmp->fork_l);
		print_status(tmp, "has taken a fork");
		pthread_mutex_lock(&tmp->fork);
		print_status(tmp, "has taken a fork");
		print_status(tmp, "is eating");
		tmp->nbr_meals_per_philo++;
		if (tmp->nbr_meals_per_philo == tmp->data->nbr_meals)
			tmp->data->nbr_philo_meals++;
		pthread_mutex_lock(&tmp->data->monitor);
		tmp->last_meal = get_time_now();
		pthread_mutex_unlock(&tmp->data->monitor);
		ft_usleep(tmp->data->time_to_eat);
		pthread_mutex_unlock(tmp->fork_l);
		pthread_mutex_unlock(&tmp->fork);
		print_status(tmp, "is thinking");
		print_status(tmp, "is sleeping");
		if (tmp->data->dead)
			return (NULL);
		ft_usleep(tmp->data->time_to_sleep);
	}
	return (NULL);
}

int	start_simulation(t_data *data)
{
	int	i;
	pthread_t	tmp[201];

	i = 0;
	if (!data)
		return (1);
	data->start_time = get_time_now();
	while (i < data->nbr_philo)
	{
		data->philos[i].last_meal = data->start_time;
		if (pthread_create(&tmp[i], NULL, &routine, &data->philos[i]))
			return (free(data->philos), 1);
		pthread_detach(tmp[i]);
		i++;
	}
	if (check_death(data))
		return (destroy_mutexs(data, 1), free(data->philos), 1);//i need to destroy all mutexes
	return (0);
}
