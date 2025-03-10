/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrzesiek <ggrzesiek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:27:15 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/03/10 13:39:35 by ggrzesiek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	num_len(long int n, int base)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

int	ft_putnbr_hex_fd(unsigned long n,int sign, int fd)
{
	char	*chars;
	int	count;

	count = 0;
	chars = "0123456789abcdef";
	if(sign)
		chars = "0123456789ABCDEF";
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return 1;
	}
	else if (n >= 16)
	{
		count+=ft_putnbr_hex_fd(n / 16, sign, fd);
		ft_putchar_fd(chars[n % 16], fd);
		count++;
	}
	else
	{
		ft_putchar_fd(chars[n], fd);
		count++;
	}
	return (count);	
}
long int	power(long int nb, int pow)
{
	int	i;
	int	tmp;

	tmp = nb;
	i = 0;
	while (i < pow)
	{
		nb = nb * tmp;
		i++;
	}
	return (nb);
}

void	ft_putnbr_fd(int n, int fd)
{
	long nb;
	nb = n;
	if(nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if(nb >= 10)
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putchar_fd((nb % 10) + '0', fd);
	}
	else
		ft_putchar_fd((nb + '0'), fd);
}
void	ft_putnbr_uns_fd(unsigned int n, int fd)
{
	if(n >= 10)
	{
		ft_putnbr_uns_fd((n / 10), fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
	else
		ft_putchar_fd((n + '0'), fd);
}