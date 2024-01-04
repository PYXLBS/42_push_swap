/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:27:23 by pabertha          #+#    #+#             */
/*   Updated: 2024/01/04 18:27:33 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_operation
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}					t_operation;

typedef struct s_list
{
	int				content;
	int				position;
	struct s_list	*next;
}					t_list;

// SPRRR

void				swap(t_list **lst, t_operation to_do);
void				push(t_list **src, t_list **dst, t_operation to_do);
void				rotate(t_list **lst, t_operation to_do);
void				reverse_rotate(t_list **lst, t_operation to_do);

// ERROR

void				no_parameter(int ac, char **av);
void				is_not_number(int ac, char **av);
void				is_not_int(int ac, char **av);
void				is_double(int ac, char **av);
void				error(int ac, char **av);

// LST

void				arg_to_lst(t_list **lst, int ac, char **av);
void				lstadd_back(t_list **lst, t_list *new);
void				lstadd_front(t_list **lst, t_list *new);
void				lstclear(t_list **lst, void (*del)(void *));
t_list				*lstnew(int content);
int					lstsize(t_list *lst);

// ALGO

void				sort(t_list **a, t_list **b, int lst_size);

// UTILS

size_t				ft_strlen(const char *s);
void				putstr(char *s);
int					ft_isdigit(int c);
long				ft_atoi(const char *nptr);

// UTILS ALGO

int					get_min(t_list *lst);
int					is_max(t_list *lst, int to_compare);
int					is_not_sorted(t_list **lst);
void				get_position(t_list **lst);

#endif
