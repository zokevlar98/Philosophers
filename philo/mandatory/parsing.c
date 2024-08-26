/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 08:20:18 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/26 06:49:30 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_args(char **av)
{
    int i;

    i = 1;
    while (av[++i])
    {
        if ((ft_atoi(av[i]) <= 0)  || (ft_atoi(av[i]) > INT_MAX))
            return (0);
    }
    return (1);
}

int check_data(int ac, char **av, t_data *data)
{
    data->nbr_philo = (int)ft_atoi(av[1]);
    if (data->nbr_philo <= 0 || data->nbr_philo > 200)
    {
        printf("Error: Number of philos should be greater than 0 & less than 200\n");
        return (0);
    }
    data->time_to_die = ft_atoi(av[2]) * 1e3;
    data->time_to_eat = ft_atoi(av[3]) * 1e3;
    data->time_to_sleep = ft_atoi(av[4]) * 1e3;
    if (ac == 6)
        data->nbr_meals = (int)ft_atoi(av[5]);
    else 
        data->nbr_meals = -1;
    return (1);
}

t_data *parsing(int ac, char **av)
{
    t_data *data;

    data = (t_data *)malloc(sizeof(t_data));
    if (!data)
        return (NULL);
    if (!check_data(ac, av, data))
    {
        free(data);
        return (NULL);
    }
    return (data);
}
