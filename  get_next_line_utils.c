/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:14:40 by filipe            #+#    #+#             */
/*   Updated: 2022/12/21 16:47:41 by filipe           ###   ########.fr       */
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
	char	*string;
	int	index;
	int	size;
	
	index = 0;
	size = ft_strlen(s);
	if (size == 0)
		return (NULL);
	string = malloc(sizeof(char) * (size + 1));
	if (string == NULL)
		return (NULL);
	if (s[0] == '\0')
		return (NULL);
	while (s[index] != '\0')
	{
		string[index] = s[index];
		index++;
	}
	string[index] = '\0';
	return (string);
}

char	*ft_substr(char *string, int start, int length)
{
	char	*sub_string;
	int	index;
	int	string_length;
	
	index = 0;
	string_length = ft_strlen(string);
	if (string_length < length)
		sub_string = malloc(sizeof(char) * (string_length + 1));
	else if (start > string_length)
		sub_string = malloc(sizeof(char));
	else
		sub_string = malloc(sizeof(char) * (length +1));
	if (sub_string == NULL)
		return (NULL);
	while (string[start] && index < length && start < string_length)
	{
		sub_string[index] = string[start];
		start++;
		index++;
	}
	sub_string[index] = '\0';
	return (sub_string);
}