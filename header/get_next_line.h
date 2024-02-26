/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:55:06 by tauer             #+#    #+#             */
/*   Updated: 2024/02/19 19:19:44 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE
# define FT_GET_NEXT_LINE

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define 				BUFFER_SIZE 1
# endif


typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}			t_list;

t_list *ft_lst_get_last(t_list *stash);
int	find_newline(t_list *stash);
void	add_to_stash(t_list **stash, char *buff, int readed);
void	read_and_stash(t_list **stash, int *readed_ptr, int fd);
void	extract_line(t_list *stash, char **line);
void	generate_line(char **line, t_list *stash);
char	*get_next_line(int fd);
void	clear_stash(t_list **stash);

#endif