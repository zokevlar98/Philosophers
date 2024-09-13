/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 00:24:59 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/26 10:54:12 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo/includes/philo.h"


typedef struct s_thread
{
    pthread_mutex_t mutex;
    int             shared_var;
}   t_thread;

void    *calcul(void *arg)
{
    int i;
    int s;
    int res;
    t_thread *data = (t_thread *)arg;

    i = 0;
    while (i < 10000000)
    {
        s = pthread_mutex_lock(&data->mutex);
        if (s != 0)
            return (NULL);
        res = data->shared_var;
        res++;
        data->shared_var = res;
        s = pthread_mutex_unlock(&data->mutex);
        i++;
        if (s != 0)
            return (NULL);
    }
    return (NULL);
}

int main(void)
{
    pthread_t   t1;
    pthread_t   t2;
    int         s;
    t_thread    data;
    
    data.shared_var = 0;
    printf("shared_var = %d\n", data.shared_var);
    s = pthread_mutex_init(&data.mutex, NULL);
    if (s != 0)
        return (1);
    s = pthread_create(&t1, NULL, calcul, &data);
    if (s != 0)
        return (1);
    s = pthread_create(&t2, NULL, calcul, &data);
    if (s != 0)
        return (1);
    s = pthread_join(t1, NULL);
    if (s != 0)
        return (1);
    s = pthread_join(t2, NULL);
    if (s != 0)
        return (1);
    pthread_mutex_destroy(&data.mutex);
    printf("shared_var = %d\n", data.shared_var);
    // struct timeval t;
    // gettimeofday(&t, NULL);
    // printf("%ld\n", t.tv_sec * 1000 + t.tv_usec / 1000);
    return 0;
}
