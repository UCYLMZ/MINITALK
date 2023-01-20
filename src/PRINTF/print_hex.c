/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:58:41 by uyilmaz           #+#    #+#             */
/*   Updated: 2022/10/31 13:10:45 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	norm_killer(unsigned int value, char c, int *count)
{
	if (c == 'X')
	{
		if (value > 9)
			print_char((int)value + 55, count);
		else
			print_char((int)value + 48, count);
	}
	else
	{
		if (value > 9)
			print_char((int)value + 55 + 32, count);
		else
			print_char((int)value + 48, count);
	}
}

void	print_hex(unsigned long value, char c, int *count)
{
	if (c != 'p')
		value = (unsigned int) value;
	if (value >= 16)
	{
		print_hex(value / 16, c, count);
		print_hex(value % 16, c, count);
	}
	else
		norm_killer(value, c, count);
}
