/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:19:11 by simon.lau         #+#    #+#             */
/*   Updated: 2026/07/13 14:21:14 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strlen(char *str)
{
	int	count;

	if (str == NULL)
	{
		return (0);
	}
	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}
