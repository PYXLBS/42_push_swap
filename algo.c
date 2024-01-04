/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:19:06 by pabertha          #+#    #+#             */
/*   Updated: 2024/01/04 18:19:26 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_list **a)
{
	if (is_max(*a, (*a)->position))
		rotate(a, RA);
	else if (is_max(*a, (*a)->next->position))
		reverse_rotate(a, RRA);
	if ((*a)->position > (*a)->next->position)
		swap(a, SA);
}

static void	sort_four(t_list **a, t_list **b)
{
	while ((*a)->position != get_min(*a))
		rotate(a, RA);
	if (is_not_sorted(a))
	{
		push(a, b, PB);
		sort_three(a);
		push(b, a, PA);
	}
}

static void	sort_five(t_list **a, t_list **b)
{
	while (lstsize(*a) > 3)
	{
		if ((*a)->position < 3)
			push(a, b, PB);
		else
			rotate(a, RA);
	}
	sort_three(a);
	if ((*b)->position < (*b)->next->position)
		swap(b, SB);
	while (*b)
		push(b, a, PA);
}

static void	radix(t_list **a, t_list **b, int lst_size)
{
	int	bit;
	int	move;

	bit = 0;
	move = 0;
	while (is_not_sorted(a))
	{
		while (bit < lst_size && (*a) != NULL)
		{
			if (!(((*a)->position >> move) & 1))
				push(a, b, PB);
			else
				rotate(a, RA);
			bit++;
		}
		while (*b != NULL)
			push(b, a, PA);
		bit = 0;
		move++;
	}
}

void	sort(t_list **a, t_list **b, int lst_size)
{
	get_position(a);
	if (lst_size == 2)
		swap(a, SA);
	else if (lst_size == 3)
		sort_three(a);
	else if (lst_size == 4)
		sort_four(a, b);
	else if (lst_size == 5)
		sort_five(a, b);
	else
		radix(a, b, lst_size);
}
