/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:00:28 by tauer             #+#    #+#             */
/*   Updated: 2024/03/17 22:06:01 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_putnbr_base(int nbr, char *base, int *len)
{
	int			len_base;
	long int	nbr_cast;

	nbr_cast = nbr;
	len_base = ft_strlen_printf(base);
	if (nbr_cast < 0)
	{
		ft_putchar_len('-', len);
		nbr_cast *= -1;
	}
	if (nbr_cast > len_base - 1)
	{
		ft_putnbr_base(nbr_cast / len_base, base, len);
		ft_putnbr_base(nbr_cast % len_base, base, len);
	}
	else
	{
		ft_putchar_len(base[nbr_cast], len);
	}
}

void	ft_putnbr_un(unsigned int nbr, char *base, int *len)
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
