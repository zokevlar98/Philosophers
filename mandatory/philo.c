/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 03:17:58 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/15 19:26:30 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;
	
	if (ac == 5 || ac == 6)
	{
		if (!check_args(av))
			return (printf("Invalide args\n"), 1);
		data = parsing(ac, av);
		if (!data)
			return (1);
		data = init_philos(data, data->nbr_philo);
		if (!data)
			return (1);
	}
	else
		printf("Error: Wrong number of arguments\n");
	return (0);
}
