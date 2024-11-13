/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:02:48 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/13 22:32:06 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init_philos(t_data *data, int n)
{
	t_philos	*tmp = NULL;
	int	i = 0;

	if (!data)
		return (NULL);
	tmp = malloc(sizeof(t_philos) * n);
	if (!tmp)
		return (NULL);
	while (i < n)
	{
		tmp[i].data = data;
		pthread_mutex_init(&tmp[i].fork, NULL);
		tmp[i].id = i + 1;
		tmp[i].nbr_meals_per_philo = 0;
		tmp[i].last_meal = get_time_now();
	data->philos = tmp;
		i++;
	}
	data->nbr_philo_meals = 0;
	i = 0;
	pthread_mutex_init(&data->print, NULL);
	while (i < n)
	{
		if (pthread_create(&tmp[i].philo, NULL, &routine1, &tmp[i]))
		{
			printf("Error: pthread_create\n");
			return (NULL);
		}
		i++;
	}
	if (death_checker(tmp, n))
		return (NULL);
	i = 0;
	while (i < n)
	{
		pthread_join(tmp[i].philo, NULL);
		i++;
	}
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
		while (i < n)
		{
			tmp = philo[i];
			if (n == philo->data->nbr_philo_meals)
			{
				philo->data->dead = 1;
				for(int j = 0; j < n; j++)
					pthread_join(philo[j].philo, NULL);
				return (1);
			}
			if ((long)(get_time_now() - tmp.last_meal) > philo->data->time_to_die)
			{
				philo->data->dead = 1;
				for(int j = 0; j < n; j++)
					pthread_join(philo[j].philo, NULL);
				pthread_mutex_lock(&philo->data->print);
				printf("%ld %d %s\n", get_time_now() - philo->data->start_time, philo->id, "is dead");
				return (1);
			}
			i++;
		}
	}
	return (0);
}
