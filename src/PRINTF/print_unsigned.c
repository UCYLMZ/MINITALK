/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:56:11 by uyilmaz           #+#    #+#             */
/*   Updated: 2022/10/27 17:53:01 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned(unsigned int n, int *count)
{
	if (n > 9)
	{
		print_unsigned(n / 10, count);
		print_unsigned(n % 10, count);
	}
	else
		print_char(n + 48, count);
}
