/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:02:48 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/17 00:09:08 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init_philos(t_data *data, int n)
{
	t_philos	*tmp;
	int			i;

	i = 0;
	tmp = malloc(sizeof(t_philos) * n);
	if (!tmp)
		return (NULL);
	data->nbr_philo_meals = 0;
	pthread_mutex_init(&data->print, NULL);
	while (i < n)
	{
		tmp[i].data = data;
		pthread_mutex_init(&tmp[i].fork, NULL);
		tmp[i].id = i + 1;
		tmp[i].nbr_meals_per_philo = 0;
		tmp[i].last_meal = get_time_now();
		i++;
	}
	data->philos = tmp;
	i = 0;
	while (i < n)
	{
		if (pthread_create(&tmp[i].philo, NULL, &routine, &tmp[i]))
			return (printf("Error: pthread_create\n"), NULL);
		i++;
	}
	for (int j = 0; j < n; j++)
		pthread_detach(tmp[j].philo);
	if (death_checker(tmp, n))
		return (NULL);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&tmp->fork);
	free(tmp);
	return (data);
}

int	death_checker(t_philos *philo, int n)
{
	int			i;
	t_philos	tmp;

	while (1)
	{
		i = 0;
		ft_usleep(10);
		while (i < n)
		{
			tmp = philo[i];
			if (n == philo->data->nbr_philo_meals)
			{
				philo->data->dead = 1;
				return (1);
			}
			if ((long)(get_time_now() - tmp.last_meal) > philo->data->time_to_die)
			{
				philo->data->dead = 1;
				pthread_mutex_lock(&philo->data->print);
				printf("%ld %d %s\n", get_time_now() - philo->data->start_time, philo->id, "is dead");
				return (1);
			}
			i++;
		}
	}
	return (0);
}
