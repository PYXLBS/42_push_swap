/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:24:53 by pabertha          #+#    #+#             */
/*   Updated: 2024/01/04 18:25:05 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list *lst)
{
	int	min;

	min = lst->position;
	while (lst != NULL)
	{
		if (min > lst->position)
			min = lst->position;
		lst = lst->next;
	}
	return (min);
}

int	is_max(t_list *lst, int to_compare)
{
	if (lst != NULL)
	{
		while (lst != NULL && to_compare >= lst->position)
			lst = lst->next;
		if (lst == NULL)
			return (1);
	}
	return (0);
}

int	is_not_sorted(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if ((*lst) == NULL)
		return (0);
	while ((*lst)->next != NULL)
	{
		if ((*lst)->content > (*lst)->next->content)
		{
			*lst = tmp;
			return (1);
		}
		*lst = (*lst)->next;
	}
	*lst = tmp;
	return (0);
}

void	get_position(t_list **lst)
{
	t_list	*first_node;
	t_list	*tmp;

	first_node = *lst;
	tmp = *lst;
	while (*lst != NULL)
	{
		(*lst)->position = 1;
		while (tmp != NULL)
		{
			if ((*lst)->content > tmp->content)
				(*lst)->position++;
			tmp = tmp->next;
		}
		*lst = (*lst)->next;
		tmp = first_node;
	}
	*lst = first_node;
}
