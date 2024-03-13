/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_garbage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:38:21 by tauer             #+#    #+#             */
/*   Updated: 2024/03/14 00:44:11 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

bool init_garbage_memory(t_data *data)
{
	data->memory = NULL;
	data->memory = malloc(sizeof(t_memory));
	if (!data->memory)
		return (false);
	data->memory->ptr = NULL;
	data->memory->next = NULL;
	data->memory->name = NULL;
	data->memory->path = NULL;
	data->memory->index = 0;
	return true;
}

bool	add_img_to_garbage_memory(t_data *data, t_img *new_img, char *name, char *path)
{
	t_memory *memory_element;
	t_memory *memory_temp;

	*new_img = new_file_img(path, data);
	if (!(*new_img).img)
	{
		printf("failed to load [%s - %s]\n", name, path);
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
		memory_element->index = 0;
		memory_element->ptr = (*new_img).img;
		free(data->memory);
		printf("[%d] %s [%s] [%p]\n", memory_element->index, memory_element->name, memory_element->path, memory_element->next);
	}
	else if (data->memory->ptr)
	{
		memory_temp = data->memory;
		memory_element->name = name;
		memory_element->path = path;
		memory_element->index = 0;
		memory_element->next = memory_temp;
		memory_element->ptr = (*new_img).img;
		printf("[%d] %s [%p] [%p]\n", memory_element->index, memory_element->name, memory_element->path, memory_element->next);
	}
	data->memory = memory_element;
	return (true);
}

bool	clean_garbage_memory(t_data *data)
{
	t_memory *memory_current;
	t_memory *temp;
	
	if (!data->memory)
		return (false);
	memory_current = data->memory;
	while (memory_current)
	{
		temp = memory_current->next;
		printf("destroyed [%d] %s [%p] %p\n", memory_current->index, memory_current->name, memory_current->ptr, memory_current->next);
		mlx_destroy_image(data->mlx, memory_current->ptr);
		free(memory_current);
		memory_current = temp;
	}
	return (true);
}