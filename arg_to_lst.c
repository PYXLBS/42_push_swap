/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:20:06 by pabertha          #+#    #+#             */
/*   Updated: 2024/01/04 18:20:08 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arg_to_lst(t_list **lst, int ac, char **av)
{
	int		ac_2;
	t_list	*av_2;

	ac_2 = 1;
	while (ac_2 < ac)
	{
		av_2 = lstnew(ft_atoi(av[ac_2]));
		if (av_2 == NULL)
		{
			lstclear(lst, free);
			exit(1);
		}
		lstadd_back(lst, av_2);
		ac_2++;
	}
}
