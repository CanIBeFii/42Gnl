/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:14:21 by filipe            #+#    #+#             */
/*   Updated: 2022/12/26 14:58:22 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
/**
 * @brief Receives a fd (file descriptor) and returns a string with a line
 *  read (strings needs to end in '\\n' or a EOF) from it.
 * 
 * @param fd int
 * @return char* 
 */
char	*get_next_line(int fd);

/**
 * @brief Receives a string and a file_descriptor, if the string doesn't have 
 * a newline '\\n', it will read BUFFER_SIZE from 'file_descriptor' 
 * until it finds a '\\n'.
 * 
 * @param string char*
 * @param file_descriptor int
 * @return char* 
 */
char	*find_new_line(char *string, int file_descriptor);

/**
 * @brief Receives a string and returns a string with all the characters
 *  until the first occurence of '\\n'.
 * 
 * @param string char*
 * @return char* 
 */
char	*get_before_nl(char *string);

/**
 * @brief Receives a string and returns the rest of the string after
 *  the first occurence of '\\n'.
 * 
 * @param string char*
 * @return char* 
 */
char	*get_after_nl(char *string);

/**
 * @brief Reads BUFFER_SIZE bytes from 'file_descriptor' and returns it.
 * 
 * @param file_descriptor int
 * @return char* 
 */
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