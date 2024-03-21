/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:02:29 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 18:59:39 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

size_t	ft_strlen_printf(const char *str)
{
	size_t	size;

	size = 0;
	while (*str)
	{
		size++;
		str++;
	}
	return (size);
}

int	selecter(const char c, int ret_size, va_list arg)
{
	if (c == '%')
		ft_putchar_len('%', &ret_size);
	if (c == 's')
		ft_putstr_len(va_arg(arg, char *), &ret_size);
	if (c == 'p')
		ft_putptr_len(va_arg(arg, void *), &ret_size);
	if (c == 'd')
		ft_putnbr_len(va_arg(arg, int), &ret_size);
	if (c == 'i')
		ft_putnbr_len(va_arg(arg, int), &ret_size);
	if (c == 'c')
		ft_putchar_len(va_arg(arg, int), &ret_size);
	if (c == 'x')
		ft_putnbr_ptr((unsigned int)va_arg(arg, int), "0123456789abcdef",
			&ret_size);
	if (c == 'X')
		ft_putnbr_ptr((unsigned int)va_arg(arg, int), "0123456789ABCDEF",
			&ret_size);
	if (c == 'u')
		ft_putnbr_un(va_arg(arg, unsigned int), "0123456789", &ret_size);
	return (ret_size);
}
