/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:11:43 by filipe            #+#    #+#             */
/*   Updated: 2022/12/22 12:22:59 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int file_descriptor)
{
	static char	*string;
	char		*string_tmp1;
	char		*string_tmp2;

	while (ft_findchar(string, '\n') == -1)
	{
		string_tmp1 = string;
		string_tmp2 = ft_gnl_read(file_descriptor);
		if (string_tmp2 == NULL)
			return (string);
		string = ft_strjoin(string_tmp1, string_tmp2);
		if (string_tmp1 != NULL)
			free(string_tmp1);
		if (string_tmp2 != NULL)
			free(string_tmp2);
	}
	string_tmp1 = ft_strdup(string);
	string_tmp1 = get_before_nl(string_tmp1);
	string = get_after_nl(string);
	return (string_tmp1);
}

char	*get_before_nl(char *string)
{
	char	*return_string;
	int		index;
	int		counter;

	index = ft_findchar(string, '\n');
	if (index == -1)
		return (string);
	return_string = malloc(sizeof(char) * (index + 1));
	if (return_string == NULL)
		return (NULL);
	counter = 0;
	while (counter < index)
	{
		return_string[counter] = string[counter];
		counter++;
	}
	return_string[counter] = '\0';
	free(string);
	return (return_string);
}

char	*get_after_nl(char *string)
{
	char	*temporary_string;
	int		size;
	int		start;

	if (string == NULL)
		return (NULL);
	size = ft_strlen(string);
	start = 0;
	while (string[start] && string[start] != '\n')
		start++;
	if (string[start] == '\n')
		start++;
	temporary_string = ft_substr(string, start, (size - start));
	if (temporary_string[0] == '\0')
	{
		free(string);
		free(temporary_string);
		return (NULL);
	}
	free(string);
	return (temporary_string);
}

char	*ft_gnl_read(int file_descriptor)
{
	char	*string;
	size_t	size_read;

	string = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (string == NULL)
		return (NULL);
	size_read = read(file_descriptor, string, BUFFER_SIZE);
	if (size_read <= 0 || size_read > BUFFER_SIZE)
	{
		free(string);
		return (NULL);
	}
	string[size_read] = '\0';
	return (NULL);
}
