/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 08:20:18 by zqouri            #+#    #+#             */
/*   Updated: 2024/07/20 13:50:44 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int put_data(int ac, char **av, t_philo *philo)
{
    philo->nbr_philo = ft_atoi(av[1]);
    if (philo->nbr_philo <= 0)
        return (0);
    philo->time_to_die = ft_atoi(av[2]);
    philo->time_to_eat = ft_atoi(av[3]);
    philo->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        philo->nbr_meals = ft_atoi(av[5]);
    else
        philo->nbr_meals = -1;
    return (1);
}

int parsing(int ac, char **av, t_philo *philo)
{
    if (!put_data(ac, av, philo))
        return (0);
    return (1);
}
