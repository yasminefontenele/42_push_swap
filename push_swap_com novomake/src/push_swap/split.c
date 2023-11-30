/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:52:16 by yfontene          #+#    #+#             */
/*   Updated: 2023/11/06 19:52:16 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int count_words(char *s, char c)
{
	int		count;
	bool	inside_words;

	count = 0;
	while(*s)
	{
		inside_words = false;
		while(*s == c)
			++s;
		while(*s != c && *s)
		{
			if(!inside_words) //ou seja, se estiver dentro da string
			{
				++count;
				inside_words = true;
			}
			++s;
		}
	}
	return(count);
}

static char *get_next_word(char *s, char c) //função responsável por extrair a próxima palavra da string, utilizando o delimitador definido
{
	static int	cursor = 0; //static pq a variável é inicializada apenas uma vez na primeira chamada da função e manterá seu valor entre chamadas subsequentes
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while(s[cursor] == c)
		++cursor;
	while((s[cursor + len] != c) && s[cursor + len]) //essa parte é usada para determinar o tamanho da próxima palavra a ser extraída da string
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if(!next_word)
		return(NULL);
	while((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return(next_word);
}

char **split( char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;

	i = 0;
	words_count = count_words(s, c);
	if(!words_count)
		exit(1);
	result_array = malloc((size_t)(words_count + 2) * sizeof(char *));
	if(!result_array)
		return(NULL);
	while(words_count-- >= 0)
	{
		if(i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if(!result_array[i])
				return(NULL);
			result_array[i++][0] = '\0';
			continue;
		}
		result_array[i++] = get_next_word(s, c);
	}
	result_array[i] = NULL;
	return(result_array);
}