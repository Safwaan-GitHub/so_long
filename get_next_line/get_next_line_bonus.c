/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:15:02 by sanoor            #+#    #+#             */
/*   Updated: 2024/01/24 15:37:47 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	append(char *ret, t_line **head)
{
	t_line	*new_node;
	t_line	*last_node;

	new_node = malloc(sizeof(t_line));
	last_node = get_last_node(*head);
	if (new_node == NULL)
		return ;
	if (!last_node)
		*head = new_node;
	else
		last_node->next = new_node;
	new_node->content = ret;
	new_node->next = NULL;
}

void	get_line(int fd, t_line **head)
{
	char	*ret;
	int		rd_length;

	rd_length = 0;
	while (!no_newline(*head))
	{
		ret = malloc(BUFFER_SIZE + 1);
		if (!ret)
			return ;
		rd_length = read(fd, ret, BUFFER_SIZE);
		if (rd_length <= 0)
		{
			free(ret);
			return ;
		}
		ret[rd_length] = '\0';
		append(ret, head);
	}
}

char	*full_line(t_line *head)
{
	char	*ret;
	int		len;

	len = count_max(head);
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	cpy_line(head, ret);
	return (ret);
}

void	ammend_list(t_line **head)
{
	t_line	*clean_node;
	t_line	*last_node;
	int		i;
	int		j;
	char	*str;

	str = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_line));
	if (!(clean_node && str))
		return ;
	last_node = get_last_node(*head);
	i = 0;
	j = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i] && last_node->content[++i])
		str[j++] = last_node->content[i];
	str[j] = '\0';
	clean_node->content = str;
	clean_node->next = NULL;
	dealloc(head, clean_node, str);
}

char	*get_next_line(int fd)
{
	static t_line	*head[4096];
	char			*ret;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE == 0)
		return (NULL);
	get_line(fd, &head[fd]);
	if (head[fd] == NULL)
		return (NULL);
	ret = full_line(head[fd]);
	ammend_list(&head[fd]);
	return (ret);
}
/*
int	main(void)
{
	int	fd;
	int	i;
	char	*ret;

	i = 0;
	fd = open("file.txt", O_RDONLY);
	while (i < 10)
	{
		ret = get_next_line(fd);
		printf("s: %s\n", ret);
		i++;
		free(ret);
	}
}
*/
