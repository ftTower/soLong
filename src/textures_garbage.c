/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_garbage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:38:21 by tauer             #+#    #+#             */
/*   Updated: 2024/03/14 19:38:43 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

bool	init_garbage_memory(t_data *data)
{
	data->memory = NULL;
	data->memory = malloc(sizeof(t_memory));
	if (!data->memory)
		return (false);
	data->memory->ptr = NULL;
	data->memory->next = NULL;
	data->memory->name = NULL;
	data->memory->path = NULL;
	return (true);
}

bool	add_img_to_garbage_memory(t_data *data, t_img *new_img, char *name,
		char *path)
{
	t_memory	*memory_element;
	t_memory	*memory_temp;

	*new_img = new_file_img(path, data);
	if (!(*new_img).img)
	{
		printf("| ⛔ : \033[38;5;160m%s\033[0m | \033[38;5;160m(nil)\033[0m | \033[38;5;160m%s\033[0m\n",
			name, path);
		// printf("failed to load [%s - %s]\n", name, path);
		return (false);
	}
	memory_element = malloc(sizeof(t_memory));
	if (!memory_element)
		return (false);
	else if (!data->memory->ptr && !data->memory->next)
	{
		memory_element->name = name;
		memory_element->path = path;
		memory_element->next = NULL;
		memory_element->ptr = (*new_img).img;
		free(data->memory);
	}
	else if (data->memory->ptr)
	{
		memory_temp = data->memory;
		memory_element->name = name;
		memory_element->path = path;
		memory_element->next = memory_temp;
		memory_element->ptr = (*new_img).img;
	}
	printf("| ✅ : \033[38;5;15m%s\033[0m | \033[38;5;129m%p\033[0m | \033[38;5;118m%s\033[0m\n",
		memory_element->name, memory_element->ptr, memory_element->path);
	usleep(5000);
	data->memory = memory_element;
	return (true);
}

bool	clean_garbage_memory(t_data *data, int mode)
{
	t_memory	*memory_current;
	t_memory	*temp;

	if (!data->memory)
		return (false);
	memory_current = data->memory;
	if (mode != -1)
		printf("\033c");
	printf("=========================================================================================\n| FREE_TEXTURES\n=========================================================================================\n");
	while (memory_current)
	{
		usleep(5000);
		temp = memory_current->next;
		printf("| ❌ : \033[38;5;129m%p\033[0m | \033[38;5;15m%s\033[0m\n", memory_current->ptr, memory_current->name);
		mlx_destroy_image(data->mlx, memory_current->ptr);
		free(memory_current);
		memory_current = temp;
	}
	if (mode != -1)
		printf("\033c\n\n\n\n\n\t\t ✅ CLEARED TEXTURES\n\n\t\tyou finished wave %d !\n\n\n\n\n", data->wave);
	return (true);
}
