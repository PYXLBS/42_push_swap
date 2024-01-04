/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:20:22 by pabertha          #+#    #+#             */
/*   Updated: 2024/01/04 18:20:30 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int ac, char **av)
{
	no_parameter(ac, av);
	is_not_number(ac, av);
	is_not_int(ac, av);
	is_double(ac, av);
}
