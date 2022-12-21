/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:14:21 by filipe            #+#    #+#             */
/*   Updated: 2022/12/21 17:12:08 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

// Utils
/**
 * @brief Finds the first char C in STRING and returns it's, if there's none returns 0 
 * 
 * @param string
 * @param c 
 * @return int 
 */
int	ft_findchar(char *string, char c);

/**
 * @brief 
 * 
 * @param string 
 * @return int 
 */
int	ft_strlen(char *string);

#endif