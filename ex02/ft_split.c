/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 21:38:28 by simon.lau         #+#    #+#             */
/*   Updated: 2026/07/21 15:04:21 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char *separators, char c)
{
	while (*separators != '\0')
	{
		if (*separators == c)
		{
			return (1);
		}
		separators++;
	}
	return (0);
}

int	count_separators_sets(char *separators, char *str)
{
	int	count;
	int	start;

	count = 0;
	start = 0;
	while (*str != '\0')
	{
		if (is_separator(separators, *str))
		{
			if (start == 0)
			{
				count++;
				start = 1;
			}
		}
		else
		{
			start = 0;
		}
		str++;
	}
	return (count);
}

int	move_to_pass_next_separator_end(char *separators, char **str)
{
	int	count;
	int	start;

	count = 0;
	start = is_separator(separators, **str);
	while (**str != '\0')
	{
		if (!is_separator(separators, **str))
		{
			if (start == 1)
			{
				break ;
			}
			count++;
			*str += 1;
		}
		else
		{
			while (is_separator(separators, **str))
			{
				*str += 1;
				start = 1;
			}
		}
	}
	// *str += 1;
	return (count);
}

char	*slice_num_letters_to_new_str(char *str, int num)
{
	char	*new_str;
	int		i;

	new_str = malloc((1 + num) * sizeof(*new_str));
	if (!new_str)
	{
		return (NULL);
	}
	if (str == NULL || *str == '\0')
	{
		return (new_str);
	}
	i = 0;
	while (i < num)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	**ft_split(char *str, char *charset)
{
	char	**ptr_str;
	int		count;
	char	**result;
	int		i;
	char	*current_letter;
	int		x;

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
	while (i < count)
	{
		x = move_to_pass_next_separator_end(charset, &current_letter);
		result[i] = slice_num_letters_to_new_str(str, x);
		i++;
		str = current_letter;
	}
	result[i] = NULL;
	return (result);
}
