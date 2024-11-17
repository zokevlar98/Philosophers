/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 08:20:18 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/17 19:31:17 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	check_args(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (!check_str(av[i]))
			return (0);
	}
	i = 0;
	while (av[++i])
	{
		if ((ft_atoi(av[i]) <= 0) || (ft_atoi(av[i]) > INT_MAX))
			return (0);
	}
	return (1);
}

int	check_data(int ac, char **av, t_data *data)
{
	data->nbr_philo = (int)ft_atoi(av[1]);
	if (data->nbr_philo <= 0 || data->nbr_philo > 200)
	{
		printf("Error: Number of philos should ");
		printf("be greater than 0 & less than 200\n");
		return (0);
	}
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->dead = 0;
	if (ac == 6)
		data->nbr_meals = (int)ft_atoi(av[5]);
	else
		data->nbr_meals = -1;
	return (1);
}

t_data	*parsing(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	if (!check_data(ac, av, data))
		return (free(data), NULL);
	return (data);
}
