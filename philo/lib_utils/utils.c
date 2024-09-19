/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 05:46:06 by zqouri            #+#    #+#             */
/*   Updated: 2024/09/19 08:49:33 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philos    *ft_lstnew_ph(int id, t_data *data)
{
    t_philos    *new;

    new = (t_philos *)malloc(sizeof(t_philos));
    if (!new)
        return (NULL);
    new->id = id;
    new->nbr_meals_per_philo = 0;
    new->data = data;
    if (pthread_mutex_init(new->fork, NULL))
        return (NULL);
    new->next = NULL;
}

t_philos    *ft_lstlast_ph(t_philos *lst)
{
    t_philos    *last;
    
    last = lst;
    if (!lst)
        return (NULL);
    while (last->next)
        last = last->next;
    return (last);
}

void    ft_lstadd_back_ph(t_philos **lst, t_philos *new)
{
    t_philos    *last;
    
    if (!new || !lst)
        return ;
    last = ft_lstlast_ph(*lst);
    if (!last)
        return ;
    if (!*lst)
        *lst = new;
    else
        last->next = new;
}
