/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:16:45 by nschumac          #+#    #+#             */
/*   Updated: 2021/07/07 19:28:37 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/*
** INCLUDES
*/
# include <unistd.h>
# include <stdlib.h>
/*
** INCLUDES
*/

/*
** MACROS
*/
# define GNL_ERROR -1
# define GNL_LINE_READ 1
# define GNL_TRUE 1
# define GNL_FALSE 0
# define GNL_END_OF_FILE 0
# define GNL_FD_MAX 65536
# define BUFFER_SIZE 32
/*
** MACROS
*/

/*
** STRUCTS
*/
typedef struct s_data
{
	char	*newline[GNL_FD_MAX];
	char	*rest[GNL_FD_MAX];
	int		result;
	char	initialized[GNL_FD_MAX];
	int		fd;
}				t_data;
/*
** STRUCTS
*/

/*
** FUNCTION PROTOTYPES
*/
size_t	ft_strlensep(char *str, char seperator);
void	ft_strcpycount(char *str1, char *str2, int c);
void	ft_freedata(t_data *data);
int		ft_get_next_line(int fd, char **line);
int		ft_initializedata(t_data *data);
/*
** FUNCTION PROTOTYPES
*/

#endif
