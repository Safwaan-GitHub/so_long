/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:32:30 by sanoor            #+#    #+#             */
/*   Updated: 2024/01/19 15:33:54 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct t_head
{
	char			*content;
	struct t_head	*next;
}	t_line;

void	get_line(int fd, t_line **head);
char	*full_line(t_line *head);
void	ammend_list(t_line **head);
void	append(char *ret, t_line **head);
char	*get_next_line(int fd);
int		no_newline(t_line *head);
t_line	*get_last_node(t_line *head);
int		count_max(t_line *head);
void	cpy_line(t_line *head, char *ret);
void	dealloc(t_line **head, t_line *clean_node, char *buf);

#endif
