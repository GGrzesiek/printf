/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrzesiek <ggrzesiek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:28:56 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/03/03 18:47:53 by ggrzesiek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
int handle_numbers(const char *ptr, va_list args)
{
	if(*ptr == 'd' || *ptr == 'i')
	{
		ft_putnbr_fd(va_arg(args, int), 1);
		return (num_len(va_arg(args, int),10));
	}
	if(*ptr == 'u')
	{
		ft_putnbr_fd((int)va_arg(args, unsigned), 1);
		return ((int)num_len(va_arg(args, unsigned),10));
	}
	return 0;
}
int handle_hex(const char *ptr, va_list args)
{
	if(*ptr == 'p')
	{
		if(!va_arg(args, void *))
		{
			ft_putstr_fd("(nil)", 1);
			return (5);
		}
		ft_putstr_fd("0x", 1);
		return (ft_putnbr_hex_fd(va_arg(args, unsigned long), 0, 1));
	}
	if(*ptr == 'x')
		return (ft_putnbr_hex_fd(va_arg(args, unsigned), 0, 1));
	if(*ptr == 'X')
		return (ft_putnbr_hex_fd(va_arg(args, unsigned), 1, 1));
	return 0;
}

int define_format(const char *ptr, va_list args)
{
	char *arg;

	if (*ptr == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		ptr++;
		return (1);
	}
	if (*ptr == 's')
	{
		arg = va_arg(args, char *);
		if(!arg)
			arg = "(null)";
		ft_putstr_fd(arg, 1);
		return (ft_strlen(arg));
	}
	if (*ptr == 'd' || *ptr == 'i' || *ptr == 'u')
		return (handle_numbers(ptr,args));
	if (*ptr == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return 0;
}

int ft_printf(const char *fmt, ...)
{
	va_list ap;
	int count;

	count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 'p' || *fmt == 'x' || *fmt == 'X')
				count += handle_hex(fmt, ap);
			else
				count += define_format(fmt, ap);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			count++;
		}
		fmt++;
	}
	va_end(ap);
	return (count);
}
