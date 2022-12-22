/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:11:43 by filipe            #+#    #+#             */
/*   Updated: 2022/12/22 14:36:46 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_next_line(int file_descriptor)
// {
// 	static char	*string;
// 	char		*string_tmp1;
// 	char		*string_tmp2;
// 	int			index;
// 	int			i;

// 	index = ft_findchar(string, '\n');
// 	while (index == -1)
// 	{
// 		string_tmp1 = string;
// 		string_tmp2 = ft_gnl_read(file_descriptor);
// 		if (string_tmp2 == NULL)
// 			return (string);
// 		string = ft_strjoin(string_tmp1, string_tmp2);
// 		if (string_tmp1 != NULL)
// 			free(string_tmp1);
// 		if (string_tmp2 != NULL)
// 			free(string_tmp2);
// 		index = ft_findchar(string, '\n');
// 	}
// 	string_tmp2 = ft_strdup(string);
// 	string_tmp1 = ft_substr(string_tmp2, 0, index);
// 	free(string_tmp2);
// 	string_tmp2 = string;
// 	i = ft_strlen(string_tmp2);
// 	string = ft_substr(string_tmp2, index, i);
// 	free(string_tmp2);
// 	if (*string_tmp1 == '\0')
// 	{
// 		free(string_tmp1);
// 		return (NULL);
// 	}
// 	return (string_tmp1);
// }
char	*get_next_line(int file_descriptor)
{
	static char	*str;
	char		*line;
	char		*tmp;

	if (file_descriptor < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_gnl_read(file_descriptor);
	tmp = str;
	str = ft_strjoin(tmp, line);
	if (line)
		free(line);
	if (tmp)
		free(tmp);
	if (!str)
		return (NULL);
	if (ft_findchar(str, '\n') == -1)
		str = find_new_line(str, file_descriptor);
	tmp = ft_strdup(str);
	tmp = get_before_nl(tmp);
	str = get_after_nl(str);
	return (tmp);
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
