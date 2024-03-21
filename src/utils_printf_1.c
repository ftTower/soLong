/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:46:22 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 18:59:30 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_putchar_len(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putstr_len(const char *s, int *len)
{
	if (!s)
	{
		write(1, "(null)", 6);
		*len += 6;
		return ;
	}
	while (*s)
	{
		ft_putchar_len(*s, len);
		s++;
	}
}

void	ft_putnbr_len(int nb, int *len)
{
	long int	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		write(1, "-", 1);
		*len += 1;
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_len(nbr / 10, len);
		ft_putnbr_len(nbr % 10, len);
	}
	else
	{
		ft_putchar_len(nbr + '0', len);
	}
}

void	ft_putnbr_ptr(size_t nbr, char *base, int *len)
{
	size_t			len_base;

	len_base = ft_strlen_printf(base);
	if (nbr > len_base - 1)
	{
		ft_putnbr_ptr(nbr / len_base, base, len);
		ft_putnbr_ptr(nbr % len_base, base, len);
	}
	else
	{
		ft_putchar_len(base[nbr], len);
	}
}

void	ft_putptr_len(void *ptr, int *len)
{
	if (ptr == 0)
	{
		ft_putstr_len("(nil)", len);
		return ;
	}
	ft_putstr_len("0x", len);
	ft_putnbr_ptr((size_t)ptr, "0123456789abcdef", len);
}
