/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:14:55 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/01/22 16:36:58 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	signal_handler(int signal)
{
	static char	value;
	static int	nl_flag;
	static int	i;

	if (signal == SIGUSR1)
		value += 1 << (7 - i++);
	else if (signal == SIGUSR2)
		i++;
	if (i == 8)
	{
		ft_printf("%c", value);
		i = 0;
		nl_flag = value;
		value = 0;
	}
	if (nl_flag == 10)
	{
		nl_flag = 0;
		return (0);
	}
	return (1);
}

void	message_feedback(int signal)
{
	static int	c_pid;
	static int	j;

	if (j < 32)
	{
		if (signal == SIGUSR1)
			c_pid += 1 << j++;
		if (signal == SIGUSR2)
			j++;
	}
	else
	{
		if (!signal_handler(signal))
		{
			kill(c_pid, SIGUSR1);
			c_pid = 0;
			j = 0;
		}
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("pid: %d\n", pid);
	signal(SIGUSR1, message_feedback);
	signal(SIGUSR2, message_feedback);
	while (1)
	{
		pause();
	}
	return (0);
}
