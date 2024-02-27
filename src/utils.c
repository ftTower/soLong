/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:14:57 by tauer             #+#    #+#             */
/*   Updated: 2024/02/21 18:27:13 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

clock_t	gettime(void)
{
	return ((clock() / (CLOCKS_PER_SEC / 1000)));
}

void	delete_emptyness(t_data *data,char **map)
{
	int x;
	int y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '0')
				data->map[x][y] = 'X';
			y++;
		}
		x++;
	}
}

// char	*ft_strdup(const char *s)
// {
// 	size_t	len_s;
// 	char	*str;
// 	char	*ptr;

// 	len_s = strlen(s);
// 	str = (char *)malloc(sizeof(char) * (len_s + 1));
// 	if (!str)
// 		return (NULL);
// 	ptr = str;
// 	while (len_s-- > 0)
// 		*str++ = *s++;
// 	*str = '\0';
// 	return (ptr);
// }

// size_t	ft_strlen(const char *str)
// {
// 	size_t i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while(str[i])
// 		i++;
// 	return (i);
// }

