/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:29:53 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/17 17:08:21 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time_now(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL) == -1)
	{
		printf("Error: gettimeofday\n");
		return (0);
	}
	return ((t.tv_sec * 1e3) + (t.tv_usec / 1e3));
}

void	ft_usleep(unsigned long time)
{
	unsigned long	range;

	range = get_time_now();
	if (range == 0)
		return ;
	while (get_time_now() < range + time)
		usleep(100);
	return ;
}
