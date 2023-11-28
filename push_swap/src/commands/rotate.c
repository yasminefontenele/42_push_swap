/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:30:22 by yfontene          #+#    #+#             */
/*   Updated: 2023/11/15 08:30:22 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void rotate(t_stack_node **stack)
{
	t_stack_node *last_node;

	if(!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void ra(t_stack_node **a, bool print)
{
	rotate(a);
	if(!print)
		ft_print_f("ra\n");
}

void rb(t_stack_node **b, bool print)
{
	rotate(b);
	if(!print)
		ft_printf("rb\n");
}

void rr(t_stack_node **a, t_stack_node**b, bool print)
{
	rotate(a);
	rotate(b);
	if(!print)
		ft_printf("rr\n");
}