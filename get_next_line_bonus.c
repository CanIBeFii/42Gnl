/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:11:43 by filipe            #+#    #+#             */
/*   Updated: 2022/12/26 13:19:49 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*string;
	char		*line_read;
	char		*temporary_string;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line_read = ft_gnl_read(fd);
	temporary_string = string;
	string = ft_strjoin(temporary_string, line_read);
	if (line_read)
		free(line_read);
	if (temporary_string)
		free(temporary_string);
	if (!string)
		return (NULL);
	if (ft_findchar(string, '\n') == -1)
		string = find_new_line(string, fd);
	temporary_string = ft_strdup(string);
	temporary_string = get_before_nl(temporary_string);
	string = get_after_nl(string);
	return (temporary_string);
}

char	*find_new_line(char *str, int fd)
{
	char	*tmp1;
	char	*tmp2;

	while (ft_findchar(str, '\n') == -1)
	{
		tmp1 = str;
		tmp2 = ft_gnl_read(fd);
		if (!tmp2)
			return (str);
		str = ft_strjoin(tmp1, tmp2);
		if (tmp1)
			free(tmp1);
		if (tmp2)
			free(tmp2);
	}
	return (str);
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
	return (string);
}
