/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:57:55 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/01/22 16:36:49 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int signal, int pid)
{
	if (signal % 2 == 1 || signal % 2 == -1)
		kill(pid, SIGUSR1);
	else if (signal % 2 == 0)
		kill(pid, SIGUSR2);
	usleep(130);
}

void	send_pid(int c_pid, int pid)
{
	static int		i;

	while (i < 32)
	{
		send_signal(c_pid % 2, pid);
		c_pid /= 2;
		i++;
	}
}

void	feedback_receiver(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Your message received!");
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
	troll_newline(pid);
}

int	main(int ac, char **av)
{
	char	*str;
	int		pid;
	int		c_pid;

	signal(SIGUSR1, feedback_receiver);
	if (ac != 3)
	{
		ft_printf("Wrong Argument Count!");
		return (1);
	}
	pid = ft_atoi(av[1]);
	c_pid = getpid();
	str = av[2];
	send_pid(c_pid, pid);
	convert_binary(str, pid);
}
