/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:32:49 by tauer             #+#    #+#             */
/*   Updated: 2024/03/11 12:03:58 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char	*ft_strdup(const char *s)
{
	size_t	len_s;
	char	*str;
	char	*ptr;

	len_s = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!str)
		return (NULL);
	ptr = str;
	while (len_s-- > 0)
		*str++ = *s++;
	*str = '\0';
	return (ptr);
}

int	is_c(char c_s, char c)
{
	return (c_s == c);
}

unsigned int	count_word(char const *s, char c)
{
	size_t			i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i] && s[i + 1])
	{
		if (is_c(s[i], c) && !is_c(s[i + 1], c))
			count += 1;
		else if (i == 0 && !is_c(s[i], c))
			count += 1;
		i++;
	}
	return (count);
}

char	*mal_str(char const *s, char c, int *ptr)
{
	size_t	len;
	char	*dup;

	len = 0;
	while (is_c(s[*ptr], c) && s[*ptr])
		(*ptr)++;
	while (!is_c(s[*ptr], c) && s[*ptr])
	{
		(*ptr)++;
		len++;
	}
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	(*ptr) -= len;
	len = 0;
	while (!is_c(s[*ptr], c) && s[*ptr])
	{
		dup[len] = s[*ptr];
		(*ptr)++;
		len++;
	}
	dup[len] = '\0';
	return (dup);
}

char	**tab_tab_split(const char *s, char c)
{
	char	**tab;
	int		i;
	int		pos;
	int		count;

	i = 0;
	pos = 0;
	count = count_word(s, c);
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	while (i < count)
	{
		pos = 0;
		tab[i] = mal_str(s, c, &pos);
		if (!tab[i])
		{
			free(tab);
			return (0);
		}
		s += pos;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
