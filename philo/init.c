/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:02:48 by zqouri            #+#    #+#             */
/*   Updated: 2024/09/18 00:18:48 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data    *init_philos(t_data **data, int n)
{
    t_data *new;

    new = (t_data *)malloc(sizeof(t_data));
    if (!new)
        return (NULL);
    return (new);
}
