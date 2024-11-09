/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:39:16 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/09 12:41:38 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


long long ft_atoi(char *str)
{
	int         i;
	int         sign;
	long long   res;
	long long   tmp;

	i = 0;
	res = 0;
	sign = 1;
	if (!str)
		return (-1);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = res;
		res = res * 10 + str[i] - '0';
		if (res < tmp)
			return (-1);
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (res * sign);
}
