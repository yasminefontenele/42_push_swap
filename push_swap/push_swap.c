/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:35:21 by yfontene          #+#    #+#             */
/*   Updated: 2023/11/06 18:35:21 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;

	if(argc == 1 || (argc == 2 && !argv[1][0])) //[1][0]segundo argumento sendo \0
		return(1);
	else if(argc == 2)
		argv = split(argv[1], ' '); //fazer um "fake" argv ex.: [push_swap 1 2 3] [push_swap "1 2 3"]
	
}