/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_ws.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:35:43 by myarovoy          #+#    #+#             */
/*   Updated: 2018/11/17 16:35:44 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_count(char *str)
{
	int word_count;
	int i;

	i = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		while (WHITESPACE(str[i]) && str[i] != '\0')
			i++;
		while (!(WHITESPACE(str[i])) && str[i] != '\0')
			i++;
		while (WHITESPACE(str[i]) && str[i] != '\0')
			i++;
		word_count++;
	}
	return (word_count);
}

static int		ft_word_size(char *str)
{
	int i;

	i = 0;
	while (WHITESPACE(str[i]) && str[i] != '\0')
		str++;
	while (!(WHITESPACE(str[i])) && str[i] != '\0')
		i++;
	return (i);
}

char			**ft_strsplit_ws(char *str)
{
	int		word_count;
	int		words_entered;
	int		i;
	char	**words;
	char	*word;

	i = 0;
	words_entered = 0;
	word_count = ft_word_count(str);
	words = (char**)malloc(sizeof(char*) * (word_count + 1));
	while (words_entered < word_count)
	{
		word = (char*)malloc(sizeof(char) * (ft_word_size(str) + 1));
		while (WHITESPACE(str[0]) && str[0] != '\0')
			str++;
		while (!(WHITESPACE(str[0])) && str[0] != '\0')
			word[i++] = *str++;
		word[i] = '\0';
		words[words_entered++] = word;
		i = 0;
	}
	words[word_count] = 0;
	return (words);
}
