/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:41:44 by abettini          #+#    #+#             */
/*   Updated: 2024/01/16 16:58:33 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_count(char const *s, char *c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (!ft_strchr(c, s[i]))
		{
			count++;
			while (!ft_strchr(c, s[i]) && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_strlenmod(const char *s, char *c)
{
	int	i;

	i = 0;
	while (!ft_strchr(c, s[i]) && s[i] != '\0')
		i++;
	return (i);
}

char	**ft_split_2(char const *s, char *c)
{
	char	**mat;
	int		count;
	int		i;
	int		j;

	count = ft_str_count(s, c);
	mat = malloc(sizeof(char *) * (count + 1));
	if (!mat)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count)
	{
		if (!ft_strchr(c, s[i]))
		{
			mat[j] = ft_substr(&s[i], 0, ft_strlenmod(&s[i], c));
			i = i + ft_strlenmod(&s[i], c);
			j++;
		}
		else
			i++;
	}
	mat[j] = NULL;
	return (mat);
}
