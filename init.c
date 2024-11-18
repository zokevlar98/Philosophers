/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:02:48 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/17 23:41:52 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexs(t_data *data, int n)
{
	pthread_mutex_destroy(&data->print);
	if (n > 0)
		pthread_mutex_destroy(&data->monitor);
}

int	init_mutexs(t_data *data)
{
	if (pthread_mutex_init(&data->print, NULL))
		return (1);
	if (pthread_mutex_init(&data->monitor, NULL))
		return (destroy_mutexs(data, 0), 1);
	return (0);
}

t_data	*init(t_data *data)
{
	int	i;

	i = 0;
	if (init_mutexs(data))
		return (NULL);
	data->philos = malloc(sizeof(t_philos) * data->nbr_philo);
	if (!data->philos)
		return (destroy_mutexs(data, 1), NULL);
	while (i < data->nbr_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].nbr_meals_per_philo = 0;
		data->philos[i].data = data;
		if (pthread_mutex_init(&data->philos[i].fork, NULL))
			return (NULL);//i need to destroy all mutexs if it faild
		if (i + 1 == data->nbr_philo)
			data->philos[i].fork_l = &data->philos[0].fork;
		else
			data->philos[i].fork_l = &data->philos[i + 1].fork;
		// fprintf(stderr, "fork right: %p\n", &data->philos[i].fork);
		// fprintf(stderr, "fork left: %p\n\n\n", &(*data->philos[i].fork_l));
		i++;
	}	
	return (data);
}
