/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:25:46 by pabertha          #+#    #+#             */
/*   Updated: 2024/01/04 18:25:48 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	putstr(char *s)
{
	if (s == NULL)
		return ;
	if (*s != '\0')
		write(1, s, ft_strlen(s));
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	int		symb;
	long	res;

	i = 0;
	symb = 1;
	res = 0;
	while (nptr[i] != '\0')
	{
		while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
			i++;
		if (nptr[i] == 43 || nptr[i] == 45)
		{
			if (nptr[i] == 45)
				symb = -symb;
			i++;
		}
		while (ft_isdigit(nptr[i]))
		{
			res = (res * 10) + (nptr[i] - 48);
			i++;
		}
		return (symb * res);
	}
	return (0);
}
