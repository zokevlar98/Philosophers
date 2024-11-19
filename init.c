/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:02:48 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/19 01:41:42 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexs(t_data *data, int n)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->print);
	while (i < n)
	{
		pthread_mutex_destroy(&data->philos[i].fork);
		i++;
	}
}

t_data	*init(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->print, NULL))
		return (NULL);
	data->philos = malloc(sizeof(t_philos) * data->nbr_philo);
	if (!data->philos)
		return (destroy_mutexs(data, 0), NULL);
	while (i < data->nbr_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].nbr_meals_per_philo = 0;
		data->philos[i].data = data;
		if (pthread_mutex_init(&data->philos[i].fork, NULL))
			return (destroy_mutexs(data, i), free(data->philos), NULL);
		if (i + 1 == data->nbr_philo)
			data->philos[i].fork_l = &data->philos[0].fork;
		else
			data->philos[i].fork_l = &data->philos[i + 1].fork;
		i++;
	}
	return (data);
}
