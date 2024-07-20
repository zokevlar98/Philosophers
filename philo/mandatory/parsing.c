/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 08:20:18 by zqouri            #+#    #+#             */
/*   Updated: 2024/07/20 15:23:30 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_data(int ac, char **av, t_philo *philo)
{
    philo->nbr_philo = ft_atoi(av[1]);
    if (philo->nbr_philo <= 0 || philo->nbr_philo >  200)
        return (0);
    philo->time_to_die = ft_atoi(av[2]);
    if (philo->time_to_die <= 60 || philo->time_to_die > INT_MAX)
        return (0);
    philo->time_to_eat = ft_atoi(av[3]);
     if (philo->time_to_eat <= 60 || philo->time_to_eat > INT_MAX)
        return (0);
    philo->time_to_sleep = ft_atoi(av[4]);
     if (philo->time_to_sleep <= 60 || philo->time_to_sleep > INT_MAX)
        return (0);
    if (ac == 6)
    {
        philo->nbr_meals = ft_atoi(av[5]);
        if (philo->nbr_meals <= 0 || philo->nbr_meals > INT_MAX)
            return (0);
    }
    else 
        philo->nbr_meals = -1;
    return (1);
}

void    put_data(t_philo *philo)
{
    philo->time_to_die = philo->time_to_die * 1e3;
    philo->time_to_eat = philo->time_to_eat * 1e3;
    philo->time_to_sleep = philo->time_to_sleep * 1e3;
}

int parsing(int ac, char **av, t_philo *philo)
{
    if (!check_data(ac, av, philo))
    {
        printf("ERROR\n");
        return (0);
    }
    put_data(philo);
    return (1);
}
