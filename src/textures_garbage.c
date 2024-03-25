/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_garbage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:38:21 by tauer             #+#    #+#             */
/*   Updated: 2024/03/22 18:54:04 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

bool	init_garbage_memory(t_data *data)
{
	data->memory = NULL;
	data->memory = malloc(sizeof(t_memory));
	if (!data->memory)
		return (false);
	data->memory->id = NULL;
	data->memory->ptr = NULL;
	data->memory->next = NULL;
	data->memory->name = NULL;
	data->memory->path = NULL;
	return (true);
}

void	give_data_to_element(t_memory *memory_element, t_img *new_img,
		char **tab)
{
	memory_element->name = tab[0];
	memory_element->path = tab[1];
	memory_element->id = tab[2];
	memory_element->ptr = (*new_img).img;
	memory_element->img = new_img;
}

bool	make_element(t_data *data, t_memory *memory_temp, t_img *new_img,
		char **tab)
{
	t_memory	*memory_element;

	memory_element = NULL;
	memory_element = malloc(sizeof(t_memory));
	if (!memory_element)
		return (true);
	if (!data->memory->ptr && !data->memory->next)
	{
		memory_element->next = NULL;
		free(data->memory);
	}
	else if (data->memory->ptr)
	{
		memory_temp = data->memory;
		memory_element->next = memory_temp;
	}
	give_data_to_element(memory_element, new_img, tab);
	ft_printf("| ✅ : \033[38;5;15m%s\033[0m | \033[38;5;129m%p\033[0m |",
		memory_element->name, memory_element->ptr);
	ft_printf(" \033[38;5;118m%s\033[0m | \033[38;5;118m%s\033[0m\n",
		memory_element->id, memory_element->path);
	data->memory = memory_element;
	usleep(5000);
	return (false);
}

bool	add_img_to_garbage_memory(t_data *data, t_img *new_img, char *name)
{
	t_memory	*memory_temp;
	char		**tab;

	memory_temp = NULL;
	tab = ft_split(name, ':', 0);
	if (!tab)
		return (false);
	*new_img = new_file_img(tab[1], data);
	if (!(*new_img).img)
	{
		ft_printf("| ⛔ : \033[38;5;160m%s\033[0m |", tab[0]);
		ft_printf("   \033[38;5;160m(nil)\033[0m   |");
		ft_printf(" \033[38;5;160m%s\033[0m |", tab[2]);
		ft_printf("\033[38;5;160m%s\033[0m\n", tab[1]);
		free_map(tab);
		return (false);
	}
	make_element(data, memory_temp, new_img, tab);
	free(tab);
	return (true);
}

bool	clean_garbage_memory(t_data *data, int mode)
{
	t_memory	*memory_current;
	t_memory	*temp;

	(void)mode;
	if (!data->memory)
		return (false);
	memory_current = data->memory;
	if (mode != -1)
		ft_printf("\033c");
	put_error_msg("| FREE_TEXTURES");
	while (memory_current)
	{
		usleep(5000);
		temp = memory_current->next;
		free_element(memory_current, data);
		memory_current = temp;
	}
	if (mode != -1)
	{
		ft_printf("\033c\n\n\n\n\n\t\t ✅ CLEARED TEXTURES\n\n\t\t");
		ft_printf("you finished wave \033[38;5;125m%d\033[0m !\n\n\n\n\n",
			data->wave);
	}
	return (true);
}
