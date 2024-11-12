/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 03:17:58 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/12 14:04:51 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
    t_data *data;
    
    if (ac == 5 || ac == 6)
    {
        //check_args() : check if all arguments are numbers
        if (!check_args(av))
            return (printf("Invalide args\n"), 0);
        //parsing : check input and put data in struct
        data = parsing(ac, av);
        if (!data)
            return (1);
        data = init_philos(data, data->nbr_philo);
        if (!data)
            return (1);
        // affiche(data);
        // diner_start(data->philos, data->nbr_philo);
        //data_init() :  malloc philo malloc forks and init mutex...
        
        //diner_start() start_simulation : create threads and start simulation
        //diner_end() : join threads and free philo malloc forks and destroy mutex...
        //clean() : free philo malloc forks and destroy mutex...
    }
    else
        printf("Error: Wrong number of arguments\n");
    return (0);
}
