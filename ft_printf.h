/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrzesiek <ggrzesiek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:33:25 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/03/03 18:46:30 by ggrzesiek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		num_len(long int n, int base);
char	*ft_itoa(int n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int		sign_check(long int *tmp);
int     ft_putnbr_hex_fd(unsigned n,int sign, int fd);

#endif // FT_PRINTF_H