/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:23:25 by pabertha          #+#    #+#             */
/*   Updated: 2024/01/04 18:23:39 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_error(void)
{
	putstr("Error\n");
	exit(1);
}

void	no_parameter(int ac, char **av)
{
	if (ac < 2 || av == NULL)
		exit(0);
}

void	is_not_number(int ac, char **av)
{
	int	ac_2;
	int	ac_3;

	ac_2 = 1;
	while (ac_2 < ac)
	{
		ac_3 = 0;
		while (av[ac_2][ac_3])
		{
			if (ft_isdigit(av[ac_2][ac_3]) != 1 && (ac_3 != 0
					|| (av[ac_2][ac_3] != '-' && av[ac_2][ac_3] != '+')
					|| ft_isdigit(av[ac_2][ac_3 + 1]) != 1))
				write_error();
			ac_3++;
		}
		ac_2++;
	}
}

void	is_not_int(int ac, char **av)
{
	int		ac_2;
	long	av_2;

	ac_2 = 1;
	while (ac_2 < ac)
	{
		if (ft_strlen(av[ac_2]) > 11)
			write_error();
		av_2 = ft_atoi(av[ac_2]);
		if (av_2 < INT_MIN || av_2 > INT_MAX)
			write_error();
		ac_2++;
	}
}

void	is_double(int ac, char **av)
{
	int	ac_2;
	int	ac_3;
	int	av_2;

	ac_2 = 1;
	while (ac_2 < ac)
	{
		ac_3 = ac_2 + 1;
		av_2 = ft_atoi(av[ac_2]);
		while (av[ac_3])
		{
			if (av_2 == ft_atoi(av[ac_3]))
				write_error();
			ac_3++;
		}
		ac_2++;
	}
}
