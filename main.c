/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 03:17:58 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/18 00:14:37 by zqouri           ###   ########.fr       */
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
			return (free(data), 1);
		data = init(data);
		if (!data)
			return (free(data), 1);
		if (start_simulation(data))
			return (free(data), 1);
	}
	else
		printf("Error: Wrong number of arguments\n");
	return (0);
}
