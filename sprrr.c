/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprrr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:24:15 by pabertha          #+#    #+#             */
/*   Updated: 2024/01/04 18:24:17 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_todo(t_operation to_do)
{
	if (to_do == SA)
		putstr("sa\n");
	else if (to_do == SB)
		putstr("sb\n");
	else if (to_do == SS)
		putstr("ss\n");
	else if (to_do == PA)
		putstr("pa\n");
	else if (to_do == PB)
		putstr("pb\n");
	else if (to_do == RA)
		putstr("ra\n");
	else if (to_do == RB)
		putstr("rb\n");
	else if (to_do == RR)
		putstr("rr\n");
	else if (to_do == RRA)
		putstr("rra\n");
	else if (to_do == RRB)
		putstr("rrb\n");
	else if (to_do == RRR)
		putstr("rrr\n");
}

void	swap(t_list **lst, t_operation to_do)
{
	t_list	*to_swap;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	to_swap = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	lstadd_front(lst, to_swap);
	write_todo(to_do);
}

void	push(t_list **src, t_list **dst, t_operation to_do)
{
	t_list	*to_push;

	if (*src == NULL)
		return ;
	to_push = *src;
	*src = (*src)->next;
	lstadd_front(dst, to_push);
	write_todo(to_do);
}

void	rotate(t_list **lst, t_operation to_do)
{
	t_list	*to_rotate;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	to_rotate = *lst;
	*lst = (*lst)->next;
	lstadd_back(lst, to_rotate);
	to_rotate->next = NULL;
	write_todo(to_do);
}

void	reverse_rotate(t_list **lst, t_operation to_do)
{
	t_list	*to_reverse_rotate;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	to_reverse_rotate = *lst;
	while (to_reverse_rotate->next->next != NULL)
		to_reverse_rotate = to_reverse_rotate->next;
	lstadd_front(lst, to_reverse_rotate->next);
	to_reverse_rotate->next = NULL;
	write_todo(to_do);
}
