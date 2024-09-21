/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:02:48 by zqouri            #+#    #+#             */
/*   Updated: 2024/09/21 03:51:47 by zqouri           ###   ########.fr       */
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
	t_philos    	*tmp;
	pthread_mutex_t *m;
	pthread_mutex_t *p;

	i = 1;
	if (!data)
		return (NULL);
	m = allocate_mutex(n);
	p = allocate_mutex(1);
	if (!m || !p)
		return (NULL);
	while (i < n + 1)
	{
		if (pthread_mutex_init(&m[i - 1], NULL))
			return (NULL);
		tmp = ft_lstnew_ph(i, *data);
		if (!tmp)
			return (NULL);
		tmp->print = p;
		tmp->monitor = &m[i - 1];
		ft_lstadd_back_ph(&(*data)->philos, tmp);
		i++;
	}
	ft_lstlast_ph((*data)->philos)->next = (*data)->philos;
	return (free(m) ,free(p) , (*data));
}
