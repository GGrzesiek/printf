/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:28:56 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/02/22 12:07:09 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}


int	define_format(const char *ptr, va_list args)
{
	int		count;
	char	*arg;

	count = 0;
	if (*ptr == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		count += 1;
		ptr++;
	}
	if (*ptr == 's')
	{
		arg = va_arg(args, char *);
		ft_putstr_fd(arg, 1);
		count = (ft_strlen(arg) - 1);
		ptr++;
	}
	// if (*ptr == 'p' || *ptr == 'x' || *ptr == 'X')
	// 	count += ft_print_hex(va_arg(args, unsigned int), 1);
	if (*ptr == 'd' || *ptr == 'i')
	{
		ft_putnbr_fd(va_arg(args, int), 1);
		count += num_len(va_arg(args, int));
	}
	// if (*ptr == 'u')
	// 	count += ft_print_unsigned(va_arg(args, unsigned int));
	if (*ptr == '%')
		ft_putchar_fd('%', 1);
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;

	// int		type;
	count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			count += define_format(fmt, ap);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
		}
		fmt++;
		count++;
	}
	va_end(ap);
	return (count);
}
