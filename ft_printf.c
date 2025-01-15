/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:28:56 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/01/15 15:34:32 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		define_format(const char *ptr,va_list args)
{
	int count;

	count = 0;
	if (*ptr == 'c')
	{
		ft_putchar_fd(va_arg(args, int),1);
		count += 1;
		ptr++;
	}
	if (*ptr == 's')
	{
		char * arg =  va_arg(args, char *);
		ft_putstr_fd(arg,1);
		count = (ft_strlen(arg) - 1);
		ptr++;
	}
	// if (*ptr == 'p')
	// 	count += ft_print_pointer(va_arg(args, void *));
	if (*ptr == 'd' || *ptr == 'i')
	{
		// count += ft_putnbr_fd(va_arg(args, int),1);
	}
	// if (*ptr == 'u')
	// 	count += ft_print_unsigned(va_arg(args, unsigned int));
	// if (*ptr == 'x')
	// 	count += ft_print_hex(va_arg(args, unsigned int), 0);
	// if (*ptr == 'X')
	// 	count += ft_print_hex(va_arg(args, unsigned int), 1);
	if (*ptr == '%')
		ft_putchar_fd('%',1);
	return count;
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	// int		type;
	int count;

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
			ft_putchar_fd(*fmt, 1);
		fmt++;
		count++;
	}
	va_end(ap);
	return count;
}

int	main(void)
{
	char s1[] = "aa";
	int cnt;
	
	cnt = 0;
	// cnt +=	ft_printf("%sr%s", s1, s1);
	cnt +=	ft_printf("%%%%%%%%%%");
	printf("%d",cnt);
	return (0);
}
