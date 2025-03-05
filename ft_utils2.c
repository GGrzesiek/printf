/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrzesiek <ggrzesiek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:27:15 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/03/03 18:45:12 by ggrzesiek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len(long int n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if(n < 0)
	{
		n = -n;
		len++;
	}
	while (n >= base)
	{
		len++;
		n = n / base;
	}
	return (len);
}

int	ft_putnbr_hex_fd(unsigned n,int sign, int fd)
{
	char	*chars;
	int	count;

	count = 0;
	chars = "0123456789abcdef";
	if(sign)
		chars = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_putnbr_hex_fd(n / 16, sign, fd);
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

void	write_to_str(char *str, int i, int len, long int nb)
{
	long int	singl_dig;
	int			j;

	j = 0;
	while (len > i)
	{
		singl_dig = nb % power(10, j);
		nb -= singl_dig;
		while (singl_dig >= 10)
			singl_dig /= 10;
		str[len - 1] = singl_dig + '0';
		len--;
		j++;
	}
}

int	ft_putnbr_fd(int n, int fd)
{
	long nb;
	int count;

	nb = n;
	count = 0;
	if(nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
		count++;
	}
	if(nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd(nb % 10 + '0', fd);
		count++;
	}
	else
	{
		ft_putchar_fd(nb + '0', fd);
		count++;
	}
	return (count);
}
/*
char	*ft_itoa(int n)
{
	long int	tmp;
	int			i;
	int			len;
	char		*str;

	i = 0;
	tmp = n;
	len = (num_len(tmp,10));
	str = (char *)ft_calloc((sizeof(char) * (len + 1)), sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[i] = '-';
		i++;
	}
	write_to_str(str, i, len, tmp);
	return (str);
} */
