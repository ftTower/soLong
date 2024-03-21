/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:34:28 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 18:59:41 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

unsigned long	len_tab(char **tab)
{
	int	x;

	x = 0;
	while (tab[x])
		x++;
	return (x);
}

char	**ft_split(char *s, char c, int mode)
{
	char	**tab_split;

	if (!s)
		return (NULL);
	tab_split = tab_tab_split(s, c);
	if (!tab_split)
		return (NULL);
	if (mode == 1)
		free(s);
	return (tab_split);
}

char	**tab_argv(int argc, char **argv)
{
	int		i;
	int		i2;
	char	**tab;

	i = 0;
	i2 = 1;
	tab = (char **)malloc(sizeof(char *) * argc);
	if (!tab)
		return (NULL);
	while (i < argc - 1)
	{
		tab[i] = ft_strdup(argv[i2]);
		if (!tab[i])
		{
			free_map(tab);
			return (NULL);
		}
		i++;
		i2++;
	}
	tab[i] = NULL;
	return (tab);
}
