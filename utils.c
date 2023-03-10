/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:38:04 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/01/22 16:23:32 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		result = result * 10 + (str[i] - 48) * sign;
		if (result > 2147483647)
			return (-1);
		if (result < -2147483648)
			return (0);
		i++;
	}
	return ((int)result);
}

void	troll_newline(int pid)
{
	kill(pid, SIGUSR2);
	usleep(130);
	kill(pid, SIGUSR2);
	usleep(130);
	kill(pid, SIGUSR2);
	usleep(130);
	kill(pid, SIGUSR2);
	usleep(130);
	kill(pid, SIGUSR1);
	usleep(130);
	kill(pid, SIGUSR2);
	usleep(130);
	kill(pid, SIGUSR1);
	usleep(130);
	kill(pid, SIGUSR2);
	usleep(130);
}
