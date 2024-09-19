/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 05:46:06 by zqouri            #+#    #+#             */
/*   Updated: 2024/09/20 00:35:24 by zqouri           ###   ########.fr       */
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
    if (pthread_mutex_init(&new->fork, NULL))
        return (NULL);
    new->next = NULL;
    return (new);
}

t_philos    *ft_lstlast_ph(t_philos *lst)
{
    t_philos    *last;
    
    if (!lst)
        return (NULL);
    last = lst;
    while (last->next)
    {
        last = last->next;
    }
    return (last);
}

void    ft_lstadd_back_ph(t_philos **lst, t_philos *new)
{
    
    if (!new || !lst)
        return ;
    if (!*lst)
        *lst = new;
    else
        ft_lstlast_ph(*lst)->next = new;
}
