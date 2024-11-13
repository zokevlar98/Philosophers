/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:35:58 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/13 11:42:37 by zqouri           ###   ########.fr       */
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
	printf("dead: %d\n", data->dead);
	while (i < data->nbr_philo)
	{
		philo = tmp[i];
		printf("philos %d====================\n", philo.id);
		printf("nbr_meals_per_philo: %d\n", philo.nbr_meals_per_philo);
		printf("last_meal: %ld\n", philo.last_meal);
		i++;
	}    
}
