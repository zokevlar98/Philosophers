/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:02:48 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/12 20:28:40 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t *allocate_mutex(int nbr)
{
	pthread_mutex_t	*mutex;

	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nbr);
	if (!mutex)
		return (NULL);
	return (mutex);
}

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
		// pthread_mutex_init(&tmp[i].print, NULL);
		tmp[i].id = i + 1;
		tmp[i].nbr_meals_per_philo = 0;
		tmp[i].last_meal = 0;
		i++;
	}
	i = 0;
	pthread_mutex_init(&data->print, NULL);
	while (i < n)
	{
		if (pthread_create(&tmp[i].philo, NULL, &routine, &tmp[i]))
		{
			ft_putstr_fd("Error: pthread_create\n", 2);
			return (NULL);
		}
		i++;
	}
	if (death_checker(tmp, n))
		return (NULL);
	//exit_dyal()
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
	int			nbr_meals;
	t_philos	tmp;

	while (1)
	{
		i = 0;
		nbr_meals = 0;
		while (i < n)
		{
			tmp = philo[i];
			if ((long)(get_time_now() - tmp.last_meal) >= philo->data->time_to_die)
				return (print_status(&tmp, "is dead"), philo->data->dead = 1);
			i++;
		}
	}
	return (0);
}
