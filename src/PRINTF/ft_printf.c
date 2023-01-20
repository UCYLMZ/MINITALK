/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:35:07 by uyilmaz           #+#    #+#             */
/*   Updated: 2022/10/31 13:20:24 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	formatter(va_list s, char f, int *count)
{
	if (f == 'd' || f == 'i')
		print_int(va_arg(s, int), count);
	else if (f == 'c')
		print_char(va_arg(s, int), count);
	else if (f == 's')
		print_string(va_arg(s, char *), count);
	else if (f == 'u')
		print_unsigned(va_arg(s, unsigned int), count);
	else if (f == 'p')
		print_ptr(va_arg(s, unsigned long), count);
	else if (f == 'X' || f == 'x')
		print_hex(va_arg(s, unsigned int), f, count);
	else if (f == '%')
		print_char('%', count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	lst;

	va_start(lst, s);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			formatter(lst, s[++i], &count);
		else
			print_char(s[i], &count);
		i++;
	}
	va_end(lst);
	return (count);
}
