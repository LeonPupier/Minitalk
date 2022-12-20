/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:14:28 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/20 17:14:38 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Headers
#include "../headers/minitalk.h"

/**
 * @brief Function to create a new instance of the t_list structure.
 * 
 * @param content character to add to the new link t_list.
 * @return t_list* Returns a new instance of a t_list.
 */
t_list	*ft_lstnew(char content)
{
	t_list	*elt;

	elt = malloc(sizeof(t_list));
	if (!elt)
		return (NULL);
	elt->content = content;
	elt->next = NULL;
	return (elt);
}

/**
 * @brief Function to add a link to the beginning of a t_list structure.
 * 
 * @param lst The original list to which the link should be added.
 * @param new New link to add to the basic list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new && lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

/**
 * @brief Clean up the list of struct t_list and free memory.
 * 
 * @param lst the structure list t_list to clean.
 */
void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (lst)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			free(*lst);
			*lst = temp;
		}
		*lst = NULL;
	}
}
