/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:21:46 by simon.lau         #+#    #+#             */
/*   Updated: 2026/07/13 14:23:19 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	char	*s1_letter;
	char	*s2_letter;
	int		diff;

	s1_letter = s1;
	s2_letter = s2;
	while (*s1_letter != '\0' || *s2_letter != '\0')
	{
		diff = *s1_letter - *s2_letter;
		if (diff != 0)
		{
			return (diff);
		}
		s1_letter++;
		s2_letter++;
	}
	return (0);
}
