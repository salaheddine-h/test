/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahosni <fahosni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:37:21 by salhali           #+#    #+#             */
/*   Updated: 2025/12/15 16:25:02 by fahosni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	add_allocation(ptr);
	return (ptr);
}

t_alloc	**g_allocs(void)
{
	static t_alloc	*head = NULL;

	return (&head);
}

void	add_allocation(void *ptr)
{
	t_alloc	*node;

	node = (t_alloc *)malloc(sizeof(t_alloc));
	if (!node)
	{
		perror("Error: Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	node->ptr = ptr;
	node->next = *g_allocs();
	*g_allocs() = node;
}

void	ft_free_all(void)
{
	get_next_line(-1);
	free_all_allocations();
}

void	free_all_allocations(void)
{
	t_alloc	*tmp;

	while (*g_allocs())
	{
		tmp = (*g_allocs())->next;
		if ((*g_allocs())->ptr)
			free((*g_allocs())->ptr);
		free(*g_allocs());
		*g_allocs() = tmp;
	}
}
