/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:14:21 by filipe            #+#    #+#             */
/*   Updated: 2022/12/22 14:35:34 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*find_new_line(char *str, int fd);

char	*get_next_line(int file_descriptor);
char	*get_before_nl(char *string);
char	*get_after_nl(char *string);
char	*ft_gnl_read(int file_descriptor);


// Utils

/**
 * @brief Finds the first char C in STRING and returns it's, 
 * if there's none returns 0.
 * 
 * @param string  char*
 * @param c  char
 * @return int 
 */
int		ft_findchar(char *string, char c);

/**
 * @brief Finds the length of the string and returns it,
 *  if the string is not allocated returns 0.
 * 
 * @param string char*
 * @return int 
 */
int		ft_strlen(char *string);

/**
 * @brief Joins the string1 and the string2.
 * 
 * @param string1 char*
 * @param string2 char*
 * @return char* 
 */
char	*ft_strjoin(char *string1, char *string2);

/**
 * @brief Creates a duplicate of string and allocates the memory needed.
 * 
 * @param string char*
 * @return char* 
 */
char	*ft_strdup(char *string);

/**
 * @brief Creates a new string(sub_string) that copys 'length'
 *  characters of 'string' starting from 'start'. 
 * 
 * @param string char*
 * @param start int
 * @param length int
 * @return char* 
 */
char	*ft_substr(char *string, int start, int length);

#endif