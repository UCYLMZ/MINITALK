/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:28:16 by uyilmaz           #+#    #+#             */
/*   Updated: 2022/10/27 18:31:35 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(int n, int *count)
{
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		*count += 11;
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		print_char('-', count);
	}
	if (n > 9)
	{
		print_int(n / 10, count);
		print_int(n % 10, count);
	}
	else
		print_char(n + 48, count);
}
