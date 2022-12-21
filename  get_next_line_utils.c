/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:14:40 by filipe            #+#    #+#             */
/*   Updated: 2022/12/21 12:45:38 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_findchar(char *str, char c)
{
	int	index;
	
	if (str == NULL)
		return (-1);
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == c)
			return (index + 1);
		index++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int	i1;
	int	i2;
	
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_Strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i1 = 0;
	i2 = 0;
	while (s1 != NULL && s1[i1] != '\0')
	{
		str[i1] = s1[i1];
		i1++;
	}
	while (s2 != NULL && s2[i2] != '\0')
	{
		str[i1 + i2] = s2[i2];
		i2++;
	}
	str[i1 + i2] = '\0';
	return (str);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int	index;
	int	size;
	
	index = 0;
	size = ft_strlen(s);
	if (size == 0)
		return (NULL);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
}