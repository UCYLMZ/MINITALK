/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:17:27 by uyilmaz           #+#    #+#             */
/*   Updated: 2022/10/31 13:09:22 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	print_int(int n, int *count);
void	print_char(char c, int *count);
void	print_string(char *str, int *count);
void	print_unsigned(unsigned int n, int *count);
void	print_hex(unsigned long value, char c, int *count);
void	print_ptr(unsigned long ptr, int *count);
#endif