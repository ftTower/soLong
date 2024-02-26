/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:39:38 by tauer             #+#    #+#             */
/*   Updated: 2023/11/06 15:39:38 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

// size_t ft_strlen(const char *s)
// {
// 	size_t i;

// 	i = 0;
// 	while(s[i])
// 		i++;
// 	return (i);
// }

char	*ft_strdup(const char *s)
{
	size_t	len_s;
	char	*str;
	char	*ptr;

	len_s = strlen(s);
	str = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!str)
		return (NULL);
	ptr = str;
	while (len_s-- > 0)
		*str++ = *s++;
	*str = '\0';
	return (ptr);
}

// int main(void)
// {
//     char *test = "phrase tester";

//     char *result = ft_strdup(test);

//     printf("%s\n", result);

//     free(result);

//     return (0);
// }
