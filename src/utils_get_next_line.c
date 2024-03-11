/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:38:23 by marvin            #+#    #+#             */
/*   Updated: 2023/11/27 22:38:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
#include "../header/so_long.h"

void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	generate_line(line, stash);
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	free_stash(t_list *stash)
{
	t_list *current;
	t_list *next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free (current);
		current = next;
	}
}

void	clear_stash(t_list **stash)
{
	t_list *last;
	t_list *clean_node;
	int i;
	int j;

	clean_node = malloc(sizeof(t_list));
	if (stash == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_lst_get_last(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i) + 1));
	if (clean_node == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}

extern char	*get_next_line(int fd)
{
	static t_list *stash = NULL;
	char			*line;
	int				readed;

	
	if (fd < 0 || BUFFER_SIZE < 0  || read(fd, &line, 0) < 0)
		return (NULL);
	readed = 1;
	line = NULL;
	//read from fd and add to linker list
	read_and_stash(&stash, &readed, fd);
	if (stash == NULL)
		return (NULL);
	//extract from stash to line
	extract_line(stash, &line);
	//cleanup la stash
	clear_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}