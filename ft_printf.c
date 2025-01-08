/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:28:56 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/01/08 15:34:36 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	define_format(const char *ptr,int *count,va_list args)
{
	if (*ptr == 'c')
		count += ft_putchar_fd(va_arg(args, int));
	if (*ptr == 's')
		count += ft_putstr_fd(va_arg(args, char *));
	// if (*ptr == 'p')
	// 	count += ft_print_pointer(va_arg(args, void *));
	if (*ptr == 'd' || *ptr == 'i')
	{
		printf("xd");
		count += ft_putnbr_fd(va_arg(args, int));
	}
	// if (*ptr == 'u')
	// 	count += ft_print_unsigned(va_arg(args, unsigned int));
	// if (*ptr == 'x')
	// 	count += ft_print_hex(va_arg(args, unsigned int), 0);
	// if (*ptr == 'X')
	// 	count += ft_print_hex(va_arg(args, unsigned int), 1);
	// if (*ptr == '%')
	// 	count += ft_print_percent();
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		type;
	int count;

	count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		// printf("%c",*fmt);
		if (*fmt == '%')
		{
			count++;
			define_format(fmt,&count, ap);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
		}
		fmt++;
		count++;
	}
	va_end(ap);
	return count;
}

int	main(void)
{
	ft_printf("%d SAD", 42);
	// printf("%d XD",42);
	return (0);
}
