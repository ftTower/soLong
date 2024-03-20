/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:40:26 by tauer             #+#    #+#             */
/*   Updated: 2024/03/20 15:33:35 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_img	new_file_img(char *path, t_data *data)
{
	t_img	image;

	image.img = mlx_xpm_file_to_image(data->mlx, path, &image.w, &image.h);
	if (!image.img)
	{
		image.img = NULL;
		write(2, "File could not be read\n", 23);
	}
	else
	{
		image.addr = mlx_get_data_addr(image.img, &(image.bits_per_pixel),
				&(image.line_length), &(image.endian));
		if (!image.addr)
		{
			image.addr = NULL;
			write(2, "Addr could not be get\n", 23);
		}
	}
	return (image);
}

unsigned int	get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr + (y * img.line_length) + (x
				* img.bits_per_pixel / 8))));
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	put_img_to_img(t_img dst, t_img src, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	while (i < src.w)
	{
		j = 0;
		while (j < src.h)
		{
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}

t_img	new_img(int w, int h, t_data *data)
{
	t_img	image;

	image.img = mlx_new_image(data->mlx, w, h);
	image.addr = mlx_get_data_addr(image.img, &(image.bits_per_pixel),
			&(image.line_length), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}
