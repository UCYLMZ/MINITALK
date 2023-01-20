/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:57:55 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/01/20 03:20:45 by uyilmaz          ###   ########.fr       */
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

void	send_signal(int a, int pid)
{
	if (a % 2 == 1 || a % 2 == -1)
	{
		kill(pid, SIGUSR1);
	}
	else if (a % 2 == 0)
	{
		kill(pid, SIGUSR2);
	}
	usleep(100);
}

void	ft_newline(int pid)
{
	kill(pid, SIGUSR2);
	usleep(100);
	kill(pid, SIGUSR2);
	usleep(100);
	kill(pid, SIGUSR2);
	usleep(100);
	kill(pid, SIGUSR2);
	usleep(100);
	kill(pid, SIGUSR1);
	usleep(100);
	kill(pid, SIGUSR2);
	usleep(100);
	kill(pid, SIGUSR1);
	usleep(100);
	kill(pid, SIGUSR2);
}

void	convert_binary(char *str, int pid)
{
	unsigned int	i;
	char			value;
	int				j;

	i = 0;
	while (str[i])
	{
		value = (unsigned int)str[i];
		j = 7;
		while (j >= 0)
		{
			send_signal(value >> j, pid);
			j--;
		}
		i++;
	}
	ft_newline(pid);
}

int	main(int ac, char **av)
{
	char	*str;
	int		pid;
	int		c_pid;

	if (ac != 3)
	{
		ft_printf("Wrong Argument Count!");
		return (1);
	}
	pid = ft_atoi(av[1]);
	c_pid = getpid();
	str = av[2];
	convert_binary(str, pid);
	convert_binary(av[1], pid);
	ft_printf("%s", av[1]);
}
