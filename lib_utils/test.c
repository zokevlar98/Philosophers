/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:35:58 by zqouri            #+#    #+#             */
/*   Updated: 2024/09/20 00:43:53 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    affiche(t_data *data)
{
    t_philos *tmp;

    tmp = data->philos;
    while (tmp)
    {
        printf("philos %d====================\n", tmp->id);
        printf("id: %d\n", tmp->id);
        printf("nbr_meals_per_philo: %d\n", tmp->nbr_meals_per_philo);
        printf("last_meal: %ld\n", tmp->last_meal);
        tmp = tmp->next;
    }    
}
