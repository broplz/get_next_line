/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:55:22 by hcherrie          #+#    #+#             */
/*   Updated: 2021/01/25 15:55:23 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	const char	*s;

	s = str;
	while (*s)
		++s;
	return (s - str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	char	*g1;
	char	*head;

	head = s1;
	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	g1 = res;
	if (res == NULL)
		return (NULL);
	if (head != NULL)
	{
		while (*head)
			*res++ = *head++;
	}
	while (*s2)
		*res++ = *s2++;
	free(s1);
	s1 = NULL;
	*res = '\0';
	return (g1);
}

void	*ft_memcpy(void *dst, void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	d = dst;
	s = src;
	i = 0;
	if (dst == 0 && src == 0)
		return (dst);
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (dst);
}

char	*ft_strdup(char *str)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(str);
	if ((copy = malloc(len + 1)) == NULL)
		return (NULL);
	ft_memcpy(copy, (char *)str, len);
	return (copy);
}

int		ft_strchr(char *str, int ch, int flag)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
		{
			if (flag == 1)
				return (1);
			else
				return (i);
		}
		i++;
	}
	if (str[i] == '\0')
	{
		if (flag == 1)
			return (0);
		else
			return (i);
	}
	return (i);
}
