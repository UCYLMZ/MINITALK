/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:14:55 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/01/20 03:18:05 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	message_feedback(int signal, char *value, int *i)
{
	static int	c_pid;
	static int	j;

	j = 32;
	while (j > 0)
	{
		if (signal == SIGUSR1)
		{
			ft_printf("*%d", 1);
			//c_pid += 1 << j;
			j--;
		}
		else if (signal == SIGUSR2)
		{
			ft_printf("*%d", 0);
			j--;
		}
	}
	ft_printf("%d", c_pid);
	*value = 0;
	*i = 7;
}

void	signal_handler(int signal)
{
	static char	value;
	static int	i;

	i = 7;
	if (signal == SIGUSR1)
	{
		value += 1 << i;
		i--;
	}
	else if (signal == SIGUSR2)
		i--;
	if (i == -1)
	{
		write(1, &value, 1);
		if (value == '\n')
		{
			message_feedback(signal, &value, &i);
			return ;
		}
		i = 7;
		value = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("pid: %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
