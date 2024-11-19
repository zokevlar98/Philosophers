/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:36:44 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/19 01:46:21 by zqouri           ###   ########.fr       */
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
			return (data->dead = 1, 1);
		if ((get_time_now() - data->philos[i].last_meal) > data->time_to_die)
		{
			data->dead = 1;
			pthread_mutex_lock(&data->print);
			printf("%ld ", get_time_now() - data->start_time);
			printf("%d %s\n", data->philos[i].id, "is dead");
			return (1);
		}
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
	while (!tmp->data->dead)
	{
		pthread_mutex_lock(tmp->fork_l);
		print_status(tmp, "has taken a fork");
		pthread_mutex_lock(&tmp->fork);
		print_status(tmp, "has taken a fork");
		print_status(tmp, "is eating");
		tmp->nbr_meals_per_philo++;
		if (tmp->nbr_meals_per_philo == tmp->data->nbr_meals)
			tmp->data->nbr_philo_meals++;
		tmp->last_meal = get_time_now();
		ft_usleep(tmp->data->time_to_eat);
		pthread_mutex_unlock(tmp->fork_l);
		pthread_mutex_unlock(&tmp->fork);
		print_status(tmp, "is sleeping");
		ft_usleep(tmp->data->time_to_sleep);
		print_status(tmp, "is thinking");
	}
	return (NULL);
}

int	start_simulation(t_data *data)
{
	int			i;
	t_philos	*tmp;

	i = 0;
	tmp = data->philos;
	data->start_time = get_time_now();
	while (i < data->nbr_philo)
	{
		tmp[i].last_meal = data->start_time;
		if (pthread_create(&tmp[i].philo, NULL, &routine, &tmp[i]))
			return (free(data->philos), 1);
		pthread_detach(tmp[i].philo);
		i++;
	}
	if (check_death(data))
		return (destroy_mutexs(data, data->nbr_philo - 1), free(tmp), 1);
	return (0);
}
