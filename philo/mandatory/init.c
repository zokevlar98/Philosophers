/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:02:48 by zqouri            #+#    #+#             */
/*   Updated: 2024/09/19 09:02:20 by zqouri           ###   ########.fr       */
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

t_data	*init_philos(t_data **data, int n)
{
	int         	i;
	t_philos		*last;
	t_philos    	*philo;
	pthread_mutex_t *m;
	pthread_mutex_t *p;

	i = 1;
	m = allocate_mutex(n);
	p = allocate_mutex(1);
	if (!m || !p)
		return (NULL);
	while (i < n)
	{
		if (pthread_mutex_init(&m[i - 1], NULL))
			return (NULL);
		philo = ft_lstnew_ph(i, *data);
		if (!philo)
			return (NULL);
		philo->print = p;
		philo->monitor = &m[i - 1];
		ft_lstadd_back_ph(&(*data)->philos, philo);
		i++;
	}
	last = ft_lstlast_ph((*data)->philos);
	last->next = (t_philos *)(*data)->philos;//error
	return (free(m) ,free(p) , (*data));
}
