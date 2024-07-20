/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 03:17:58 by zqouri            #+#    #+#             */
/*   Updated: 2024/07/20 14:07:59 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
    t_philo philo;
    if (ac == 5 || ac == 6)
    {
        //parsing : check input and put data in struct
        if (!parsing(ac, av, &philo))
            return (0);
        //data_init() :  malloc philo malloc forks and init mutex...
        //diner_start() start_simulation : create threads and start simulation
        //diner_end() : join threads and free philo malloc forks and destroy mutex...
        //clean() : free philo malloc forks and destroy mutex...
    }
    else
        printf("Error: Wrong number of arguments\n");
    return (0);
}
