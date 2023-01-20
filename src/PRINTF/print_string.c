/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:51:55 by uyilmaz           #+#    #+#             */
/*   Updated: 2022/10/27 18:05:01 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_string(char *str, int *count)
{
	if (!str)
	{
		*count += (write (1, "(null)", 6));
		return ;
	}
	*count += write (1, str, ft_strlen(str));
}
