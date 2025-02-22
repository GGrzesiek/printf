/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:27:15 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/02/22 12:27:23 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len(long int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		len++;
		n = n / 10;
	}
	return (len);
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

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	str = ft_itoa(n);
	ft_putstr_fd(str, fd);
	free(str);
}

char	*ft_itoa(int n)
{
	long int	tmp;
	int			i;
	int			len;
	int			is_neg;
	char		*str;

	i = 0;
	tmp = n;
	is_neg = sign_check(&tmp);
	len = (num_len(tmp) + is_neg);
	str = (char *)ft_calloc((sizeof(char) * (len + 1)), sizeof(char));
	if (!str)
		return (NULL);
	if (is_neg)
	{
		str[i] = '-';
		i++;
	}
	write_to_str(str, i, len, tmp);
	return (str);
}

void	ft_putnbrhex_fd(int n, int fd)
{
	char	*str;

	str = ft_itoa(n);
	ft_putstr_fd(str, fd);
	free(str);
}