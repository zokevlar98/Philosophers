/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 08:20:18 by zqouri            #+#    #+#             */
/*   Updated: 2024/07/20 20:51:28 by zqouri           ###   ########.fr       */
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

int check_data(int ac, char **av, t_philo *philo)
{
    philo->nbr_philo = ft_atoi(av[1]);
    if (philo->nbr_philo <= 0 || philo->nbr_philo > 200)
    {
        printf("Error: Number of philos should be greater than 0 & less than 200\n");
        return (0);
    }
    philo->time_to_die = ft_atoi(av[2]) * 1e3;
    philo->time_to_eat = ft_atoi(av[3]) * 1e3;
    philo->time_to_sleep = ft_atoi(av[4]) * 1e3;
    if (ac == 6)
        philo->nbr_meals = ft_atoi(av[5]);
    else 
        philo->nbr_meals = -1;
    return (1);
}

t_philo *parsing(int ac, char **av)
{
    t_philo *philo;

    philo = (t_philo *)malloc(sizeof(t_philo));
    if (!philo)
        return (NULL);
    if (!check_data(ac, av, philo))
    {
        free(philo);
        return (NULL);
    }
    return (philo);
}
