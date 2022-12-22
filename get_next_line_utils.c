/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:14:40 by filipe            #+#    #+#             */
/*   Updated: 2022/12/22 14:32:53 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_findchar(char *string, char c)
{
	int	index;

	if (!string)
		return (-1);
	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == c)
			return (index + 1);
		index++;
	}
	return (-1);
}

int	ft_strlen(char *string)
{
	int	index;

	index = 0;
	if (string == NULL)
		return (0);
	while (string[index] != '\0')
		index++;
	return (index);
}

char	*ft_strjoin(char *string1, char *string2)
{
	int		index1;
	int		index2;
	char	*string_join;

	if (string1 == NULL && string2 == NULL)
		return (NULL);
	string_join = malloc(sizeof(char) * (ft_strlen(string1)
				+ ft_strlen(string2) + 1));
	if (string_join == NULL)
		return (NULL);
	index1 = 0;
	index2 = 0;
	while (string1 != NULL && string1[index1] != '\0')
	{
		string_join[index1] = string1[index1];
		index1++;
	}
	while (string2 != NULL && string2[index2] != '\0')
	{
		string_join[index1 + index2] = string2[index2];
		index2++;
	}
	string_join[index1 + index2] = '\0';
	return (string_join);
}

char	*ft_strdup(char *string)
{
	int		index;
	int		size;
	char	*return_string;

	index = 0;
	size = ft_strlen(string);
	if (size == 0)
		return (NULL);
	return_string = malloc(sizeof(char) * (size + 1));
	if (return_string == NULL)
		return (NULL);
	if (string[0] == '\0')
		return (NULL);
	while (string[index] != '\0')
	{
		return_string[index] = string[index];
		index++;
	}
	return_string[index] = '\0';
	return (return_string);
}

char	*ft_substr(char *string, int start, int length)
{
	int		index;
	int		string_length;
	char	*sub_string;

	if (start == length)
		return (NULL); 
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
