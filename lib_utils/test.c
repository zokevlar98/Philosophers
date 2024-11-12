/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:35:58 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/12 22:14:26 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    affiche(t_data *data)
{
	t_philos    *tmp;
	t_philos    philo;
	int         i = 0;

	tmp = data->philos;
	printf("info data====================\n");
	printf("nbr_philo: %d\n", data->nbr_philo);
	printf("nbr_meals: %d\n", data->nbr_meals);
	printf("time_to_die: %ld\n", data->time_to_die);
	printf("time_to_eat: %ld\n", data->time_to_eat);
	printf("time_to_sleep: %ld\n", data->time_to_sleep);
	printf("start_time: %ld\n", data->start_time);
	while (i < n)
	{
		philo = tmp[i];
		printf("philos %d====================\n", tmp->id);
		printf("id: %d\n", tmp->id);
		printf("nbr_meals_per_philo: %d\n", tmp->nbr_meals_per_philo);
		printf("last_meal: %ld\n", tmp->last_meal);
		i++;
		if (i >= data->nbr_philo)
			break ; 
	}    
}
