/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:29:32 by sanoor            #+#    #+#             */
/*   Updated: 2024/03/21 18:59:00 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	no_newline(t_line *head)
{
	int	i;

	if (!head)
		return (0);
	while (head)
	{
		i = 0;
		while (head->content[i] && i < BUFFER_SIZE)
		{
			if (head->content[i] == '\n')
				return (1);
			i++;
		}
		head = head->next;
	}
	return (0);
}

t_line	*get_last_node(t_line *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	count_max(t_line *head)
{
	int	i;
	int	j;

	if (!head)
		return (0);
	j = 0;
	while (head)
	{
		i = 0;
		while (head->content[i])
		{
			if (head->content[i] == '\n')
			{
				j++;
				return (j);
			}
			i++;
			j++;
		}
		head = head->next;
	}
	return (j);
}

void	cpy_line(t_line *head, char *ret)
{
	int	i;
	int	j;

	j = 0;
	while (head)
	{
		i = 0;
		while (head->content[i])
		{
			if (head->content[i] == '\n')
			{
				ret[j++] = '\n';
				ret[j] = '\0';
				return ;
			}
			ret[j++] = head->content[i++];
		}
		head = head->next;
	}
	ret[j] = '\0';
}

void	dealloc(t_line **head, t_line *clean_node, char *buf)
{
	t_line	*temp;

	while (*head)
	{
		temp = (*head)->next;
		free((*head)->content);
		free((*head));
		*head = temp;
	}
	*head = NULL;
	if (clean_node->content[0])
		*head = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}
