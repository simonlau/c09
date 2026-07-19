/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 21:38:28 by simon.lau         #+#    #+#             */
/*   Updated: 2026/07/19 16:05:54 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	if (src == NULL || *src == '\0')
	{
		return (dest);
	}
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	count_separators_sets(char *separators, char *str)
{
	int		count;
	char	*current_sep;

	count = 0;
	current_sep = separators;
	while (*str != '\0')
	{
		if (*current_sep == *str)
		{
			current_sep++;
			if (*current_sep == '\0')
			{
				count++;
				current_sep = separators;
			}
		}
		else
		{
			current_sep = separators;
		}
		str++;
	}
	return (count);
}

int	move_to_pass_next_separator_end(char *separators, char **str)
{
	int	count;

	count = 0;
	while (**str != '\0')
	{
		if (**str == *separators)
		{
			separators++;
			*str += 1;
			if (*separators == '\0')
			{
				return (count);
			}
		}
		else
		{
			count++;
			*str += 1;
		}
	}
	*str += 1;
	return (count);
}

char	*slice_num_letters_to_new_str(char *str, int num, char **result,
		int index)
{
	char	*new_str;
	int		i;

	new_str = malloc((1 + num) * sizeof(*new_str));
	if (!new_str)
	{
		i = 0;
		while (i < index)
		{
			free(result[i]);
			i++;
		}
		free(result);
		return (NULL);
	}
	ft_strncpy(new_str, str, num);
	return (new_str);
}

char	**ft_split(char *str, char *charset)
{
	char	**ptr_str;
	int		count;
	int		i;
	char	*current_letter;
	char	**result;

	ptr_str = &str;
	move_to_pass_next_separator_end(charset, ptr_str);
	count = count_separators_sets(charset, *ptr_str);
	if (count < 1)
		return (NULL);
	result = malloc((1 + count) * sizeof(*result));
	if (!result)
		return (NULL);
	i = 0;
	current_letter = *ptr_str;
	while (*str != '\0')
	{
		count = move_to_pass_next_separator_end(charset, &current_letter);
		result[i] = slice_num_letters_to_new_str(str, count, result, i);
		i++;
		str = current_letter;
	}
	result[i] = NULL;
	return (result);
}
