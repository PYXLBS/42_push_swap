/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:26:24 by pabertha          #+#    #+#             */
/*   Updated: 2024/01/04 18:26:31 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	error(ac, av);
	arg_to_lst(&a, ac, av);
	if (is_not_sorted(&a))
		sort(&a, &b, lstsize(a));
	lstclear(&a, free);
	lstclear(&b, free);
	return (0);
}
